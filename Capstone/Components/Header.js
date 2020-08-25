import React from "react"
import headerImage from "../Images/headerImage.jpg"
import facebook from "../Images/facebook.png"
import instagram from "../Images/instagram.png"
import linkedin from "../Images/linkedin.png"
import { Link } from 'react-scroll'
import Navbar from './Navbar.js'
import "../CSS/Header.css"

class Header extends React.Component {
  state = {};
  render() {
    return (
          <div>
          <Navbar />
            <header>
              <div className="socialIcons">
                <a href="https://www.facebook.com/MLNRETIREMENTPLANNING/"><img src={facebook} alt="facebook" /></a>
                <a href="https://www.instagram.com/mlnrp/"><img src={instagram} alt="instagram" /></a>
                <a href="https://www.linkedin.com/in/mniemczyk/"><img src={linkedin} alt="linkedin" /></a>
              </div>
              <div className="HeaderMenuList">
              <Link 
                activeClass="active"
                className='MenuList'
                to="GettingStarted"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}><div className="HeaderMenuText">Getting Started</div></Link>
                <Link 
                activeClass="active"
                className='MenuList'
                to="AboutUs"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}><div className="HeaderMenuText">About Us</div></Link>
                <Link 
                activeClass="active"
                className='MenuList'
                to="FreeBook"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}><div className="HeaderMenuText">Free Book</div></Link>
                <Link 
                activeClass="active"
                className='MenuList'
                to="ContactUs"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}><div className="HeaderMenuText">Contact Us</div></Link>
              </div>
                <img src={headerImage} alt="header image" className="headerImage" />
            </header>
          </div>
          
    );
  }
}

export default Header