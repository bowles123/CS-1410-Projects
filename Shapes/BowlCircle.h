// Definition of the Circle class, derived from the shape class.
// Brian Bowles, 03/18/14.
#ifndef BOWLCIRCLE_H
#define BOWLCIRCLE_H

#include "BowlShape.h"

// Namespace.
namespace Bowles
{
	// Global constant for PI.
	const double PI = 3.14159;

	class Circle: public Shape
	{
	// Member functions.
	public:
		Circle ();
		double getArea () const;
		double getPerimeter () const;
		void print () const;
		double getRadius () const;
		void setRadius (double);
	// Data members.
	private:
		double radius_;
	};
}
#endif
