const acorn = require("acorn");

var a = "something else";
const something = "anything else";

function declaration() {
  const arr = new Array();
  console.log(arr);
  return "something is being declared here";
}
