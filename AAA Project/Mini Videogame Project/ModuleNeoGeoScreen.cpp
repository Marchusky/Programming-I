#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleCharacterSelect.h"
#include "ModuleCongratsScreen.h"
#include "ModuleInput.h"
#include "ModuleHaohmaru.h"
#include "ModuleHaohmaru2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleNeoGeoScreen.h"
#include "ModuleAudio.h"

ModuleNeo::ModuleNeo() {

	IntroNeo.PushBack({ 0, 0 , 360, 240 });
	IntroNeo.PushBack({ 360, 0 , 360, 240 });
	IntroNeo.PushBack({ 0, 240 , 360, 240 });
	IntroNeo.PushBack({ 360, 240, 360, 240 });
	IntroNeo.PushBack({ 0, 720, 360, 240 });
	IntroNeo.PushBack({ 360, 720, 360, 240 });
	IntroNeo.PushBack({ 0, 960, 360, 240 });
	IntroNeo.PushBack({ 360, 960, 360, 240 });
	IntroNeo.PushBack({ 0, 1200, 360, 240 });
	IntroNeo.PushBack({ 360, 1200, 360, 240 });
	IntroNeo.PushBack({ 0, 1440, 360, 240 });
	IntroNeo.PushBack({ 360, 1440, 360, 240 });
	IntroNeo.PushBack({ 0, 1680, 360, 240 });
	IntroNeo.PushBack({ 360, 1680, 360, 240 });
	IntroNeo.PushBack({ 0, 1920, 360, 240 });
	IntroNeo.PushBack({ 360, 1920, 360, 240 });
	IntroNeo.PushBack({ 0, 2160, 360, 240 });
	IntroNeo.PushBack({ 360, 2160, 360, 240 });
	IntroNeo.PushBack({ 0, 2400, 360, 240 });
	IntroNeo.PushBack({ 360, 2400, 360, 240 });
	IntroNeo.PushBack({ 0, 2640, 360, 240 });
	IntroNeo.PushBack({ 360, 2640, 360, 240 });
	IntroNeo.PushBack({ 0, 2880, 360, 240 });
	IntroNeo.PushBack({ 360, 2880, 360, 240 });
	IntroNeo.PushBack({ 0, 3120, 360, 240 });
	IntroNeo.PushBack({ 360, 3120, 360, 240 });
	IntroNeo.PushBack({ 0, 3360, 360, 240 });
	IntroNeo.PushBack({ 360, 3360, 360, 240 });
	IntroNeo.PushBack({ 0, 3600, 360, 240 });
	IntroNeo.PushBack({ 360, 3600, 360, 240 });
	IntroNeo.PushBack({ 0, 3840, 360, 240 });
	IntroNeo.PushBack({ 360, 3840, 360, 240 });
	IntroNeo.PushBack({ 0, 4080, 360, 240 });
	IntroNeo.PushBack({ 360, 4080 , 360, 240 });
	IntroNeo.PushBack({ 0, 4320, 360, 240 });
	IntroNeo.PushBack({ 360, 4320, 360, 240 });
	IntroNeo.PushBack({ 0, 4560, 360, 240 });
	IntroNeo.PushBack({ 360, 4560, 360, 240 });
	IntroNeo.PushBack({ 0, 4800, 360, 240 });
	IntroNeo.PushBack({ 360,4800, 360, 240 });
	IntroNeo.PushBack({ 0, 5040, 360, 240 });
	IntroNeo.PushBack({ 360, 5040, 360, 240 });
	IntroNeo.PushBack({ 0, 5280, 360, 240 });
	IntroNeo.PushBack({ 360, 5280, 360, 240 });
	IntroNeo.PushBack({ 0, 5520, 360, 240 });
	IntroNeo.PushBack({ 360, 5520, 360, 240 });
	IntroNeo.PushBack({ 0, 5760, 360, 240 });
	IntroNeo.PushBack({ 360, 5760, 360, 240 });
	IntroNeo.PushBack({ 0, 6000, 360, 240 });
	IntroNeo.PushBack({ 360, 6000, 360, 240 });
	IntroNeo.PushBack({ 0, 6240, 360, 240 });
	IntroNeo.PushBack({ 360, 6240, 360, 240 });
	IntroNeo.PushBack({ 0, 6480, 360, 240 });
	IntroNeo.PushBack({ 360, 6480, 360, 240 });
	IntroNeo.PushBack({ 0, 6720, 360, 240 });
	IntroNeo.PushBack({ 360, 6720, 360, 240 });
	IntroNeo.PushBack({ 0, 6960, 360, 240 });
	IntroNeo.PushBack({ 360, 6960, 360, 240 });
	IntroNeo.PushBack({ 0, 7200, 360, 240 });
	IntroNeo.PushBack({ 360, 7200, 360, 240 });
	IntroNeo.PushBack({ 0, 7440, 360, 240 });
	IntroNeo.PushBack({ 360, 7440, 360, 240 });
	IntroNeo.PushBack({ 0, 7680, 360, 240 });
	IntroNeo.PushBack({ 360, 7680, 360, 240 });
	IntroNeo.PushBack({ 0, 7920, 360, 240 });
	IntroNeo.PushBack({ 360, 7920, 360, 240 });
	IntroNeo.PushBack({ 0, 8160, 360, 240 });
	IntroNeo.PushBack({ 360, 8160, 360, 240 });
	IntroNeo.PushBack({ 0, 8400, 360, 240 });
	IntroNeo.PushBack({ 360, 8400, 360, 240 });
	IntroNeo.PushBack({ 0, 8640, 360, 240 });
	IntroNeo.PushBack({ 360, 8640, 360, 240 });
	IntroNeo.PushBack({ 0, 8880, 360, 240 });
	IntroNeo.PushBack({ 360, 8880, 360, 240 });
	IntroNeo.PushBack({ 0, 9120, 360, 240 });
	IntroNeo.PushBack({ 360, 9120, 360, 240 });
	IntroNeo.PushBack({ 0, 9360, 360, 240 });
	IntroNeo.PushBack({ 360, 9360, 360, 240 });
	IntroNeo.PushBack({ 0, 9600, 360, 240 });
	IntroNeo.PushBack({ 360, 9600, 360, 240 });
	IntroNeo.PushBack({ 0, 9840, 360, 240 });
	IntroNeo.PushBack({ 360, 9840, 360, 240 });
	IntroNeo.PushBack({ 0, 10080, 360, 240 });
	IntroNeo.PushBack({ 360, 10080, 360, 240 });
	IntroNeo.PushBack({ 0, 10320, 360, 240 });
	IntroNeo.PushBack({ 360, 10320, 360, 240 });
	IntroNeo.PushBack({ 0, 10560, 360, 240 });
	IntroNeo.PushBack({ 360, 10560, 360, 240 });
	IntroNeo.PushBack({ 0, 10800, 360, 240 });
	IntroNeo.PushBack({ 360, 10800, 360, 240 });
	IntroNeo.loop = false;

	for (int i = 0; i < 3000; i++) { IntroNeo.PushBack({ 0, 11040, 360, 240 }); }

	IntroNeo.speed = 0.3f;

}

ModuleNeo::~ModuleNeo() {}

bool ModuleNeo::Start() {

	LOG("Loading NeoGeo intro");

	intro = App->textures->Load("Textures/Screens/Intro_NeoGeo.png");

	neo = App->audio->LoadMus("Audios/Music/NeoGeoIntro.ogg");

	time = SDL_GetTicks();

	Mix_FadeInMusic(neo, 0, 1500);

	return true;
}

bool ModuleNeo::CleanUp() {

	LOG("Unloading NeoGeo scene");

	App->textures->Unload(intro);

	App->audio->DeleteMusic(neo);

	time = 0;

	this->Disable();

	return true;
}

update_status ModuleNeo::Update() {

	App->render->Blit(intro, 120, 146, &(IntroNeo.GetCurrentFrame()), 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || (SDL_GetTicks() - time) > 7000) {

		App->fade->FadeToBlack(this, App->welcome, 2.0f);
		Mix_FadeOutMusic(2000);
	}

	//shortcut

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN) {

		App->fade->FadeToBlack(this, App->background, 1.0f);
		Mix_FadeOutMusic(2000);
	}

	return UPDATE_CONTINUE;
}