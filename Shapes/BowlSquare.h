// Defintion of the Square class, derived from the Rectangle class.
// Brian Bowles, 03/18/14.
#ifndef BOWLSQUARE_H
#define BOWLSQUARE_H

#include "BowlRectangle.h"

// Namespace.
namespace Bowles
{
	class Square: public Rectangle
	{
	// Member functions.
	public:
		Square (double side = 0): Rectangle (side, side)
		{}
		void print () const;
	};
}
#endif