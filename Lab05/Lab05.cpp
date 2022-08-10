#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "fileheadding.h"

using namespace std;

int main()
{
    vector<vector<double>> p1, p2;//initialization
    vector<double> d;

    rf("input.txt", p1, p2);//if we can read the file

    gD(p1, p2, d);//get the distance 
  
    wf("output.txt", d);// output the distance into a file
    
    sort(d);//sort the distances

    wf("output_sorted.txt", d);//writes the sorted scores into a file 
    
}

