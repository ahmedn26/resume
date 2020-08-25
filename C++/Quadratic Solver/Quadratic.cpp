/*
AUTHOR:	Nusra Ahmed
CLASS:	CIS2542
DATE:	09/06/2017
FILE:	Quadratic.cpp
DESCR:	Implementation file for the quadratic class.
*/

#include <iostream>
#include "quadratic.h"

//constructor-->initialize quadratic data using defaults
quadratic::quadratic() {
	a = 0.0F;
	b = 0.0F;
	c = 0.0F;
}

//mutator functions
void quadratic::setA(float CoefficientA) {
	a = CoefficientA;
}

void quadratic::setB(float CoefficientB) {
	b = CoefficientB;
}

void quadratic::setC(float CoefficientC) {
	c = CoefficientC;
}

//valuation functions
double quadratic::evalQuadForX(double x) const {
	return a * pow(x, 2) + b * x + c;
}

//overload + operator as friend function (can use the member dot)
quadratic operator + (const quadratic& q1, const quadratic& q2) {
	quadratic q3;
	q3.a = q1.a + q2.a;
	q3.b = q1.b + q2.b;
	q3.c = q1.c + q2.c;
	return q3;
}

quadratic operator * (double r, const quadratic& q) {
	quadratic q2;
	q2.a = q.a * r;
	q2.b = q.b * r;
	q2.c = q.c * r;
	return q2;
}

/*OUTPUT
Input the values for the first quadratic expression.
a: 3.2
b: 5.5
c: 1.7

The quadratic expression is:
3.2x^2 + 5.5x + 1.7

Enter a value for x: 2
Evaluation of the quadratic expression is: 25.5

Input the values for the second quadratic expression
to add to the first.
a: 1.8
b: 5
c: 3.2

The quadratic expression is:
1.8x^2 + 5x + 3.2

Added quadratic expression is: 5x^2 + 10.5x + 4.9

Enter a value for x: 3.5

Evaluation of the quadratic expression is: 102.9

Input the multiplier value for the third quadratic expression
to multiply with the first: 7.7

The multiplied quadratic expression is: 24.64x^2 + 42.35x + 13.09

Please enter a value for x: 8.1

Evaluation of the quadratic expression is: 1972.76
Press any key to continue . . .*/