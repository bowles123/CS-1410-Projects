// Definiton of the Square class.
#ifndef BOWLSQUARE_H
#define BOWLSQUARE_H

#include "BowlPoint.h"
#include <iostream>
using namespace std;

// Namespace.
namespace Bowles
{
	class Square
	{
	// Member functions. 
	public:
		Square (Point point = (0.0, 0.0), double side = 0.0)
		{ lowerLeft_ = point; side_ = side; }
		void setLowerLeft (Point& );
		void setSide (double);
		Point getLowerLeft () const;
		double getSide () const;
		double getArea () const;
		friend ostream &operator<< (ostream& , Square&);
	// Data members.
	private:
		Point lowerLeft_;
		double side_;
	};
}
#endif
