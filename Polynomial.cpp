// Polynomial.cpp
#include "Polynomial.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//create an empty value polynomial
Polynomial::Polynomial() : polyterm(new Term[MAX_DEGREE])
{
	for (int i = 0; i < MAX_DEGREE; i++)
	{
		polyterm[i].exponent = i;
		polyterm[i].coefficient = 0;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//create a polynomial object from an inputted vector of terms
Polynomial::Polynomial(vector<Term> terms) : polyterm(new Term[terms.size()])
{
	size = terms.size();
	for (int i = 0; i < terms.size(); i++)
	{
		polyterm[i].exponent = terms[i].exponent;
		polyterm[i].coefficient = terms[i].coefficient;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//copy the inputted polynomial
Polynomial::Polynomial(Polynomial const& other) : polyterm(new Term[other.size])
{
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		polyterm[i].exponent = other.polyterm[i].exponent;
		polyterm[i].coefficient = other.polyterm[i].coefficient;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//deletes the polynomial's terms
Polynomial::~Polynomial()
{
	delete[] polyterm;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//changes the coefficient of the selected term
void Polynomial::setCoef(int k, double value)
{

	if (k <= MAX_DEGREE)
	{
		if (k < size)
		{
			polyterm[k].exponent = k;
			polyterm[k].coefficient = value;
		}
		else // create a new polyterm using a temp Term that has more space
		{
			int prevSize = size; 
			size = k + 1;
			Term* temp = new Term[size];
			for (int i = 0; i < prevSize; i++) // insert all the values of the original
			{
				temp[i].exponent = polyterm[i].exponent;
				temp[i].coefficient = polyterm[i].coefficient;
			}
			temp[k].exponent = k; // add new term
			temp[k].coefficient = value;

			delete[] polyterm;
			polyterm = temp;
		}
	}
	else
	{
		cout << "ERROR: Inputted exponent value is too high. Please enter a new value below " << MAX_DEGREE << ".";
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//set all coefficients to zero
void Polynomial::clear()
{
	for (int i = 0; i < size; i++)
	{
		polyterm[i].coefficient = 0;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//return the coefficient of the chosen term
double Polynomial::getCoef(int k) const
{
	if (k <= getDegree())
	{
		return polyterm[k].coefficient;
	}
	else
	{
		return 0;
	}
}
int Polynomial::getExp(int k) const
{
	return polyterm[k].exponent;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//return the highest exponent of the polynomial
int Polynomial::getDegree() const
{
	int max = -1;
	for (int i = 0; i < size; i++)
	{
		if (polyterm[i].exponent > max && polyterm[i].coefficient != 0)
		{
			max = polyterm[i].exponent; //set new high
		}
	}
	return max;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//evaluate the polynomial at a given x value
double Polynomial::evaluate(double value) const
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		double termTotal = 1;
		for (int j = 0; j < polyterm[i].exponent; j++) //basically a pow() function
		{
			termTotal *= value;
		}
		termTotal *= polyterm[i].coefficient; //multiply by the coefficient
		total += termTotal;
	}

	return total;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//adds two polynomials together
Polynomial Polynomial::operator+(Polynomial const& rightPoly)
{
	Polynomial result;
	int maxDegree;
	//determine the size of the return poly
	if (getDegree() >= rightPoly.getDegree())
	{
		maxDegree = getDegree();
	}
	else
	{
		maxDegree = rightPoly.getDegree();
	}
	result.size = maxDegree + 1;
	result.polyterm = new Term[result.size];

	// Initialize result polynomial
	for (int i = result.size - 1; i >= 0; --i) 
	{
		result.polyterm[i].exponent = i;
		result.polyterm[i].coefficient = 0.0;
	}

	// Add terms from the first polynomial
	for (int i = size - 1; i >= 0; --i) 
	{
		result.polyterm[i].coefficient += polyterm[i].coefficient;
	}

	// Add terms from the second polynomial
	for (int i = 0; i < rightPoly.size; ++i) 
	{
		int exponent = rightPoly.polyterm[i].exponent;
		result.polyterm[exponent].coefficient += rightPoly.polyterm[i].coefficient;
	}

	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// subtracts two polynomials
Polynomial Polynomial::operator-(Polynomial const& rightPoly)
{
	Polynomial result;
	int maxDegree;
	if (getDegree() >= rightPoly.getDegree())
	{
		maxDegree = getDegree();
	}
	else
	{
		maxDegree = rightPoly.getDegree();
	}
	result.size = maxDegree + 1;
	result.polyterm = new Term[result.size];

	// Initialize result polynomial
	for (int i = result.size - 1; i >= 0; --i) 
	{
		result.polyterm[i].exponent = i;
		result.polyterm[i].coefficient = 0.0;
	}

	// Add terms from the first polynomial
	for (int i = 0; i < result.size; ++i)
	{
		result.polyterm[i].coefficient = polyterm[i].coefficient;
	}

	// Add terms from the second polynomial
	for (int i = 0; i < result.size; ++i) 
	{
		result.polyterm[i].coefficient -= rightPoly.polyterm[i].coefficient;
	}

	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//set first poly = second poly
Polynomial Polynomial::operator=(Polynomial const& rightPoly)
{
	if (this != &rightPoly) //immediately return if they are already equal
	{
		delete[] polyterm; //delete polyterm so we can use the name
	}
	else
	{
		return *this;
	}

	size = rightPoly.size;

	polyterm = new Term[size]; //new polyterm now has rightPoly's size

	for (int i = 0; i < size; i++) //set polyterm's values to those of rightPoly
	{
		polyterm[i].exponent = i;
		polyterm[i].coefficient = rightPoly.polyterm[i].coefficient;
	}

	return *this;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//returns true if the values of both polys are the same, and false otherwise
bool Polynomial::operator==(Polynomial const& rightPoly)
{
	if (size != rightPoly.size) // return false if the sizes of the polynomials are different
	{
		return false;
	}
		
	for (int i = 0; i < size; i++) // return false if any terms are not equal
	{
		if (polyterm[i].exponent != rightPoly.polyterm[i].exponent ||
			polyterm[i].coefficient != rightPoly.polyterm[i].coefficient)
		{
			return false;
		}
	}

	return true; // if all terms are equal, the function will reach this line
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//asks the user to input the term data values for a polynomial
Polynomial Polynomial::readPolynomial()
{
	int degree;

	cout << "Enter the degree of the polynomial: "; //ask for user input
	cin >> degree; //store as int
	vector<Term> terms(degree + 1); //create new term with size of degree + 1


	for (int i = 0; i <= degree; i++) //ask for user input on each coefficient
	{
		cout << "Enter the coefficient of x^" << i << ": " << endl;
		cin >> terms[i].coefficient;
		terms[i].exponent = i;
	}

	return Polynomial(terms);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//adds a single term to an existing polynomial
Polynomial Polynomial::addTerm(Term const& newTerm)
{
	if (newTerm.exponent > getDegree())
	{
		Term* temp = polyterm;
		for (int i = 0; i < size; i++)
		{
			temp[i].exponent = polyterm[i].exponent;
			temp[i].coefficient = polyterm[i].coefficient;
		}
		delete[] polyterm;
		size++;
		temp[size - 1].exponent = newTerm.exponent;
		temp[size - 1].coefficient = newTerm.coefficient;

		Term* polyterm = new Term[size];
		polyterm = temp;
	}
	else
	{
		cout << "ERROR: Term exponent is already included in the polynomial.";
	}

	return *this;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//returns a formatted toString for the polynomial
ostream& operator<<(ostream& out, const Polynomial& p)
{
	if (p.getDegree() < 0) // tells if empty poly
	{
		out << "empty";
	}
	else
	{
		for (int i = p.getDegree(); i >= 0; i--) //store the exponent and coefficient of each term into out
		{
			if (p.getCoef(i) != 0)
			{
				if (p.getExp(i) > 0)
				{
					out << "(" << p.getCoef(i) << "x^" << p.getExp(i) << ")";
				}
				else
				{
					out << "(" << p.getCoef(i) << ")";
				}
				if (i > 0)
				{
					out << " + ";
				}
			}
		}
	}
	return out;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

