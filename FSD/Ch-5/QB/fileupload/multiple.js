const express = require("express");
const app = express();
const bodyparser = require("body-parser");
const multer = require("multer");
const url = bodyparser.urlencoded({extended:false});
const spath = __dirname;
app.use(express.static(spath,{index:"multiple.html"}))
var storage = multer.diskStorage({
    destination:"multiple",
    filename:function(req,file,cb){
        cb(null,file.originalname)
    }
});
var upload = multer({storage:storage});
app.post("/uploadfile",upload.array("mydoc",5),url,(req,res)=>{
    const files = req.files
    if(files){
        res.set("content-type","text/html");
        for(i of files){
            res.write("<h2>"+JSON.stringify(i.originalname)+" has been uploaded</h2>");
        }
        res.send();
    }
});
app.listen(3800,()=>{
    console.log("Started");
});