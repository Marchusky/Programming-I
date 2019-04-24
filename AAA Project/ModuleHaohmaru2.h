#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )

struct SDL_Texture;

class ModuleHaohmaru2 : public Module
{
public:
	ModuleHaohmaru2();
	~ModuleHaohmaru2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	
	Animation* current_animation = nullptr;
	Animation idle;
	iPoint position;

	Mix_Chunk* CharacterJump = nullptr;
	Mix_Chunk* CharacterGround = nullptr;

	//player collider
	Collider* player2Collider;

};

#endif