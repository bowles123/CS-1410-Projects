// This program demonstrates the List class and allows the user to operate on the list.
// Brian Bowles, 04/15/14.

#include "BowlList.h"
#include <iostream>
using namespace std;
using namespace Bowles;

// Prototypes.
void menu ();

// This function allows the user to operate on the linked list it creates.
int main ()
{
	// Variables.
	int item, choice;
	List<int> list;

	// Greeting.
	cout << "Hello, this program demonstrates a linked list. " << endl;
	cout << "What would you like to do with the list? " << endl;

	// Display the menu for the user and operate on the linked list.
	do
	{
		menu ();
		cin >> choice;

		// Append the linked list.
		if (choice == 1)
		{
		cout << "Please enter the new item to add to the list: ";
		cin >> item;
		list.append (item);
		}
		else
			// Display the linked list.
			if (choice == 2)
			list.display ();
		else
			// Remove an item from the linked list.
			if (choice == 3)
			{
				cout << "Please enter the item you would like to remove: ";
				cin >> item;
				try
				{
					list.remove (item);
					list.display ();
				}
				catch (ListException list)
				{
					cout << list.what() << endl;
				}
			}
		else
			exit (0);
	}
	while (choice != 4);
	return 0;

}

// This function displays the menu for the user.
void menu ()
{
	cout << "1. Append" << endl << "2. Display" << endl;
	cout << "3. Remove" << endl << "4. Quit" << endl;
}