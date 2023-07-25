const express=require('express')
const app=express()

// for using date function:
// app.get('/',(req,res,next)=>{
//     res.write('received on '+ new Date())
//     next()
// })
// app.get('/',(req,res,next)=>{
//     res.write('hello')
//     next()
// })
// app.get('/',(req,res)=>{
//     res.send()
// })

//for using  set content:type or something:
// app.use('/',(req,res,next)=>{
//     res.set({'content-type':'text/html'})
//     res.write('received on '+ new Date())
//     next()
// },
// (req,res,next)=>{
//     res.write('<h1 style="color: red">hello</h1>')
//     next()
// },
// (req,res)=>{
//     res.write("<h1>waah</h1>")
//     res.send()
// })
// app.listen(5000)

// storing in a variable:
// const filter=((req,res,next)=>{
//     console.log('thanks')
//     res.write('hello')
//     next()
// })
// app.use(filter)
// app.get('/',(req,res)=>{
//     res.write('heelo 2')
//     res.send()
// })
// app.listen(5000)