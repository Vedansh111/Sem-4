const express=require('express')
const app=express()
const bodyParser=require('body-parser')
const path=require('path')

app.use(bodyParser.urlencoded({extended:false}))
const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'task-7.html'}))
app.get('/',(req,res)=>{
    res.sendFile(staticPath+'/task-7.html')
})
app.post('/check',(req,res,next)=>{
    if (req.body.username=='admin'){
        next();
    }
    else{
        res.write('<div style="color:red">Warning</div>')
    }
    res.send()
},(req,res)=>{
    res.write('welcome admin')
    res.send()
})

app.listen(5000,()=>{
    console.log('Server running...')
})