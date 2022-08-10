#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "fileheadding.h"

using namespace std;

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2);
int rf(string fn, vector<vector<double>> &p1, vector<vector<double>> &p2);
int wf(string fn, vector<double> &d);
void gD(vector<vector<double>> p1, vector<vector<double>> p2, vector<double> &d);
void sort(vector<double>& d);