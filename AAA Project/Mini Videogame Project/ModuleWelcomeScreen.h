#ifndef __MODULE_WELCOME_SCREEN_H__
#define __MODULE_WELCOME_SCREEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )


struct SDL_Texture;

class ModuleWelcomeScreen : public Module {

public:
	ModuleWelcomeScreen();
	~ModuleWelcomeScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* welcomeScreen = nullptr;
	SDL_Texture* UIWelcome = nullptr;

	Animation intro;
	Animation UI_Title;
	Animation* current = nullptr;

	Mix_Music* Mwelcome = nullptr;
};

#endif //__MODULE_WELCOME_SCREEN_H__