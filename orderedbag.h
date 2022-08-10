#pragma once

#ifndef ORDEREDBAG_H
#define	ORDEREDBAG_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "bag.h"
#include "orderedbag.h"

using namespace std;


class OrderedBag : public Bag {
public:
	OrderedBag();
	int remove_item();
};


#endif //ORDEREDBAG_H