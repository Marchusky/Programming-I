#pragma once
#include <iostream>
#include <string.h>
#include "Building.h"

using namespace std;

class Warehouse :public Building
{
private:
	int wood;
	int rocks;
	int wheat;
public:
	Warehouse(const char*name, int w, int r, int h) :Building(name) {
		wood = w;
		rocks = r;
		wheat = h;
	}
	int printResources() {
		cout << "Wood: " << wood << endl;
		cout << "Rocks: " << rocks << endl;
		cout << "Wheat: " << wheat << endl;
	}
};