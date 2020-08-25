import React from "react"
import facebook from "../Images/facebook.png"
import instagram from "../Images/instagram.png"
import linkedin from "../Images/linkedin.png"
import "../CSS/Footer.css"

function Footer() {
    return (
        <div className="Footer"> 
            <div className="footerSocialIcons">
                <a href="https://www.facebook.com/MLNRETIREMENTPLANNING/"><img src={facebook} alt="facebook" /></a>
                <a href="https://www.instagram.com/mlnrp/"><img src={instagram} alt="instagram" /></a>
                <a href="https://www.linkedin.com/in/mniemczyk/"><img src={linkedin} alt="linkedin" /></a>
            </div>

            <p>Investment advisory services offered through Michael Niemczyk Associates, Inc., a State Registered Investment Advisor.</p>
            <p>© Copyright 2019   |   Michael Niemczyk Associates, Inc. |   All Rights Reserved   |  It’s never too late to take the first step or get a second opinion</p>
        </div>
    )
}

export default Footer