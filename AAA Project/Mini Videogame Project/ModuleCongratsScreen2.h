#ifndef __MODULE_CONGRATS_SCREEN2_H__
#define __MODULE_CONGRATS_SCREEN2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"


#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )

struct SDL_Texture;

class ModuleCongratsScreen2 : public Module {

public:
	ModuleCongratsScreen2();
	~ModuleCongratsScreen2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* congratScreen2 = nullptr;

	Mix_Music* Mcongrat2 = nullptr;
};


#endif //__MODULE_CONGRATS_SCREEN2_H__