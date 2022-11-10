const fs = require("fs");
const acorn = require("acorn");
const recast = require("recast");
const escodegen = require("escodegen");
const util = require("util");

const exec = util.promisify(require("child_process").exec);

const contents = fs.readFileSync("sample.js", { encoding: "utf8", flag: "r" });
const ast = acorn.parse(contents, {
  allowHashBang: false,
});

const sourceAst = [...ast.body];

const t1Rule = (t1Args, variableName, declarator) => {
  const wasm = `(global $d1 (export "d1") (mut i32) (i32.const 0))\n(memory (export "memory") 1)\n(data $data0 (i32.const 0) "${t1Args}\\00"))`;
  const modifiedJs =
    `${declarator} ${variableName} = ` + "(function decodeString() {\n\tlet m = instanWasm(source);\n\tlet buf = m.instance.exports.memory.buffer;\n\tlet startInd = m.instance.exports.d1;\n\treturn loadStrFromBuf(buf, startInd);\n})()";
  return { wasm, modifiedJs };
};

const t2Rule = (t2Args) => {
  let wasm = '(memory (export "memory") 1)\n(func $f (export "f")';
  for (let i = 0; i < t2Args.length; i++) {
    wasm += `\n\ti32.const ${i}`;
    wasm += `\n\ti32.const ${t2Args[i]}`;
    wasm += "\n\ti32.store";
  }
  wasm += ")";
  const modifiedJs =
    "(function arrInput() {\n\tlet m = instanWasm(source);\n\tlet buf = m.instance.exports.memory.buffer;\n\tm.instance.exports.f();\n\treturn arr = loadArrFromBuf(buf, startInd, len)\n})()";
  return { wasm, modifiedJs };
};

const t3Rule = (functionName, t3Args) => {
  const wasm = `(global $d1 (export "d1") (mut i32) (i32.const 0))\n(memory (export "memory") 1)\n(data $data0 (i32.const 0) "${functionName}\\00"))`;
  let modifiedJs =
    "let m = instanWasm(source);\nlet buf = m.instance.exports.memory.buffer;\nlet startInd = m.instance.exports.d1;"
  t3Args.map((item) => {
    modifiedJs += `\nwindow[loadStrFromBuf(buf, startInd)](${item})`;
  });
  return { wasm, modifiedJs };
}

const t4RuleA = (functionName, args) => {
  const functionSignature = args.length <= 0 ? `${functionName}()` : `${functionName}(${args.join(",")})`;
  const wasm = '(func $f0 (export "f0")\n\tcall $impFunc) ;; JS import';
  const modifiedJs = `let impObj = {imports: {impFunc: () => ${functionSignature}}}\nlet m = instanWasm(source, impObj);\nm.instance.exports.f0()`;
  return { wasm, modifiedJs };
}

const t4RuleB = (functionName, args) => {
  const functionSignature = args.length <= 0 ? `f0()` : `f0(${args.join(",")})`;
  const wasm = '(func $f0 (export "f0) (param externref) (result externref)\n\tlocal.get $p\n\tcall $impFunc) ;; JS import'
  const modifiedJs = `let impObj = {imports: {impFunc: ${functionName}}};\nlet m = instanWasm(source, impObj);\nlet r = m.instance.exports.${functionSignature};`
  return { wasm, modifiedJs };
}

const t5Rule = (condition, ifblocks, elseblocks) => {
  let wasm = '(func $f (export "f0") (param $p)\n\tlocal.get $p)\nif\n\tcall $imp1 ;; JS import'
  if (elseblocks.length > 0) {
    wasm += '\nelse\n\tcall $imp2 ;; JS import'
  }
  wasm += '\nend)'

  let ifStatements = "";
  ifblocks.map((statement) => {
    ifStatements += statement;
  });
  let elseStatements = "";
  elseblocks.map((statement) => {
    elseStatements += statement;
  });
  const modifiedJs = `let impObj = {imports: {\n\timp1: () => {${ifStatements}},\n\timp2: () => {${elseStatements}}}};\nlet m = instanWasm(source, impObj);\nm.instance.exports.f(${condition} ? 1 : 0);`
  return { wasm, modifiedJs };
}

const t6Rule = (condition, increment, body) => {
  const wasm = `(func $f (export "f0")\n\tblock $L0\n\t\tloop $L1\n\t\t\tcall ${condition} ;; JS import\n\t\t\ti32.eqz\n\t\t\tbr_if $L0\n\t\t\tcall $body ;; JS import\n\t\t\tcall $incre ;; JS import\n\t\t\tbr $L1\n\t\tend\n\tend)`
  const modifiedJs = `init;\nlet impObj = {\n\timports: {\n\t\tcond:() => {return ${condition} ? 1 : 0},\n\t\tincre: () => {${increment}},\n\t\tbody: () => {${body}}\n\t}\n};\nlet m = instanWasm(source, impObj);\nm.instance.exports.f();`
  return { wasm, modifiedJs };
}

const t7Rule = (condition, body) => {
  const wasm = `(func $f (export "f0") (param $p)\n\tblock $L0\n\t\tloop $L1\n\t\t\tcall ${condition} ;; JS import\n\t\t\ti32.eqz\n\t\t\tbr_if $L0\n\t\t\tcall $body ;; JS import\n\t\t\tbr $L1\n\t\tend\n\tend)`
  const modifiedJs = `let impObj = {\n\timports: {\n\t\tcond:() => {return ${condition} ? 1 : 0},\n\t\tbody: () => {${body}}\n\t}\n};\nlet m = instanWasm(source, impObj);\nm.instance.exports.f();`
  return { wasm, modifiedJs };
}

recast.visit(sourceAst, {
  visitNode: (path) => {
    let declaration = {};
    for (let ind in path.value.declarations) {
      declaration = path.value.declarations[ind];
    }
    if (typeof (declaration.init) !== "undefined") {
      // T1-StringLiteral
      if (declaration.init.type === 'Literal' && typeof (declaration.init.value) === 'string') {
        const code = constructASTNode(path.value);
        let variableName;
        let declarator = "var";
        if (code.search('var') === 0) {
          variableName = code.split("var")[1].split("=")[0].trim();
          declarator = "var";
        } else if (code.search('const') === 0) {
          variableName = code.split("const")[1].split("=")[0].trim();
          declarator = "const";
        } else if (code.search('let') === 0) {
          variableName = code.split("let")[1].split("=")[0].trim();
          declarator = "let";
        }
        const { modifiedJs } = t1Rule(path.value.value, variableName, declarator);
        const generatedAst = acorn.parse(modifiedJs, {
          allowHashBang: false,
        });
        path.replace(generatedAst);
      } else if (declaration.init.type === 'NewExpression') {
        // T2-ArrayInitialization
        const code = constructASTNode(path.value);
      }
    }
    return false;
  },
  // T3-FunctionName
  visitExpressionStatement: (path) => {
    if (path.value.expression.type === 'CallExpression' && checkIfNameExists(path.value.expression.callee.name)) {
      const functionName = path.value.expression.callee.name;
      const args = [];
      path.value.expression.arguments.map((item) => {
        args.push(item.name);
      });
      const { modifiedJs } = t3Rule(functionName, args);
      const generatedAst = acorn.parse(modifiedJs, {
        allowHashBang: false,
      });
      path.replace(generatedAst);
    } else if (path.value.expression.type === 'CallExpression') {
      const functionName = path.value.expression.callee.name;
      const args = [];
      path.value.expression.arguments.map((item) => {
        args.push(item.value);
      });
      const { modifiedJs } = t4RuleA(functionName, args);
      const generatedAst = acorn.parse(modifiedJs, {
        allowHashBang: false,
      });
      path.replace(generatedAst);
    }
    return false;
  },
  // T5-IfStatement
  visitIfStatement: (path) => {
    const condition = constructASTNode(path.value.test);
    const ifBlock = [];
    const elseBlock = [];
    path.value.consequent.body.map((node) => {
      ifBlock.push(constructASTNode(node));
    });
    path.value.alternate.body.map((node) => {
      elseBlock.push(constructASTNode(node));
    });
    const { modifiedJs } = t5Rule(condition, ifBlock, elseBlock);
    const generatedAst = acorn.parse(modifiedJs, {
      allowHashBang: false,
    });
    path.replace(generatedAst);
    return false;
  },
  // T6-ForStatement
  visitForStatement: (path) => {
    const condition = constructASTNode(path.value.test);
    const increment = constructASTNode(path.value.update);
    let body = "";
    path.value.body.body.map((statement) => {
      body += constructASTNode(statement);
    });
    const { modifiedJs } = t6Rule(condition, increment, body);
    const generatedAst = acorn.parse(modifiedJs, {
      allowHashBang: false,
    });
    path.replace(generatedAst);
    return false;
  },
  // T7-WhileStatement
  visitWhileStatement: (path) => {
    const condition = constructASTNode(path.value.test);
    let body = "";
    path.value.body.body.map((statement) => {
      body += constructASTNode(statement);
    });
    const { modifiedJs } = t7Rule(condition, body);
    const generatedAst = acorn.parse(modifiedJs, {
      allowHashBang: false,
    });
    path.replace(generatedAst);
    return false;
  }
});

function constructFromAST(ast) {
  // console.log(------------------------------------------------------------------------------");
  for (ind in ast) {
    const generated = escodegen.generate(ast[ind]);
    console.log(generated);
    // console.log("------------------------------------------------------------------------------");
  }
}

function constructASTNode(node) {
  const generated = escodegen.generate(node);
  return generated;
}

function checkIfNameExists(functionName) {
  const unsafe = ["eval", "escape", "atob", "btoa", "WScript", "unescape", "escape", "Function", "ActiveXObject"];
  unsafe.forEach((func) => functionName === func);
  return false;
}

console.log("ORIGINAL");
console.log(
  "------------------------------------------------------------------------------"
);
console.log(contents);
console.log("GENERATED");
console.log(
  "------------------------------------------------------------------------------"
);

console.log(constructFromAST(sourceAst));
