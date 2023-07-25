const express=require('express')
const router=express.Router()
const movies=[
    {
        id:101,
        name:'abc',
        year:1999
    },
    {
        id:201,
        name:'xyz',
        year:2005
    }
]

module.exports=router
router.get('/',(req,res)=>{
    res.json(movies)
})

router.get('/:id([0-9]{3,})',(req,res)=>{
    var currMovie=movies.filter((m)=>{
        if(m.id==req.params.id){
            return true
        }
    })
    if(currMovie.length==1){
        res.json(currMovie[0])
    }
    else{
       res.json({message:'not found'})
    }
})