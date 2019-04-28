#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleHaohmaru.h"
#include "ModuleHaohmaru2.h"
#include "ModuleNeoGeoScreen.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleCharacterSelect.h"
#include "ModuleCongratsScreen.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleCharacterSelection::ModuleCharacterSelection() {

	//Square select player1//
	square1.x = 250;
	square1.y = 21;
	square1.w = 40;
	square1.h = 48;

	//Square select player2//
	square2.x = 295;
	square2.y = 23;
	square2.w = 40;
	square2.h = 48;

	//SelHao//
	HaoSel1.x = 104;
	HaoSel1.y = 410;
	HaoSel1.w = 40;
	HaoSel1.h = 48;

	//Title Hao//
	HaoLet1.x = 16;
	HaoLet1.y = 163;
	HaoLet1.w = 128;
	HaoLet1.h = 32;

	//Born Hao//
	HaoBorn1.x = 357;
	HaoBorn1.y = 32;
	HaoBorn1.w = 43;
	HaoBorn1.h = 15;
	
}

ModuleCharacterSelection::~ModuleCharacterSelection() {

}

bool ModuleCharacterSelection::Start() {

	LOG("Loading character selection scene");

	square1X = 211;
	square1Y = 210;
	square2X = 428;
	square2Y = 210;

	charSelect = App->textures->Load("Textures/Screens/CharacterSelecting.png");
	Characters = App->textures->Load("Textures/UI/Character Selection.png");
	player1 = App->textures->Load("Textures/UI/Sprite_Sheet_UI_1.png");

	McharSelect = App->audio->LoadMus("Audios/Music/CharacterSelecting.ogg");

	IntroHM = App->audio->LoadFX("Audios/FX/Haohmaru/HaohmaruIntro.wav");
	CharSel = App->audio->LoadFX("Audios/FX/General/Character_Selecting.wav");
	pass_char = App->audio->LoadFX("Audios/FX/General/selecting_character.wav");

	Mix_FadeInMusic(McharSelect, -1, 00);

	return true;
}

bool ModuleCharacterSelection::CleanUp() {

	LOG("Unloading selection scene");

	this->Disable();

	App->textures->Unload(charSelect);
	App->textures->Unload(Characters);
	App->textures->Unload(player1);

	App->audio->DeleteMusic(McharSelect);
	App->audio->DeleteChunk(IntroHM);
	App->audio->DeleteChunk(CharSel);
	App->audio->DeleteChunk(pass_char);

	return true;
}

update_status ModuleCharacterSelection::Update() {

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN) {

		square1X += 43;
		Mix_PlayChannel(-1, pass_char, 0);
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN) {

		square1X -= 43;
		Mix_PlayChannel(-1, pass_char, 0);
	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_DOWN) {

		square1Y -= 51;
		Mix_PlayChannel(-1, pass_char, 0);
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_DOWN) {

		square1Y += 51;
		Mix_PlayChannel(-1, pass_char, 0);
	}

	Mix_VolumeChunk(pass_char, MIX_MAX_VOLUME / 2);

	if (square1X < 211)
	{
		square1X = 211;
	}
	if (square1X > 426)
	{
		square1X = 426;
	}
	if (square1Y > 261)
	{
		square1Y = 261;
	}
	if (square1Y < 210)
	{
		square1Y = 210;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_DOWN) {

		square2X += 43;
		Mix_PlayChannel(-1, pass_char, 0);
	}
	if (App->input->keyboard[SDL_SCANCODE_H] == KEY_STATE::KEY_DOWN) {

		square2X -= 43;
		Mix_PlayChannel(-1, pass_char, 0);
	}
	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_DOWN) {

		square2Y -= 51;
		Mix_PlayChannel(-1, pass_char, 0);
	}
	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN) {

		square2Y += 51;
		Mix_PlayChannel(-1, pass_char, 0);
	}

	Mix_VolumeChunk(pass_char, MIX_MAX_VOLUME / 2);

	if (square2X < 213)
	{
		square2X = 213;
	}
	if (square2X > 428)
	{
		square2X = 428;
	}
	if (square2Y > 263)
	{
		square2Y = 263;
	}
	if (square2Y < 212)
	{
		square2Y = 212;
	}


	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN) {
		
		if (square1X == 297 && square1Y == 210) {

			Mix_PlayChannel(-1, IntroHM, 0);
			Mix_PlayChannel(-1, CharSel, 0);

			App->player->Enable();

			Mix_VolumeChunk(IntroHM, MIX_MAX_VOLUME / 2);
			Mix_VolumeChunk(CharSel, MIX_MAX_VOLUME / 3);

			player1Ready = true;
		}
		
	}

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN) {

		if (square2X == 299 && square1Y == 210) {

			Mix_PlayChannel(-1, IntroHM, 0);
			Mix_PlayChannel(-1, CharSel, 0);

			App->player2->Enable();

			Mix_VolumeChunk(IntroHM, MIX_MAX_VOLUME / 2);
			Mix_VolumeChunk(CharSel, MIX_MAX_VOLUME / 3);

			player2Ready = true;

		}

	}

	if (player1Ready && player2Ready) {

		App->fade->FadeToBlack(this, App->background, 3.0f);

		Mix_FadeOutMusic(1500);

	}


	App->render->Blit(charSelect, 160, 195, NULL);
	App->render->Blit(Characters, 210, 210, NULL);

	if (square1X == 297 && square1Y == 210) {

		App->render->Blit(player1, 200, 340, &HaoLet1);
		App->render->Blit(player1, 240, 375, &HaoBorn1);
		App->render->Blit(player1, 299, 212, &HaoSel1);
	}

	if (square2X == 299 && square2Y == 212) {

		App->render->Blit(player1, 360, 340, &HaoLet1);
		App->render->Blit(player1, 415, 375, &HaoBorn1);
		App->render->Blit(player1, 299, 212, &HaoSel1);
	}
	
	App->render->Blit(player1, square1X, square1Y, &square1);
	App->render->Blit(player1, square2X, square2Y, &square2);
	
	return UPDATE_CONTINUE;
}