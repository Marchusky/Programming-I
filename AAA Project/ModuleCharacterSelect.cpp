#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleHaohmaru.h"
#include "ModuleNeoGeoScreen.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleCharacterSelect.h"
#include "ModuleCongratsScreen.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleCharacterSelection::ModuleCharacterSelection() {

}

ModuleCharacterSelection::~ModuleCharacterSelection() {

}

bool ModuleCharacterSelection::Start() {

	LOG("Loading character selection scene");

	charSelect = App->textures->Load("Textures/Screens/CharacterSelecting.png");
	Characters = App->textures->Load("Textures/UI/Character Selection.png");
	player1 = App->textures->Load("Textures/UI/Sprite_Sheet_UI_1.png");

	McharSelect = App->audio->LoadMus("Audios/Music/CharacterSelecting.ogg");

	IntroHM = App->audio->LoadFX("Audios/FX/Haohmaru/HaohmaruIntro.wav");
	CharSel = App->audio->LoadFX("Audios/FX/General/Character_Selecting.wav");

	Mix_FadeInMusic(McharSelect, -1, 00);

	time = SDL_GetTicks();

	return true;
}

bool ModuleCharacterSelection::CleanUp() {

	LOG("Unloading selection scene");

	this->Disable();

	time = 0;

	App->textures->Unload(charSelect);
	App->textures->Unload(Characters);
	App->textures->Unload(player1);

	App->audio->DeleteMusic(McharSelect);
	App->audio->DeleteChunk(IntroHM);
	App->audio->DeleteChunk(CharSel);

	return true;
}

update_status ModuleCharacterSelection::Update() {

	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN) {
		
		Mix_PlayChannel(-1, IntroHM, 0);
		Mix_PlayChannel(-1, CharSel, 0);
		
		App->player->Enable();

		Mix_VolumeChunk(IntroHM, MIX_MAX_VOLUME / 2);
		Mix_VolumeChunk(CharSel, MIX_MAX_VOLUME / 3);

		if ((SDL_GetTicks() - time) > 500) {

			Mix_VolumeChunk(IntroHM, MIX_MAX_VOLUME / 2);

			App->fade->FadeToBlack(this, App->background, 3.0f);

			Mix_FadeOutMusic(1500);

		}
	}


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {

		Mix_PlayChannel(-1, IntroHM, 0);

		Mix_VolumeChunk(IntroHM, MIX_MAX_VOLUME / 2);

		App->fade->FadeToBlack(this, App->background, 1.5f);

		Mix_FadeOutMusic(1500);
	}

	App->render->Blit(charSelect, 160, 195, NULL);
	App->render->Blit(Characters, 210, 210, NULL);
	App->render->Blit(player1, 210, 210, NULL);

	return UPDATE_CONTINUE;
}