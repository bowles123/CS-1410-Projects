// Defintions of member and friend functions declared in the Rational class.
#include "BowlRational.h"
#include <iostream>
#include <cmath>
using namespace std;

// Namespace Bowles.
namespace Bowles
{
	// Default Constructor
	Rational:: Rational ()
	{
		num_ = 0;
		den_ = 1;
	}

	// Explicit value constructor.
	Rational:: Rational (int numerator, int denominator)
	{
		numerator = 0;
		denominator = 1;
	}

	// This function allows a double to recieve the value of a rational.
	Rational:: operator double () const 
	{
		// Variables of type double so the rational number can be converted to a real number.
		double tempNum = num_;
		double tempDen = den_;
		return tempNum / tempDen;
	}

	// This function reduces the rational number.
	void Rational:: reduce()
	{
		int GCF;

		// Assign GCF the smallest of the numerator or denominator.
		if (abs(num_) <= abs(den_))      
			GCF = abs(num_);
		else
			GCF = abs(den_);
	
		// Find the greatest common factor and reduce.
		if (num_ > 0 || den_ > 0)
			for (GCF; GCF >= 1; GCF--)
				if ((num_ % GCF == 0) && (den_ % GCF == 0))
				{
					num_ = num_ / GCF;
					den_ = den_ / GCF;
				}
	}

	// Overloaded addition operator.
	Rational Rational:: operator+ (const Rational &right)
	{
		Rational sum;

		// Add the two rational numbers together.
		sum.num_ = num_ * right.den_ + den_ * right.num_;
		sum.den_ = den_ * right.den_;
		sum.reduce();
		return sum;
	}

	// Overloaded subtraction operator.
	Rational Rational:: operator- (const Rational &right)
	{
		Rational sum;

		// Subtract one rational number from another.
		sum.num_ = num_ * right.den_ - den_ * right.num_;
		sum.den_ = den_ * right.den_;
		sum.reduce();
		return sum;
	}

	// Overloaded multiplication operator.
	Rational Rational:: operator* (const Rational &right)
	{
		Rational sum;

		// Multiply the two rational numbers.
		sum.num_ = num_ * right.num_;
		sum.den_ = den_ * right.den_;
		sum.reduce();
		return sum;
	}

	// Overloaded division operator.
	Rational Rational:: operator/ (const Rational &right)
	{
		Rational sum;

		// Divide one rational number from another.
		sum.num_ = num_ * right.den_;
		sum.den_ = den_ * right.num_;
		sum.reduce();
		return sum;
	}

	// Overloaded less than relational operator.
	bool Rational:: operator< (const Rational &right) const
	{
		return num_ * right.den_ < right.num_ * den_;
	}

	// Overloaded greater than relational operator.
	bool Rational:: operator> (const Rational &right) const
	{
		return num_ * right.den_ > right.num_ * den_;
	}

	// Overloaded less than or equal to operator.
	bool Rational:: operator<= (const Rational &right) const
	{
		return num_ * right.den_ <= right.num_ * den_;
	}

	// Overloaded greater than or equal to operator.
	bool Rational:: operator>= (const Rational &right) const
	{
		return num_ * right.den_ >= right.num_ * den_;
	}

	// Overloaded equal to operator.
	bool Rational:: operator== (const Rational &right) const
	{
		return num_ * right.den_ == right.num_ * den_;
	}

	// Overloaded is not equal to operator.
	bool Rational:: operator!= (const Rational &right) const
	{
		return num_ * right.den_ != right.num_ * den_;
	}

	// Overloaded input operator.
	istream& operator>> (istream &in, Rational &data)
	{
		// Get the numerator
		char ch;
		in >> data.num_;

		// Get the slash.
		if (in.peek() == '/')
		{
			// Get the next denominator as long as it's not zero.
			in.get(ch);
			if ((isdigit (in.peek())) && in.peek() != '0')
				in >> data.den_;
			else
				data.den_ = 1;
		}
		else
			data.den_ = 1;
		data.reduce();
		return in;
	}

	// Overloaded output operator.
	ostream& operator<< (ostream &out, const Rational &data)
	{
		// Output the rational number.
		if (data.den_ != 1 && data.num_ != 0)
			out << data.num_ << '/' << data.den_;
		else
			if (data.num_ == 0)
				out << "0";
			else
				out << data.num_;
		return out;
	}
}
