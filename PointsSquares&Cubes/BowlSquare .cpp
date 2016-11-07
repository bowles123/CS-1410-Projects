// Implementations of the member functions of the Square class.
#include "BowlSquare.h"

// Namespace.
namespace Bowles
{
	// Sets the lowerleft point of the square.
	void Square:: setLowerLeft (Point &point)
	{
		lowerLeft_ = point;
	}

	// Sets the side length of the square.
	void Square:: setSide (double side)
	{
		side_ = side >= 0.0?side: 0.0;
	}

	// Gets the lowerleft point of the square.
	Point Square:: getLowerLeft () const
	{
		return lowerLeft_;
	}

	// Gets the side length of the square.
	double Square:: getSide () const
	{
		return side_;
	}

	// Gets the Area of the square.
	double Square:: getArea () const
	{
		return side_ * side_;
	}

	// Overloaded output operator.
	ostream &operator<< (ostream &out, Square &object)
	{
		out << object.lowerLeft_ <<", ";
		out << object.getSide () << ", ";
		out << object.getArea ();
		return out;
	}
}

