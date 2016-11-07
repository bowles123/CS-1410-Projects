// This program creates problems, and throws exceptions to deal with those problems.
// Brian Bowles, 04/01/14.
#include "BowlExceptions.h"
#include <iostream>
#include <new>
#include <string>
using namespace Bowles;

// Function prototypes.
void overflowException ();
void subscriptException ();
void memoryException ();

// This function deals with one of three exceptions that may be thrown.
int main ()
{
	// Greeting
	cout << "Hello, this programming throws exceptions to specific problems." << endl;

	// Try block for the exception handling.
	try
	{
		int exception;
		cout << "Please pick an exception to test: " << endl << "1. Overflow Exception" << endl;
		cout << "2. SubscriptException" << endl << "3. MemoryException" << endl;
		cin >> exception;
		while (exception > 3 || exception < 1)
		{
			cout << "Invalid choice, please try again: ";
			cin >> exception;
		}
		if (exception == 1)
			overflowException ();
		else
			if (exception == 2)
				subscriptException ();
			else
				memoryException ();
	}
	// OverflowException catch block.
	catch (OverflowException overflow)
	{
		cout << overflow.what() << endl;
	}
	// SubscriptException catch block.
	catch (SubscriptException subscript)
	{
		cout << subscript.what() << endl;
	}
	// MemoryException catch block.
	catch (MemoryException memory)
	{
		cout << memory.what() << endl;
	}
	return 0;
}

// This function generates and throws and OverflowException.
void overflowException ()
{
	// Variable to be overflowed
	short sum = 32750;

	// Overflow variable and throw the OverflowException.
	for (int i = 0; i < 50; i++)
	{
		if (sum < 0)
			throw OverflowException ("Number too large.");
		cout << "The number is: " << sum << endl;
		sum++;
	}
}

// This function generates and throws and SubscriptException.
void subscriptException ()
{
	// Variables.
	int arraySize;
	int *arrayPtr;

	// Get the size of the array to be dynamically allocated.
	cout << "How big does the array need to be? ";
	cin >> arraySize;
	arrayPtr = new int [arraySize];

	// Generate and throw the SubscriptException.
	for (short i = 0; i < 33000; i++)
	{
		if (i > arraySize)
			throw SubscriptException ("Subscript out of bounds.");
		cout << "The subscript is: " << i << endl;
	}
	delete arrayPtr;
}

// This function generates and throws and MemoryException.
void memoryException ()
{
	// Variables.
	int *ptr;
	int size = 1, arrayNumber = 0;

	do
	{
		// Create first array of size 1, and throw the MemoryException if it's detected.
		ptr = new int [size];
		if (ptr == 0)
			throw MemoryException ("No memory remaining.");
		arrayNumber++;

		// Output which array is being dynamically allocated.
		if (arrayNumber == 1)
			cout << "The " << arrayNumber << "st array is being dynamically allocated." << endl;
		else
			if (arrayNumber == 3)
				cout << "The " << arrayNumber << "rd array is being dynamically allocated." << endl;
			else
				cout << "The " << arrayNumber << "th array is being dynamically allocated." << endl;
		delete ptr;

		// Times size by ten and create another array.
		size *= 10;
		try 
		{
			ptr = new int [size];
			arrayNumber++;

			// Output which array is being dynamically allocated.
			if (arrayNumber == 2)
				cout << "The " << arrayNumber << "nd array is being dynamically allocated." << endl;
			else
				cout << "The " << arrayNumber << "th array is being dynamically allocated." << endl;
		}
		catch (bad_alloc a)
		{
			throw MemoryException ("No memory remaining.");
		}
	}
	while (ptr != 0);
}


		