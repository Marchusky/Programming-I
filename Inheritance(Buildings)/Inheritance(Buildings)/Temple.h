#pragma once
#include <iostream>
#include <string.h>
#include "Building.h"

using namespace std;


class Temple :public Building
{
private:
	int floors;
	int inhabitants;
	int servants;
public:
	Temple(const char *name, int f, int i, int s) :Building(name) {
		floors = f;
		inhabitants = i;
		servants = s;
	}
	int printHouse() {
		cout << "Floors: " << floors << endl;
		cout << "Inhabitants: " << inhabitants << endl;
		cout << "Servants: " << servants << endl;
	}

};