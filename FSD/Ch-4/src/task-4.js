const express=require('express')
const app=express()
const bodyParser=require('body-parser')
const path=require('path')

app.use(bodyParser.urlencoded({extended:false}))
const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'task-4.html'}))
app.get('/',(req,res)=>{
    res.sendFile(staticPath+'/form.html')
})
app.post('/process',(req,res)=>{
    res.send(req.body)
})
app.listen(5000,()=>{
    console.log('Server running...')
})