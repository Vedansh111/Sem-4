var expr = require("express");
var app = expr();

app.get("/",(req,res)=>{
    res.send("Welcome to My Home Page...");
});

app.get("/about",(req,res)=>{
    res.send("Welcome to My About Page...");
});

app.get("/contact",(req,res)=>{
    res.send("Welcome to My Contact Page...");
});

app.get("/temp",(req,res)=>{
    res.send("Welcome to My Temp Page...");
});

app.get("/*",(req,res)=>{
    res.send("404 Page Not Found !")
});

app.listen(6105);