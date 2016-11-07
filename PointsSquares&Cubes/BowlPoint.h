// Defintion of the Point class.
#ifndef BOWLPOINT_H
#define BOWLPOINT_H

#include <iostream>
using namespace std;

// Namespace.
namespace Bowles
{
	class Point
	{
	// Member functions.
	public:
		Point:: Point (double x = 0, double y = 0)
		{ x_ = x; y_ = y; }
		void setX (double);
		void setY (double);
		int getX () const;
		int getY () const;
		friend ostream &operator<< (ostream &, const Point &);
	// Data members.
	private:
		double x_;
		double y_;  
	};
}
#endif