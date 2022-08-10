#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include "librarybook.h"
#include "file.h"

using namespace std;    

int main()
{
    vector <LibraryBook>  Books;//initilization of the books

    readBOOKS(Books, "books.txt");// reads in the books

    readISBN(Books, "isbns.txt");//checks in and out the books

    writeFile(Books, "checkedout.csv"); //makes a file for checked out books

}