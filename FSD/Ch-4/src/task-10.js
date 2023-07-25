const express=require('express')
const app=express()
var cp=require('cookie-parser')
const bodyParser=require('body-parser')
const path=require('path')

app.use(bodyParser.urlencoded({extended:false}))
const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'task-9.html'}))
app.get('/',(req,res)=>{
    res.sendFile(staticPath+'/task-9.html')
})

app.use(cp())
app.get('/process',(req,res,next)=>{
    const waah={u:req.query.username, p:req.query.password, e:req.query.email, r:req.query.rating}
    res.cookie('feedback',waah.u+ waah.p+ waah.e+ waah.r,{maxAge:10000})
    next()
})
app.get('/process',(req,res)=>{
    res.send('<h1>Thank you for the feedback 😁 </h1> <a href="feedbackview">Show Feedback</a><br> <button><a href="/">Logout</button>')
})
app.get('/feedbackview',(req,res)=>{
    res.send(req.cookies.feedback)
})
app.listen(4000,()=>{
    console.log("server running...")
})                           