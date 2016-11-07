// This programs simulates a line at a bank using a queue object.
// Brian Bowles, 04/22/14.
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

// Prototypes.
int randomInt();
bool endOfDay (int, int);
void display (int, int, int);
 
// This function runs the simulation, calling other funtions to assist.
int main()
{
	// Variables.
	int businessTime, currentTime = 0, serviceEndTime = 0, nextArrival;
	int longest = 0, maxLength = 0, customers = 0, waitTime;
	bool servicingCustomer = false, firstCustomer = true;
	// Queue object.
	queue<int> line;
    
	srand(time(0));

	// Greeting.
	cout << "Hello, this program simulates a line at a bank" << endl;
	cout << "How long would you like to run the simulation? (480 = 8 hours): ";
	cin >> businessTime;
 
	// Get the arrival time of first customer.
	nextArrival = randomInt();
 
	// Run the program as long as the day isn't over or someone is still being serviced.
	while (endOfDay(businessTime, currentTime) == false || servicingCustomer)
	{
		
		// Add customers to the queue.
		if (currentTime >= nextArrival && endOfDay(businessTime, currentTime) == false)
		{
			line.push (currentTime);
			customers++;
			nextArrival = randomInt() + currentTime;

			// Output for the first customer.
			if (!firstCustomer)
			cout << "Another customer arrived at " << currentTime << " minutes." << endl;
			else
			{
			cout << "The first customer arrived at " << currentTime << " minutes." << endl;
			firstCustomer = false;
			}
      
		}
 
		// If it's time to service a customer pull them from the queue.
		if (currentTime >= serviceEndTime && servicingCustomer)
		{
			servicingCustomer = false;
			cout << "The customer was finshed being serviced at " << currentTime << " minutes." << endl;
		}
 
		// Get the wait time of the customer if there is no one being serviced and the line is empty.
		if (!servicingCustomer && !line.empty())
		{
			servicingCustomer = true;
			waitTime = currentTime - line.front();
			serviceEndTime = currentTime + randomInt();
			line.pop();
			if(waitTime > longest)
			longest = waitTime;
		}
 
		// Find the biggest the line ever got.
		if (line.size() > maxLength)
			maxLength = line.size();
    
		// Check to see if the day is over, if it is then finish servicing customers until the queue is empty.
		endOfDay (businessTime, currentTime);
		currentTime++;
	}
	display(longest, maxLength, customers);
}
 
// This function generates a random number.
int randomInt()
{
  return (rand() % 4) + 1;
}

// This function checks to see if it's the end of the work day.
bool endOfDay (int workTime, int time)
{
	if (time >= workTime)
		return true;
	else
		return false;
}

// This function displays the longest a customer waited, the biggest the line got, and the amount of customers.
void display (int tempLongest, int tempMax, int tempCustomers)
{
	cout << "The longest a customer waited was: " << tempLongest << " minutes." << endl;
	cout << "The biggest the line got was: " << tempMax << " people at a time." << endl;
	cout << "The total amount of customers were: " << tempCustomers << " customers." << endl;
}