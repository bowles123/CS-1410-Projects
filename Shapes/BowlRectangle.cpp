// Implementations of the member functions of the Rectangle class.
// Brian Bowles, 03/18/14.
#include "BowlRectangle.h"
#include <iostream>
using namespace std;

// Namespace.
namespace Bowles 
{
	// Default constructor.
	Rectangle:: Rectangle ()
	{
		length_ = width_ = 0.0;
	}

	// Explicit value constructor.
	Rectangle:: Rectangle (double length, double width)
	{
		length_ = length;
		width_ = width;
	}

	// This function returns the area of a rectangle.
	double Rectangle:: getArea () const
	{
		return length_ * width_;
	}

	// This functions returns the perimeter of a rectangle.
	double Rectangle:: getPerimeter () const
	{
		return 2 * length_ + 2 * width_;
	}

	// This functions prints the name "Rectangle" and displays it's attributes.
	void Rectangle:: print () const
	{
		cout << "Rectangle, the length is " << length_ << ", and the width is " << width_ << endl;
	}

	// This function returns the length of a rectangle
	double Rectangle:: getLength () const
	{
		return length_;
	}

	// This function returns the width of a rectangle
	double Rectangle:: getWidth () const
	{
		return width_;
	}

	// This function sets the length of a rectangle.
	void Rectangle:: setLength (double length)
	{ 
		length_ = length >= 0.0?length: 0.0;
	}
	
	// This function sets the width of a rectangle.
	void Rectangle:: setWidth (double width)
	{
		width_ = width >= 0.0?width: 0.0;
	}
}

