/*
Name:	Nusra Ahmed
Class:	CIS2542
File:	AdvNALab1-Assertion.cpp
Date:	08/23/2017
Descr:	Lab to calculate the real roots of a quadratic expression.
*/

#include <iostream>
#include <cassert> //for assertion checks
using namespace std;

//function prototype
void calcRealRoots(double, double, double, double[]);

int main() {
	//array to hold the roots
	double roots[2];
	//local variables
	double a, b, c;
	cout << "For a quadratic expression such as: ax^2 + bx + c" << endl;
	cout << "Please identify the following: " << endl;
	cout <<	"a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	//calculate and display the real roots using assertion
	calcRealRoots(a,b,c, roots);
	cout << "The real roots of " 
		<< a << "x^2 + " << b << "x + " << c << " are " << roots[0] << " and " << roots[1]  << endl;
	return 0;
}

//function to calculate the roots
//assertion
//Precondition: a != 0 && b^2 > 4ac
//Postcondition: An array with 2 real roots is passed by reference
void calcRealRoots(double a, double b, double c, double roots[]) {
	//use assertion to ensure precondition
	assert(a != 0 && pow(b,2) > 4*a*c);
	roots[0] = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	roots[1] = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
}

/*OUTPUT
For a quadratic expression such as: ax^2 + bx + c
Please identify the following:
a: 6.75
b: 12.5
c: 2.25
The real roots of 6.75x^2 + 12.5x + 2.25 are -0.202044 and -1.64981
Press any key to continue . . .
*/

/*OUTPUT
For a quadratic expression such as: ax^2 + bx + c
Please identify the following:
a: 1
b: 20
c: 100
Assertion failed: a != 0 && pow(b,2) > 4*a*c, file c:\users\nunua\desktop\cod\sophomore\17fall\advanced c++\advnalab1-assertion.cpp, line 42
Press any key to continue . . .
*/