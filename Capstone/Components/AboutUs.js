import React from "react"
import NiemczykMike from "../Images/NiemczykMike.jpg"
import Austin from "../Images/Austin.jpg"
import Ashelie from "../Images/Ashelie.jpg"
import Kristy from "../Images/kristy.jpg"
import Adrienne from "../Images/Adrienne.jpg"
import Keith from "../Images/keith.jpg"
import BarkateBrenden from "../Images/BarkateBrenden.jpg"
import DiorioMark from "../Images/DiorioMark.jpg"
import PerkinsMark from "../Images/mark.jpg"
import David from "../Images/David.jpg"
import Hamilton from "../Images/hamilton.jpg"
import MeetingRoom from "../Images/MeetingRoom.jpeg"
import "../CSS/AboutUs.css"

function AboutUs() {
    return (
        <div class="AboutUsContainer">
            <div class="AboutUsContainer2">   
                    <div className="AboutUsBackground">
                        <img src={MeetingRoom} className="MeetingRoomImage" />
                    </div>    
                    <h1 class="xlarge-font2"><b>Meet Your Team</b></h1>
                    <h1 class="large-font2"><b>Dedicated to You</b></h1>
                    
                    <div className="AboutUsSection1">
                        <div className="AboutUsColumn1">
                            <div className="AboutUsContainerImage">
                                <img src={NiemczykMike} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Michael Niemczyk, IAR, CIS and Author</div>
                                    </div>
                            </div>
                        </div>
                        <div className="AboutUsColumn1">
                            <div className="AboutUsContainerImage">
                                <img src={Kristy} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Kristy Niemczyk, Licensed Financial Professional</div>
                                    </div>
                            </div>
                        </div>
                        <div className="AboutUsColumn1">
                            <div className="AboutUsContainerImage">
                                <img src={BarkateBrenden} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Brenden Barkate, Insurance Analyst</div>
                                    </div>
                            </div>
                        </div>
                    </div>

                    <div className="AboutUsSection2">
                        <div className="AboutUsColumn2">
                            <div className="AboutUsContainerImage">
                                <img src={Austin} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Austin Larkin, Advisor’s Assistant</div>
                                    </div>
                            </div>
                        </div>
                        <div className="AboutUsColumn2">
                            <div className="AboutUsContainerImage">
                                <img src={Adrienne} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Adrienne Larkin, Financial Education Coordinator</div>
                                    </div>
                            </div>
                        </div>
                        <div className="AboutUsColumn2">
                            <div className="AboutUsContainerImage">
                                <img src={Keith} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Keith Baum, EA, Accounting, Taxation Advisor and Representation</div>
                                    </div>
                            </div>
                        </div>
                        <div className="AboutUsColumn2">
                            <div className="AboutUsContainerImage">
                                <img src={Ashelie} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Ashelie Edmark, Office Manager and Director of Marketing</div>
                                    </div>
                            </div>
                        </div>
                    </div>



                    <div className="AboutUsSection3">
                        <div className="AboutUsColumn3">
                            <div className="AboutUsContainerImage">
                                <img src={DiorioMark} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Mark Diorio, CFA, Portfolio Design/Open Architecture Design</div>
                                    </div>
                            </div>
                        </div>
                        
                        <div className="AboutUsColumn3">
                            <div className="AboutUsContainerImage">
                                <img src={PerkinsMark} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Mark Perkins, Principal Attorney</div>
                                    </div>
                            </div>
                        </div>
                        <div className="AboutUsColumn3">
                            <div className="AboutUsContainerImage">
                                <img src={David} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">David McKnight, Tax-Free Income Specialist</div>
                                    </div>
                            </div>
                        </div>
                        <div className="AboutUsColumn3">
                            <div className="AboutUsContainerImage">
                                <img src={Hamilton} className="AboutUsImage" />
                                    <div className="Middle">
                                        <div class="AboutUsText">Hamilton Morales, NSSA, Social Security Advisor</div>
                                    </div>
                            </div>
                        </div>
                    </div>
                    
            </div>         
        </div>
    )
}

export default AboutUs