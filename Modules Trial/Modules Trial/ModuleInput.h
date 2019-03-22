#pragma once

#include "Module.h"
#include <iostream>

class ModuleInput : public Module
{
public:
	ModuleInput(const char *pname) : Module(pname) { }

	void start() override { std::cout << name << " - start()" << std::endl; }
	void update() override { std::cout << name << " - update()" << std::endl; }
	void stop() override { std::cout << name << " - stop()" << std::endl; }
};





