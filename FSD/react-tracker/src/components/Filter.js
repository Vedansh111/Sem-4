import React from "react";

export default function Filter(){
    const arr=[2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
    const newarr=arr.filter((num)=>{
        var flag=0
        for(var i=2;i<num;i++){
            if (num%i===0){
                flag=1;
                break
            }
        }
        if(flag===0) return true
        else return false
        
    }    
    )

    return(
        <>
            <h1>Prime:{newarr.join(',')}</h1>
        </>
    )
}