#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleHaohmaru.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleHaohmaru2.h"

ModuleHaohmaru::ModuleHaohmaru()
{
	position.x = 220;
	position.y = 420;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 632, 566, 79, 123 });
	idle.PushBack({ 713, 568, 77, 121 });
	idle.PushBack({ 795, 563, 86, 126 });
	idle.PushBack({ 632, 686, 80, 124 });
	idle.PushBack({ 713, 686, 80, 124 });
	idle.PushBack({ 795, 686, 80, 124 });
	idle.speed = 0.09f;

	// walk forward animation (arcade sprite sheet)
	forward.PushBack({ 0, 0, 74, 121 });
	forward.PushBack({ 125, 0, 74, 121 });
	forward.PushBack({ 257, 0, 71, 121 });
	forward.PushBack({ 387, 0, 73, 121 });
	forward.PushBack({ 510, 0, 80, 121 });
	forward.PushBack({ 630, 0, 80, 121 });
	forward.speed = 0.1f;

	// haohmaru walk backwards with the correct animations
	backward.PushBack({ 64, 0, 90, 120 });
	backward.PushBack({ 200, -5, 90, 125 });
	backward.PushBack({ 341, -5, 82, 125 });
	backward.PushBack({ 480, -5, 78, 125 });
	backward.PushBack({ 18, 120, 88, 120 });
	backward.PushBack({ 157, 120, 83, 120 });
	backward.PushBack({ 296, 120, 96, 120 });
	backward.speed = 0.1f;

	//haohmaru jump
	jump.PushBack({ 0, 0, 64, 112 });
	jump.PushBack({ 72, 20, 78, 92 });
	jump.PushBack({ 156, 26, 84, 86 });
	jump.PushBack({ 240, 0, 72, 112 });
	jump.speed = 0.1f;

	// Attack animation
	attack.PushBack({ 8, 0, 74, 138 });
	attack.PushBack({ 144, 0, 82, 138 });
	attack.PushBack({ 303, 0, 136, 138 });
	attack.PushBack({ 451, 0, 136, 138 });
	attack.PushBack({ 598, 0, 138, 138 });
	attack.PushBack({ 745, 0, 136, 138 });
	attack.PushBack({ 891, 0, 135, 138 });
	attack.PushBack({ 1035, 0, 126, 138 });
	attack.PushBack({ 1182, 0, 90, 138 });
	attack.PushBack({ 1327, 0, 133, 138 });
	attack.speed = 0.37f;

	//Before tornado animation
	tornado.PushBack({ 0, 271, 100, 102 });
	tornado.PushBack({ 102, 271, 81, 103 });
	tornado.PushBack({ 202, 274, 107, 99 });
	tornado.PushBack({ 315, 264, 100, 107 });
	tornado.PushBack({ 419, 248, 141, 125 });
	tornado.PushBack({ 564, 188, 109, 185 });
	tornado.PushBack({ 713, 257, 117, 117 });
	tornado.PushBack({ 858, 250, 135, 124 });
	tornado.PushBack({ 1030, 263, 115, 107 });
	tornado.PushBack({ 1193, 264, 89, 108 });
	tornado.speed = 0.17f;

	//Kick animation
	kick.PushBack({ 43, 21, 68, 99 });
	kick.PushBack({ 111, 19, 90, 101 });
	kick.PushBack({ 43, 21, 68, 99 });
	kick.speed = 0.15f;

}

ModuleHaohmaru::~ModuleHaohmaru()
{}

// Load assets
bool ModuleHaohmaru::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Textures/Spritesheets/haohmaru_spritesheet.png"); // arcade version
	graphicsf = App->textures->Load("Textures/Spritesheets/haohmaru_forward.png");
	graphicsb = App->textures->Load("Textures/Spritesheets/haohmaru_backward.png");
	graphicsj = App->textures->Load("Textures/Spritesheets/haohmaru_jump.png");
	graphicsa = App->textures->Load("Textures/Spritesheets/haohmaru_light_attack.png");
	graphicst = App->textures->Load("Textures/Spritesheets/haohmaru_anim_tornado.png");
	graphicsk = App->textures->Load("Textures/Spritesheets/HaohmaruKick.png");

	bef_tornado = App->audio->LoadFX("Audios/FX/Haohmaru/HaohmaruTornadoVoice.wav");
	while_tornado = App->audio->LoadFX("Audios/FX/Haohmaru/HaohmaruTornado.wav");
	kickS = App->audio->LoadFX("Audios/FX/General/Kick.wav");
	slash = App->audio->LoadFX("Audios/FX/General/Slash.wav");

	//player collider
	player1Collider = App->collision->AddCollider({position.x +10, position.y -100, 50, 100 }, COLLIDER_PLAYER1, this);
	player1Collider->callback = App->player;

	return ret;
}

// Update: draw background
update_status ModuleHaohmaru::Update()
{

	Animation* current_animation = &idle;
	p2Qeue<Player_Inputs>inputs;
	Player_States current_state = ST_UNKNOWN;

	int speed = 1;

	//GodMode Here


	while (input_ex(inputs)) {

		input_in(inputs);

		Player_States state = process_fsm(inputs);

		if (state != current_state) {

			switch (state) {

			case ST_IDLE:
				current_animation = &idle;

				break;
			case ST_FORWARD:
				current_animation = &forward;
				position.x += speed + 1.3;


				break;
			case ST_BACKWARD:
				current_animation = &backward;
				position.x -= speed + 1;

				break;
			case ST_JUMP_NEUTRAL:
				current_animation = &jump;

				break;
			case ST_JUMP_FORWARD:
				current_animation = &jumpF;

				break;
			case ST_JUMP_BACKWARD:
				current_animation = &jumpB;

				break;
			case ST_JUMP_ATTACK:
				current_animation = &jumpA;
				Mix_PlayChannel(-1, slash, 0);

				break;
			case ST_JUMP_KICK:
				current_animation = &jumpK;
				Mix_PlayChannel(-1, kickS, 0);

				break;
			case ST_JUMP_BACKWARD_ATTACK:
				current_animation = &jumpBA;
				Mix_PlayChannel(-1, slash, 0);

				break;
			case ST_JUMP_FORWARD_ATTACK:
				current_animation = &jumpFA;
				Mix_PlayChannel(-1, slash, 0);

				break;
			case ST_JUMP_BACKWARD_KICK:
				current_animation = &jumpBK;
				Mix_PlayChannel(-1, kickS, 0);

				break;
			case ST_JUMP_FORWARD_KICK:
				current_animation = &jumpFK;
				Mix_PlayChannel(-1, kickS, 0);

				break;
			case ST_ATTACK_STANDING:
				current_animation = &attack;
				Mix_PlayChannel(-1, slash, 0);
				//Here will be the colliders & collisions

				break;
			case ST_KICK_STANDING:
				current_animation = &kick;
				Mix_PlayChannel(-1, kickS, 0);

				break;
			case ST_TORNADO:
				current_animation = &tornado;

				App->particles->AddParticle(App->particles->tornado_creation, position.x - 20, position.y - 93, COLLIDER_PLAYER1_SHOT);
				
				// Also here will be the audio mixer
				Mix_PlayChannel(-1, bef_tornado, 0);
				Mix_PlayChannel(-1, while_tornado, 0);

				break;
			case ST_CROUCH:
				current_animation = &crouch;

				break;
			case ST_CROUCH_ATTACK:
				current_animation = &crouchA;
				Mix_PlayChannel(-1, slash, 0);

				break;
			case ST_CROUCH_KICK:
				current_animation = &crouchK;
				Mix_PlayChannel(-1, kickS, 0);

				break;
			}

			current_state = state;

				// Draw everything --------------------------------------
			SDL_Rect hm = current_animation->GetCurrentFrame();

			if (current_animation == &idle)
			{
				App->render->Blit(graphics, position.x, position.y - hm.h, &hm);
			}
			if (current_animation == &forward)
			{
				App->render->Blit(graphicsf, position.x, position.y - hm.h - 5, &hm);
			}
			if (current_animation == &backward)
			{
				App->render->Blit(graphicsb, position.x, position.y - hm.h - 5, &hm);
			}
			if (current_animation == &attack)
			{
				App->render->Blit(graphicsa, position.x, position.y - hm.h + 5, &hm);
			}
			if (current_animation == &tornado)
			{
				App->render->Blit(graphicst, position.x, position.y - hm.h - 5, &hm);
			}
			if (current_animation == &kick)
			{
				App->render->Blit(graphicsk, position.x, position.y - hm.h - 5, &hm);
			}
			if (current_animation == &jump)
			{
				App->render->Blit(graphicsj, position.x, position.y - hm.h - 5, &hm);
			}

			// Calculate collisions ---------------------------------------------------
			//He calculado las colisiones prácicamente igual que calculan las colisiones entre particulas.
			//Tengo un getCollider hecho en ModuleColliders.h que me coje la array de colliders para poderla usar aquí.

			Collider* c1;
			Collider* c2;

			for (uint i = 0; i < MAX_COLLIDERS; ++i)
			{
				// skip empty colliders
				if (App->collision->getColliders()[i] == nullptr)
					continue;

				c1 = App->collision->getColliders()[i];

				// avoid checking collisions already checked
				for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
				{
					// skip empty colliders
					if (App->collision->getColliders()[k] == nullptr)
						continue;

					c2 = App->collision->getColliders()[k];

					if (c1->CheckCollision(c2->rect) == true)
					{
						// he variado estas condiciones ya que no cualquier colision valida me sirve, tiene que ser COLLIDER_PLAYER con COLLIDER_WALL.

						if (COLLIDER_PLAYER2 == c1->type && COLLIDER_PLAYER1 == c2->type)
							PlayerOnCollision(c1, c2); //Aplico la función creada más a bajo para volver al principio del programa.

						if (COLLIDER_PLAYER2 == c2->type && COLLIDER_PLAYER1 == c1->type)
							PlayerOnCollision(c1, c2); //Aplico la función creada más a bajo para volver al principio del programa.
					}
				}
			}

			//Update collider position to player position
			player1Collider->SetPos(position.x + 10, position.y - 100);
			return UPDATE_CONTINUE;
		}
	}
}

void ModuleHaohmaru::PlayerOnCollision(Collider* c1, Collider* c2)
{

	if (c1 != nullptr)//porsiacaso compruebo que no sea null
	{
		
		App->player2->position.x += 2;
	
	}

}

bool ModuleHaohmaru::input_ex(p2Qeue<Player_Inputs>& inputs) {

	static bool left = false;
	static bool right = false;
	static bool down = false;
	static bool up = false;

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{

		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym) {

			case SDLK_RIGHT:
				right = true;
				break;

			case SDLK_LEFT:
				left = true;
				break;

			case SDLK_UP:
				up = true;
				break;

			case SDLK_DOWN:
				down = true;
				break;

			case SDLK_a:
				inputs.Push(IN_A);
				break;

			case SDLK_d:
				inputs.Push(IN_D);
				break;

			case SDLK_t:
				inputs.Push(IN_T);
				break;
			}
		}

		if (event.type == SDL_KEYUP && event.key.repeat == 0) {

			switch (event.key.keysym.sym) {

			case SDLK_RIGHT:
				inputs.Push(IN_RIGHT_UP);
				right = false;
				break;

			case SDLK_LEFT:
				inputs.Push(IN_LEFT_UP);
				left = false;
				break;

			case SDLK_DOWN:
				inputs.Push(IN_CROUCH_UP);
				down = false;
				break;

			case SDLK_UP:
				up = false;
				break;

			case SDLK_a:
				return false;
				break;

			case SDLK_k:
				return false;
				break;

			case SDLK_t:
				return false;
				break;
			}
		}
	}

	if (left && right)
		inputs.Push(IN_LEFT_AND_RIGHT);
	else
	{
		if (left)
			inputs.Push(IN_LEFT_DOWN);
		if (right)
			inputs.Push(IN_RIGHT_DOWN);
	}

	if (up && down)
		inputs.Push(IN_JUMP_AND_CROUCH);
	else
	{
		if (down)
			inputs.Push(IN_CROUCH_DOWN);
		if (up)
			inputs.Push(IN_JUMP);
	}

	return true;

}

void ModuleHaohmaru::input_in(p2Qeue<Player_Inputs>& inputs) {

	if (attack_timer > 0)
	{
		if (SDL_GetTicks() - attack_timer > ATTACK_TIME)
		{
			inputs.Push(IN_ATTACK_FINISH);
			attack_timer = 0;
		}
	}

	if (jump_timer > 0)
	{
		if (SDL_GetTicks() - jump_timer > JUMP_TIME)
		{
			inputs.Push(IN_JUMP_FINISH);
			jump_timer = 0;
		}
	}

	if (kick_timer > 0)
	{
		if (SDL_GetTicks() - kick_timer > KICK_TIME)
		{
			inputs.Push(IN_KICK_FINISH);
			kick_timer = 0;
		}
	}

	if (tornado_timer > 0)
	{
		if (SDL_GetTicks() - tornado_timer > TORNADO_TIME)
		{
			inputs.Push(IN_TORNADO_FINISH);
			tornado_timer = 0;
		}
	}
}

bool ModuleHaohmaru::CleanUp()
{
	LOG("Unloading player");

	if (player1Collider != nullptr) {

		player1Collider->to_delete = true;
	}

	App->textures->Unload(graphics);
	App->textures->Unload(graphicsa);
	App->textures->Unload(graphicsf);
	App->textures->Unload(graphicsb);
	App->textures->Unload(graphicsj);
	App->textures->Unload(graphicst);
	App->textures->Unload(graphicsk);

	App->audio->DeleteChunk(bef_tornado);
	App->audio->DeleteChunk(while_tornado);
	App->audio->DeleteChunk(kickS);
	App->audio->DeleteChunk(slash);

	return true;
}