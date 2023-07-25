import React from 'react';

export default function Task1(){
    const v={
        name:"ved",
        date:new Date().toLocaleDateString(),
        time:new Date().toLocaleTimeString()
    }

    return(
        <>
            <h1>{v.name}</h1>
            <p>{v.date}</p>
            <p>{v.time}</p>
        </>
    )
}