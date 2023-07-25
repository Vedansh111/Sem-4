const express=require('express')
const app=express()
var path=require('path')

// app.listen(808,()=>{
//     console.log("hello.")
// })

// app.get('/', (req, res) => {
//     res.send("HomePage");
// })
// app.listen(4000,()=>{
//     console.log('server running...')
// })


//*** example-1(not that imp)
// app.get('/',(req,res)=>{
//     res.send('<h1>HomePage</h1>')
// })
// app.get('/about',(req,res)=>{
//     res.send('<h1 style="color: aqua;">About <span style="color: red;">Us</span></h1>')
// })
// app.get('/contact',(req,res)=>{
//     res.send('Contact Us')
// })
// app.listen(4000,()=>{
//     console.log('server running...')
// })


//*** task-1:
// app.get('/',(req, res)=>{
//     res.send('<h1 style="color: blue">HomePage</h1>')
// })
// app.get('/student',(req,res)=>{
//     res.send('<h1>Welcome Students</h1>')
// })
// app.get('/about',(req,res)=>{
//     res.send('<em style="color: green;">About Us</em>')
// })
// app.listen(4000,()=>{
//     console.log('server running....')
// })    


//*** how to parse json obj:-
// const obj=[
//     {
//         'name':'ved',
//         'sub':'fsd-2'
//     },
//     {
//         'name':'krut',
//         'sub':'fsd-2'
//     }
//     ]
// app.get('/1',(req, res)=>{
//     res.send(obj[0].name+" "+obj[0].sub)
// })
// app.get('/2',(req, res)=>{
//     res.send(obj[1].name+" "+obj[1].sub)
// })
// app.listen(4000,()=>{
//     console.log('server running....')
// })

//*** task-2:-
// const obj=[
//     {
//         'name':'ved',
//         'age':21
//     },
//     {
//         'name':'krut',
//         'age':20
//     },
//     {
//         'name':'rajat',
//         'age':54
//     },
// ]

// const sorta=obj.sort((a,b)=>{
//    return a.age-b.age
// });

// const sortn=[obj[0].name,obj[1].name,obj[2].name]

// app.get('/1',(req, res)=>{
//     res.send(sorta)
// })
// app.get('/url',(req, res)=>{
//     res.send(sortn.sort())
// })
// app.listen(5000,()=>{
//     console.log('server running....')
// })

// ***to load an image,html:-
// app.get('/',(req,res)=>{
//     res.sendFile(path.join(__dirname,'src/index.html'))
// })
// app.listen(5000)

