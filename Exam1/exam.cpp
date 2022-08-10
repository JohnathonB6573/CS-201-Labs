#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <iomanip>
#include <sstream>
#include "exam.h"

using namespace std;

void readFile(vector<double> &tv, vector<double> &dvd, vector<double> &music) {

	ifstream fin;
	fin.open("input-2.txt");//opens the file

	string currType;
	double currVal;
	int k = 0, j = 0, i = 0; //initialization

	if (fin.is_open()) {

		while (!fin.eof()) {

			fin >> currType;//finds out what type it is 
			fin >> currVal;

			if (currType == "TV") {//stores the information
				tv.resize(i + 1);
				tv.at(i) = currVal;
				i++;
			}
			if (currType == "DVD") {
				dvd.resize(j + 1);
				dvd.at(j) = currVal;
				j++;
			}
			if (currType == "MUSIC") {
				music.resize(k + 1);
				music.at(k) = currVal;
				k++;
			}

		}
		fin.close(); //closes the file
	}
	else {
		cout << "There was an error opening input-2.txt\n";//if there was an error opening the file 
		exit(1);
	}
}

void sort(vector<double> &c) {

	for (unsigned int i = 0; i < c.size() - 1; i++) {
		for (unsigned int j = 0; j < c.size() - i - 1; j++) {//bubble sort function
			if (c.at(j) > c.at(j + 1)) {
				double temp = c.at(j);
				c.at(j) = c.at(j + 1);
				c.at(j + 1) = temp;
			}
		}
	}
}

double Median(vector<double> c){

	int i;
	string error = "Error: TYPE_NAN for \n";

	try {
		
		if (c.size() == 0) {
			throw error;
		}
		if (c.size() % 2 == 0) {
			i = (c.size() / 2);
			return (c[i] + c[i + 1]) / 2;// if the size is even do the average of the two middle numbers
		}
		else {
			i = (c.size() / 2);// if the size is odd return the middle number
			return c[i];
		}
		
	}
	catch (string err) {//return the error to main
		return -1;
	}
}

double Mean(vector<double> c) {
	
	double total = 0;
	string error = "Error: TYPE_NAN for \n";
	
	try {
	
		if (c.size() == 0) {//if there is an error
			throw error;
		}
		else{

		for (unsigned int i = 0; i < c.size(); i++) {
			total += c.at(i);
		}

		total = total / c.size();
		return total;
	}
		
	}
	catch (string err) {//return the error to main
		return -1;
	}
}

double Total(vector<double> c) {

	double total = 0;

	for (unsigned int i = 0; i < c.size(); i++) {//adds the total and returns the total
		total += c.at(i);
	}

	return total;

}

void writeFile(vector<double> t, vector<double> med, vector<double> mode){

	ofstream fout;
	fout.open("output.txt");

	if (fout.is_open()) {

		fout << left << setw(7) << "       " << setw(10) << "Total" << setw(10) << "Median" << setw(10) << "Mean" << endl;
		fout << left << setw(7) << "DVD" << setw(10) << s(t.at(0)) << setw(10) << s(med.at(0)) << setw(10) << s(mode.at(0)) << endl;
		fout << left << setw(7) << "TV" << setw(10) << s(t.at(1)) << setw(10) << s(med.at(1)) << setw(10) << s(mode.at(1)) << endl;
		fout << left << setw(7) << "MUSIC" << setw(10) << s(t.at(2)) << setw(10) << s(med.at(2)) << setw(10) << s(mode.at(2)) << endl;
	}
	else {
		cout << "There was an error opening output.txt\n";//if there was an error opening the file 
		exit(1);
	}

	fout.close();

}

string s(double d) {

	string temp;

	if (d == -1) {//if the value is -1 then print nan
		return "nan";
	}
	else {// otherwise print the string set to 3 precision
		
		stringstream stream;
		// Set precision level to 3
		stream.precision(3);
		stream << fixed;

		// Convert double to string
		stream << d;
		string str = stream.str();
		return str;
	} 
}