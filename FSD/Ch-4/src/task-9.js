const express=require('express')
const app=express()
var cp=require('cookie-parser')
const bodyParser=require('body-parser')
const path=require('path')

app.use(bodyParser.urlencoded({extended:false}))
const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'form.html'}))
app.get('/',(req,res)=>{
    res.sendFile(staticPath+'/form.html')
})

app.use(cp())
app.get('/process',(req,res)=>{
    const waah={u:req.query.username, p:req.query.password}
    if (req.query.subscribe==null){
        res.send("Please subscribe.")
    }
    else(
        res.send('Thnks '+waah.u+' for subscribing.')
    )
    res.send()
})
app.listen(5000,()=>{
    console.log("server running...")
})                           