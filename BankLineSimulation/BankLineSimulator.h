#pragma once
#include <queue>
#include <cstdlib>
#include <ctime>

class BankLineSimulator {
public:
	BankLineSimulator();
	void simulateLine();
	void displayDay();
private:
	int businessTime;
	int currentTime;
	int serviceEndTime;
	int nextArrival;
	int longest;
	int maxLength;
	int customers;
	bool servicingCustomer;
	bool firstCustomer;
	std::queue<int> line;

	void displayGreeting();
	int randomInt();
	void addCustomer();
	void completeCustomerService();
	int getCustomerWaitTime();
	bool endOfDay();
};
