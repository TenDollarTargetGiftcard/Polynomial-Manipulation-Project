// Polynomial.h

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Term
{
	int exponent;
	double coefficient;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Polynomial
{
public:
	//constants
	const int MAX_DEGREE = 10;
	//constructors
	Polynomial();
	Polynomial(Polynomial const& other);
	Polynomial(vector<Term> terms);
	//destructor
	~Polynomial();
	//member functions
	void setCoef(int k, double value);
	void clear();
	double getCoef(int k)const;
	int getExp(int k) const;
	int getDegree()const;
	double evaluate(double value)const;
	Polynomial operator+(Polynomial const& rightPoly);
	Polynomial operator-(Polynomial const& rightPoly);
	Polynomial operator=(Polynomial const& rightPoly);
	bool operator==(Polynomial const& rightPoly);
	Polynomial addTerm(Term const& newTerm);
	Polynomial readPolynomial();
private:
	//instance variables
	int size = MAX_DEGREE;
	//dynamically allocated array
	Term* polyterm;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& out, const Polynomial& p);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // POLYNOMIAL_H