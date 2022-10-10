/* Program to create a clock program that will display time in 12 hour
and 24 hour formats on the screen. There will be a menu allowing the
user to change the hour, minute, second, and quit the program.
The 12 and 24 hour clocks will display simultaneously on the screen.

Rob Marlatt
09/17/2022
*/


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;



string nCharString(size_t n, char c) { // Function to repeat "*" to format the program output
	std::string str(""); // intitialize string str
	str.insert(0, n, c); // insert n amount of char c into str
	return str; // Return result to main
} // Function nCharString end


void printMenu() { // Function to print menu
	
	cout << nCharString(26, '*') << endl; // Print Header  
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << nCharString(26, '*') << endl; // Print footer
	cout << endl;
	cout << endl;

} // Function printMenu end


unsigned int getMenuChoice() { // Function to process user input from menu choices
	unsigned int choice = 0;
	cout << "Please enter a number from the menu above:" << endl;
	cout << endl;
	cin >> choice; // Get user input for menu choice
	
	while ((choice < 1) || (choice > 4)) { // Loop back if choice outside of menu range
		cout << "Not a valid number!" << endl;
		cout << "Choose a number between 1 and 4." << endl;
		cout << endl;
		cin >> choice; // Ask for user input again
	}
	return choice; // Return result to main 
} // Function getMenuChoice end


void displayClocks(int& clock12Hour1, int& clock12Hour2, int& clock24Hour1, int& clock24Hour2, int& minutes1, int& minutes2, int& seconds1,
	int& seconds2, string& amPm) { // Function to display time in both 12 and 24 hour formats

	// cout 27 stars + 3 spaces + 27 stars + endl
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	// cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
	cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
	// cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
	cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
	// cout an endl for a blank line
	cout << endl;
	// cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
	cout << nCharString(1, '*') << nCharString(6, ' ') << clock12Hour1 << clock12Hour2 << nCharString(1, ':') << minutes1 << minutes2 <<
		nCharString(1, ':') << seconds1 << seconds2 << " " << amPm << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
	// cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
	cout << nCharString(1, '*') << nCharString(8, ' ') << clock24Hour1 << clock24Hour2 << nCharString(1, ':') << minutes1 << minutes2 <<
		nCharString(1, ':') << seconds1 << seconds2 << nCharString(9, ' ') << nCharString(1, '*') << endl;
	// cout 27 stars + 3 spaces + 27 stars + endl
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	cout << endl;

} // Function displayClocks end

void addOneHour(int& clock12Hour1, int& clock12Hour2, int& clock24Hour1, int& clock24Hour2, string& amPm) { // Function to add an hour to the clocks
	if (clock12Hour2 < 10) {
		clock12Hour2 = clock12Hour2 + 1;
	} // End if
	
	if (clock12Hour2 == 10) {
		clock12Hour1 = 1; clock12Hour2 = 0;
	} // End if
	
	if (clock12Hour1 == 1 && clock12Hour2 == 3) {
		clock12Hour1 = 0; clock12Hour2 = 1;
	} // End if
	
	if (clock24Hour2 < 10) {
		clock24Hour2 = clock24Hour2 + 1;
	} // End if
	
	if (clock24Hour1 == 1 && clock24Hour2 == 10) {
		clock24Hour1 = 2; clock24Hour2 = 0;
	} // End if
	
	if (clock24Hour2 == 10) {
		clock24Hour2 = 0; clock24Hour1 = 1;
	} // End if

	if (clock24Hour1 == 2 && clock24Hour2 == 4) {
		clock24Hour1 = 0;
		clock24Hour2 = 0;
	} //End if

} // End addOneHour


void addOneMinute(int& minutes1, int& minutes2, int& clock12Hour1,
	int& clock12Hour2, int& clock24Hour1, int& clock24Hour2, string& amPm) { // Function to add a minute to the clocks
	if (minutes2 < 10) {
		minutes2 = minutes2 + 1;
	} // End if
	
	if (minutes1 == 5 && minutes2 == 10) {
		minutes1 = 0;
		minutes2 = 0;

		if (clock12Hour2 < 10) {
			clock12Hour2 = clock12Hour2 + 1;
		} // End if

		if (clock12Hour2 == 10) {
			clock12Hour1 = 1;
			clock12Hour2 = 0;
		} // End if

		if (clock12Hour1 == 1 && clock12Hour2 == 3) {
			clock12Hour1 = 0;
			clock12Hour2 = 1;
		} // End if

		if (clock24Hour2 < 10) {
			clock24Hour2 = clock24Hour2 + 1;
		} // End if

		if (clock24Hour1 == 1 && clock24Hour2 == 10) {
			clock24Hour1 = 2;
			clock24Hour2 = 0;
		} // End if

		if (clock24Hour2 == 10) {
			clock24Hour2 = 0;
			clock24Hour1 = 1;
		} // End if

		if (clock24Hour1 == 2 && clock24Hour2 == 4) {
			clock24Hour1 = 0;
			clock24Hour2 = 0;
		} // End if
	}

	if (minutes1 == 4 && minutes2 == 10) {
		minutes1 = 5;
		minutes2 = 0;
	} // End if
	
	if (minutes1 == 3 && minutes2 == 10) {
		minutes1 = 4;
		minutes2 = 0;
	} // End if
	
	if (minutes1 == 2 && minutes2 == 10) {
		minutes1 = 3;
		minutes2 = 0;
	} // End if

	if (minutes1 == 1 && minutes2 == 10) {
		minutes1 = 2;
		minutes2 = 0;
	} // End if

	if (minutes2 == 10) {
		minutes1 = 1;
		minutes2 = 0;
	} // End if

} // End addOneMinute

void addOneSecond(int& seconds1, int& seconds2, int& minutes1, int& minutes2,
	int& clock12Hour1, int& clock12Hour2, int& clock24Hour1, int& clock24Hour2, string& amPm) { // Function to add a second to the clocks
	
	if (seconds2 < 10) {
		seconds2 = seconds2 + 1;
	} // End if
	
	if (seconds1 == 5 && seconds2 == 10) {
		seconds1 = 0;
		seconds2 = 0;
		
		if (minutes2 < 10) {
			minutes2 = minutes2 + 1;
		} // End if
		
		if (minutes1 == 5 && minutes2 == 10) {
			minutes1 = 0;
			minutes2 = 0;
			
			if (clock12Hour2 < 10) {
				clock12Hour2 = clock12Hour2 + 1;
			} // End if
			
			if (clock12Hour2 == 10) {
				clock12Hour1 = 1;
				clock12Hour2 = 0;
			} // End if
			
			if (clock12Hour1 == 1 && clock12Hour2 == 3) {
				clock12Hour1 = 0;
				clock12Hour2 = 1;
			} // End if
			
			if (clock24Hour2 < 10) {
				clock24Hour2 = clock24Hour2 + 1;
			} // End if

			if (clock24Hour1 == 1 && clock24Hour2 == 10) {
				clock24Hour1 = 2;
				clock24Hour2 = 0;
			} // End if
			
			if (clock24Hour2 == 10) {
				clock24Hour2 = 0;
				clock24Hour1 = 1;
			} // End if
			
			if (clock24Hour1 == 2 && clock24Hour2 == 4) {
				clock24Hour1 = 0;
				clock24Hour2 = 0;
			} // End if

		}
		
		if (minutes1 == 4 && minutes2 == 10) {
			minutes1 = 5;
			minutes2 = 0;
		} // End if
		
		if (minutes1 == 3 && minutes2 == 10) {
			minutes1 = 4;
			minutes2 = 0;
		} // End if
		
		if (minutes1 == 2 && minutes2 == 10) {
			minutes1 = 3;
			minutes2 = 0;
		} // End if

		if (minutes1 == 1 && minutes2 == 10) {
			minutes1 = 2;
			minutes2 = 0;
		} // End if
		
		if (minutes2 == 10) {
			minutes1 = 1;
			minutes2 = 0;
		} // End if
	
	} // End if

	if (seconds1 == 4 && seconds2 == 10) {
		seconds1 = 5;
		seconds2 = 0;
	} // End if
	
	if (seconds1 == 3 && seconds2 == 10) {
		seconds1 = 4;
		seconds2 = 0;
	} // End if

	if (seconds1 == 2 && seconds2 == 10) {
		seconds1 = 3;
		seconds2 = 0;
	} // End if
	
	if (seconds1 == 1 && seconds2 == 10) {
		seconds1 = 2;
		seconds2 = 0;
	} // End if
	
	if (seconds2 == 10) {
		seconds1 = 1;
		seconds2 = 0;
	} // End if

} // End addOneSecond


int main() { // Main function of program
	
	// Variables for changing time
	int clock12Hour1 = 1;
	int clock12Hour2 = 2;
	int clock24Hour1 = 0;
	int clock24Hour2 = 0;
	int minutes1 = 5;
	int minutes2 = 9;
	int seconds1 = 5;
	int seconds2 = 9;	
	string amPm = "A M";
	bool menuChoice = "true";
	
	system("CLS"); // Clears the screen for use
	displayClocks(clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, minutes1, minutes2,
		seconds1, seconds2, amPm); // calls displayClocks

	printMenu(); // calls printMenu

	while (menuChoice) {

		switch (getMenuChoice()) {
		case 1: // addOneHour function call
			addOneHour(clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, amPm);
			system("CLS");
			displayClocks(clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, minutes1, minutes2, seconds1, seconds2, amPm);
			printMenu();
			break; // end case 1

		case 2: // addOneMinute function call
			addOneMinute(minutes1, minutes2, clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, amPm);
			system("CLS");
			displayClocks(clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, minutes1, minutes2, seconds1, seconds2, amPm);
			printMenu();
			break; // end case 2

		case 3: // addOne Second function call
			addOneSecond(seconds1, seconds2, minutes1, minutes2, clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, amPm);
			system("CLS");
			displayClocks(clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, minutes1, minutes2, seconds1, seconds2, amPm);
			printMenu();
			break; // end case 3

		case 4: // end program call
			cout << "Thank you for using the clock program." << endl;
			return 0; // end case 4

		default:
			break;
		} // End switch

	} // End while loop

	return 0;

} // End program