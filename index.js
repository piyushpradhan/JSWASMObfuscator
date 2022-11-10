const fs = require("fs");
const acorn = require("acorn");
const recast = require("recast");
const escodegen = require("escodegen");

const contents = fs.readFileSync("sample.js", { encoding: "utf8", flag: "r" });
const ast = acorn.parse(contents, {
  allowHashBang: false,
});

const sourceAst = [...ast.body];

const t1Rule = (t1Args) => {
  const wasm = `(global $d1 (export "d1") (mut i32) (i32.const 0))\n(memory (export "memory") 1)\n(data $data0 (i32.const 0) "${t1Args}\\00"))`;
  const modifiedJs =
    "(function decodeString() {\n\tlet m = instanWasm(source);\n\tlet buf = m.instance.exports.memory.buffer;\n\tlet startInd = m.instance.exports.d1;\n\treturn loadStrFromBuf(buf, startInd);\n})()";
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

recast.visit(sourceAst, {
  visitNode: (path) => {
    const generated = constructASTNode(path.value);
    console.log("NODE");
    console.log(generated);
    return false;
  },
  // T1-StringLiteral
  visitLiteral: (path) => {
    // Note: only for string literals
    if (
      typeof path.value.value === "string" &&
      path.parentPath.value.type !== "ReturnStatement" &&
      path.parentPath.parentPath.value.type !== "CallExpression"
    ) {
      // const code = constructASTNode(path.value);
      // console.log(code);
      const { modifiedJs } = t1Rule(path.value.value);
      // generate the desired ast according to Rule T1
      const generatedAst = acorn.parse(modifiedJs, {
        allowHashBang: false,
      });
      path.replace(generatedAst);
    }
    return false;
  },
  // T2-ArrayInitialization
  visitNewExpression: (path) => {
    if (path.value.callee.name === "Array") {
      const { modifiedJs } = t2Rule(path.value.arguments);
      // generate the desired ast according to Rule T2
      const generatedAst = acorn.parse(modifiedJs, {
        allowHashBang: false,
      });
      // do something here
    }
    return false;
  },
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
