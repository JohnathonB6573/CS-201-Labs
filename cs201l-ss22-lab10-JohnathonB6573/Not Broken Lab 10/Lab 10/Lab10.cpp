// Johnathon Brumdield
// 07/14/22
// Lab 10

#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// Input/output files
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Throw error if can't open input file
	if (!fin)
	{
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}

	// While there's data in the file, read in a line and calculate it
	while (fin.good())
	{
		// Read in two fractions and the operator to perform
		Fraction fract1, fract2;
		char oper;
		fin >> fract1 >> oper >> fract2;
		

		// Print out original functions read in
		fout << fract1 << " " << oper << " " << fract2 << " = ";
		
		// Do math on them
		switch (oper)
		{
		case '+':
			fout << fract1 + fract2 << endl;
			break;

		case '-':
			fout << fract1 - fract2 << endl;
			break;

		case '*':
			fout << fract1 * fract2 << endl;
			break;

		case '/':
			fout << fract1 / fract2 << endl;
			break;

		case '=':
			if (fract1 == fract2)
				fout << "True" << endl;
			else
				fout << "False" << endl;
			break;

		}
	}

	// Close files
	fin.close();
	fout.close();

	// Quit without error
	return 0;

}