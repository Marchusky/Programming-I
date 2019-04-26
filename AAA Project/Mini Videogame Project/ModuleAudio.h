#ifndef __ModuleAudio_H__
#define __ModulesAudio_H__

#include "Module.h"
#include "Globals.h"

// We define music and FX as arrays
#define MAX_MUSIC 10
#define MAX_FX 30

struct Mix_Music;
struct Mix_Chunk;

class ModuleAudio : public Module {

public:

	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();
	/*update_status Update();*/

	// We create two functions that load a path
	Mix_Music* const LoadMus(const char*  path);
	Mix_Chunk* const LoadFX(const char* path);

public: 

	/*bool play = true;*/

	Mix_Music* musics[MAX_MUSIC];
	Mix_Chunk* fx[MAX_FX];

	// We create other functions to unload the music
	bool DeleteMusic(Mix_Music* music);
	bool DeleteChunk(Mix_Chunk* fx);
};

#endif // __ModuleAudio_H__


