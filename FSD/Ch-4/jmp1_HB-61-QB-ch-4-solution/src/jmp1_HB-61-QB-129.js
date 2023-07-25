var expr = require("express");
var app = expr();
var path = require("path");

var static_path = path.join(__dirname,"/uplod");

var sp2 = path.join(__dirname,"/../public");

app.use(expr.static(sp2,{index:"img.html"}));

app.use(expr.static(static_path));


app.get("/",(req,res)=>{

    res.send();

}).listen(6110);