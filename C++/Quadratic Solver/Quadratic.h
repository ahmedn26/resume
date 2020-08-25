/*
AUTHOR:	Nusra Ahmed
CLASS:	CIS2542
DATE:	09/06/2017
FILE:	Quadratic.h
DESCR:	Declaration file for the quadratic class.
*/


class quadratic {
	//items are private by default
	float a, b, c;
public:
	//constructor(does not return a value and is used to assign data values)
	quadratic(); //default
	~quadratic() {}; //destuctor
	//accessor functions--> inline function
	float getA() const { return a; }
	float getB() const { return b; }
	float getC() const { return c; }
	//mutator functions (function definition in quadratic.cpp)
	void setA(float CoefficientA);
	void setB(float CoefficientB);
	void setC(float CoefficientC);
	//valuation function
	double evalQuadForX(double x) const;
	//friend function
	friend quadratic operator * (double r, const quadratic& q);
	friend quadratic operator + (const quadratic& q1, const quadratic& q2);
};