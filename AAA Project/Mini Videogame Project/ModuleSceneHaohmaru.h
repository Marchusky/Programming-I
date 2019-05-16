#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )

struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* lifebar = nullptr;
	SDL_Texture* UI = nullptr;
	SDL_Rect Rbar;
	SDL_Rect Lbar;
	SDL_Rect IRbar;
	SDL_Rect ILbar;
	SDL_Rect HaoBar;
	SDL_Rect Points;
	SDL_Rect KO;

	Animation background;

	Mix_Music* HaohmaruStage = nullptr;

	Mix_Chunk* BeforeBattle = nullptr;

	int timeAudio1;
};

#endif // __MODULE_CHARACTER_SELECT_H__