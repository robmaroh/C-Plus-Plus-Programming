/*
 * Calculator.cpp
 *
 *  Date: 09/08/2022
 *  Author: Rob Marlatt
 */

#include <iostream> 

using namespace std;

int main() // Changed from type void to int since it returns an integer
{
	// char statement[100]; // Commented out unused variable
	double op1, op2; // Changed to double to get more exact answer
	char operation;
	char answer = 'Y';  /* Corrected char initialization by changing to 
						*  single quotes from double quotes, and added semicolon at end */
	
	while (answer == 'Y' || answer == 'y')  // Changed to 'y' or 'Y' to allow upper and lower case
	{
		if (answer == 'N' || answer == 'n') // Added program termination loop
		{
			cout << "Program Finished.";
			break;
		}

		cout << "Enter expression" << endl;
		cin >> op1 >> operation >> op2; // Changed order in which integers are inputted to match operations

		if (operation == '+') { /* Changed from double quotes to single quotes,
								 *Addedcurly braces to match if loop */

			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;  /* Changed direction of symbols to
																		* match cout operation */
		}

		if (operation == '-') { // Added curly braces to match if loop
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; /* Changed direction of symbols to
																	   * match cout operation  */
		}

		if (operation == '*') { // Added curly braces to match if loop
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; /* Added semicolon to complete
																	   * statement; changed operator to * */
		}

		if (operation == '/') { // Added curly braces to match if loop
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; // Changed operator to /
		}

		cout << "Do you wish to evaluate another expression?" << endl; // Removed space after ?
		cin >> answer;
	}
}





