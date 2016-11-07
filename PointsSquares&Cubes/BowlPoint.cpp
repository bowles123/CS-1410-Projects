// Implementations of the member functions of the Point class.
#include "BowlPoint.h"
#include <iostream>
using namespace std;

// Namespace.
namespace Bowles
{
	// Sets the x-coordinate.
	void Point:: setX (double x)
	{
		x_ = x;
	}

	// Sets the y-coordinate.
	void Point:: setY (double y)
	{
		y_ = y;
	}

	// Gets the x-coordinate.
	int Point:: getX () const
	{
		return x_;
	}

	// Gets the y-coordinate.
	int Point:: getY () const
	{
		return y_;
	}

	// Overloaded output operator.
	ostream &operator<< (ostream &out, const Point &object)
	{
		out << "(" << object.x_ << ", " << object.y_ << ")";
		return out;
	}
}


