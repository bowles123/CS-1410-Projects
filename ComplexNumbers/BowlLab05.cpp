// This program adds and subtract two complex numbers, Brian Bowles, 02/04/14.
#include <iostream>
#include "BowlComplex.h"
using namespace std;
using namespace BOWLES;

// Prototypes.
Complex getInput ();

// Main function that gets two complex numbers from the user and adds and subtracts them.
int main ()
{
	// Objects
	Complex number1, number2, number3;

	cout << "Welcome, this program adds and subtracts two complex numbers." << endl;

	// Get complex numbers from user.
	number1 = getInput ();
	number2 = getInput ();
	
	// Add the complex numbers together.
	number3 = number2.addNumber (number1);
	cout << "The two complex numbers added together equals: ";
	number3.displayAdd (number1, number2);
	cout << endl;

	// Subtract one complex number from the other.
	number3 = number2.subtractNumber (number1);
	cout << "The two complex numbers subtracted equals: ";
	number3.displaySubtract (number1, number2);
	cout << endl;
	return 0;
}

// This function asks the user for a real and imaginary number sends them to the class.
Complex getInput ()
{
	// Variables.
	Complex number;
	double tempReal, tempImaginary;

	// Get real number from user.
	cout << "Please enter a real number: ";
	cin >> tempReal;
	number.setReal (tempReal);

	// Get imaginary number from the user.
	cout << "Please enter the coefficient of the imaginary number: ";
	cin >> tempImaginary;
	number.setImaginary (tempImaginary);
	return number;
}
	