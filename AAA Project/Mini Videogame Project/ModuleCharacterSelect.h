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

	SDL_Rect square1;
	int square1X = 211;
	int square1Y = 210;

	SDL_Rect square2;
	int square2X = 428;
	int square2Y = 212;
	
	SDL_Rect HaoSel1;
	SDL_Rect HaoLet1;
	SDL_Rect HaoBorn1;

	SDL_Rect HaoSel2;
	SDL_Rect HaoLet2;
	SDL_Rect HaoBorn2;

	Mix_Music* McharSelect = nullptr;
	Mix_Chunk* IntroHM = nullptr;
	Mix_Chunk* CharSel = nullptr;
	Mix_Chunk* pass_char = nullptr;

	bool player1Ready = false;
	bool player2Ready = false;
};
#endif // __MODULE_CHARACTER_SELECT_H__
