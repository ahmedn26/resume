import React, { Component} from "react"
import { Link } from 'react-scroll'
import "../CSS/GettingStarted.css"

class GettingStarted extends Component {
    state = {};
    render() {
        return (
            <div className="container1">
                <div className="row1"> 
                    <h1 className="xlarge-font1"><b>We'll Help You Design Your Own Strategy for Financial Independence</b></h1>
                        <div className="column1">
                        <h1 className="large-font1"><b>Discover</b></h1>
                        <p className="GettingStartedText">Schedule a Meeting where our process begins with understanding your personal situation. We accomplish this through
                             a thorough fact-finding interview to understand what you want your money to do for you.
                        </p>
                        </div>
                        <div class="column1">
                        <h1 className="large-font1"><b>Strategize</b></h1>
                        <p className="GettingStartedText">We will implement the MLN Retirement Planning process to examine your financial circumstances and determine
                             an effective strategy to meet short, intermediate, and long-term financial needs.
                        </p>
                        </div>
                        <div class="column1">
                        <h1 className="large-font1"><b>Implement</b></h1>
                        <p className="GettingStartedText">After the Discovery and Strategize stages from the previous MLN Retirement Planning process steps,
                             you will be provided a certified financial plan with ongoing management and daily monitoring.
                        </p>
                        </div>
                        
                        <Link 
                        activeClass="active"
                        className='MenuList'
                        to="ContactUs"
                        spy={true}
                        smooth={true}
                        offset={0}
                        duration={500}><button className="GettingStartedButton">Get Started</button></Link>
                        
                </div>
            </div>
            )
    }
}

export default GettingStarted