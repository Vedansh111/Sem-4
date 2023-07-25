var expr = require("express");
var app = expr();
var path = require("path");

const obj=[
    {
        'name':'ved',
        'age':21
    },
    {
        'name':'krut',
        'age':20
    },
    {
        'name':'rajat',
        'age':54
    },
]

const sorta=obj.sort((a,b)=>{
   return a.age-b.age
});

const sortn=[obj[0].name,obj[1].name,obj[2].name]

app.get('/1',(req, res)=>{
    res.send(sorta)
})
app.get('/url',(req, res)=>{
    res.send(sortn.sort())
})

app.listen(6100);