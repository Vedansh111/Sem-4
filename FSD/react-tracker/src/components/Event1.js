import React from 'react';

export default function Event1(){
    function waah(){
        alert("Noooooooo!!!")
    }

    var flag=0
    function nah(){
        const color=['skyblue','lightpink','lightblue']
        document.body.style.backgroundColor=color[flag]
        flag ++;
        if (flag==3){
            flag=0
        }
    }

    function xyz(e){
        console.log(e.target.value)
    }

    return(
        <>
            <button style={{backgroundColor:"brown",color:"Orange"}} onClick={setInterval((nah),1000)}>Waah</button>
            <input type="text" onChange={xyz}></input>
        </>
    )
}