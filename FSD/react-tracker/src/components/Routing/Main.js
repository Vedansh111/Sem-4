import React from "react";
import { BrowserRouter as Router,Routes,Route,Link} from "react-router-dom";
import Home from './Home'
import Shop from './Shop';
import Contact from './Contact';
import Nopage from './Nopage';

export default function Main(){
    return (
        <div> 
            <Router>
                <div className="main-route">
                    <nav>
                        <ul style={{display:"inline-flex",listStyleType:"none",gap:"1rem", margin:0, padding:"0"}}>
                            <li><Link to='/'>Home</Link></li>
                            <li><Link to='/Shop'>Shop</Link></li>
                            <li><Link to='/Contact'>Contact</Link></li>
                            <li><Link to='/Nopage'>Nopage</Link></li>
                        </ul>
                    </nav>
                </div>
                
                <Routes>
                    <Route path="/" element={<Home/>}/>
                    <Route path="/Shop" element={<Shop/>}/>
                    <Route path="/Contact" element={<Contact/>}/>
                    <Route path="/Nopage" element={<Nopage/>}/>
                </Routes>
            </Router>             
        </div>
    )
}