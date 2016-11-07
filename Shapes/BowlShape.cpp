// Implementation of the print member function of the abstract class.
// Brian Bowles, 03/18/14.
#include "BowlShape.h"
#include <iostream>
using namespace std;

namespace Bowles
{
	void Shape:: print () const
	{
		cout << "Area: " << getArea () << endl;
		cout << "Perimeter: " << getPerimeter () << endl;
	}
}