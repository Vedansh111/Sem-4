var express=require('express')
var app=express()
const movies=require('./movies')
app.use('/movies',movies)
app.listen(3000,()=>{
    console.log("server is running...")
})