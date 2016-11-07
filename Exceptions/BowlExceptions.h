// Exception classes.
#ifndef BOWLEXCEPTIONS_H
#define BOWLEXCEPTIONS_H

#include <exception>
using namespace std;

// Namespace.
namespace Bowles
{
	// OverflowException class.
	class OverflowException: public exception
	{
	// Member functions.
	public:
		OverflowException (char * overflow): exception (overflow)
		{}
	};

	// SubscriptException class.
	class SubscriptException: public exception
	{
	// Member functions.
	public:
		SubscriptException (char *subscript): exception (subscript)
		{}
	};

	// MemoryException class.
	class MemoryException: public exception
	{
	// Member funcitons.
	public:
		MemoryException (char *memory): exception (memory)
		{}
	};
}
#endif