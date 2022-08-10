#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "fileheadding.h"

using namespace std;

int rf(string fn, vector<vector<double>> &p1, vector<vector<double>> &p2) {

    ifstream fin;
    fin.open("input.txt");//opens the file

    if (fin.is_open()) {//if the file is open
        while (!fin.eof()) {
            int i;
            
            p1.resize(p1.size() + 1);
            p2.resize(p2.size() + 1);//resizes the vector according to file size

            i = p2.size() - 1;

            p1.at(i).resize(3);
            p2.at(i).resize(3);

            fin >> p1.at(i).at(0) >> p1.at(i).at(1) >> p1.at(i).at(2);
            fin >> p2.at(i).at(0) >> p2.at(i).at(1) >> p2.at(i).at(2); // stores the values of the vector
        }
        
        fin.close();// closes the file
        return 1;
    }
    else {
       cout << "file is not open!" << endl;//if the file cannot be opened it displays a message to the user
      exit(1);
    }
}

int wf(string fn, vector<double>& d) {
    ofstream fout;
    fout.open(fn);// opens the file

    if (fout.fail()) {
        cout << "Output file opeing failed\n";//if the output file cannot be opened exit
        exit(1);
    }

    for (unsigned int i = 0; i < d.size(); i++) {//outputs the results in a file
        fout << "element " << i << " = " << d[i] << endl;
    }

    fout.close(); //closes the file

    return 1;
}

void gD(vector<vector<double>> p1, vector<vector<double>> p2, vector<double>& d) {// gets the values from the file and puts them in the distance forumla

    d.resize(p1.size());

    for (unsigned int i = 0; i < d.size(); i++) {
        d.at(i) = calcDistance(p1.at(i).at(0), p1.at(i).at(1), p1.at(i).at(2),
            p2.at(i).at(0), p2.at(i).at(1), p2.at(i).at(2));
    }
    
}

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2) {
    //math for the distance forumula
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
}

void sort(vector<double>& d) {

    for (unsigned int i = 0; i < d.size() - 1; i++) {
        for (unsigned int j = 0; j < d.size() - i - 1; j++) {//bubble sort function
            if (d.at(j) > d.at(j + 1)) {
                double temp = d.at(j);
                d.at(j) = d.at(j + 1);
                d.at(j + 1) = temp;
            }
        }
    }
}
