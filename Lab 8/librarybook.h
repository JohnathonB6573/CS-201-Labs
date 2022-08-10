#pragma once

#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class LibraryBook {
private:
	std::string Title;
	std::string Author;
	std::string ISBN;
	bool CheckedOut;
public :
	LibraryBook();
	LibraryBook(std::string title, std::string author, std:: string isbn);
	std::string getTitle();
	std::string getAuthor();
	std::string getISBN();
	void checkOut();
	void checkIn();
	bool isCheckedOut();
};


