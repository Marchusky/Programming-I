#ifndef __MODULE_NEOGEO_H__
#define __MODULE_NEOGEO_H__

#endif // __MODULE_NEOGEO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )

struct SDL_Texture;

class ModuleNeo : public Module {

public:
	ModuleNeo();
	~ModuleNeo();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* intro = nullptr;

	Animation IntroNeo;
	int time;

	Mix_Music* neo = nullptr;

};