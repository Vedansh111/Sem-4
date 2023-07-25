const express=require('express')
const app=express()
const bodyParser=require('body-parser')
const path=require('path')

app.use(bodyParser.urlencoded({extended:false}))
const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'task-5.html'}))
app.get('/',(req,res)=>{
    res.sendFile(staticPath+'/task-5.html')
})
app.post('/login',(req,res)=>{
    if(req.body.username=='admin'){
        res.write(`<h1 style:"color: red">${req.body.username},welcome</h1>`)
    }
    else{
        res.write("get out")
    }
    res.send()
})
app.listen(5000,()=>{
    console.log('Server running...')
})