#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include "exam.h"

using namespace std;

int main()
{
    vector<double> tv, dvd, music, Totals, Medians, Modes;//initialization

    readFile(tv, dvd, music);//Reads the data and stores it into the vectors

    sort(tv);
    sort(dvd);
    sort(music);//sorts the vectors

    Medians.resize(3);
    Modes.resize(3);
    Totals.resize(3);//resizes the vectors


    Medians.at(1) = Median(tv);
    Medians.at(0) = Median(dvd);
    Medians.at(2) = Median(music);//produces the outputs for the medains if there is an error it will let the user know
    
    Modes.at(1) = Mean(tv);
    Modes.at(0) = Mean(dvd);
    Modes.at(2) = Mean(music);//produces the outputs for the means if there is an error it will let the user know

    Totals.at(1) = Total(tv);
    Totals.at(0) = Total(dvd);
    Totals.at(2) = Total(music);//produces the outputs for the total if there is an error it will let the user know

    writeFile(Totals, Medians, Modes);

}