#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleNeoGeoScreen.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleCharacterSelect.h"
#include "ModuleCongratsScreen.h"
#include "ModuleInput.h"
#include "ModuleHaohmaru.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"

ModuleCongratsScreen::ModuleCongratsScreen() {

}

ModuleCongratsScreen::~ModuleCongratsScreen() {

}

bool ModuleCongratsScreen::Start() {

	LOG("Loading character selection scene");

	congratScreen = App->textures->Load("Textures/Screens/WinScreen.png");

	Mcongrat = App->audio->LoadMus("Audios/Music/WinScreen.ogg");

	Mix_FadeInMusic(Mcongrat, 1, 4000);

	this->Enable();

	return true;
}

bool ModuleCongratsScreen::CleanUp() {

	LOG("Unloading selection scene");

	App->textures->Unload(congratScreen);

	App->audio->DeleteMusic(Mcongrat);

	App->player->Disable();

	this->Disable();

	return true;
}

update_status ModuleCongratsScreen::Update() {

	App->render->Blit(congratScreen, 160, 195, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {

		App->fade->FadeToBlack(this, App->neogeo, 2.0f);
		Mix_FadeOutMusic(2000);
	}

	return UPDATE_CONTINUE;
}