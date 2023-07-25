const express = require("express");
const app = express();
const bodyparser = require("body-parser");
const multer = require("multer");
const url = bodyparser.urlencoded({extended:false});
const spath = __dirname;
app.use(express.static(spath,{index:"specific.html"}));
var storage = multer.diskStorage({
    destination:"specific",
    filename:function(req,file,cb){
        cb(null,file.originalname)
    }
});
const filter = (req,file,cb)=>{
    if(file.mimetype == "application/pdf"){
        cb(null,true)
    }
    else{
        cb(null,false);
        return cb("only pdf format allowed")
    }
}
const maxSize = 1024*1024*1024; //! 1 gb
var upload = multer({
    storage:storage,
    limits:{fileSize:maxSize},
    fileFilter:filter
});
app.post("/uploadfile",upload.single("mypdf"),url,(req,res)=>{
    const file = req.file
    if(file){
        res.send(`${file.originalname}`)
    }
});
app.listen(3800,()=>{
    console.log("Started");
})