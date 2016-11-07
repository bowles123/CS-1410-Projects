// Implementations of member functions of the Triangle class
// Brian Bowles, 03/18/14.
#include "BowlTriangle.h"
#include <iostream>
using namespace std;

// Namespace.
namespace Bowles
{
	// Default constructor.
	Triangle:: Triangle ()
	{
		side1_ = side2_ = side3_ = 0.0;
	}

	// This function returns the area of a triangle.
	double Triangle:: getArea () const
	{
		double s = (side1_ + side2_ + side3_) / 2;

		return sqrt(s * (s - side1_) * (s - side2_) * (s - side3_));
	}

	// This function returns the perimeter of a triangle.
	double Triangle:: getPerimeter () const
	{
		return side1_ + side2_ + side3_;
	}

	// This function prints the name "Triangle" and it's attributes.
	void Triangle:: print () const
	{
		cout << "Triangle, the three sides are: " << side1_ << ", " << side2_ << ", and " << side3_ << ", ";
		cout << "respectively." << endl;
	}

	// This function returns the value of side1.
	double Triangle:: getSide1 () const
	{
		return side1_;
	}

	// This function returns the value of side2.
	double Triangle:: getSide2 () const
	{
		return side2_;
	}

	// This function returns the value of side3.
	double Triangle:: getSide3 () const
	{
		return side3_;
	}

	// This function sets the values for the three sides.
	void Triangle:: setSides (double side1, double side2, double side3)
	{
		// Variable.
		double greatest = side1;

		// Find the biggest side.
		if (greatest < side2)
		{
			greatest = side2;

			if (greatest < side3)
			{
				greatest = side3;
				if (greatest > (side1 + side2))
					side1 = side2 = side3 = 0.0;
			}

			if (greatest > (side1 + side3))
				side1 = side2 = side3 = 0.0;
		}
		else 
			if (greatest < side3)
			{
				greatest = side3;
				if (greatest > (side2 + side1))
				side1 = side2 = side3 = 0.0;
			}
			else 
				if (greatest > (side2 + side3))
					side1 = side2 = side3 = 0;

		// Validate that the sides aren't less than zero.
		side1_ = side1 >= 0.0?side1: 0.0;
		side2_ = side2 >= 0.0?side2: 0.0;
		side3_ = side3 >= 0.0?side3: 0.0;
	}
}
