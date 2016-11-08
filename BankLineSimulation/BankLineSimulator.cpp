#include <iostream>
#include "BankLineSimulator.h"

BankLineSimulator::BankLineSimulator()
{
	currentTime = 0;
	serviceEndTime = 0;
	longest = 0;
	maxLength = 0;
	customers = 0;
	servicingCustomer = false;
	firstCustomer = true;
}

bool BankLineSimulator::endOfDay()
{
	return currentTime >= businessTime;
}

void BankLineSimulator::displayDay()
{
	std::cout << "The longest a customer waited was: " << longest << " minutes." << std::endl;
	std::cout << "The biggest the line got was: " << maxLength << " people at a time." << std::endl;
	std::cout << "The total amount of customers was: " << customers << " customers." << std::endl;
}

void BankLineSimulator::displayGreeting()
{
	std::cout << "Hello, this program simulates a line at a bank" << std::endl;
	std::cout << "How long would you like to run the simulation? (480 = 8 hours): ";
	std::cin >> businessTime;
}

int BankLineSimulator::randomInt()
{
	return (rand() % 4) + 1;
}

void BankLineSimulator::addCustomer()
{
	line.push(currentTime);
	customers++;
	nextArrival = randomInt() + currentTime;

	// Output for the first customer.
	if (!firstCustomer)
		std::cout << "Another customer arrived at " << currentTime << " minutes." << std::endl;
	else
	{
		std::cout << "The first customer arrived at " << currentTime << " minutes." << std::endl;
		firstCustomer = false;
	}
}

void BankLineSimulator::completeCustomerService()
{
	servicingCustomer = false;
	std::cout << "Customer was finshed being serviced at " << currentTime << " minutes." << std::endl;
}

int BankLineSimulator::getCustomerWaitTime()
{
	servicingCustomer = true;
	int waitTime = currentTime - line.front();
	serviceEndTime = currentTime + randomInt();
	line.pop();
	return waitTime;
}

void BankLineSimulator::simulateLine()
{
	srand(time(0));
	displayGreeting();
	nextArrival = randomInt();

	// Run the program as long as the day isn't over or someone is still being serviced.
	while (!endOfDay() || servicingCustomer)
	{

		// Add customer to the queue.
		if (currentTime >= nextArrival && !endOfDay())
			addCustomer();

		// If it's time to service a customer pull them from the queue.
		if (currentTime >= serviceEndTime && servicingCustomer)
			completeCustomerService();

		// Get the wait time of the customer if there is no one being serviced and the line is empty.
		if (!servicingCustomer && !line.empty())
		{
			int time = getCustomerWaitTime();

			if (time > longest)
				longest = time;
		}

		// Find the biggest the line ever got.
		if (line.size() > maxLength)
			maxLength = line.size();

		// Check to see if the day is over, if it is then finish servicing customers until the queue is empty.
		endOfDay();
		currentTime++;
	}
	displayDay();
}