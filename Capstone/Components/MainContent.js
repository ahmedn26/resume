import React, { Component } from "react"
import Header from "./Header";
import GettingStarted from "./GettingStarted";
import AboutUs from "./AboutUs";
import FreeBook from "./FreeBook";
import ContactUs from "./ContactUs";
import Footer from "./Footer";

function MainContent() {
    return (
        <div>
            <Header />
            <div id='GettingStarted' />
            <GettingStarted />
            <div id='AboutUs' />
            <AboutUs />
            <div id='FreeBook' />
            <FreeBook />
            <div id='ContactUs' />
            <ContactUs />
            <Footer />
        </div>
    )
}

export default MainContent