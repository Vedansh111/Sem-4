var expr = require("express");
var app = expr();
var path = require("path");

var static_path = path.join(__dirname,"/../public");

app.use(expr.static(static_path,{index:"student_info.html"}));

app.get("/",(req,res)=>{

    app.send();

});

app.get("/display",(req,res)=>{

    var name = req.query.student_name;
    var mobile_no = req.query.student_no;

    console.log(name," ",mobile_no);
    res.send();

});

app.listen(6111);