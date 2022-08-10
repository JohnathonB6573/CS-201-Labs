#pragma once

#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "bag.h"

using namespace std;

class Bag {
protected :
	vector<int> n;
public : 
	Bag(); 
	bool add_item(int nx);
	int remove_item();
	bool delete_item(const int &nx);
	bool delete_all(const int& nx);
	int size() const;
	void clear(); 
	void BagFunction(ifstream &fin, ofstream &fout, Bag& b1);
};


#endif // BAG_H
