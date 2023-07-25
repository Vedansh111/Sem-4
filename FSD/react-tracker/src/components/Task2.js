import React from 'react';

export default function Task2(props){
    return (
        <>
            <table>
                <tr>
                    <td colSpan={4}>{props.name}</td>
                </tr>
                <tr>    
                    <td colSpan={3}><img src={props.img} /></td>
                </tr>
                <tr>    
                    <td colSpan={31}>{props.price}</td>
                </tr>
            </table>
        </>
    )
}