const express = require("express")
const app = express();
const movies = require("./movies");
app.use("/movies",movies);
app.listen(3800,()=>{
    console.log();
})