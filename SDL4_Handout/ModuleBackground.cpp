#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;

	// TODO 2 (big ship)
	ship.x = 8;
	ship.y = 8;
	ship.w = 530;
	ship.h = 200;

	// TODO 3 (girl)
	girl.PushBack({ 622,140,40,60 });
	girl.PushBack({ 622,76,40,60 });
	girl.PushBack({ 622,12,40,60 });
	girl.speed = 0.08f;

}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation

	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	App->render->Blit(graphics, 0, -20, &ship, 0.70f); // ship

	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	App->render->Blit(graphics, 190, 96, &(girl.GetCurrentFrame()), 0.75f); // flag animation


	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}