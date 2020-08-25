import React, { Component} from "react"
import { slide as Menu} from 'react-burger-menu'
import { Link } from 'react-scroll'
import '../CSS/Navbar.css'
class Navbar extends Component {
  state = {};
  render () {
    return (
          <div>
              <Menu>
                <Link 
                activeClass="active"
                className='MenuList'
                to="GettingStarted"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}>Getting Started</Link>
                <Link 
                activeClass="active"
                className='MenuList'
                to="AboutUs"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}>About Us</Link>
                <Link 
                activeClass="active"
                className='MenuList'
                to="FreeBook"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}>Free Book</Link>
                <Link 
                activeClass="active"
                className='MenuList'
                to="ContactUs"
                spy={true}
                smooth={true}
                offset={0}
                duration={500}>Contact Us</Link>
              </Menu>
          </div> 
    )
  }
}

export default Navbar