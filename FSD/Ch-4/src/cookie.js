const express=require('express')
const app=express()
var cp=require('cookie-parser')
app.use(cp())
app.get('/',(req,res,next)=>{
    res.cookie('uname','xyz',{expires: new Date(Date.now()+20000)})
    res.cookie('abc','pqr')
    next()
})
app.get('/',(req,res,next)=>{
    console.log(req.cookie);
    next();
    res.send()
})
app.listen(5000)