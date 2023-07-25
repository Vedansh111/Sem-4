import React from "react";

export default function Task4(){
    const a =[1,2,3,4]
    return(
        <>
            {a.map(value=>{
                return <h1>{value*5}</h1>
            })}
        </>
    )
}