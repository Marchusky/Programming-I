#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneIntro.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"



// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading intro scene");

	intro = App->textures->Load("rtype/intro.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(intro);
	App->player->Disable();

	return true;
}

// Update: draw intro
update_status ModuleSceneIntro::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(App->scene_intro,App->scene_space, 2.0f);
	}

	// Draw everything --------------------------------------
	App->render->Blit(intro, 0, 0, NULL);

	return UPDATE_CONTINUE;
}