import React from 'react';

export default function Keys(){
    const students=[
        {
            id:1,
            name:'Abc'
        },
        {
            id:2,
            name:'Cde'
        },
        {
            id:3,
            name:'Bcd'
        }
    ]

    function But(){
        {students.map(students=>{
            return <>
                <h1>Key={students.id.toString()}</h1>
                <h1>Name={students.name}</h1>
            </>
        })}
    }

    return(
        <>
            <button onClick={But}>Waah</button>
        </>
    )
}