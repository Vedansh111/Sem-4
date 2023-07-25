const expr =require("express")
const app =expr()
const movies=require("./movies")
app.use("/movies",movies)
app.listen(2000,()=>
{
    console.log("Server running on200")
})