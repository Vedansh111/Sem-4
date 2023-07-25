const express=require('express')
const app=express()
var cp=require('cookie-parser')
const bodyParser=require('body-parser')
const path=require('path')

app.use(bodyParser.urlencoded({extended:false}))
const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'index.html'}))
app.get('/',(req,res)=>{
    res.sendFile(staticPath+'/index.html')
})

app.use(cp())
app.get('/next',(req,res,next)=>{
    const waah={u:req.query.username, p:req.query.password}
    res.cookie('username',waah.u)
    next()
})
app.get('/next',(req,res)=>{
    res.send(req.cookies)
})
app.listen(4000,()=>{
    console.log("server running...")
})                           