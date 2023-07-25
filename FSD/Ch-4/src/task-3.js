const express=require('express')
const app=express()
const path=require('path')

const staticPath=path.join(__dirname,'../public');
console.log(staticPath)

app.use(express.static(staticPath));
app.listen(4000,()=>{
    console.log('server running...')
})