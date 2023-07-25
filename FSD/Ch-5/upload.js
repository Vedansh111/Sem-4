const express=require('express')
const multer=require('multer')
const app=express()

//***for multiple files to upload
app.get('/',(req,res)=>{
    res.sendFile(__dirname+'/fileupload.html')
})

var storage=multer.diskStorage({
    destination:'single',
    filename:function(req,file,cb){
        console.log(file)
        cb(null,file.originalname)
    }
})

var upload=multer({
    storage:storage
})

app.post('/uploadfile',upload.array('mypic',10),(req,res)=>{
    const file=req.files
    if(file){
        for(i of file){
            res.write(JSON.stringify(i.originalname)+' has been uploaded.')
        }
        res.send()
    }   
})

app.listen(5000,()=>{
    console.log('server running...')
})
