#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include "librarybook.h"
#include "file.h"

using namespace std;

void readBOOKS(vector <LibraryBook> & Books, string fn ) {

	ifstream fin;
	fin.open(fn);//opens the file

	string name, author, isbn;
	int i = 0;
	//initialization

	if (fin.is_open()) {

		while (!fin.eof()) {
							
			getline(fin, name);// reads the strings
			getline(fin, author);
			getline(fin, isbn);
			Books.push_back(LibraryBook(name, author, isbn));//stores the strings
		}
		fin.close(); //closes the file
	}
	else {
		cout << "There was an error opening " << fn << endl;//if there was an error opening the file 
		exit(1);
	}
}

void readISBN(vector <LibraryBook> &Books, string fn) {

	ifstream fin;
	fin.open(fn);//opens the file

	string isbn;
	int index;

	if (fin.is_open()) {

		while (!fin.eof()) {
			getline(fin, isbn);//gets isbn from the file
			index = compareISBN(isbn, Books);//compares the isbn and returns the index
			CheckInOut(Books, index);//checks in or out the book
		}
		fin.close(); //closes the file
	}
	else {
		cout << "There was an error opening " << fn << endl;//if there was an error opening the file 
		exit(1);
	}


}

int compareISBN(string isbn, vector <LibraryBook>  Books) {

	for (unsigned int i = 0; i < Books.size(); i++) {
		if (Books[i].getISBN() == isbn) {//finds the matching isbn and returns the index
			return i;
		}
	}
	return 0;
}

void CheckInOut(vector <LibraryBook> &Books, int index) {

	if (Books[index].isCheckedOut() == false) {//checks if the book is checked in or out and changes the bool
		Books[index].checkOut();
		cout << "Check out\n";
	}
	else {
		Books[index].checkIn();
		cout << "Check in\n";
	}
}


void writeFile(vector <LibraryBook> Books, string fn) {

	ofstream fout;
	fout.open(fn);

	if (fout.is_open()) {

		fout << "\"Title\",\"Author\",\"ISBN\"\n";

		for (unsigned int i = 0; i < Books.size(); i++) {
			if (Books[i].isCheckedOut() == true) {//finds the matching isbn and returns the index
				
				fout << "\"" << Books[i].getTitle() << "\"," << "\"" << Books[i].getAuthor() << "\",\n"
					<< "\"" << Books[i].getISBN() << "\"\n";
			}
		}
	}
	else {
		cout << "There was an error opening output.txt\n";//if there was an error opening the file 
		exit(1);
	}

	fout.close();

}