#ifndef RATIONAL_H
#define RATIONAL_H

// Class defintion.
class Rational
{
public:
	// Member function prototypes.
	Rational ();
	void setNumerator (int &numerator);
	void setDenominator (int &denominator);
	void reduceFraction (int &numerator, int &denominator);
private:
	// Data members.
	int numerator_;
	int denominator_;
};
#endif