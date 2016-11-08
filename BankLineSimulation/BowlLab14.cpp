// This programs simulates a line at a bank using a queue object.
// Brian Bowles, 04/22/14.
#include "BankLineSimulator.h"

// This function runs the simulation, calling other funtions to assist.
int main()
{
	// Variables.
	BankLineSimulator bank1 = BankLineSimulator();

	// Run the program as long as the day isn't over or someone is still being serviced.
	bank1.simulateLine();
	bank1.displayDay();
	return 0;
}
