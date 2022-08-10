#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

double GetMiles() {

	double x;

	try {

		string str = "Invalid input received, you must enter a decimal number. ";

		cout << "Enter the number of miles: ";
		cin >> x;
		cout << endl;

		if (cin.fail()) {
			// Clear error state
			cin.clear();
			// Ignore characters in stream until newline
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw str;

		}

			if (x >= 0) {//if x is positive then return
				return x;
			}
						//if negative throw x
			throw x;

	}
	catch (double e) {
		
		cout << "Miles cannot be less than 0.\n\n";
		return -1;
	}
	catch (string s) {
		cout << s << endl << endl;
		return -1;
	}
}

double GetGallons() {

	double x;

	try {

		string str = "Invalid input received, you must enter a decimal number.";

		cout << "Enter the number of gallons: ";
		cin >> x;
		cout << endl;

		if (cin.fail()) {
			// Clear error state
			cin.clear();
			// Ignore characters in stream until newline
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw str;

		}

		if (x >= 0) {//if x is positive then return
			return x;
		}
		//if negative throw x
		throw x;

	}
	catch (double e) {

		cout << "Gallons cannot be less than 0.\n\n";
		return -1;
	}
	catch (string s) {
		cout << s << endl << endl;
		return -1;
	}
}

double GetMPG(vector<double> miles, vector<double> gallons) {

	string str = "No values recorded MPG is nan.";
	double totalm = 0, totalg = 0;

	try {
		if (miles.size() == 0) {//if there was noting in the vector it throws an error but I already made sure that there would be something in the vector :)
			throw str;
		}
		for (unsigned int j = 0; j < miles.size(); j++) {//adds total miles and gallons
			totalm += miles.at(j);
			totalg += gallons.at(j);
		}
		return totalm / totalg;
	}
	catch (string strung) {
		cout << strung << endl;//disiplays error message
	}
}