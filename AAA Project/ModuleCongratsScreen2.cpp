#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleNeoGeoScreen.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleCharacterSelect.h"
#include "ModuleCongratsScreen.h"
#include "ModuleCongratsScreen2.h"
#include "ModuleInput.h"
#include "ModuleHaohmaru.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"

ModuleCongratsScreen2::ModuleCongratsScreen2() {

}

ModuleCongratsScreen2::~ModuleCongratsScreen2() {

}

bool ModuleCongratsScreen2::Start() {

	LOG("Loading character selection scene");

	congratScreen2 = App->textures->Load("Textures/Screens/WinScreen2.png");

	Mcongrat2 = App->audio->LoadMus("Audios/Music/WinScreen.ogg");

	Mix_FadeInMusic(Mcongrat2, 1, 4000);

	this->Enable();

	return true;
}

bool ModuleCongratsScreen2::CleanUp() {

	LOG("Unloading selection scene");

	App->textures->Unload(congratScreen2);

	App->player->Disable();

	this->Disable();

	return true;
}

update_status ModuleCongratsScreen2::Update() {

	App->render->Blit(congratScreen2, 160, 195, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {

		App->fade->FadeToBlack(this, App->neogeo, 2.0f);
		Mix_FadeOutMusic(2000);
	}

	return UPDATE_CONTINUE;
}