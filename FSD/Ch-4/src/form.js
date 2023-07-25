const express=require('express');
const app=express();
const path=require('path');

const staticPath=path.join(__dirname,'../public');
app.use(express.static(staticPath,{index:'index.html'}));

app.get('/process',(req,res)=>{
    const users={
        u:req.query.username,
        p:req.query.password
    }
    res.send(users);
});

app.listen(5000,()=>{
    console.log("asd");
})
