#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleCharacterSelect.h"
#include "ModuleNeoGeoScreen.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleAudio.h"
#include "ModuleHaohmaru.h"
#include "ModuleHaohmaru2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCongratsScreen.h"
#include "ModuleCongratsScreen2.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFonts.h"

Application::Application() {

	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = audio = new ModuleAudio();
	modules[4] = textures = new ModuleTextures();
	modules[5] = neogeo = new ModuleNeo();
	modules[6] = characterSelect = new ModuleCharacterSelection();
	modules[7] = welcome = new ModuleWelcomeScreen();
	modules[8] = background = new ModuleBackground();
	modules[9] = player = new ModuleHaohmaru();
	modules[10] = player2 = new ModuleHaohmaru2();
	modules[11] = congrats = new ModuleCongratsScreen();
	modules[12] = congrats2 = new ModuleCongratsScreen2();
	modules[13] = particles = new ModuleParticles();
	modules[14] = fonts = new ModuleFonts();
	modules[15] = collision = new ModuleCollision();
	modules[16] = fade = new ModuleFadeToBlack();
	
}

Application::~Application() {

	for (int i = NUM_MODULES - 1; i >= 0; i--) {

		delete modules[i];
	}
}

bool Application::Init() {

	bool ret = true;

	welcome->Disable();
	background->Disable();
	characterSelect->Disable();
	congrats->Disable();
	congrats2->Disable();
	player->Disable();
	player2->Disable();

	for (int i = 0; i < NUM_MODULES && ret == true; i++) {

		ret = modules[i]->Init();
	}
	for (int i = 0; i < NUM_MODULES && ret == true; ++i) {

		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;
	}
		
	return ret;
}

update_status Application::Update() {

	update_status ret = UPDATE_CONTINUE;


	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp() {

	bool ret = true;
	for (int i = NUM_MODULES - 1; i <= 0 && ret == true; i--) {

		ret = modules[i]->CleanUp();
	}

	return ret;
}