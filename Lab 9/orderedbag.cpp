#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "bag.h"
#include "orderedbag.h"

using namespace std;

OrderedBag :: OrderedBag() {
	n = {};
}
int OrderedBag::remove_item() {
	int k = 10000;
	for (unsigned int i = 0; i < n.size(); i++) {
		if (n.at(i) < k) {
			k = n.at(i);//makes k the smallest value 
		}
	}
	for (unsigned int j = 0; j < n.size(); j++) {
		if (n.at(j) == k) {
			n.erase(n.begin() + j);//deletes the item out of the vector and returns the value of k
			return k;
		}
	}
	return -1;
}