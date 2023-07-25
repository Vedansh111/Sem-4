var expr = require("express");
var app = expr();
var multer = require("multer");
var path = require("path");

var storage = multer.diskStorage({

    destination:"upload",
    filename: (req,file,cb)=>{
        cb(null,file.originalname);
    }

}); 

var upload = multer({
    storage:storage,
    // fileFilter: (req,file,cb)=>{
    //     if(file.mimetype == "application/pdf"){
    //         cb(null,true);
    //     }
    //     else
    //     {
    //         return cb("Only Pdf Allowd !");
    //     }
    // }
}).single("file_uploader");

app.use(expr.static(path.join(__dirname,"/../public"),{index:"practice-1.html"}));
app.use(expr.static(path.join(__dirname,"/upload")));

app.get("/",upload,(req,res)=>{

    res.send();

});

app.post("/display",upload,(req,res)=>{
    
    res.set("content-type","text/html");
    res.send("<div name='img' style='background-color:orangered;overflow:hidden;display:flex;align-items:center;justify-content:center;border-radius:100%;width:200px;height:200px;position:absolute;top:50%;left:50%;transform:translate(-50%,-50%);'> <img src='" + req.file.filename + "' width='100%' ></div>");

});

app.listen(6100);