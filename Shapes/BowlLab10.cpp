// This program creates a circle, square, triangle, and rectangle, and displays it's attributes.
// Brian Bowles, 03/18/14.
#include "BowlCircle.h"
#include "BowlSquare.h"
#include "BowlTriangle.h"
#include "BowlRectangle.h"
#include <iostream>
using namespace std;
using namespace Bowles;

// Prototypes.
void getCircle (Circle &);
void getSquare (Square &);
void getTriangle (Triangle &);
void getRectangle (Rectangle &);
void printObject (Shape *ptr);
// This function instantiates the classes and gets values for thier attributes from the user.
int main ()
{
	// Objects of type Circle, Square, Triangle, and Rectangle.
	Circle circle;
	Square square;
	Triangle triangle;
	Rectangle rectangle;
	Shape *sptr;

	// Greeting.
	cout << "This program creates a circle, square, triangle, and rectangle object, " << endl;
	cout << "and gets values for them from the user, then outputs their attributes." << endl;

	// Set the data members of the istantiated classes.
	getCircle (circle);
	getSquare (square);
	getTriangle (triangle);
	getRectangle (rectangle);

	// Print the attributes, area, and perimeter of the objects.
	sptr = &circle;
	printObject (sptr);
	sptr = &square;
	printObject (sptr);
	sptr = &triangle;
	printObject (sptr);
	sptr = &rectangle;
	printObject (sptr);
	return 0;
}

// This functions gets values for the data members of a circle object.
void getCircle (Circle &tempCircle)
{
	// Temporary variable to pass to the setRadius function.
	double tempRadius;

	// Get the radius of the circle from the user, and validate its value.
	cout << "Please enter the radius of the circle: ";
	cin >> tempRadius;
	while (tempRadius < 0 )
	{
		cout << "That's an invalid radius value, please try again: ";
		cin >> tempRadius;
	}
	tempCircle.setRadius(tempRadius);
}

// This functions gets values for the data members of a square object.
void getSquare (Square &tempSquare)
{
	// Temporary variable to pass to the setLength and setWidth functions.
	double tempSide;

	// Get the side of the square from the user, and validate its value.
	cout << "Please enter the side length of the square: ";
	cin >> tempSide;
	while (tempSide < 0 )
	{
		cout << "That's an invalid side length, please try again: ";
		cin >> tempSide;
	}
	tempSquare.setLength(tempSide);
	tempSquare.setWidth(tempSide);
}

// This functions gets values for the data members of a triangle object.
void getTriangle (Triangle &tempTriangle)
{
	// Temporary variables to pass the the setSides function.
	double tempSide1, tempSide2, tempSide3;

	// Get the values for the sides of the triangle, and validate their values.
	cout << "Please enter the first side length of the triangle: ";
	cin >> tempSide1;
	while (tempSide1 < 0 )
	{
		cout << "That's an invalid side length, please try again: ";
		cin >> tempSide1;
	}
	cout << "Please enter the second side length of the triangle: ";
	cin >> tempSide2;
	while (tempSide2 < 0 )
	{
		cout << "That's an invalid side length, please try again: ";
		cin >> tempSide2;
	}
	cout << "Please enter the third side length of the triangle: ";
	cin >> tempSide3;
	while (tempSide3 < 0 )
	{
		cout << "That's an invalid side length, please try again: ";
		cin >> tempSide3;
	}

	// Set the values of the sides of the triangle.
	tempTriangle.setSides(tempSide1, tempSide2, tempSide3);
}

// This functions gets values for the data members of a rectangle object.
void getRectangle (Rectangle &tempRectangle)
{
	// Temporary variables to pass to the setLength and setWidth functions.
	double tempLength, tempWidth;

	// Get the values for the length and the width of the rectangle, and validate their values.
	cout << "Please enter the length of the rectangle: ";
	cin >> tempLength;
	while (tempLength < 0 )
	{
		cout << "That's an invalid length, please try again: ";
		cin >> tempLength;
	}
	cout << "Please enter the width of the rectangle: ";
	cin >> tempWidth;
	while (tempWidth < 0 )
	{
		cout << "That's an invalid width, please try again: ";
		cin >> tempWidth;
	}

	// Set the of the length and width of the data members of the rectangle class.
	tempRectangle.setLength(tempLength);
	tempRectangle.setWidth(tempWidth);
}

// This function prints the attributes, area, and perimeter of a given shape.
void printObject (Shape *ptr)
{
	ptr -> print();
	cout << "Area: " << ptr -> getArea() << endl;
	cout << "Perimeter: " << ptr -> getPerimeter() << endl;
}

