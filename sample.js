const acorn = require("acorn");

var a = "something else";
const something = "anything else";

var arr = new Array();
arr[0] = 1;
arr[1] = 2;

var str = "malicious code";

eval(str);

