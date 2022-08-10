#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "bag.h"
#include "orderedbag.h"

using namespace std;

void BagFunction(ifstream& fin, ofstream& fout, Bag& b1) {

    fout << "Welcome to Lab 9!\n";

    char uC;
    int in, out;
    bool a;

    while (fin >> uC) {
        switch (toupper(uC)) {
        case 'A':
            fin >> in;
            a = b1.add_item(in);
            if (a = true) {
                fout << "Item " << in << " was succesfully added.\n";
            }
            else {
                fout << "Item " << in << " was not added to the bag.\n";
            }
            break;
        case 'R':
            in = b1.remove_item();
            if (in > 1) {
                fout << in << " was removed from the bag\n";
            }
            else {
                fout << "Nothing was removed from the bag\n";
            }
            break;
        case 'D':
            fin >> in;
            a = b1.delete_item(in);
            if (a = true) {
                fout << "Item " << in << " was succesfully deleted.\n";
            }
            else {
                fout << "Item " << in << " was not deleted.\n";
            }
            break;
        case 'Z':
            fin >> in;
            a = b1.delete_all(in);
            if (a = true) {
                fout << "All instances of " << in << " were succesfully deleted.\n";
            }
            else {
                fout << "Nothing was not deleted.\n";
            }
            break;
        default:
            cout << "Please enter a valid letter\n";
            break;

        }
    }

    fout << "There are now " << b1.size() << " item(s) in the bag\n";
    fin.clear();
    fin.seekg(0);//clears and rewinds the file so the second time it is called it can be used
}

void BagFunction2(ifstream& fin, ofstream& fout, OrderedBag& b1) {

    fout << "Welcome to Lab 9!\n";

    char uC;
    int in, out;
    bool a;

    while (fin >> uC) {
        switch (toupper(uC)) {
        case 'A':
            fin >> in;
            a = b1.add_item(in);
            if (a = true) {
                fout << "Item " << in << " was succesfully added.\n";
            }
            else {
                fout << "Item " << in << " was not added to the bag.\n";
            }
            break;
        case 'R':
            in = b1.remove_item();
            if (in > 1) {
                fout << in << " was removed from the bag\n";
            }
            else {
                fout << "Nothing was removed from the bag\n";
            }
            break;
        case 'D':
            fin >> in;
            a = b1.delete_item(in);
            if (a = true) {
                fout << "Item " << in << " was succesfully deleted.\n";
            }
            else {
                fout << "Item " << in << " was not deleted.\n";
            }
            break;
        case 'Z':
            fin >> in;
            a = b1.delete_all(in);
            if (a = true) {
                fout << "All instances of " << in << " were succesfully deleted.\n";
            }
            else {
                fout << "Nothing was not deleted.\n";
            }
            break;
        default:
            cout << "Please enter a valid letter\n";
            break;

        }
    }

    fout << "There are now " << b1.size() << " item(s) in the bag\n";
  
}

int main()
{
    Bag b1;
    OrderedBag b2;
    ifstream fin;
    ofstream fout, ffout;//initialization

    fin.open("input.txt");
    fout.open("output.txt");
    ffout.open("input.txt");//opening files

    cout << "Welcome to Lab 9!\n";
    char c = 't';
    int t;

    while (toupper(c) != 'Q') {
        cout << "Please enter your choice:\nA. Add Item + (int)\nR. Remove Item\n D. Delete Item + (int)\nZ. Delete All + (int)\nQ. Quit\n";
        cin >> c;
        switch (toupper(c)) {
        case 'A':
            cin >> t;
            ffout << " a " << t;
            break;
        case 'R':
            ffout << " r ";
            break;
        case 'D':
            cin >> t;
            ffout << " d " << t;
            break;
        case 'Z':
            cin >> t;
            ffout << " z " << t;
            break;

        default:
            cout << "Please enter a valid letter\n";
            break;
        }
    }
    ffout.close();//file close

    BagFunction(fin, fout, b1); //bag
    BagFunction2(fin, fout, b2);//ordered bag
    
    fin.close();
    fout.close();//file close
}
