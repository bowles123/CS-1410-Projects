// This program gets a fraction from the user, then reduces and displays that fraction.
// Brian Bowles, 01/28/14.
#include "BowlRational.h"
#include <iostream>
using namespace std;

// Prototypes.
int getNumerator ();
int getDenominator ();

int main ()
{
	// Object and variable defenitions.
	Rational realNumber1;
	Rational realNumber2;
	int numerator, denominator;

	// Greeting.
	cout << "Hello, this program reduces two fractions, then dispalys the reduced fractions." << endl;

	// Get first fraction and reduce.
	numerator = getNumerator ();
	denominator = getDenominator ();
	realNumber1.setNumerator (numerator);
	realNumber1.setDenominator (denominator);
	realNumber1.reduceFraction (numerator, denominator);

	// Get second fraction and reduce.
	numerator = getNumerator ();
	denominator = getDenominator ();
	realNumber2.setNumerator (numerator);
	realNumber2.setDenominator (denominator);
	realNumber2.reduceFraction (numerator, denominator);
	return 0;
}

// This function gets a numerator from the user.
int getNumerator ()
{
	int numerator;

	cout << "Please enter the numerator of the fraction: ";
	cin >> numerator;
	return numerator;
}

// This function gets a denominator from the user.
int getDenominator ()
{
	int denominator;

	cout << "Please enter the denominator of the fraction: ";
	cin >> denominator;

	while (denominator == 0)
	{
		cout << "That is not a valid numerator, please try again: ";
		cin >> denominator;
	}
	return denominator;
}
