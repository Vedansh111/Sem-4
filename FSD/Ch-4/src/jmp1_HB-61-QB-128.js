var expr = require("express");
var app = expr();


app.get("/",(req,res,next)=>{

    res.write("from first gate method...");
    next();

});
app.get("/",(req,res,next)=>{

    res.write("\nfrom second get method...");
    next();

});
app.get("/",(req,res)=>{

    res.write("\nfrom third get method...");
    res.send();

});
app.listen(6109);