// This program creates and utilizes a class template to better the use of arrays.
// Brian Bowles, 04/08/14.
#include "Bowlarray.h"
#include <iostream>
#include <string>
using namespace std;
using namespace Bowles;

// Prototypes.
void fillArray (Array <string> &, int);
void displayArray (Array <string> &);
int menu (Array <string> &);

int main ()
{
	// Greeting 
	cout << "Hello, this program creates and utilizes a class template to " << endl;
	cout << "better the use of arrays." << endl;

	// Variables
	int size, again;

	// Get the size of the array and validate it.
	cout << "Please enter a size for the array: ";
	cin >> size;
	if (size <= 0)
	{
		cout << "Invalid size, please try again: ";
		cin >> size;
	}

	Array <string> dataArray (size);

	// Get data into the array from the user and display it.
	fillArray (dataArray, size);
	cout << "The data in the array is as follows: ";
	displayArray (dataArray);

	// Ask user whether they want to add and element, remove one, or quit, then display the new info.
	do
	{
		again = menu (dataArray);
		cout << "The data in the array is now as follows: ";
		displayArray (dataArray);
	}
	while (again != 3);
	return 0;
}

// This function asks the user to enter the data for the array and stores it.
void fillArray (Array <string> &tempArray, int tempSize)
{
	for (int i = 0; i < tempSize; i++)
	{
		if (i == 0)
			cout << "Please enter the " << i + 1 << "st element of the array: ";
		else
			if (i == 1)
				cout << "Please enter the " << i + 1 << "nd element of the array: ";
		else
			if (i == 2)
				cout << "Please enter the " << i + 1 << "rd element of the array: ";
		else
			cout << "Please enter the " << i + 1 << "th element of the array: ";
		cin >> tempArray [i];
	}
}

// This function displays the data in the array.
void displayArray (Array <string> &tempArray)
{
	for (int i = 0; i < tempArray.getSize(); i++)
		if (i == (tempArray.getSize() - 1))
			cout << tempArray [i] << "." << endl;
		else
			cout << tempArray [i] << ", ";
}

// This function gives the user an option to remove or add an element, or quit.
int menu (Array <string> & tempArray)
{
	// Variable.
	int menuOption;

	// Menu.
	cout << "Would you like to: " << endl << "1. Add an element" << endl;
		cout << "2. Remove and element" << endl << "3. Quit" << endl;
		cin >> menuOption;
		try
		{
			if (menuOption == 1)
			{
				// Make sure array can be dynamically allocated.
	
				// Variable.
				string newData;

				// Add an element and get data to store into it.
				cout << "Please enter something to add to the last element of the array: ";
				cin >> newData;
				tempArray.addElement (newData);
			}
			else
				if (menuOption == 2)
				{
					// Remove an element.
					tempArray.removeElement();
					// Throw exception if the array size is less than 1.
					if (tempArray.getSize() < 1)
						throw exception ("Array can't shrink anymore.");
				}
				else
					// Quit.
					exit (0);
		}
		// Catch the bad_alloc exception.
		catch (bad_alloc bad)
		{
			throw exception ("No Memory.");
		}
		// Catch the exception for removing an element from an array.
		catch (exception e)
		{
			cout << e.what () << endl;
			exit (1);
		}
		return menuOption;
}