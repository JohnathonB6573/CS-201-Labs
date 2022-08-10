#include <iostream> 
#include <string>
#include <vector>
#include "librarybook.h"
#include "file.h"

using namespace std;

std:: string LibraryBook :: getTitle() {// returns Title
	return Title;
}

std::string LibraryBook::getAuthor() {//returns Author
	return Author;
}

std::string LibraryBook:: getISBN() {//returns ISBN
	return ISBN;
}

LibraryBook::LibraryBook() {//sets the default constructor
	Title = " ";
	Author = " ";
	ISBN = " ";
	CheckedOut = false;
}

LibraryBook::LibraryBook(std::string title, std::string author, std::string isbn) {//sets consturctor to the inputs
	Title = title;
	Author = author;
	ISBN = isbn;
	CheckedOut = false;
}

void LibraryBook:: checkOut() {
	CheckedOut = true;//checks out the book
}

void LibraryBook:: checkIn() {
	CheckedOut = false;//checks in the book
}

bool LibraryBook:: isCheckedOut() {
	return CheckedOut;//tells if the book is checked in or checked out 
}

