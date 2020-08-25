/*
Name:	Nusra Ahmed
Class:	CIS2542
File:	AdvNALab1-Exception.cpp
Date:	08/23/2017
Descr:	Lab to calculate the real roots of a quadratic expression.
*/

#include <iostream>
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
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	//incorporate exception handling with try/catch
	try {
		calcRealRoots(a,b,c,roots);
	}
	catch (char* str) {
		cout << str << endl;
		exit(EXIT_FAILURE);
	}
	//catch all will handle any exception thrown
	catch (...) {
		cerr << "Exception thrown" << endl;
		exit(EXIT_FAILURE);
	}
	//display the results
	cout << "The real roots of "
		<< a << "x^2 + " << b << "x + " << c << " are " << roots[0] << " and " << roots[1] << endl;
	return EXIT_SUCCESS;
}


//function to calculate the roots
//exception handling
//Precondition: a != 0 && b^2 > 4ac
//Postcondition: An array with 2 real roots is passed by reference
void calcRealRoots(double a, double b, double c, double roots[]) {
	//see if precondition is met
	if (!(a != 0 && pow(b, 2) > 4*a*c))
		throw "ERROR! a = 0 OR b^2 < 4ac";
	//no exception thrown; continue processing
	roots[0] = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	roots[1] = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
}

/*OUTPUT
For a quadratic expression such as: ax^2 + bx + c
Please identify the following:
a: -5
b: 8
c: -3
The real roots of -5x^2 + 8x + -3 are 0.6 and 1
Press any key to continue . . .
*/

/*OUTPUT
For a quadratic expression such as: ax^2 + bx + c
Please identify the following:
a: 1
b: 20
c: 100
ERROR! a = 0 OR b^2 < 4ac
Press any key to continue . . .
*/