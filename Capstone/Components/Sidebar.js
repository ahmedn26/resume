import React from "react"
import { slide as Menu} from 'react-burger-menu'
function Sidebar() {
    return (
          <div>
              <Menu>
                <a id="GettingStarted" className="menu-item" href="/gettingstarted">Getting Started</a>
                <a id="AboutUs" className="menu-item" href="/aboutus">About Us</a>
                <a id="FreeBook" className="menu-item" href="/freebook">Free Book</a>
                <a id="ContactUs" className="menu-item" href="/contactus">Contact Us</a>
              </Menu>
          </div> 
    )
}

export default Sidebar