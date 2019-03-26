#pragma once

#include "ModuleInput.h"
#include "ModuleLogic.h"
#include "ModuleRender.h"

class Application
{
private:
	Module *modules[3];

public:

	void start() {
		modules[0] = new ModuleInput("ModuleInput");
		modules[1] = new ModuleLogic("ModuleLogic");
		modules[2] = new ModuleRender("ModuleRender");

		for (int i = 0; i < 3; ++i) {
			modules[i]->start();
		}
	}

	void update() {
		for (int i = 0; i < 3; ++i) {
			modules[i]->update();
		}
	}

	void stop() {
		for (int i = 2; i >= 0; --i) {
			modules[i]->stop();
			delete modules[i];
		}
	}
};
