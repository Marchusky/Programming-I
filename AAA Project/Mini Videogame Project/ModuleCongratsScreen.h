#ifndef __MODULE_CONGRATS_SCREEN_H__
#define __MODULE_CONGRATS_SCREEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"


#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )


struct SDL_Texture;

class ModuleCongratsScreen : public Module {

public:
	ModuleCongratsScreen();
	~ModuleCongratsScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* congratScreen = nullptr;

	Mix_Music* Mcongrat = nullptr;
};

#endif //__MODULE_CONGRATS_SCREEN_H__