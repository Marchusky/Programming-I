#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleHaohmaru2.h"
#include "ModuleAudio.h"

ModuleHaohmaru2::ModuleHaohmaru2()
{
	position.x = 400;
	position.y = 420;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 1337, 566, 79, 123 });
	idle.PushBack({ 1256, 568, 77, 121 });
	idle.PushBack({ 1175, 563, 85, 126 });
	idle.PushBack({ 1337, 686, 80, 124 });
	idle.PushBack({ 1256, 686, 80, 124 });
	idle.PushBack({ 1175, 686, 80, 124 });
	idle.speed = 0.09f;
}

ModuleHaohmaru2::~ModuleHaohmaru2()
{}

// Load assets
bool ModuleHaohmaru2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Textures/Spritesheets/haohmaru_spritesheet2.png"); // arcade version
	current_animation = &idle;
	//player collider
	player2Collider = App->collision->AddCollider({ position.x + 25, position.y - 90, 40, 80 }, COLLIDER_PLAYER2, this);

	return ret;
}

// Update: draw background
update_status ModuleHaohmaru2::Update()
{
	int speed = 1;

	// Draw everything --------------------------------------
	SDL_Rect hm = current_animation->GetCurrentFrame();
	if (current_animation == &idle)
	{
		App->render->Blit(graphics, position.x, position.y - hm.h, &hm);
	}

	//Update collider position to player position
	player2Collider->SetPos(position.x + 25, position.y - 90);

	return UPDATE_CONTINUE;
}  

bool ModuleHaohmaru2::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}