// This program implements the recreation of the string class, Brian Bowles, 02/11/14.
#include <iostream>
#include "BowlString.h"
using namespace std;
using namespace Bowles;

// This program implements the recreation of the string class.
int main ()
{
	// Variables.
	String sentence;
	char array1 [80];
	int length;

	// Get input from user.
	cout << "Please enter a sentence: ";
	cin.getline (array1, 80);

	// Find the length of the sentence entered and assign it to size_.
	length = strnlen (array1, 80);
	sentence.setSize (length + 1);

	// Set and display the string, then display the size of the array.
	sentence.setString (array1);
	sentence.dispalyString ();
	cout << "The size of the array is: " << sentence.getSize () << endl;
	return 0;
}
