#pragma once

void readBOOKS(vector <LibraryBook> &Books, string fn);
void readISBN(vector <LibraryBook> &Books, string fn);
int compareISBN(string isbn, vector <LibraryBook> Books);
void CheckInOut(vector <LibraryBook> & Books, int index); 
void writeFile(vector <LibraryBook> Books, string fn);