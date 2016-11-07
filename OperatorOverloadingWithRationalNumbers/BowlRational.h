// Definition of the Rational class, which consists of a numerator and a denominator.
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

// Namespace Bowles.
namespace Bowles
{
	// Class defintion.
	class Rational
	{
	public:
		// Member function and friend function prototypes.
		Rational ();
		Rational (int, int);
		operator double () const;
		Rational operator+ (const Rational &);
		Rational operator- (const Rational &);
		Rational operator* (const Rational &);
		Rational operator/ (const Rational &);
		bool operator< (const Rational &) const;
		bool operator> (const Rational &) const;
		bool operator<= (const Rational &) const;
		bool operator>= (const Rational &) const;
		bool operator== (const Rational &) const;
		bool operator!= (const Rational &) const;
		// Friend functions.
		friend istream &operator>> (istream &, Rational &);
		friend ostream &operator<< (ostream &, const Rational &);
	private:
		// Private member function.
		void reduce();
		// Data members.
		int num_;
		int den_;
	};
}

#endif