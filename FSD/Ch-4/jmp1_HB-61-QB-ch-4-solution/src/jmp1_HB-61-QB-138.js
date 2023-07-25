var expr = require("express");
var app = expr();
var path = require("path");
var session = require("express-session");

var static_path = path.join(__dirname,"/../public");

app.use(session({
    save:false,
    saveUninitialized:false,
    secret:"hello"
}));

app.use(expr.static(static_path,{index:"userlogin_page.html"}));

app.get("/",(req,res)=>{

    res.send();

});

app.get("/sessionpage",(req,res)=>{

    req.session.name = req.query.name;
    req.session.gender = req.query.gender;

    res.send("<script> window.location = '/fetchsession' </script>");

});

app.get("/fetchsession",(req,res)=>{
    
    res.send("name : " + req.session.name + "\n," + " gender : " + req.session.gender + "\n," +" <a href='/deletesession'>logout</a>");

});

app.get("/deletesession",(req,res)=>{

    req.session.destroy();
    res.redirect("/");

});

app.listen(6115);