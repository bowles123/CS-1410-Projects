// Definition of Triangle class, derived from the Shape class.
// Brian Bowles, 03/18/14.
#ifndef BOWLTRIANGLE_H
#define BOWLTRIANGLE_H

#include "BowlShape.h"

// Namespace.
namespace Bowles
{
	class Triangle: public Shape
	{
	// Member functions.
	public:
		Triangle ();
		double getArea () const;
		double getPerimeter () const;
		void print () const;
		double getSide1 () const;
		double getSide2 () const;
		double getSide3 () const;
		void setSides (double, double, double);
	// Data members.
	private:
		double side1_;
		double side2_;
		double side3_;
	};
}
#endif
