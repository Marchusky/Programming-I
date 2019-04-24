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
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"

ModuleWelcomeScreen::ModuleWelcomeScreen() {

	//Title intro

	intro.PushBack({ 0,0,360,240 });
	intro.PushBack({ 360, 0, 360, 240 });
	intro.PushBack({ 360, 0, 360, 240 });
	intro.PushBack({ 720, 0, 360, 240 });
	intro.PushBack({ 1080, 0, 360, 240 });
	intro.PushBack({ 1440, 0, 360, 240 });
	intro.PushBack({ 1440, 0, 360, 240 });
	intro.PushBack({ 1800, 0, 360, 240 });
	intro.PushBack({ 2160, 0, 360, 240 });
	intro.PushBack({ 2520, 0, 360, 240 });
	intro.PushBack({ 2520, 0, 360, 240 });
	intro.PushBack({ 2520, 0, 360, 240 });
	intro.PushBack({ 2880, 0, 360, 240 });
	intro.PushBack({ 3240, 0, 360, 240 });
	intro.PushBack({ 3600, 0, 360, 240 });
	intro.PushBack({ 3600, 0, 360, 240 });
	intro.PushBack({ 3600, 0, 360, 240 });
	intro.PushBack({ 3960, 0, 360, 240 });
	intro.PushBack({ 4320, 0, 360, 240 });
	intro.PushBack({ 4680, 0, 360, 240 });
	intro.PushBack({ 4680, 0, 360, 240 });
	intro.PushBack({ 4680, 0, 360, 240 });
	intro.PushBack({ 5040, 0, 360, 240 });
	intro.PushBack({ 5400, 0, 360, 240 });
	intro.PushBack({ 5760, 0, 360, 240 });
	intro.PushBack({ 5760, 0, 360, 240 });
	intro.PushBack({ 6120, 0, 360, 240 });
	intro.PushBack({ 6480, 0, 360, 240 });
	intro.PushBack({ 6840, 0, 360, 240 });
	intro.PushBack({ 6840, 0, 360, 240 });
	intro.PushBack({ 0, 240, 360, 240 });
	intro.PushBack({ 0, 240, 360, 240 });
	intro.PushBack({ 0, 240, 360, 240 });
	intro.PushBack({ 360, 240, 360, 240 });
	intro.PushBack({ 720, 240, 360, 240 });
	intro.PushBack({ 1080, 240, 360, 240 });
	intro.PushBack({ 1080, 240, 360, 240 });
	intro.PushBack({ 1080, 240, 360, 240 });
	intro.PushBack({ 1440, 240, 360, 240 });
	intro.PushBack({ 1800, 240, 360, 240 });
	intro.PushBack({ 2160, 240, 360, 240 });
	intro.PushBack({ 2160, 240, 360, 240 });
	intro.PushBack({ 2160, 240, 360, 240 });
	intro.PushBack({ 2520, 240, 360, 240 });
	intro.PushBack({ 2880, 240, 360, 240 });
	intro.PushBack({ 3240, 240, 360, 240 });
	intro.PushBack({ 3240, 240, 360, 240 });
	intro.PushBack({ 3240, 240, 360, 240 });
	intro.PushBack({ 3600, 240, 360, 240 });
	intro.PushBack({ 3960, 240, 360, 240 });
	intro.PushBack({ 4320, 240, 360, 240 });
	intro.PushBack({ 4320, 240, 360, 240 });
	intro.PushBack({ 4320, 240, 360, 240 });
	intro.PushBack({ 5760, 240, 360, 240 });
	intro.PushBack({ 5760, 240, 360, 240 });
	intro.PushBack({ 5760, 240, 360, 240 });
	intro.PushBack({ 6120, 240, 360, 240 });
	intro.PushBack({ 6480, 240, 360, 240 });
	intro.PushBack({ 6840, 240, 360, 240 });
	intro.PushBack({ 6840, 240, 360, 240 });
	intro.PushBack({ 6840, 240, 360, 240 });
	intro.PushBack({ 0, 480, 360, 240 });
	intro.PushBack({ 360, 480, 360, 240 });
	intro.PushBack({ 720, 480, 360, 240 });
	intro.PushBack({ 1080, 480, 360, 240 });
	intro.PushBack({ 1440, 480, 360, 240 });
	intro.PushBack({ 1800, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2160, 480, 360, 240 });
	intro.PushBack({ 2520, 480, 360, 240 });
	intro.PushBack({ 2880, 480, 360, 240 });
	intro.PushBack({ 2880, 480, 360, 240 });
	intro.PushBack({ 2880, 480, 360, 240 });
	intro.PushBack({ 2880, 480, 360, 240 });
	intro.PushBack({ 2880, 480, 360, 240 });
	intro.PushBack({ 2880, 480, 360, 240 });
	intro.PushBack({ 3240, 480, 360, 240 });
	intro.PushBack({ 3240, 480, 360, 240 });
	intro.PushBack({ 3240, 480, 360, 240 });
	intro.PushBack({ 3240, 480, 360, 240 });
	intro.PushBack({ 3240, 480, 360, 240 });
	intro.PushBack({ 3600, 480, 360, 240 });
	intro.PushBack({ 3960, 480, 360, 240 });
	intro.PushBack({ 3960, 480, 360, 240 });
	intro.PushBack({ 3960, 480, 360, 240 });
	intro.PushBack({ 3960, 480, 360, 240 });
	intro.PushBack({ 4320, 480, 360, 240 });
	intro.PushBack({ 4320, 480, 360, 240 });
	intro.PushBack({ 4320, 480, 360, 240 });
	intro.PushBack({ 4320, 480, 360, 240 });
	intro.PushBack({ 4320, 480, 360, 240 });
	intro.PushBack({ 4320, 480, 360, 240 });
	intro.PushBack({ 4320, 480, 360, 240 });
	intro.PushBack({ 5040, 480, 360, 240 });
	intro.PushBack({ 5040, 480, 360, 240 });
	intro.PushBack({ 5040, 480, 360, 240 });
	intro.PushBack({ 5040, 480, 360, 240 });
	intro.PushBack({ 5040, 480, 360, 240 });
	intro.PushBack({ 5040, 480, 360, 240 });
	intro.PushBack({ 5400, 480, 360, 240 });
	intro.PushBack({ 5400, 480, 360, 240 });
	intro.PushBack({ 5400, 480, 360, 240 });
	intro.PushBack({ 5760, 480, 360, 240 });
	intro.PushBack({ 5760, 480, 360, 240 });
	intro.PushBack({ 6120, 480, 360, 240 });
	intro.PushBack({ 6120, 480, 360, 240 });
	intro.PushBack({ 6120, 480, 360, 240 });
	intro.PushBack({ 6840, 480, 360, 240 });
	intro.PushBack({ 6840, 480, 360, 240 });
	intro.PushBack({ 6840, 480, 360, 240 });
	intro.PushBack({ 0, 720, 360, 240 });
	intro.PushBack({ 0, 720, 360, 240 });
	intro.PushBack({ 0, 720, 360, 240 });
	intro.PushBack({ 360, 720, 360, 240 });
	intro.PushBack({ 360, 720, 360, 240 });
	intro.PushBack({ 360, 720, 360, 240 });
	intro.PushBack({ 1080, 720, 360, 240 });
	intro.PushBack({ 1080, 720, 360, 240 });
	intro.PushBack({ 1080, 720, 360, 240 });
	intro.PushBack({ 1800, 720, 360, 240 });
	intro.PushBack({ 1800, 720, 360, 240 });
	intro.PushBack({ 1800, 720, 360, 240 });
	intro.PushBack({ 2520, 720, 360, 240 });
	intro.PushBack({ 2520, 720, 360, 240 });
	intro.PushBack({ 2520, 720, 360, 240 });
	intro.PushBack({ 3240, 720, 360, 240 });
	intro.PushBack({ 3240, 720, 360, 240 });
	intro.PushBack({ 3240, 720, 360, 240 });
	intro.PushBack({ 3960, 720, 360, 240 });
	intro.PushBack({ 3960, 720, 360, 240 });
	intro.PushBack({ 3960, 720, 360, 240 });
	intro.PushBack({ 4680, 720, 360, 240 });
	intro.PushBack({ 4680, 720, 360, 240 });
	intro.PushBack({ 4680, 720, 360, 240 });
	intro.PushBack({ 5040, 720, 360, 240 });
	intro.PushBack({ 5040, 720, 360, 240 });
	intro.PushBack({ 5040, 720, 360, 240 });
	intro.PushBack({ 5400, 720, 360, 240 });
	intro.PushBack({ 5400, 720, 360, 240 });
	intro.PushBack({ 5400, 720, 360, 240 });
	intro.PushBack({ 5760, 720, 360, 240 });
	intro.PushBack({ 5760, 720, 360, 240 });
	intro.PushBack({ 5760, 720, 360, 240 });
	intro.PushBack({ 6120, 720, 360, 240 });
	intro.PushBack({ 6120, 720, 360, 240 });
	intro.PushBack({ 6120, 720, 360, 240 });
	intro.PushBack({ 6480, 720, 360, 240 });
	intro.PushBack({ 6480, 720, 360, 240 });
	intro.PushBack({ 6480, 720, 360, 240 });

	for (int i = 0; i < MAX_FRAMES; i++) { intro.PushBack({ 6840, 720, 360, 240 }); intro.loop = true; }

	intro.speed = 0.35f;

	//Load UI Intro
	for (int i = 0; i < 40; i++) { UI_Title.PushBack({ 0 * i, 0 * i, 0, 0 }); }

	for (int j = 0; j < 200; j++) {

		for (int i = 0; i < 10; i++) { UI_Title.PushBack({ 0 * i, 0 * i, 360, 240 }); }
		for (int i = 0; i < 10; i++) { UI_Title.PushBack({ 0 * i, 0 * i, 0, 0 }); }
	}

	UI_Title.speed = 0.1f;
}

ModuleWelcomeScreen::~ModuleWelcomeScreen() {

}

bool ModuleWelcomeScreen::Start() {

	LOG("Loading welcome scene");

	welcomeScreen = App->textures->Load("Textures/WelcomeScreen/Intro_Title.png");
	UIWelcome = App->textures->Load("Textures/WelcomeScreen/Insert_UI.png");

	Mwelcome = App->audio->LoadMus("Audios/Music/Title.ogg");

	Mix_FadeInMusic(Mwelcome, -1, 1500);

	return true;
}

bool ModuleWelcomeScreen::CleanUp() {

	LOG("Unloading welcome scene");

	App->textures->Unload(welcomeScreen);
	App->textures->Unload(UIWelcome);
	App->audio->DeleteMusic(Mwelcome);
	this->Disable();

	return true;
}

update_status ModuleWelcomeScreen::Update() {


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {

		App->fade->FadeToBlack(this, App->characterSelect, 1.0f);
		Mix_FadeOutMusic(1500);
	}

	App->render->Blit(welcomeScreen, 120, 146, &(intro.GetCurrentFrame()), 0.75f);
	App->render->Blit(UIWelcome, 120, 150, &(UI_Title.GetCurrentFrame()), 0.75f);

	return UPDATE_CONTINUE;

}