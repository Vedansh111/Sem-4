var nm = require("nodemailer");
var trans = nm.createTransport({
    service:"gmail",
    host:"smtp.gmail.com",
    post:465,
    secure:true,
    auth:{
        user:"phardikpatel647@gmail.com",
        pass:"bhxcgyozzzhbbxyg"
    }
});

var mailoption = {
    from:"phardikpatel647@gmail.com",
    to:"gunjanvyas76@gmail.com",
    subject:"title",
    text:"data description"
}

trans.sendMail(mailoption,(err,info)=>{

    if(err){
        console.log(err);
    }
    else
    {
        console.log(info.response);
    }

});