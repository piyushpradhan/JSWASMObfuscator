const acorn = require("acorn");

var a = "something else";
const something = "anything else";

var arr = new Array();
arr[0] = 1;
arr[1] = 2;

var str = "malicious code";

eval(str);

function callThisFunction(a, b) {
  return a + b;
}

callThisFunction(1, 23);

let r = callThisFunction(5, 8);

if (arr[0] === 1) {
  let first = "first";
  let second = "second";
} else {
  let hint = "hint";
}

for (let i = 0; i < 5; i++) {
  console.log("Another statement");
  console.log("loop : ", i);
}
