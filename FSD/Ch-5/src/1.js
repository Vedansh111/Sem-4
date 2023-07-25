var express=require('express')
var app=express()

app.set('view engine','pug')
var p=require('path')
const staticPath=p.join(__dirname,'../public')

app.get('/',(req,res)=>{
    res.render(staticPath+'/1')
})
app.get('/about',(req,res)=>{
    res.write('Waah')
    res.send()
})
app.listen(5000,()=>{
    console.log('server running...')
})