const express=require('express')
const multer=require('multer')
const app=express()

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

app.post('/uploadfile',upload.single('mypic'),(req,res)=>{
    const file=req.file
    if(file.mimetype=='application/pdf'){
        res.send('file '+file.originalname+' has been uploaded in '+file.destination)
    }
    else{
        res.write('Nope')
    }   
})

app.listen(5000,()=>{
    console.log('server running...')
})