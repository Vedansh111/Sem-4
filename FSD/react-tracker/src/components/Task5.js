import React from "react";

export default function Task5(){
    const a=['logo192.png','logo192.png','logo192.png','logo192.png','logo192.png']
    return(
        <>
            {a.map(value=>{
                return <img src={value}></img>
            })}
        </>
    )
}