#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "exam.h"

using namespace std;

void readFile(vector<double> &tv, vector<double> &dvd, vector<double> &music);
double Median(vector<double> c);
void sort(vector<double> &c);
double Mean(vector<double> c);
void writeFile(vector<double> t, vector<double> med, vector<double> mode);
double Total(vector<double> c);
string s(double d);