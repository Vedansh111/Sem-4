const express = require("express");
const app = express();
const bodyparser = require("body-parser");
const url = bodyparser.urlencoded({extended:false0});
const spath = __dirname;
const multer = require("multer");
app.use(express.static(spath,{index:"fileupload.html"}));
var storage = multer.diskStorage({
    destination:"upload",
    filename:function(req,file,cb){
        cb(null,file.originalname)
    }
})
var upload = multer({storage:storage})
app.post("/upload",upload.single("profileImage"),url,(req,res)=>{
    const file = req.file;
    console.log(req.file);
    if(file){
        res.send(`<h1>file ${file.originalname} has been uploaded in ${file.destination} folder`)
    }
});
app.listen(3800,()=>{
    console.log("started");
})

