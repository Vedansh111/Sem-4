var expr = require("express");
var app = expr();
var path = require("path");

var obj1 = [{
    "name":"kartik",
    "age":24
},
{
    "name":"parth",
    "age":22
},
{
    "name":"sahil",
    "age":20
}
];

app.get("/",(req,res)=>{

    console.log(obj1.length);
    res.send();

});

app.get("/Sorted_Names",(req,res)=>{
        
    for(var i=0;i<obj1.length;i++){
        for(var i=0;i<obj1.length;i++){

            var counter = i+1;    
            if(counter != obj1.length && obj1[i].age > obj1[counter].age){
    
                var temp = obj1[i];
                obj1[i] = obj1[counter];
                obj1[counter] = temp;
                 
            }    
        }
    }


    var st1 = "<table border=1 width='100%' style='text-align:center' height='100%'>";
    for(var i=0;i<obj1.length;i++){
       
       var st2 = ("<tr><td>" + obj1[i].name.toString() + "</td>" + "<td>" + obj1[i].age.toString() + "</td></tr>");
       st1 += st2;

    }

    st1 += "</table>";
    res.send(st1);
    
});

app.listen(6100);