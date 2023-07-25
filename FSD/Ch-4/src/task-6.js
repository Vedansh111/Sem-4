const express = require('express');
app = express();
const path = require('path');

const staticPath=path.join(__dirname,'../public')
app.use(express.static(staticPath,{index:'task-6.html'}))
app.get('/process', (req, res) => {
    if (req.query.a<0 || req.query.b<0) {
        res.send(`<center><h1>Enter Valid Value</h1></center>`);
    }
    else if(req.query.operation=="") {
        res.send(`<center><h1>Enter a Operation to perform</h1></center>`);
    }
    else if(req.query.operation=="add") {
        res.send(`<center><h1>${req.query.a}+${req.query.b}=${parseInt(req.query.a)+parseInt(req.query.b)}</h1></center>`);
    }
    else if(req.query.operation=="mul") {
        res.send(`<center><h1>${req.query.a}*${req.query.b}=${req.query.a*req.query.b}</h1></center>`);
    }
    else if(req.query.operation=="sub") {
        res.send(`<center><h1>${req.query.a}-${req.query.b}=${req.query.a-req.query.b}</h1></center>`);
    }
    else if(req.query.operation=="div") {
        res.send(`<center><h1>${req.query.a}/${req.query.b}=${req.query.a/req.query.b}</h1></center>`);
    }
})
app.listen(8080,()=>{
    console.log('server running....')
})