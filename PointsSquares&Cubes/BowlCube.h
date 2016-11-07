// Definition of the Cube class.
#ifndef BOWLCUBE_H
#define BOWLCUBE_H

#include "BowlSquare.h"
using namespace std;

// Namespace.
namespace Bowles
{
	class Cube: public Square
	{
	// Member functions.
	public:
		Cube (Point point = (0, 0), double side = 0.0) : Square(point, side)
		{}
		double getArea () const;
		double getVolume () const;
	};
}
#endif
