var expr = require("express");
var app = expr();
var bodyp = require("body-parser");
var url = bodyp.urlencoded({extended:false});
var path = require("path");

var static_path = path.join(__dirname,"/../public");

app.use(expr.static(static_path,{index:"index_3.html"}));

app.get("/",(req,res)=>{

    res.send();

});

app.post("/display",url,(req,res)=>{

    var name = req.body.t1;
    var pass = req.body.t2;

    console.log(name," ",pass);
    res.send("Cheack Your console...");
    
});

app.listen(6107);