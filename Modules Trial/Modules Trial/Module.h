#pragma once

#include <string.h>

class Module
{
public:
	char name[32];

	Module(const char *pname)
	{
		strcpy_s(name, pname);
	}

	virtual ~Module() { }

	virtual void start() { }
	virtual void update() { }
	virtual void stop() { }
};
