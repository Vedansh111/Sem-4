var expr = require("express");
const router = expr.Router();

const object = [{
    id:101,name:"shree mad bhagavat geeta",year:500,rating:"infinity"
}
,
{
    id:102,name:"ramayan",year:500,rating:"inifinity"
}];

module.exports = router;

router.get("/:id",(req,res)=>{

    var data = object.filter((m)=>{
        if(m.id == req.params.id){
            return true;
        }
    });

    if(data.length == 1){
        res.send(data[0]);
    }
    else{
        res.send("Message not found !");
    }

});