import React from "react"
import Book from "../Images/book.png"
import "../CSS/FreeBook.css"

function FreeBook() {
    return (
        <div className="container3">
            <div className="row3">
                <div class="column3-66">
                    <h1 className="xlarge-font3"><b>Michael's Book</b></h1>
                    <h1 className="large-font3"><b>Why buy it?</b></h1>
                    <p id='FreeBookText'>Our parents and grandparents were concerned with dying too early in retirement—now that fear has been
                         replaced with living too long, teeing up the question, “Will you run out of money before you run out of life?™” 
                         This book provides insight into the vast world of financial planning, as well as pitfalls to avoid and questions
                          to ask those who are handling your money. It will provide ideas on how to properly grow your money,
                           while also identifying the fees you are paying. Learn what to be aware of when passing your assets 
                           on to loved ones and how to ensure they go where you intended them to go. Ideas and proven strategies 
                           to help make your retirement a success!</p>
                           <a href="https://www.amazon.com/Will-You-Money-Before-Life/dp/1075266297/ref=sr_1_1?
                           keywords=Will+You+Run+Out+of+Money+Before+You+Run+Out+of+Life%3F%3A+Planning+%26+Strategy+for+a+Sound+Financial+Future&qid=1565802711&s=gateway&sr=8-1">
                            <button className="BookButton">Purchase Your Copy</button></a>
                </div>
                <div className="column3-33">
                 <img src={Book} className="FreeBookImage" />
                </div>
            </div>
            <iframe id='FreeBookVideo' width="1150"
                 height="650" 
                 src="https://www.youtube.com/embed/b22Ud8s2q1Y"
                 frameborder="0"
                  allow="accelerometer; 
                  autoplay; 
                  encrypted-media; 
                  gyroscope; 
                picture-in-picture" allowfullscreen></iframe>
    </div>
    )
}

export default FreeBook