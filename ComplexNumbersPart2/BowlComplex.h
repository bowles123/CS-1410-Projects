// New class called Complex to deal with complex numbers, Brian Bowles, 02/04/14.
#ifndef COMPLEX_H
#define COMPLEX_H

// New namespace holding the new class definition.
namespace BOWLES
{
	// Class defintion.
	class Complex
	{
	public: 
		// Member function prototypes.
		Complex (double real = 0, double imaginary = 0);
		Complex addNumber (Complex);
		Complex subtractNumber (Complex);
		void setReal (double);
		void setImaginary (double);
		void displayAdd (Complex, Complex) const;
		void displaySubtract (Complex, Complex) const;
	private:
		// Data members.
		double real_;
		double imaginary_;
	};
}
#endif
