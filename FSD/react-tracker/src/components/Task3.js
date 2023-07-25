import React from "react";

export default function Task3(){
    const a =["naope!!1","asds",'2as']
    return(
        <>
            {a.map(value=>{
                return <h1>{value.toUpperCase()}</h1>;
            })}
        </>
    )
}