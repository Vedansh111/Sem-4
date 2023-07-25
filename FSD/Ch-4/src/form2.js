const express=require('express')
const app=express()
const path=require('path')

const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'index.html'}))
app.get('/process',(req,res)=>{
    res.send(`<h1>UN=${req.query.username}</h1><h2 style="color: blue">PW=${req.query.password}</h2>`)
})
app.listen(5000)
