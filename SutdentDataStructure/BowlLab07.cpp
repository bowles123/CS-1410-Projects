// This program creates a database of Student structures and allows the user to
// access, display, and change the data in the structure, Brian Bowles, 02/25/14.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Named constants.
const int LASTNAME = 20;
const int FIRSTNAME = 15;

// New datatype to hold information about a student, called Student.
struct Student
{
	char last [LASTNAME];
	char first [FIRSTNAME];
	int age;
	double gpa;
};

// Function prototypes.
void displayMenu ();
void displaySummary (fstream&, Student&);
void displayEntry (fstream&, Student&);
void addEntry (fstream &, Student&);
void editEntry (fstream &, Student&);

// The function calls other functions to create and navigate a database.
int main ()
{
	// Variable.
	string fileName;
	int number;
	Student students;

	// Get the name of the file.
	cout << "Please enter the name of a file followed by .dat: ";
	cin >> fileName;

	// Open the file for input and output, and create it if it doesn't exist.
	fstream file;
	file.open (fileName, ios:: in);
	if (!file)
	{
		file.open (fileName, ios:: out);
		file.close ();
	}
	file.close ();
	file.open (fileName, ios:: in | ios:: out | ios:: binary);

	// Query controlled loop.
	do
	{
		// Display the menu of options for the user.
		displayMenu ();
		cin >> number;

		// Input validation.
		while (number < 1 || number > 5)
		{
			cout << "That's an invalid option, try again. ";
			cin >> number;
		}

		// Switch on number to determine what function to do.
		switch (number)
		{
		case 1: 
			displaySummary (file, students);
			break;
		case 2:
			displayEntry (file, students);
			break;
		case 3:
			addEntry (file, students);
			break;
		case 4:
			editEntry (file, students);
			break;
		}
	}
	while (number != 5);
	file.close ();
	return 0;
}

// This function displays the menu for this menu-driven program.
void displayMenu ()
{
	// Display the menu.
	cout << "Please pick an option from the following menu: " << endl;
	cout << "1. Display Summary List of Entries" << endl << "2. Display an Entry" << endl;
	cout << "3. Add an Entry" << endl << "4. Edit and Entry" << endl << "5. Quit." << endl;
}

// This function displays a summary of the information in the database.
void displaySummary (fstream& tempFile, Student& data)
{
	// Variable.
	int i = 1;

	// Set the marker to the beginning of the file.
	tempFile.seekg(0L, ios:: beg);

	// Read from the file, and display the last names.
	tempFile.read(reinterpret_cast <char*> (&data), sizeof(data));
	while (tempFile)
	{
		cout << i << ". " << data.last << endl;
		tempFile.read(reinterpret_cast <char*> (&data), sizeof(data));
		i++;
	}
	tempFile.clear ();
}

// This function displays one entry of information within the database.
void displayEntry (fstream& tempFile, Student& data)
{
	// Variable.
	int entry;

	// Display specific entry.
	cout << "Please enter the entry number of the entry you'd like to display: ";
	cin >> entry;
	tempFile.seekg ((sizeof (data)) * (entry-1), ios:: beg);
	tempFile.read(reinterpret_cast <char*> (&data), sizeof(data));
	cout << data.last << endl << data.first << endl << data.age << endl << data.gpa << endl;
	tempFile.clear ();
}

// This function adds an entry to the end of the database.
void addEntry (fstream& tempFile, Student& data)
{
	// Get the student's information fromt the user.
	cout << "Last Name: ";
	cin >> data.last;
	cout << "First Name: ";
	cin >> data.first;
	cout << "Age: ";
	cin >> data.age;
	cout << "GPA: ";
	cin >> data.gpa;
	
	// Write the information to the file.
	tempFile.seekp(0L, ios::end);
	tempFile.write(reinterpret_cast <char*> (&data), sizeof(data));
}

// This function edits an entry.
void editEntry (fstream& tempFile, Student& data)
{
	// Variables.
	int entry, studentInfo;
	char again;

	// Get the entry that the user would like to edit.
	cout << "Please enter the number of the entry that you'd like to edit. ";
	cin >> entry;
	tempFile.seekg ((sizeof (data)) * (entry-1), ios:: beg);

	// Output the current data.
	cout << "Here's the current data in that entry: " << endl;
	tempFile.read(reinterpret_cast <char*> (&data), sizeof(data));
	cout << data.last << endl << data.first << endl << data.age << endl << data.gpa << endl;

	do
	{
		// Get the information that the user would like to change.
		cout << "What would you like to change? Number 1, 2, 3, or 4? Press 5 to quit. " << endl;
		cin >> studentInfo;

		// Input Validation.
		while (studentInfo < 1 || studentInfo > 5)
		{
			cout << "That's an invalid option, try again. ";
			cin >> studentInfo;
		}

		// Get the new information from the user.
		switch (studentInfo)
		{
		case 1:
			cout << "Please enter the new last name: ";
			cin >> data.last;
			break;
		case 2:
			cout << "Please enter the new first name: ";
			cin >> data.first;
			break;
		case 3:
			cout << "Please enter the new age: ";
			cin >> data.age;
			break;
		case 4: 
			cout << "Please enter the new gpa: ";
			cin >> data.gpa;
		}
	}
	while (studentInfo != 5);

	// Write the new information to the file.
	tempFile.seekg ((sizeof (data)) * (entry-1), ios:: beg);
	tempFile.write(reinterpret_cast <char*> (&data), sizeof(data));
}