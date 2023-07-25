var expr = require("express");
var app = expr();
var session = require("express-session");
var path = require("path");

app.use(session({save:false,saveUninitialized:false,secret:"hello!"}));
app.use(expr.static(path.join(__dirname,"/../public"),{index:"index_1.html"}));

app.get("/",(req,res)=>{

    res.send();

});

app.get("/sessionpage",(req,res)=>{

    req.session.name = req.query.TextBox1;
    res.set("content-type","text/html");
    res.write("Welcome : " + req.query.TextBox1 + "<br>");
    res.write("<a href='/sessiondestroy'>Destroy</a>");
    res.send();

});

app.get("/sessiondestroy",(req,res)=>{

    req.session.destroy();
    res.send("<script> window.location = '/'; </script>");

});

app.listen(6104);