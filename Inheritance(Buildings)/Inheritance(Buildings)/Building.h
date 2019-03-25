#pragma once
#include <iostream>
#include <string.h>


class Building {
protected:
	char name[24];
public:
	Building(const char *pname)
	{
		strcpy_s(name, pname);
	}
	const char *getName()const { return name; }
};