// const { Router } = require("express");
const express = require("express");
const router = express.Router();
const movies = [
    {
        id:101,
        name:"xyz",
        year:1999,
        rating:8.1
    }
    ,{
        id:102,
        name:"pqr",
        year:2000,
        rating:8.3
    }
]
module.exports = router;
router.get("/:id([0-9]{3,})",(req,res)=>{
    var currmovie = movies.filter((m)=>{
        if (m.id == req.params.id){
            return true;
        }
    });

    if(currmovie.length == 1){
        res.json(currmovie[0]);
    }
    else{
        res.json({message:"not found"})
    }
});