// This program gets a fraction from the user and reduces the fraction,
// it then displays the reduced fraction, Brian Bowles, 01/14/14.
#include <iostream>
using namespace std;

// New datatype called Fract, uses a numerator and denominator, both of type int.
struct Fract
{
int denominator;
int numerator;
};

// Function Prototypes.
Fract getFraction ();
Fract reduceFraction (Fract &tempFract);
void displayFraction (const Fract &tempFract);

// This function calls getFraction to recieve a fraction from the user and call reduces the fraction
// by calling reduceFraction, it then calls displayFraction to display the reduced fraction.
int main ()
{
	// Greeting
	cout << "Hello, this program reduces a fraction." << endl;
	// Structure variable.
	Fract fraction;

	// Call getFraction, reduceFraction, and displayFraction.
	fraction = getFraction ();
	fraction = reduceFraction (fraction);
	displayFraction (fraction);
	return 0;
}

// This function asks the user to enter a fraction and returns that fraction.
Fract getFraction ()
{
	// Structure variable.
	Fract fraction;

	// Get input from the user.
	cout << "Please enter the numerator of the fraction: ";
	cin >> fraction.numerator;
	cout << "Please enter the denominator of the fraction: ";
	cin >> fraction.denominator;
	return fraction;
}

// This function receives a fraction, reduces it, then returns it.
Fract reduceFraction (Fract &tempFract)
{
	int GCF;

	// Assign GCF the smallest of the numerator or denominator.
	if (tempFract.numerator <= tempFract.denominator)
		GCF = tempFract.numerator;
	else
		GCF = tempFract.denominator;
	
	// Find the greatest common factor and reduce.
	for (GCF; GCF >= 1; GCF--)
		if ((tempFract.numerator % GCF == 0) && (tempFract.denominator % GCF == 0))
		{
			tempFract.numerator = tempFract.numerator / GCF;
			tempFract.denominator = tempFract.denominator / GCF;
		}
	return tempFract;
}

// This function receives a fraction and displays that fraction.
void displayFraction (const Fract &tempFract)
{
	// Display fraction.
	cout << "The reduced fraction is: " << tempFract.numerator << "/";
	cout << tempFract.denominator << endl;
}