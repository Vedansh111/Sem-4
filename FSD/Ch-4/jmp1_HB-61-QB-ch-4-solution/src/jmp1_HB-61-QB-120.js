const expr = require("express");
const app = expr();
const path = require("path");
const bodyp = require("body-parser");
const url = bodyp.urlencoded();

var static_path = path.join(__dirname,"/../public");

app.use(expr.static(static_path,{index:"admin_login.html"}));

app.get("/",(req,res)=>{
    res.send();
});

app.post("/user_conformation",upload,url,(req,res)=>{

    var name = req.body.name;
    var pass = req.body.password;
    var filepath = req.file;

    if(name == "admin"){
        res.send("Welcome... Admin");
    }
    else
    {
        res.send("<h2 style='color:red;text-align:center;'> Only admin Can access this page ! </h2>")
    }

});

app.listen(6102);