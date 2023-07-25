var expr = require("express");
var app = expr();
var path = require("path");
var bodyp = require("body-parser");
var url = bodyp.urlencoded({extended:false});

var static_path = path.join(__dirname,"/../public");

app.use(expr.static(static_path,{index:"text_file.html"}));

app.get("/",(req,res)=>{

    res.send();

});

app.post("/display",url,(req,res)=>{

    var description = req.body.textarea_data;

    var list_st1 = String(description).split(".");

    for(var i=0;i<list_st1.length;i++){
        res.write(list_st1[i] + "\n");
    }
    
    res.send();
});

app.listen(6113);