import React from 'react';
function Intro() {

    var a = {
        color: "Orange",
    }
    var b = 25;

    return (
        <>
            <h1>Woow</h1>
            <h1 style={{ color: "red" }}>Nope</h1>
            <h1 style={a}>Hehehe</h1>
            <h1>{b}</h1>
            <img src="logo192.png" alt='img'></img>
            <ul>
                <li>1</li>
                <li>2</li>
                <li>3</li>
            </ul>

        </>
    );

}

export default Intro;
