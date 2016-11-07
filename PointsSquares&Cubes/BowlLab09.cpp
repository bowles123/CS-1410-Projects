// This program gets a point, square, and cube from the user and outputs their attributes.
// Brian Bowles, 03/10/14.
#include "BowlPoint.h"
#include "BowlSquare.h"
#include "BowlCube.h"
#include <iostream> 
using namespace std;
using namespace Bowles;

// Prototypes.
Point getPoint ();
Square getSquare ();
Cube getCube ();

// THis function gets a point, square, and cube from the user and outputs their attributes.
int main ()
{
	// Variables.
	Point point;
	Square square;
	Cube cube;

	// Give the point, square, and cube objects values.
	point = getPoint ();
	square = getSquare ();
	cube = getCube ();

	// Output the attributes of the point, square, and cube.
	cout << "The coordinate for the point is: " << point << endl;
	cout << "The coordinate, the side length, and the area of the square are: " << endl;
	cout << square << " respectively." << endl;
	cout << "The coordinate, the side length, and the surface area of the cube are: " << endl;
	cout << cube << " respectively." << endl;
}

// This function gets a value for the point.
Point getPoint ()
{
	// Variables.
	double tempX, tempY;
	Point point;

	// Get the point
	cout << "Please enter the x-coordinate for the point: ";
	cin >> tempX;
	point.setX (tempX);
	cout << "Please enter the y-coordinate for the point: ";
	cin >> tempY;
	point.setY (tempY);
	return point;
}

// This function gets a value for the square.
Square getSquare ()
{
	// Variables.
	double tempX, tempY, tempSide;
	Point point;
	Square square;

	// Get the point
	cout << "Please enter the x-coordinate for the lower left point of the square: ";
	cin >> tempX;
	point.setX (tempX);
	cout << "Please enter the y-coordinate for the lower left point of the square: ";
	cin >> tempY;
	point.setY (tempY);
	square.setLowerLeft (point);

	// Get the side length of the square.
	cout << "Please enter the side length of the square: ";
	cin >> tempSide;
	square.setSide (tempSide);
	return square;
}

// THis function gets a value for the cube.
Cube getCube ()
{
	// Variables.
	double tempX, tempY, tempSide;
	Point point;
	Cube cube;

	// // Get the point.
	cout << "Please enter the x-coordinate for the lower left point of the cube: ";
	cin >> tempX;
	point.setX (tempX);
	cout << "Please enter the y-coordinate for the lower left point of the cube: ";
	cin >> tempY;
	point.setY (tempY);
	cube.setLowerLeft (point);

	// Get the side length of the cube.
	cout << "Please enter the side length of the cube: ";
	cin >> tempSide;
	cube.setSide (tempSide);
	return cube;
}

