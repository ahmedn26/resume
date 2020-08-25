
import React from 'react';
import axios from 'axios';
import validator from 'validator';
import MLNLogo from "../Images/MLNLogo.jpg"
import "../CSS/ContactUs.css"
import "../../src/App.js"


const cors = require('cors');


class ContactUs extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            firstName: '',
            lastName: '',
            phoneNumber: null,
            callBackTime: '',
            email: '',
            interest: '',
            message: ''
        };
    }

    mySubmitHandler = (event) => {
        event.preventDefault();
        if (!validator.isMobilePhone(this.state.phoneNumber)) {
            alert("You must enter a valid phone number.");
        }
        else if (!validator.isEmail(this.state.email)) {
            alert("Please enter a valid email or leave the field blank.");
        }
        else {
            alert('Thank you for your interest in MLNRP, ' + this.state.firstName + '. An advisor will call you at your requested contact time.');
            
            const frmContact = document.getElementById('ContactForm')

            let user = new FormData(frmContact);
            user.append('firstName', this.state.firstName)
            user.append('lastName', this.state.lastName)     
            user.append('callBackTime', this.state.callBackTime)
            user.append('phoneNumber', this.state.phoneNumber)
            user.append('email', this.state.email)
            user.append('interest', this.state.interest)
            user.append('message', this.state.message)
            
         
            const api = axios.create({baseURL: 'http://localhost:80'})
            
           // axios.post('http://localhost:80/contact.php', user)
            axios.post('http://database.mlnrp.co/contact.php', user)
            .then(response => {
                console.log(response);

                const user = response.data[0]
               
                this.setState({
                    user
                })
            })
            .catch(function (response) {
                //handle error
                console.log(response)
            });
         
        }   

              
        console.log(`
            First Name: ${this.state.firstName}
            Last Name: ${this.state.lastName}
            Phone Number: ${this.state.phoneNumber}
            Call Back Time: ${this.state.callBackTime}
            Email: ${this.state.email}
            Interest: ${this.state.interest}
            Message: ${this.state.message}
        `);
    }

    myChangeHandler = (event) => {
        let nam = event.target.name;
        let val = event.target.value;
        this.setState({ [nam]: val });
    }

    

    render() {
        return (
            <div className="Container4">
                <div className="SecondContainer4">
                <img src={MLNLogo} className="MLNLogoImage" />
                
                    <form id="ContactForm" onSubmit={this.mySubmitHandler}>
                        <h1>Contact Us</h1>
                        
                        <label>* First Name:</label>
                        <input
                            type='text'
                            name='firstName'
                            onChange={this.myChangeHandler}
                            required
    
                        />
                        
                        <label>* Last Name:</label>
                        <input
                            type='text'
                            name='lastName'
                            onChange={this.myChangeHandler}
                            required
  
                        />

                        <label>* Phone #:</label>
                        <input
                            type='text'
                            name='phoneNumber'
                            onChange={this.myChangeHandler}
                            maxLength="10"
                            required
                            
                            
                            
                        />

                        <label>Call Back Time:</label>
                        <select type='text' name="callBackTime"  onChange={this.myChangeHandler}>
                            <option value=""></option>
                            <option value="Morning">Morning</option>
                            <option value="Afternoon">Afternoon</option>
                            <option value="Evening">Evening</option>
                        </select>

                        <label>Email:</label>
                        <input
                            type='email'
                            name='email'
                            onChange={this.myChangeHandler}
                        />

                        <label>Interest:</label>
                        <select name="interest" onChange={this.myChangeHandler}>
                            <option value=""></option>
                            <option value="Retirement Planning">Retirement Planning</option>
                            <option value="Portfolio Management">Portfolio Management</option>
                            <option value="Tax-Free Income Planning">Tax-Free Income Planning</option>
                            <option value="Estate Planning">Estate Planning</option>
                            <option value="Fee-Only Planning">Fee-Only Planning</option>
                            <option value="Social Security Maximization">Social Security Maximization</option>
                            <option value="Other">Other</option>
                        </select>

                        <label>Optional Message (300 characters or less): </label>
                        <textarea cols="40" rows="5" name="message" placeholder="Is there anything else you would like us to know?"
                                onChange={this.myChangeHandler} maxLength="300" /> 
                                

                        <br />
                        <p>* Indicates required field</p>
                        <p></p>
                        <input id="submitbutton" type='submit' value="Submit" />
                    </form>
                </div> 
        </div>  
        );
    }
}
export default ContactUs;