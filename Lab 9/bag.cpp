#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "bag.h"
#include "orderedbag.h"

using namespace std;

Bag :: Bag() {//default constructor
	n = {};
}

bool Bag :: add_item(int nx) {
	int s = n.size();
	n.push_back(nx);//adds the element to the vector
	if (n.size() == s) {
		return false;//if its the original size return  false 
	}
	else {
		return true;//else return true
	}
}

int Bag::remove_item() {
	int s = n.size();//returns an item in the middle of the vector
	if (s > 1) {
		int j = (n.at(s / 2));
		n.erase(n.begin() + (s / 2));
        return j;
    }
	else {
		return -1;
	}
}

bool Bag::delete_item(const int& nx) {
	for (unsigned int i = 0; i < n.size(); i++) {
		if (n.at(i) == nx) {
			n.erase(n.begin() + i);//deletes an item that matches the input
			return true;
		}
	}
	return false;
}

bool Bag::delete_all(const int& nx) {
	int s = n.size();
	for (unsigned int i = 0; i < n.size(); i++) {//deletes all items that match the input
		if (n.at(i) == nx) {
			n.erase(n.begin() + i);
		}
	}
	if (n.size() == s) {//if its the original size return false 
		return false;
	}
	else {
		return true;//else return true
	}
}

int Bag::size() const {
	return n.size();//returns the size of the bag
}

void Bag::clear() {
	for (unsigned int i = 0; i < n.size(); i++) {//deletes all items
			n.erase(n.begin() + i); // 
	}
}


