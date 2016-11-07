// Class member function definitions.
#include <iostream>
#include "BowlString.h"
using namespace std;

// New namespace named Bowles.
namespace Bowles
{
	// Default Constructor.
	String:: String ()
	{
		ptr_ = NULL;
	}

	// Explicit value constructor.
	String:: String (char *ptr)
	{
		ptr_ = ptr;
	}

	// Destructor, deletes dynamically allocated array.
	String:: ~String ()
	{
		delete [] ptr_;
	}

	// Sets the size of the array.
	void String:: setSize (int size)
	{
		size_ = size;
	}

	// Sets the string to a value.
	void String:: setString (char *ptr)
	{
		ptr_ = new char [size_];
		strcpy (ptr_, ptr);
	}

	// Displays the contents of the string object.
	void String:: dispalyString () const
	{
		cout << "The sentence you entered is: ";
		for (int i = 0; i < size_; i++)
			cout << ptr_ [i];
		cout << endl;
	}

	// Returns the size of the array.
	int String:: getSize ()
	{
		return size_ - 1;
	}
}






