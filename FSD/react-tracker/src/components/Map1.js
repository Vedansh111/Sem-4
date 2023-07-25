import React from 'react';

export default function Map1(){
    const array=[1,2,3,4]
    return(
        <>
        {array.map(value=>{
            return <h1>{value}</h1>
        })}
        </>
    )
}