#include "BowlRational.h"
#include <iostream>
#include <cmath>
using namespace std;

// Default Constructor
Rational:: Rational ()
{
	numerator_ = denominator_ = 0;
}

// This function sets the numerator of the fraction.
void Rational:: setNumerator (int &numerator)
{
	numerator_ = numerator;
}

// This function sets the denominator of the fraction.
void Rational:: setDenominator (int &denominator)
{
	denominator_ = denominator;
}

// This function reduces the function, then displays the reduced fraction.
void Rational:: reduceFraction (int &numerator, int &denominator) 
{
	int GCF;

	// Assign GCF the smallest of the numerator or denominator.
	if (abs(numerator) <= abs(denominator))
		GCF = abs(numerator);
	else
		GCF = abs(denominator);
	
	// Find the greatest common factor and reduce.
	if (numerator > 0 || denominator > 0)
		for (GCF; GCF >= 1; GCF--)
			if ((numerator % GCF == 0) && (denominator % GCF == 0))
			{
				numerator = numerator / GCF;
				denominator = denominator / GCF;
			}
	
	// Display reduced fraction.
	if (numerator == 0 || denominator == 1)
		cout << "The reduced fraction is: " << numerator << endl;
	else
		cout << "The reduced fraction is: " << numerator << "/" << denominator << "." << endl;
}


