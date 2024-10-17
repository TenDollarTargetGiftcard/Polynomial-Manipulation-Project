// main.cpp

#include "Polynomial.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_menu();
char get_user_command();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	char choice; // Command entered by the user
	int num, exp;
	double value;

	Polynomial poly1, poly2;
	cout << "creating 2 polynomials" << endl;
	cout << "Initialize polynomial 1" << endl;
	poly1 = poly1.readPolynomial();
	cout << "Initialize polynomial 2" << endl;
	poly2 = poly2.readPolynomial();
	do
	{
		print_menu();
		cout << "Enter choice: ";
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'C': // clear
			cout << "Clear polynomial 1 or 2: ";
			cin >> num;
			if (num == 1)
			{
				poly1.clear();
				cout << "poly1 cleared" << endl;
			}
			else if (num == 2)
			{
				poly2.clear();
				cout << "poly2 cleared" << endl;
			}
			else
			{
				cout << "There are only 2 polynomials - 1 and 2" << endl;
			}
			break;
		case 'E': // evaluate
			cout << "Evaluate polynomial 1 or 2: ";
			cin >> num;
			cout << "Evaluate what value: ";
			cin >> value;
			if (num == 1)
			{
				cout << poly1.evaluate(value) << endl;
			}
			else if (num == 2)
			{
				cout << poly2.evaluate(value) << endl;
			}
			else
			{
				cout << "There are only 2 polynomials - 1 and 2" << endl;
				break;
			}
			break;
		case 'P': // print polynomial
			cout << "Print polynomial 1 or 2: ";
			cin >> num;
			if (num == 1)
				cout << "poly1 is " << poly1 << endl;
			else if (num == 2)
				cout << "poly2 is " << poly2 << endl;
			else
				cout << "There are only 2 polynomials - 1 and 2" << endl;
			break;
		case 'S': // set a polynomial
			cout << "Set polynomial 1 or 2: ";
			cin >> num;
			if (num == 1)
			{
				cout << "Enter exponent to select term (or a negative number to quit): ";
				cin >> exp;
				while (exp >= 0)
				{
					cout << "Enter value of coefficient: ";
					cin >> value;
					poly1.setCoef(exp, value);
					cout << "Enter exponent to select term (or a negative number to quit): ";
					cin >> exp;
				}
				cout << "poly1 is " << poly1 << endl;
			}
			else if (num == 2)
			{
				cout << "Enter exponent to select term (or a negative number to quit): ";
				cin >> exp;
				while (exp >= 0)
				{
					cout << "Enter value of coefficient: ";
					cin >> value;
					poly2.setCoef(exp, value);
					cout << "Enter exponent to select term (or a negative number to quit): ";
					cin >> exp;
				}
				cout << "poly2 is " << poly2 << endl;
			}
			else
				cout << "There are only 2 polynomials - 1 and 2" << endl;
			break;
		case '+': // add polynomials 1 and 2
			cout << "The sum of " << poly1 << endl;
			cout << " and " << poly2 << endl;
			cout << " is " << (poly1 + poly2) << endl;
			break;
		case '-': // subtract polynomials 1 and 2
			cout << "Set polynomial 1 or 2 to be subtracted by the other: ";
			cin >> num;
			if (num == 1)
			{
				cout << "The difference between " << poly1 << endl;
				cout << " and " << poly2 << endl;
				cout << " is " << (poly1 - poly2) << endl;
			}
			else if (num == 2)
			{
				cout << "The difference between " << poly2 << endl;
				cout << " and " << poly1 << endl;
				cout << " is " << (poly2 - poly1) << endl;
			}
			else
			{
				cout << "There are only 2 polynomials - 1 and 2" << endl;
			}
			break;
		case '=': // set poly1 = poly2
			cout << "Set which polynomial equal to the other? ";
			cin >> num;
			if (num == 1)
			{
				poly1 = poly2;
				cout << "Now both polynomials = " << (poly2) << endl;
			}
			else if (num == 2)
			{
				poly2 = poly1;
				cout << "Now both polynomials = " << (poly1) << endl;
			}
			else
			{
				cout << "There are only 2 polynomials - 1 and 2" << endl;
			}
			break;
		case '_': // determine if poly1 = poly2
			cout << poly1 << (poly1 == poly2 ? " equals " : " does not equal ") << poly2 << endl;
			break;
		case 'Q': cout << "Test program ended." << endl;
			break;
		default: cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_menu()
{
	cout << endl;
	cout << "The following choices are available: " << endl;
	cout << " C Clear a polynomial" << endl;
	cout << " E Evaluate a polynomial" << endl;
	cout << " P Print a polynomial with degree" << endl;
	cout << " S Set a polynomial" << endl;
	cout << " + Add 2 polynomials" << endl;
	cout << " - subtract polynomials" << endl;
	cout << " = set polynomials equal to each other" << endl; 
	cout << " _ determine if the polynomials are already equal" << endl;
	cout << " Q Quit this test program" << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char get_user_command()
// Library facilities used: iostream
{
	char command;
	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character
	return command;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////