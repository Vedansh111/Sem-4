var expr = require("express");
var app = expr();

var _router = require("./jmp1_HB-61-practice-other-2");

app.use("/",_router);

app.listen(6100);