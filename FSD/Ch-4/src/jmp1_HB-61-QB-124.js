var expr = require("express");
var app = expr();
var path = require("path");

var static_path = path.join(__dirname,"../public");

app.get("/",(req,res)=>{
    res.sendFile(static_path + "/index.html");
});

app.get("/json",(req,res)=>{
    res.sendFile(static_path + "/index.json");
});

app.listen(6106);