// Implementation of the overridden print function of the Square class.
// Brian Bowles, 03/18/14.
#include "BowlSquare.h"
#include <iostream>
using namespace std;

// Namespace.
namespace Bowles
{
	// This function outputs the name "Square" and its attributes.
	void Square:: print () const
	{
		cout << "Square, the side length is: " << getLength() << endl;
	}
}