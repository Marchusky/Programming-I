//This is used to avoid the same header file being included multiple times within the same CPP file, so avoids redefinition errors.
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 17

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleWelcomeScreen;
class ModuleCharacterSelection;
class ModuleBackground;
class ModuleCongratsScreen;
class ModuleCongratsScreen2;
class ModuleFadeToBlack;
class ModuleAudio;
class ModuleHaohmaru;
class ModuleHaohmaru2;
class ModuleParticles;
class ModuleNeo;
class ModuleCollision;
class ModuleFonts;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleWelcomeScreen* welcome = nullptr;
	ModuleCharacterSelection* characterSelect = nullptr;
	ModuleBackground* background = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleAudio* audio = nullptr;
	ModuleCongratsScreen* congrats = nullptr;
	ModuleCongratsScreen2* congrats2 = nullptr;
	ModuleHaohmaru* player = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleHaohmaru2* player2 = nullptr;
	ModuleNeo* neogeo = nullptr;
	ModuleCollision* collision = nullptr;
	ModuleFonts* fonts = nullptr;

public:

	Application();
	~Application();

	bool Init();
	// As mentioned in Globals.h, Update is a updat_status type.
	update_status Update();
	bool CleanUp();

};

/*Extern is used to declare that the type Application has an external vinculation,
as this line of code is out of the class.*/
extern Application* App;

#endif // __APPLICATION_H__
