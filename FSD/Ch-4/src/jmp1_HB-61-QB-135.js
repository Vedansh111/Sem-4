var expr = require("express");
var app = expr();
var cookie = require("cookie-parser");

app.get("/",(req,res)=>{

    res.cookie("user_name","hardik");
    res.send();

});

app.get("/display",(req,res)=>{

    console.log(req.cookie);
    res.send(req.cookies);

});

app.listen(6112);