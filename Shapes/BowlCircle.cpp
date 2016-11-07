// Implementation of the member functions of the Circle class.
// Brian Bowles, 03/18/14.
#include "BowlCircle.h"
#include <iostream>
using namespace std;

// Namespace.
namespace Bowles
{
	// Default constructor.
	Circle:: Circle ()
	{
		radius_ = 0.0;
	}

	// Returns the area of a circle.
	double Circle:: getArea () const
	{
		return PI * (radius_ * radius_);
	}

	// Returns the circumference of a circle.
	double Circle:: getPerimeter () const
	{
		return 2 * PI * radius_ ;
	}

	// Prints the name of the shape, and it's attributes.
	void Circle:: print () const
	{
		cout << "Circle, the radius is: " << radius_ << endl;
	}

	// This functions returns the radius of a circle.
	double Circle:: getRadius () const
	{
		return radius_;
	}

	// This function sets the radius of a circle.
	void Circle:: setRadius (double radius)
	{
		radius_ = radius >= 0.0?radius: 0.0;
	}
}