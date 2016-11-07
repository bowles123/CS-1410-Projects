// This program recieves a collection of characters, then calculates and display the number of words
// it then asks the user if they'd like to repeat, Brian Bowles, 01/07/14.
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Global Constant.
const int SIZE = 80;
// Function Prototypes
char *getString ();
int countWords (char *stringPtr);

int main ()
{
	// Variables.
	char again;
	char *ptr;
	int words;
	// Title.
	cout << "Hello, this program asks the user for a collection of characters" << endl;
	cout << "and counts the amount of words in that collection, it then outputs" << endl;
	cout << "the number of words and asks the user if they'd like to do it again." << endl;
	// Qeury controlled loop.
	do
	{
		ptr = getString ();
		words = countWords (ptr);
		cout << "The number of words in the sentence is: " << words << endl;
		cout << "Would you like to do it again, Y or N?" << endl;
		cin >> again;
		cin.ignore();
	}
	while (toupper(again) == 'Y');
	return 0;
}

// This function gets a c-string from the user.
char *getString ()
{
	// Variables
	char character [SIZE];
	char *cptr;
	int length;
	// User prompt.
	cout << "Please enter a sentence: " << endl;
	cin.getline (character, SIZE);
	length = strlen (character) + 1;
	cptr = new char [length];
	strcpy (cptr, character);
	return cptr;
}

// This function counts the number of words in the c-string.
int countWords (char *stringPtr)
{
	int length, words = 1;
	length = strlen(stringPtr);
	for (int count = 0; count < length; count++)
	{
		if (stringPtr[count] == ' ')
			words++;
	}
	return words;
}



