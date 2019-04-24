#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleHaohmaru.h"
#include "ModuleHaohmaru2.h"


#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{

	LOG("Loading particles");
	graphics = App->textures->Load("Textures/Spritesheets/haohmaru_cyclone_slash.png");


	//Tornado particles ( complately hardcoded :/ )
	tornado_creation.anim.PushBack({ 0, 171, 40, 89 });
	tornado_creation.anim.PushBack({ 40, 171, 40, 89 });
	tornado_creation.anim.PushBack({ 80, 171, 50, 89 });
	tornado_creation.anim.PushBack({ 130, 171, 47, 89 });
	tornado_creation.anim.PushBack({ 177, 171, 53, 89 });
	tornado_creation.speed.x = 2;
	tornado_creation.anim.speed = 0.3f;
	tornado_creation.life = 3000;
	tornado_creation.anim.loop = false;

	for(int i = 0; i < MAX_FRAMES; i++)
	{
		tornado_creation.anim.PushBack({ 230, 171, 85, 89 });
		tornado_creation.anim.PushBack({ 315, 171, 85, 89 });
		tornado_creation.anim.PushBack({ 400, 171, 95, 89 });
		tornado_creation.anim.PushBack({ 495, 171, 90, 89 });
		tornado_creation.anim.PushBack({ 585, 171, 91, 89 });
		tornado_creation.anim.PushBack({ 676, 171, 90, 89 });
		tornado_creation.anim.PushBack({ 0, 261, 91, 89 });
		tornado_creation.anim.PushBack({ 93, 261, 85, 89 });
		tornado_creation.anim.PushBack({ 187, 261, 87, 89 });
		tornado_creation.anim.PushBack({ 282, 261, 88, 89 });
		tornado_creation.anim.PushBack({ 378, 261, 82, 89 });
		tornado_creation.anim.PushBack({ 465, 261, 79, 89 });
		tornado_creation.anim.PushBack({ 554, 261, 77, 89 });
		tornado_creation.anim.PushBack({ 635, 261, 76, 89 });
		tornado_creation.anim.PushBack({ 716, 261, 53, 89 });
		tornado_creation.anim.PushBack({ 0, 354, 55, 89 });
		tornado_creation.anim.PushBack({ 63, 354, 46, 89 });
		tornado_creation.anim.PushBack({ 124, 354, 46, 89 });
		tornado_creation.anim.PushBack({ 181, 354, 70, 89 });
		tornado_creation.anim.PushBack({ 251, 354, 64, 89 });
	}
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;

			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	if (COLLIDER_PLAYER1_SHOT == c1->type && COLLIDER_PLAYER2 == c2->type)
	{
		AddParticle(tornado_colliding, c1->rect.x, c1->rect.y - 5, COLLIDER_NONE); 
	}

		       

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{


		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;

			break;
		}
	}
}

// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	//if (collider != nullptr)
		//collider->SetPos(position.x, position.y);

	return ret;
}