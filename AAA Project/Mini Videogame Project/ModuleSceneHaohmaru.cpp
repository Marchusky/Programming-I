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
	for (int y = 0; y < 8; y++) {

		background.PushBack({ 0, 416 * y, 638, 416 });
	}
	for (int y = 0; y < 8; y++) {

		background.PushBack({ 638, 416 * y, 640, 416 });
	}

	background.PushBack({ 1275, 415, 640, 416 });

	for (int y = 1; y < 7; y++) {

		background.PushBack({ 1275, 415 + 416 * y, 640, 416 });
	}

	background.speed = 0.05f;

	//Lifebars//
	Rbar.x = 0;
	Rbar.y = 97;
	Rbar.w = 134;
	Rbar.h = 15;

	Lbar.x = 0;
	Lbar.y = 113;
	Lbar.w = 134;
	Lbar.h = 15;
	
	IRbar.x = ILbar.x = 0;
	IRbar.y = ILbar.y = 2;
	IRbar.w = ILbar.w = 128;
	IRbar.h = ILbar.h = 9;

	/*ILbar.x = 3;
	ILbar.y = 4;
	ILbar.w = 129;
	ILbar.h = 9;*/

	//Fighter_Name//
	HaoBar.x = 276;
	HaoBar.y = 489;
	HaoBar.w = 64;
	HaoBar.h = 8;

	//Points//
	Points.x = 344;
	Points.y = 15;
	Points.w = 18;
	Points.h = 8;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics = App->textures->Load("Textures/Screens/haohmaru_scene.png");
	lifebar = App->textures->Load("Textures/UI/lifebars.png");
	UI = App->textures->Load("Textures/UI/Sprite_Sheet_UI_1.png");

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
	App->textures->Unload(lifebar);
	App->textures->Unload(UI);

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
	if (App->input->keyboard[SDL_SCANCODE_H] == KEY_STATE::KEY_DOWN){ //Health-substracting button
		
		IRbar.w -= 10;

		if (IRbar.w <= 1) //40 instead of 0 because it doesnt exactly fit. If the duel ends then reset the healthbars
		{
			App->fade->FadeToBlack(this, App->congrats, 1.5f);
			Mix_FadeOutMusic(1500);
			IRbar.w = 129;
			ILbar.x = 2;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN){ //Health-substracting button
	
		ILbar.x -= 10;
		
		if (ILbar.w <= 1) //40 instead of 0 because it doesnt exactly fit. If the duel ends then reset the healthbars
		{
			App->fade->FadeToBlack(this, App->congrats, 1.5f);
			Mix_FadeOutMusic(1500);
			IRbar.w = 129;
			ILbar.x = 2;
		}
	}
	//background
	App->render->Blit(graphics, 0, 0, &(background.GetCurrentFrame()), 0.75f);

	//lifebars//
	App->render->Blit(lifebar, 380, 212, &Rbar);
	App->render->Blit(lifebar, 382, 214, &IRbar);
	App->render->Blit(lifebar, 165, 212, &Lbar);
	App->render->Blit(lifebar, 169, 214, &ILbar);

	//UI//
	App->render->Blit(UI, 170, 230, &HaoBar);
	App->render->Blit(UI, 447, 230, &HaoBar);
	App->render->Blit(UI, 400, 202, &Points);
	App->render->Blit(UI, 185, 202, &Points);

	return UPDATE_CONTINUE;
}