var expr = require("express");
var app = expr();
var path = require("path");
var static_path = path.join(__dirname,"/../public");

app.use(expr.static(static_path));

app.get("/",(req,res)=>{
    res.send();
});

app.listen(3030);