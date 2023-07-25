nm=require("nodemailer");
transfer=nm.createTransport({
    service:"gmail",
    host:"smtp.gmail.com",
    port:465,
    secure:true,
    auth:{
        user:"divyamj212@gmail.com",
        pass:"tvrcdutxaorwtkth"
    }

})
mailoption={
    from:'divyamj212@gmail.com',
    to:"sdev26937@gmail.com",
    subject:"Hello World!",
    text:"This is a test mail!"

}
transfer.sendMail(mailoption,(err,info)=>{
    if(err){
        console.log(err)
    }
    else{
        console.log(`mail sent to ${info}`)    
    }
})