#include <iostream>
#include "Globals.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleNeoGeoScreen.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleCharacterSelect.h"
#include "ModuleCongratsScreen.h"
#include "ModuleCongratsScreen2.h"
#include "ModuleHaohmaru.h"
#include "ModuleHaohmaru2.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModuleCollision.h"

ModuleBackground::ModuleBackground()
{
	for (int y = 0; y < 24; y++) {

		background.PushBack({ 0, 416 * y, 640, 416 });
	}

	background.speed = 0.05f;

}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics = App->textures->Load("Textures/Screens/haohmaru_scene.png");

	font = App->fonts->Load("Textures/Sprite_Sheet_UI_1.png", "HAOHMARU", 1);

	HaohmaruStage = App->audio->LoadMus("Audios/Music/HaohmaruScene.ogg");

	BeforeBattle = App->audio->LoadFX("Audios/FX/Judge/Merged_Befor_First_Begin.wav");

	Mix_FadeInMusic(HaohmaruStage, -1, 3000);

	App->player->Enable();
	App->player2->Enable();

	Mix_PlayChannel(-1, BeforeBattle, 0);

	App->particles->Enable();
	App->collision->Enable();

	return ret;
}



bool ModuleBackground::CleanUp() {

	bool ret = true;

	App->textures->Unload(graphics);
	App->audio->DeleteMusic(HaohmaruStage);
	App->audio->DeleteChunk(BeforeBattle);
	App->player->Disable();
	App->player2->Disable();
	App->collision->Disable();

	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	
	// Draw everything 

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN) {

		App->fade->FadeToBlack(this, App->congrats, 1.5f);
		Mix_FadeOutMusic(1500);
	}

	if (App->input->keyboard[SDL_SCANCODE_2] == KEY_STATE::KEY_DOWN) {

		App->fade->FadeToBlack(this, App->congrats2, 1.5f);
		Mix_FadeOutMusic(1500);
	}

	App->render->Blit(graphics, 0, 0, &(background.GetCurrentFrame()), 0.75f);
	sprintf_s(text1, 8, "%7d", font);
	App->fonts->BlitText(100, 0, font, text1);

	return UPDATE_CONTINUE;
}