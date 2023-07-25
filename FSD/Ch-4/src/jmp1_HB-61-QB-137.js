var expr = require("express");
var app = expr();
var path = require("path");
var multer = require("multer");

var static_path = path.join(__dirname,"/../public");

app.use(expr.static(static_path,{index:"file_upload.html"}));

var storage = multer.diskStorage({

    destination:"uploads",
    filename:(req,file,cb)=>{
        cb(null,file.originalname)
    }
});

var upload = multer({
    storage:storage
}).single("file_uploader");

app.get("/",(req,res)=>{

    res.send();

});

app.post("/display",upload,(req,res)=>{

    res.write("uploaded: " + req.file.filename);
    res.send();

});

app.listen(6114);