const express=require('express')
const sess=require('express-session')
const app=express()
app.use(sess({
    resave:false,
    saveUninitialized:false,
    secret:'waah'
}))
app.get('/',(req,res)=>{
    if(req.session.page_view){
        req.session.page_view++
        res.send("You visited "+req.session.page_view+" times.")
    }
    else{
        req.session.page_view=1
        res.send("Welcome 1st time")
    }
})
app.listen(8000,()=>{
    console.log('server running...')
})