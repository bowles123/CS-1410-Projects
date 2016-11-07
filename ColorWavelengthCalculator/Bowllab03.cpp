// This program asks the user for a color and displays the color chosen, it then finds and reports the wavelength.
// Brian Bowles, 01/21/14.
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

// Enumeration.
enum Color {BLUE, GREEN, RED, ORANGE, YELLOW, PURPLE};

// Function prototypes
Color inputColor ();
void displayColor (const Color &colorValue);
float findWavelength (const Color &colorValue);

// This function calls three function to get a color from the user, display it, and find its wavelength.
int main ()
{
	// Variables.
	float wavelength;
	Color color;
	char goAgain;

	// Greeting.
	cout << "Hello, this program asks the user for a color and displays the color chosen, " << endl;
	cout << "it then finds and reports the wavelength." << endl;

	do
	{
		// Call functions.
		color = inputColor ();
		displayColor (color);
		wavelength = findWavelength (color);
		cout << "The wave length of the color you entered is " << setprecision(8) << fixed << wavelength << " meters." << endl;
		cout << "Would you like to run the program again? Y or N? ";
		cin >> goAgain;
	}
	while (toupper(goAgain) == 'Y');
	return 0;
}

// This function allows the user to input the name of a color and returns the color value.
Color inputColor ()
{
	// Variable.
	string color;
	bool test = true;

	// Ask user to input valid color.
	cout << "Please enter one of the following colors: Blue, Green, Red, Yellow, Orange, " << endl;
	cout << "or Purple.  ";
	cin >> color;

	// Find which value to return using if/else statements, and returnt that value.
	do
	{
		if (color == "blue" || color == "Blue")
			return BLUE;
		else
			if (color == "green" || color == "Green")
				return GREEN;
		else 
			if (color == "red" || color == "Red")
				return RED;
		else 
			if (color == "Orange" || color == "orange")
				return ORANGE;
		else
			if (color == "Yellow" || color == "yellow")
				return YELLOW;
		else
			if ( color == "Purple" || color == "purple")
				return PURPLE;
		else
		{
			cout << "The color you entered is invalid, Please try again: ";
			cin >> color;
			test = false;
		}
	}
	while (test == false);
}

// This function displays the color.
void displayColor (const Color &colorValue)
{
	// Switch statement to find the color input by the user and display it.
	switch (colorValue)
	{
		case BLUE:
			cout << "The color you entered is Blue." << endl;
			break;
		case GREEN:
			cout << "The color you entered is Green." << endl;
			break;
		case RED:
			cout << "The color you entered is Red." << endl;
			break;
		case ORANGE:
			cout << "The color you entered is Orange." << endl;
			break;
		case YELLOW:
			cout << "The color you entered is Yellow." << endl;
			break;
		case PURPLE:
			cout << "The color you entered is Purple." << endl;
			break;
		default: 
			cout << "You did not enter a color from the list of options." << endl;
	}
}

// This function finds and returns the wavelength of the color in meters.
float findWavelength (const Color &colorValue)
{
	// Switch statements to find the right wavelength for the color.
	switch (colorValue)
	{
		case BLUE:
			return 0.00000047;
			break;
		case GREEN:
			return 0.00000051;
			break;
		case RED:
			return 0.00000065;
			break;
		case ORANGE:
			return 0.00000059;
			break;
		case YELLOW:
			return 0.00000057;
			break;
		case PURPLE:
			return 0.0000004;
			break;
	}
}