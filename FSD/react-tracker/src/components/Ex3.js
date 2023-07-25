import React from 'react';


export default function Ex3(props){
    return(
        <>
            <ul>
                <li>{props.car[0].name}</li>
                <li>{props.car[0].brand}</li>
                <li>{props.car[0].price}</li>
                <br />
                <li>{props.car[1].name}</li>
                <li>{props.car[1].brand}</li>
                <li>{props.car[1].price}</li>
            </ul>
        </>
    )   
}