#ifndef __MODULE_CHARACTER_SELECT_H__
#define __MODULE_CHARACTER_SELECT_H__
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"


#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )


struct SDL_Texture;

class ModuleCharacterSelection : public Module {

public:
	ModuleCharacterSelection();
	~ModuleCharacterSelection();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* charSelect = nullptr;
	SDL_Texture* Characters = nullptr;
	SDL_Texture* player1 = nullptr;

	int time;

	Mix_Music* McharSelect = nullptr;
	Mix_Chunk* IntroHM = nullptr;
	Mix_Chunk* CharSel = nullptr;
};
#endif // __MODULE_CHARACTER_SELECT_H__
