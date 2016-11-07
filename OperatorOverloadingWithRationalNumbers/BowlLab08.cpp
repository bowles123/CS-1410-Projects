// This program gets two rational numbers from the user and calculates
// the sum, difference, product, and quotient of the two rational numbers.
// It also compares the two numbers and displays the results, Brian Bowles, 03/04/14.
#include <iostream>
#include "BowlRational.h"
using namespace std;
using namespace Bowles;

// Prototypes.
void setRational (Rational &);

// This function adds, subtracts, multiplies, divides and compares two rational numbers.
int main ()
{
	// Objects and variables
	Rational number1, number2;
	double realNumber1, realNumber2;

	// Greeting.
	cout << "Hello, this program adds, subtract, multiplies, divides, and compares two " << endl;
	cout << "rational numbers." << endl;

	// Get the two rational numbers from the user.
	cout << "Please enter a rational number in the follwoing format, num/den: ";
	setRational (number1);
	cout << "Please enter the second rational number in the same format: ";
	setRational (number2);

	// Set the rational numbers equal to a variable of type double
	realNumber1 = number1;
	realNumber2 = number2;

	// Display the sum, difference, product, and quotient of the two rationals.
	cout << number1 << " + " << number2 << " = " << number1 + number2 << "." << endl;
	cout << number1 << " - " << number2 << " = " << number1 - number2 << "." << endl;
	cout << number1 << " * " << number2 << " = " << number1 * number2 << "." << endl;
	cout << number1 << " / " << number2 << " = " << number1 / number2 << "." << endl;

	// Check to see if number one is greater than or less than number two.
	if (number1 == number2)
		{
			cout << number1 << " > " << number2 << ",  false." << endl;
			cout << number1 << " < " << number2 << ",  false." << endl;
		}
	else 
	{
		if (number1 > number2)
		{
			cout << number1 << " > " << number2 << ",  true." << endl;
			cout << number1 << " < " << number2 << ",  false." << endl;
		}
		else
		{
			cout << number1 << " > " << number2 << ",  false." << endl;
			cout << number1 << " < " << number2 << ",  true." << endl;
		}
	}

	// Check to see if number one is not equal to or is equal to number two.
	if (number1 != number2)
	{
		cout << number1 << " != " << number2 << ", true." << endl;
		cout << number1 << " == " << number2 << ", false." << endl;
	}
	else 
	{	cout << number1 << " != " << number2 << ", false." << endl;
		cout << number1 << " == " << number2 << ", true." << endl;
	}

	// Check to see if number one is greater than or equal or less than or equal to number two.
	if (number1 == number2)
		{
			cout << number1 << " >= " << number2 << ", false." << endl;
			cout << number1 << " <= " << number2 << ", false." << endl;
		}
	else 
	{
		if (number1 >= number2)
		{
			cout << number1 << " >= " << number2 << ", true." << endl;
			cout << number1 << " <= " << number2 << ", false." << endl;
		}
		else
		{
			cout << number1 << " >= " << number2 << ", false." << endl;
			cout << number1 << " <= " << number2 << ", true." << endl;
		}
	}

	// Display a real number value for the rational numbers.
	cout << "The first rational number in real number form is: " << realNumber1 << "." << endl;
	cout << "The second rational number in real number form is: " << realNumber2 << "." << endl;
	return 0;
}

void setRational (Rational &number)
{
	cin >> number;
	while (cin.peek() == '0' || cin.peek() == '-')
	{
		cout << "That's an invalid expression, please try again: ";
		cin.ignore();
		cin.ignore();
		cin >> number;
	}
}