/*	This program is designed to open a text file FarenheitTemperature.txt
*		and read the 6 City Names and their average yearly temperatures inside,
*		and then close the file. Then it will convert these temperatures to
		Celsius and write a new file, CelsiusTemperature.txt, with that information,
		and then close that file.

	Rob Marlatt
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() { // Main program to convert Farenheit to Celsius
	ifstream inFS; // Allows file input
	ofstream outFS; // Allows file output
	string cityName; // City name from file
	int tempFarenheit; // Temperature from file
	double tempCelsius; // Double for Celcius to allow decimal
		
	cout << "Attempting to open FarenheitTemperature.txt..." << endl;

	inFS.open("FarenheitTemperature.txt"); // Opening .txt file

	outFS.open("CelsiusTemperature.txt"); // Creating output file
	if (!inFS.is_open()) { // Error check if file not open
		
		cout << "Could not open FarenheitTemperature.txt." << endl;
		cout << "Ending program." << endl;

		return 1; // End with error
	}

	while (inFS >> cityName >> tempFarenheit) { // Convert Farenheit to Celsius
		
		tempCelsius = (tempFarenheit - 32.0) * (5.0 / 9.0); // Formula to convert temps
		outFS << fixed << setprecision(2); // Set precision to 2 digits after decimal point
		outFS << cityName << " " << tempCelsius << endl; // Send output to CelsiusTemperature.txt
	}

	inFS.close(); // Closing TemperatureFarenheit.txt
	outFS.close(); // Closing TemperatureCelsius.txt

	return 0; // End without error

}