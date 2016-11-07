// Complex member function definitions, Brian Bowles, 02/04/14.
#include <iostream>
using namespace std;
#include "BowlComplex.h"

// Namespace holding member function definitions of class "COMPLEX".
namespace BOWLES
{
	// Constructor of class "COMPLEX".
	Complex:: Complex (double real, double imaginary)
	{
		real_ = real;
		imaginary_ = imaginary;
	}

	//  This function sets a value for the datamember "real_".
	void Complex:: setReal (double real)
	{
		real_ = real;
	}

	// This function sets a value for the datamember "imaginary_".
	void Complex:: setImaginary (double imaginary)
	{
		imaginary_ = imaginary;
	}

	// This function adds two complex numbers together.
	Complex Complex:: addNumber (Complex number1)
	{
		Complex number;

		// Add the two complex numbers together.
		number.real_ = number1.real_ + real_;
		number.imaginary_ = number1.imaginary_ + imaginary_;
		return number;
	}

	// This function subtracts two complex numbers.
	Complex Complex:: subtractNumber (Complex number1)
	{
		Complex number;

		// Subtract the two complex numbers.
		number.real_ = number1.real_ - real_;
		number.imaginary_ = number1.imaginary_ - imaginary_;
		return number;
	}

	// This function displays the operands, operator, and anwser when adding two complex numbers.
	void Complex:: displayAdd (Complex number1, Complex number2) const
	{
		if (number1.imaginary_ < 0)
			cout << "(" << number1.real_ << number1.imaginary_ << "i" << ")";
		else
			cout << "(" << number1.real_ << "+" << number1.imaginary_ << "i" << ")";
		if (number2.imaginary_ < 0)
				cout << " + (" << number2.real_ << number2.imaginary_ << "i" << ") = (";
		else
				cout << " + (" << number2.real_ << "+" << number2.imaginary_ << "i" << ") = (";
		if (imaginary_ < 0)
			cout << real_ << imaginary_ << "i)";
		else
			cout<< real_ << "+" << imaginary_ << "i)";
	}

	// This function displays the operands, operator, and anwser when subtracting two complex numbers.
	void Complex:: displaySubtract (Complex number1, Complex number2) const
	{
		if (number1.imaginary_ < 0)
			cout << "(" << number1.real_ << number1.imaginary_ << "i" << ")";
		else
			cout << "(" << number1.real_ << "+" << number1.imaginary_ << "i" << ")";
		if (number2.imaginary_ < 0)
				cout << " - (" << number2.real_ << number2.imaginary_ << "i" << ") = (";
		else
				cout << " - (" << number2.real_ << "+" << number2.imaginary_ << "i" << ") = (";
		if (imaginary_ < 0)
			cout << real_ << imaginary_ << "i)";
		else
			cout<< real_ << "+" << imaginary_ << "i)";
	}
}


