#include "Application.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )

// Constrcutor where very effect is initialized as null
ModuleAudio::ModuleAudio() : Module(){

	for (uint i = 0; i < MAX_MUSIC; ++i)
		musics[i] = nullptr;

	for (uint i = 0; i < MAX_FX; ++i)
		fx[i] = nullptr;
}

ModuleAudio::~ModuleAudio(){
}

// Here we initalize the library
bool ModuleAudio::Init() {

	LOG("Init Sound Library");
	bool ret = true;

	//Initialize SDL_mixer 
	int flags = MIX_INIT_OGG;
	int initted = Mix_Init(flags);
	if (initted&flags != flags) {

		SDL_Log("Mix_Init: Failed to init required ogg and mod support!\n");
		SDL_Log("Mix_Init: %s\n", Mix_GetError());
		ret = false;
	}

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	return ret;
}

//update_status ModuleAudio::Update() {
//
//	if (!play)
//	{
//		Mix_PlayMusic(musics[0], -1);
//		play = true;
//	}
//
//	return UPDATE_CONTINUE;
//}

bool ModuleAudio::CleanUp() {

	for (uint i = 0; i < MAX_MUSIC; ++i)
		if (musics[i] != nullptr) {
			Mix_FreeMusic(musics[i]);
			musics[i] = nullptr;
		}

	for (uint i = 0; i < MAX_FX; ++i)
		if (fx[i] != nullptr) {
			Mix_FreeChunk(fx[i]);
			fx[i] = nullptr;
		}

	Mix_CloseAudio();
	Mix_Quit();
	return true;
}

Mix_Music* const ModuleAudio::LoadMus(const char *path)
{
	Mix_Music* soundtrack = nullptr;

	soundtrack = Mix_LoadMUS(path);
	if (soundtrack == nullptr)
	{
		LOG("Unable to find a path! SDL Error: %s\n", SDL_GetError());
	}

	return soundtrack;
}

Mix_Chunk* const ModuleAudio::LoadFX(const char* path) {

	Mix_Chunk* chunk = nullptr;

	chunk = Mix_LoadWAV(path);
	if (chunk == nullptr) {

		LOG("Unable to find a path! SDL Error: %s\n", SDL_GetError());
	}

	return chunk;
}

bool ModuleAudio::DeleteMusic(Mix_Music* music)
{
	bool ret = false;

	if (music != nullptr)
	{
		for (uint i = 0; i < MAX_MUSIC; ++i)
		{
			if (musics[i] == music)
			{
				Mix_FreeMusic(music);
				musics[i] = nullptr;
				ret = true;
				break;
			}
		}
	}
	return ret;
}

bool ModuleAudio::DeleteChunk(Mix_Chunk* chunk) {
	bool ret = false;

	if (chunk != nullptr)
	{
		for (uint i = 0; i < MAX_FX; ++i)
		{
			if (fx[i] == chunk)
			{
				Mix_FreeChunk(chunk);
				fx[i] = nullptr;
				ret = true;
				break;
			}
		}

	}
	return ret;
}