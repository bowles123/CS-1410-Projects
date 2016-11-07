// Implementations of the member functions of the Cube class.
#include "BowlCube.h"

// Namespace.
namespace Bowles
{
	// Gets the surface area of the cube.
	double Cube:: getArea () const
	{
		return Square:: getArea() * 6;
	}

	// Gets the volume of the cube.
	double Cube:: getVolume () const
	{
		return Square:: getSide() * Square:: getSide() * Square:: getSide();
	}
}