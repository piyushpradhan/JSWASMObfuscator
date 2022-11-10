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
  visitExpressionStatement: (path) => {
    if (path.value.expression.type === 'CallExpression') {
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
    }
    return false;
  }
});

function constructFromAST(ast) {
  // console.log("------------------------------------------------------------------------------");
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

async function convertToWasm(code) {
  var stream = fs.createWriteStream("/tmp/temp.js");
  stream.once('open', function(fd) {
    stream.write(code);
    stream.end();
  });
  const { stdout, stderr } = await exec('nectar /tmp/temp.js --env wasm -o /tmp/temp.wasm');
  const contents = fs.readFileSync("/tmp/temp.wasm", { encoding: "utf8", flag: "r" });
  console.log(contents);
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
