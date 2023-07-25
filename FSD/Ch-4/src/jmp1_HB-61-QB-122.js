var expr = require("express");
var app = expr();

app.get("/",(req,res)=>{
    res.send("Hello World !")
});

app.listen(4000,(error)=>{
    console.log(error);
});