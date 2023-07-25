var nm = require("nodemailer");
const transfer = nm.createTransport(
    {
        service:"gamil",
        host:"smtp.gmail.com",
        port:465,
        secure:true,
        auth:{
            user:"rohanparmar1162@gmail.com",
            pass:"lopblvwrxgsghajl"
        }
    }
);
var mailoption = {
    from:"rohanparmar1162@gmail.com",
    to:"rp331563@gmail.com",
    subject:"Test Mail !",
    text:"It's Very Easy"
}
transfer.sendMail(mailoption,(err,info)=>{
    if(err){
        console.log(err);
    }else{
        console.log("Email Send"+info.response);
    }
})