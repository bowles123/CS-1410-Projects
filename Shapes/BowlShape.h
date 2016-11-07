// Definition of an abstract class named "Shape", Brian Bowles, 03/18/14.
#ifndef BOWLSHAPE_H
#define BOWLSHAPE_H

// Namespace.
namespace Bowles
{
	class Shape
	{
	// Member functions.
	public:
		virtual double getArea () const = 0;
		virtual double getPerimeter () const = 0;
		virtual void print () const = 0;
	};
}
#endif