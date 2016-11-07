// Definition of the Rectangle class, derived from the Shape class.
// Brian Bowles, 03/18/14.
#ifndef BOWLRECTANGLE_H
#define BOWLRECTANGLE_H

#include "BowlShape.h"

// Namespace.
namespace Bowles
{
	class Rectangle: public Shape
	{
	// Member functions.
	public:
		Rectangle ();
		Rectangle (double, double);
		double getArea () const;
		double getPerimeter () const;
		void print () const;
		double getLength () const;
		double getWidth () const;
		void setLength (double);
		void setWidth (double);
	// Data members.
	private:
		double length_;
		double width_;
	};
}
#endif