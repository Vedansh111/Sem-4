var expr = require("express");
var app = expr();
var path = require("path");
var bodyp = require("body-parser");
var url = bodyp.urlencoded({extended:false});

var statc_path = path.join(__dirname,"/../public");
app.use(expr.static(statc_path,{index:"index.html"}));

app.get("/",(req,res)=>{
    res.send();
});

app.post("/display",url,(req,res)=>{

    var name = req.body.name;
    var pass = req.body.password;
    var repass = req.body.repassword;
    var gender = req.body.gender1;

    console.log("complited !");
    if(repass == pass){
        
        res.write(name + "\n");
        res.write(pass + "\n");
        res.write(gender + "\n");
        res.send();
    }
    else
    {
        res.send("<script> window.location='/error'; </script>")
    }

});

app.get("/error",(req,res)=>{

    res.send("<h3 style='color:red'> No Needs To Write File having Form Element </h3>")
});

app.listen(6101);