#include <iostream>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleHaohmaru2.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "ModuleCollision.h"
#include "ModuleHaohmaru.h"

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

	// walk forward animation (arcade sprite sheet)
	forward.PushBack({ 634, 0, 74, 121 });
	forward.PushBack({ 509, 0, 74, 121 });
	forward.PushBack({ 380, 0, 71, 121 });
	forward.PushBack({ 248, 0, 73, 121 });
	forward.PushBack({ 118, 0, 80, 121 });
	forward.PushBack({ 0, 0, 80, 121 });
	forward.speed = 0.1f;

	// haohmaru walk backwards with the correct animations
	backward.PushBack({ 442, 0, 90, 120 });
	backward.PushBack({ 306, -5, 90, 125 });
	backward.PushBack({ 173, -5, 82, 125 });
	backward.PushBack({ 38, -5, 78, 125 });
	backward.PushBack({ 490, 120, 88, 120 });
	backward.PushBack({ 356, 120, 83, 120 });
	backward.PushBack({ 204, 120, 96, 120 });
	backward.speed = 0.1f;

	//haohmaru jump
	jump.PushBack({ 0, 0, 72, 112 });
	jump.PushBack({ 244, 0, 64, 112 });
	jump.PushBack({ 158, 20, 78, 92 });
	jump.PushBack({ 68, 26, 84, 86 });
	jump.loop = false;
	jump.speed = 0.1f;

	//haohmaru fall
	fall.PushBack({ 68, 26, 84, 86 });
	fall.PushBack({ 158, 20, 78, 92 });
	fall.PushBack({ 244, 0, 64, 112 });
	fall.PushBack({ 0, 0, 72, 112 });
	fall.loop = false;
	fall.speed = 0.1f;

	// Attack animation
	attack.PushBack({ 1378, 0, 74, 138 });
	attack.PushBack({ 1234, 0, 82, 138 });
	attack.PushBack({ 1021, 0, 136, 138 });
	attack.PushBack({ 873, 0, 136, 138 });
	attack.PushBack({ 724, 0, 138, 138 });
	attack.PushBack({ 579, 0, 136, 138 });
	attack.PushBack({ 434, 0, 135, 138 });
	attack.PushBack({ 299, 0, 126, 138 });
	attack.PushBack({ 188, 0, 90, 138 });
	attack.PushBack({ 0, 0, 133, 138 });
	attack.speed = 0.37f;

	//Before tornado animation
	tornado.PushBack({ 1924, 271, 100, 102 });
	tornado.PushBack({ 1841, 271, 81, 103 });
	tornado.PushBack({ 1715, 274, 107, 99 });
	tornado.PushBack({ 1609, 264, 100, 107 });
	tornado.PushBack({ 1464, 248, 141, 125 });
	tornado.PushBack({ 1351, 188, 109, 185 });
	tornado.PushBack({ 1194, 257, 117, 117 });
	tornado.PushBack({ 1031, 250, 135, 124 });
	tornado.PushBack({ 879, 263, 115, 107 });
	tornado.PushBack({ 742, 264, 89, 108 });
	tornado.speed = 0.17f;

	//Kick animation
	kick.PushBack({ 1913, 21, 68, 99 });
	kick.PushBack({ 1823, 19, 90, 101 });
	kick.PushBack({ 1913, 21, 68, 99 });
	kick.speed = 0.15f;

	//crouch animation
	crouchd.PushBack({ 0, 0, 94, 112 });
	crouchd.speed = 0.1f;
	crouchd.loop = false;

	//crouch kick animation
	crouchK.PushBack({ 1933, 846, 85, 90 });
	crouchK.PushBack({ 1800, 846, 108, 90 });
	crouchK.PushBack({ 1933, 846, 85, 90 });
	crouchK.speed = 0.15f;

	//crouch attack animation
	crouchA.PushBack({ 1105, 0, 92, 78 });
	crouchA.PushBack({ 931, 0, 131, 78 });
	crouchA.PushBack({ 798, 0, 130, 78 });
	crouchA.PushBack({ 798, 0, 130, 78 });
	crouchA.PushBack({ 662, 0, 130, 78 });
	crouchA.PushBack({ 532, 0, 130, 78 });
	crouchA.PushBack({ 438, 0, 92, 78 });
	crouchA.PushBack({ 307, 0, 87, 78 });
	crouchA.PushBack({ 175, 0, 89, 78 });
	crouchA.PushBack({ 56, 0, 80, 78 });
	crouchA.speed = 0.37f;

	//jump kick animation
	jumpK.PushBack({ 98, 0, 98, 92 });
	jumpK.PushBack({ 0, 0, 98, 92 });
	jumpK.PushBack({ 0, 0, 98, 92 });
	jumpK.speed = 0.1f;

	jumpFK.PushBack({ 98, 0, 98, 92 });
	jumpFK.PushBack({ 0, 0, 98, 92 });
	jumpFK.PushBack({ 0, 0, 98, 92 });
	jumpFK.speed = 0.1f;

	jumpBK.PushBack({ 98, 0, 98, 92 });
	jumpBK.PushBack({ 0, 0, 98, 92 });
	jumpBK.PushBack({ 0, 0, 98, 92 });
	jumpBK.speed = 0.1f;

	//jump attack animation
	jumpA.PushBack({ 534, 0, 70, 88 });
	jumpA.PushBack({ 534, 0, 70, 88 });
	jumpA.PushBack({ 534, 0, 70, 88 });
	jumpA.PushBack({ 407, 0, 110, 101 });
	jumpA.PushBack({ 407, 0, 110, 101 });
	jumpA.PushBack({ 534, 0, 70, 88 });
	jumpA.PushBack({ 534, 0, 70, 88 });
	jumpA.PushBack({ 534, 0, 70, 88 });
	jumpA.PushBack({ 300, 0, 98, 101 });
	jumpA.PushBack({ 300, 0, 98, 101 });
	jumpA.speed = 0.37f;

	jumpFA.PushBack({ 534, 0, 70, 88 });
	jumpFA.PushBack({ 534, 0, 70, 88 });
	jumpFA.PushBack({ 534, 0, 70, 88 });
	jumpFA.PushBack({ 407, 0, 110, 101 });
	jumpFA.PushBack({ 407, 0, 110, 101 });
	jumpFA.PushBack({ 534, 0, 70, 88 });
	jumpFA.PushBack({ 534, 0, 70, 88 });
	jumpFA.PushBack({ 534, 0, 70, 88 });
	jumpFA.PushBack({ 300, 0, 98, 101 });
	jumpFA.PushBack({ 300, 0, 98, 101 });
	jumpFA.speed = 0.37f;

	jumpBA.PushBack({ 534, 0, 70, 88 });
	jumpBA.PushBack({ 534, 0, 70, 88 });
	jumpBA.PushBack({ 534, 0, 70, 88 });
	jumpBA.PushBack({ 407, 0, 110, 101 });
	jumpBA.PushBack({ 407, 0, 110, 101 });
	jumpBA.PushBack({ 534, 0, 70, 88 });
	jumpBA.PushBack({ 534, 0, 70, 88 });
	jumpBA.PushBack({ 534, 0, 70, 88 });
	jumpBA.PushBack({ 300, 0, 98, 101 });
	jumpBA.PushBack({ 300, 0, 98, 101 });
	jumpBA.speed = 0.37f;

	//jump forward animation
	jumpF.PushBack({ 1129, 0, 71, 131 });
	jumpF.PushBack({ 1022, 0, 63, 131 });
	jumpF.PushBack({ 885, 0, 71, 131 });
	jumpF.PushBack({ 740, 0, 90, 131 });
	jumpF.loop = false;
	jumpF.speed = 0.1f;

	fallF.PushBack({ 634, 0, 71, 131 });
	fallF.PushBack({ 517, 0, 90, 131 });
	fallF.PushBack({ 400, 0, 85, 131 });
	fallF.PushBack({ 304, 0, 75, 131 });
	fallF.loop = false;
	fallF.speed = 0.1f;

	//jump backward animation
	jumpB.PushBack({ 955, 0, 69, 120 });
	jumpB.PushBack({ 891, 0, 51, 120 });
	jumpB.PushBack({ 789, 0, 90, 120 });
	jumpB.PushBack({ 700, 0, 70, 120 });
	jumpB.loop = false;
	jumpB.speed = 0.1f;

	fallB.PushBack({ 576, 0, 90, 120 });
	fallB.PushBack({ 476, 0, 70, 120 });
	fallB.PushBack({ 330, 0, 83, 120 });
	fallB.PushBack({ 238, 0, 75, 120 });
	fallB.loop = false;
	fallB.speed = 0.1f;
}

ModuleHaohmaru2::~ModuleHaohmaru2()
{}

// Load assets
bool ModuleHaohmaru2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Textures/Spritesheets/haohmaru_spritesheet2.png"); // arcade version
	graphicsf = App->textures->Load("Textures/Spritesheets/haohmaru_forward2.png");
	graphicsb = App->textures->Load("Textures/Spritesheets/haohmaru_backward2.png");
	graphicsj = App->textures->Load("Textures/Spritesheets/haohmaru_jump2.png");
	graphicsa = App->textures->Load("Textures/Spritesheets/haohmaru_light_attack2.png");
	graphicst = App->textures->Load("Textures/Spritesheets/haohmaru_anim_tornado2.png");
	graphicsk = App->textures->Load("Textures/Spritesheets/HaohmaruKick2.png");
	graphicsc = App->textures->Load("Textures/Spritesheets/haohmaru_crouch2.png");
	graphicsca = App->textures->Load("Textures/Spritesheets/haohmaru_crouchA2.png");
	graphicsjk = App->textures->Load("Textures/Spritesheets/haohmaru_jumpk2.png");
	graphicsja = App->textures->Load("Textures/Spritesheets/haohmaru_jumpa2.png");
	graphicsjf = App->textures->Load("Textures/Spritesheets/haohmaru_jumpf2.png");
	graphicsjb = App->textures->Load("Textures/Spritesheets/haohmaru_jumpb2.png");

	font_score = App->fonts->Load("Textures/UI/Fonts_Points_Spritesheets.png", "0123456789", 1);

	CharacterJump = App->audio->LoadFX("Audios/FX/General/CharacterJump.wav");
	bef_tornado = App->audio->LoadFX("Audios/FX/Haohmaru/HaohmaruTornadoVoice.wav");
	while_tornado = App->audio->LoadFX("Audios/FX/Haohmaru/HaohmaruTornado.wav");
	kickS = App->audio->LoadFX("Audios/FX/General/Kick.wav");
	slash = App->audio->LoadFX("Audios/FX/General/Slash.wav");

#define create_IdleCollider App->collision->AddCollider({ position.x + 15, position.y - 90, 40, 80 }, COLLIDER_PLAYER2, this);

	//player collider	
	P2MainCollider = create_IdleCollider;
	P2MainCollider->callback = App->player2;

	return ret;
}

// Update: draw background
update_status ModuleHaohmaru2::Update()
{

	Animation* current_animation = &idle;
	p2Qeue<Player2_Inputs>inputs;
	Player2_States current_state = ST_UNKNOWN;

	int speed = 1;

	//GodMode Here
	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {
		if (GodMode == false && P2MainCollider != nullptr) {
			P2MainCollider->to_delete = true;
			P2MainCollider = nullptr;
			GodMode = true;
		}
		else if (GodMode == true && P2MainCollider == nullptr) {
			P2MainCollider = App->collision->AddCollider({ position.x + 15, position.y - 90, 40, 80 }, COLLIDER_PLAYER2, this);
			GodMode = false;
		}

	}

	while (input_ex(inputs)) {

		input_in(inputs);

		Player2_States state = process_fsm(inputs);

		if (state != current_state) {

			switch (state) {

			case ST_IDLE:
				current_animation = &idle;

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 15, position.y - 90);
				}

				break;
			case ST_FORWARD:

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 15, position.y - 90);
				}
				current_animation = &forward;

				position.x += speed + 1.3;
				if (position.x >= 470)
				{
					position.x = 470;
				}

				break;
			case ST_BACKWARD:

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 15, position.y - 90);
				}

				current_animation = &backward;

				position.x -= speed + 1;
				if (position.x <= 180)
				{
					position.x = 180;
				}

				break;
			case ST_JUMP_NEUTRAL:

				Mix_PlayChannel(-1, CharacterJump, 0);
				Mix_VolumeChunk(CharacterJump, MIX_MAX_VOLUME / 10);

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 20, position.y - 90);
				}

				jumped = 1;
				if (jumped == 1) {
					if (position.y == 420) {
						maxpos = false;
						minpos = true;
					}
					if (position.y == 280) {
						minpos = false;
						maxpos = true;
					}

					if (minpos == true) {
						fall.Reset();
						position.y -= (speed * 4);
						current_animation = &jump;
					}
					if (maxpos == true) {
						jump.Reset();
						position.y += (speed * 4);
						current_animation = &fall;
					}

				}

				break;
			case ST_JUMP_FORWARD:

				Mix_PlayChannel(-1, CharacterJump, 0);
				Mix_VolumeChunk(CharacterJump, MIX_MAX_VOLUME / 10);

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 10, position.y - 90);
				}

				jumped = 1;
				if (jumped == 1) {
					if (position.y == 420) {
						maxpos = false;
						minpos = true;
					}
					if (position.y == 280) {
						minpos = false;
						maxpos = true;
					}
					if (minpos == true) {
						fallF.Reset();
						position.y -= (speed * 4);
						current_animation = &jumpF;
					}
					if (maxpos == true) {
						jumpF.Reset();
						position.y += (speed * 4);
						current_animation = &fallF;
					}
					position.x -= speed + 1.3;

				}

				break;
			case ST_JUMP_BACKWARD:

				Mix_PlayChannel(-1, CharacterJump, 0);
				Mix_VolumeChunk(CharacterJump, MIX_MAX_VOLUME / 10);

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 10, position.y - 90);
				}

				jumped = 1;
				if (jumped == 1) {
					if (position.y == 420) {
						maxpos = false;
						minpos = true;
					}
					if (position.y == 280) {
						minpos = false;
						maxpos = true;
					}
					if (minpos == true) {
						fallB.Reset();
						position.y -= (speed * 4);
						current_animation = &jumpB;
					}
					if (maxpos == true) {
						jumpB.Reset();
						position.y += (speed * 4);
						current_animation = &fallB;
					}
					position.x += speed + 1;

				}

				break;
			case ST_JUMP_ATTACK:

				current_animation = &jumpA;
				Mix_PlayChannel(-1, slash, 0);
				Mix_VolumeChunk(slash, MIX_MAX_VOLUME / 9);

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 15, position.y - 90);
				}

				if (collider)
				{
					attackCollider = App->collision->AddCollider({ position.x + 50, position.y - 50, 80, 30 }, COLLIDER_PLAYER2_SHOT, this);
					collider = false;
				}

				break;
			case ST_JUMP_KICK:

				Mix_PlayChannel(-1, kickS, 0);
				Mix_VolumeChunk(kickS, MIX_MAX_VOLUME / 6);

				if (!GodMode)
				{
					P2MainCollider->SetSize(40, 80);
					P2MainCollider->SetPos(position.x + 15, position.y - 90);
				}

				if (collider)
				{
					attackCollider = App->collision->AddCollider({ position.x + 35, position.y - 45, 80, 30 }, COLLIDER_PLAYER2_SHOT, this);
					collider = false;
				}
				current_animation = &jumpK;

				break;
			case ST_JUMP_BACKWARD_ATTACK:
				P2MainCollider->SetSize(40, 80);
				P2MainCollider->SetPos(position.x + 15, position.y - 90);
				current_animation = &jumpBA;
				Mix_PlayChannel(-1, slash, 0);
				Mix_VolumeChunk(slash, MIX_MAX_VOLUME / 6);

				break;
			case ST_JUMP_FORWARD_ATTACK:
				Mix_PlayChannel(-1, slash, 0);
				Mix_VolumeChunk(slash, MIX_MAX_VOLUME / 6);
				P2MainCollider->SetSize(40, 80);
				P2MainCollider->SetPos(position.x + 15, position.y - 90);
				current_animation = &jumpFA;

				break;
			case ST_JUMP_BACKWARD_KICK:
				P2MainCollider->SetSize(40, 80);
				P2MainCollider->SetPos(position.x + 15, position.y - 90);
				current_animation = &jumpBK;
				Mix_PlayChannel(-1, kickS, 0);

				break;
			case ST_JUMP_FORWARD_KICK:
				P2MainCollider->SetSize(40, 80);
				P2MainCollider->SetPos(position.x + 15, position.y - 90);
				current_animation = &jumpFK;
				Mix_PlayChannel(-1, kickS, 0);
				Mix_VolumeChunk(kickS, MIX_MAX_VOLUME / 6);

				break;
			case ST_ATTACK_STANDING:
				current_animation = &attack;
				Mix_PlayChannel(-1, slash, 0);
				Mix_VolumeChunk(slash, MIX_MAX_VOLUME / 9);

				if (collider)
				{
					attackCollider = App->collision->AddCollider({ position.x + 50, position.y - 70, 80, 27 }, COLLIDER_PLAYER2_SHOT, this);
					collider = false;
				}

				break;
			case ST_KICK_STANDING:

				if (collider)
				{
					attackCollider = App->collision->AddCollider({ position.x + 10, position.y - 50, 80, 30 }, COLLIDER_PLAYER2_SHOT, this);
					collider = false;
				}

				current_animation = &kick;
				Mix_PlayChannel(-1, kickS, 0);
				Mix_VolumeChunk(kickS, MIX_MAX_VOLUME / 6);

				break;
			case ST_TORNADO:

				current_animation = &tornado;

				if (!tornado_Once)
				{
					score2 += 125;
					App->particles->AddParticle(App->particles->tornado_creation, position.x - 20, position.y - 93, COLLIDER_PLAYER2_SHOT);

					tornado_Once = true;
				}

				// Also here will be the audio mixer
				Mix_PlayChannel(-1, bef_tornado, 0);
				Mix_VolumeChunk(bef_tornado, MIX_MAX_VOLUME / 4);
				Mix_PlayChannel(-1, while_tornado, 0);
				Mix_VolumeChunk(while_tornado, MIX_MAX_VOLUME / 4);

				break;
			case ST_CROUCH:

				P2MainCollider->SetPos(position.x + 40, position.y - 70);
				P2MainCollider->SetSize(50, 60);

				current_animation = &crouchd;

				break;
			case ST_CROUCH_ATTACK:

				if (collider)
				{
					attackCollider = App->collision->AddCollider({ position.x + 60, position.y - 40, 80, 30 }, COLLIDER_PLAYER2_SHOT, this);
					collider = false;
				}
				current_animation = &crouchA;
				Mix_PlayChannel(-1, slash, 0);
				Mix_VolumeChunk(slash, MIX_MAX_VOLUME / 6);

				break;
			case ST_CROUCH_KICK:

				if (collider)
				{
					attackCollider = App->collision->AddCollider({ position.x + 40, position.y - 40, 80, 30 }, COLLIDER_PLAYER2_SHOT, this);
					collider = false;
				}

				current_animation = &crouchK;
				Mix_PlayChannel(-1, kickS, 0);
				Mix_VolumeChunk(kickS, MIX_MAX_VOLUME / 6);

				break;
			}

			current_state = state;
			// Draw everything --------------------------------------
			SDL_Rect hm2 = current_animation->GetCurrentFrame();

			if (current_animation == &idle)
			{
				App->render->Blit(graphics, position.x, position.y - hm2.h, &hm2);
			}
			if (current_animation == &forward)
			{
				App->render->Blit(graphicsf, position.x, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &backward)
			{
				App->render->Blit(graphicsb, position.x, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &attack)
			{
				App->render->Blit(graphicsa, position.x, position.y - hm2.h + 5, &hm2);
			}
			if (current_animation == &tornado)
			{
				App->render->Blit(graphicst, position.x, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &kick)
			{
				App->render->Blit(graphicsk, position.x, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jump)
			{
				App->render->Blit(graphicsj, position.x, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &fall)
			{
				App->render->Blit(graphicsj, position.x, position.y - hm2.h, &hm2);
			}
			if (current_animation == &crouchd)
			{
				App->render->Blit(graphicsc, position.x, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &crouchK)
			{
				App->render->Blit(graphics, position.x + 15, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &crouchA)
			{
				App->render->Blit(graphicsca, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpK)
			{
				App->render->Blit(graphicsjk, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpA)
			{
				App->render->Blit(graphicsja, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpF)
			{
				App->render->Blit(graphicsjf, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &fallF)
			{
				App->render->Blit(graphicsjf, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpFK)
			{
				App->render->Blit(graphicsjk, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpFA)
			{
				App->render->Blit(graphicsja, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpB)
			{
				App->render->Blit(graphicsjb, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &fallB)
			{
				App->render->Blit(graphicsjb, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpBK)
			{
				App->render->Blit(graphicsjk, position.x + 20, position.y - hm2.h - 5, &hm2);
			}
			if (current_animation == &jumpBA)
			{
				App->render->Blit(graphicsja, position.x + 20, position.y - hm2.h - 5, &hm2);
			}

			// Calculate collisions ---------------------------------------------------
			//He calculado las colisiones pr�cicamente igual que calculan las colisiones entre particulas.
			//Tengo un getCollider hecho en ModuleColliders.h que me coje la array de colliders para poderla usar aqu�.

			Collider* c1;
			Collider* c2;

			for (uint i = 0; i < MAX_COLLIDERS; ++i)
			{
				// skip empty colliders
				if (App->collision->getColliders()[i] == nullptr)
					continue;

				c2 = App->collision->getColliders()[i];

				// avoid checking collisions already checked
				for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
				{
					// skip empty colliders
					if (App->collision->getColliders()[k] == nullptr)
						continue;

					c1 = App->collision->getColliders()[k];

					if (c2->CheckCollision(c1->rect) == true)
					{
						// he variado estas condiciones ya que no cualquier colision valida me sirve, tiene que ser COLLIDER_PLAYER con COLLIDER_WALL.

						if (COLLIDER_PLAYER1 == c2->type && COLLIDER_PLAYER2 == c1->type)
							Player2OnCollision(c2, c1); //Aplico la funci�n creada m�s a bajo para volver al principio del programa.

						if (COLLIDER_PLAYER1 == c1->type && COLLIDER_PLAYER2 == c2->type)
							Player2OnCollision(c2, c1); //Aplico la funci�n creada m�s a bajo para volver al principio del programa.
					}
				}
			}

			sprintf_s(score_text2, 10, "%7d", score2);
			App->fonts->BlitText(188, 202, font_score, score_text2);

			return UPDATE_CONTINUE;
		}
	}
}

void ModuleHaohmaru2::Player2OnCollision(Collider* c1, Collider* c2)
{

	if (c1 != nullptr)//porsiacaso compruebo que no sea null
	{
		App->player2->position.x += 2;
	}

}

bool ModuleHaohmaru2::input_ex(p2Qeue<Player2_Inputs>& inputs) {

	static bool left = false;
	static bool right = false;
	static bool down = false;
	static bool up = false;

	SDL_Event event2;

	while (SDL_PollEvent(&event2) != 0)
	{

		if (event2.type == SDL_KEYDOWN && event2.key.repeat == 0)
		{
			switch (event2.key.keysym.sym) {

			case SDLK_k:
				right = true;
				break;

			case SDLK_h:
				left = true;
				break;

			case SDLK_u:
				up = true;
				break;

			case SDLK_j:
				down = true;
				break;

			case SDLK_1:
				inputs.Push(IN_1);
				score2 += 13;
				break;

			case SDLK_3:
				inputs.Push(IN_3);
				break;

			case SDLK_5:
				inputs.Push(IN_5);
				break;
			}
		}

		if (event2.type == SDL_KEYUP && event2.key.repeat == 0) {

			switch (event2.key.keysym.sym) {

			case SDLK_k:
				inputs.Push(IN_k_UP);
				right = false;
				break;

			case SDLK_h:
				inputs.Push(IN_h_UP);
				left = false;
				break;

			case SDLK_j:
				inputs.Push(IN_CROUCH_UP);
				down = false;
				break;

			case SDLK_u:
				up = false;
				break;

			case SDLK_1:
				return false;
				break;

			case SDLK_3:
				return false;
				break;

			case SDLK_5:
				return false;
				break;
			}
		}
	}

	if (left && right)
		inputs.Push(IN_h_AND_k);
	else
	{
		if (left)
			inputs.Push(IN_h_DOWN);
		if (right)
			inputs.Push(IN_k_DOWN);
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

void ModuleHaohmaru2::input_in(p2Qeue<Player2_Inputs>& inputs) {

	if (attack_timer > 0)
	{
		if (SDL_GetTicks() - attack_timer > ATTACK_TIME)
		{
			inputs.Push(IN_ATTACK_FINISH);
			attack_timer = 0;

			if (attackCollider != nullptr)
			{
				collider = true;
				attackCollider->to_delete = true;
				attackCollider = nullptr;
			}
		}
	}

	if (jump_timer > 0)
	{
		if (SDL_GetTicks() - jump_timer > JUMP_TIME)
		{
			inputs.Push(IN_JUMP_FINISH);
			jump_timer = 0;
			position.y = 420;
		}
	}

	if (kick_timer > 0)
	{
		if (SDL_GetTicks() - kick_timer > KICK_TIME)
		{
			inputs.Push(IN_KICK_FINISH);
			kick_timer = 0;

			if (attackCollider != nullptr)
			{
				attackCollider->to_delete = true;
				attackCollider = nullptr;
				collider = true;
			}
		}
	}

	if (tornado_timer > 0)
	{
		if (SDL_GetTicks() - tornado_timer > TORNADO_TIME)
		{
			inputs.Push(IN_TORNADO_FINISH);
			tornado_timer = 0;
			tornado_Once = false;
		}
	}
}

bool ModuleHaohmaru2::CleanUp()
{
	LOG("Unloading player");

	if (p2IdleCollider != nullptr) {

		p2IdleCollider->to_delete = true;
	}

	App->textures->Unload(graphics);
	App->textures->Unload(graphicsa);
	App->textures->Unload(graphicsf);
	App->textures->Unload(graphicsb);
	App->textures->Unload(graphicsj);
	App->textures->Unload(graphicst);
	App->textures->Unload(graphicsk);
	App->textures->Unload(graphicsc);
	App->textures->Unload(graphicsca);
	App->textures->Unload(graphicsjk);
	App->textures->Unload(graphicsja);
	App->textures->Unload(graphicsjf);
	App->textures->Unload(graphicsjb);

	App->audio->DeleteChunk(bef_tornado);
	App->audio->DeleteChunk(while_tornado);
	App->audio->DeleteChunk(kickS);
	App->audio->DeleteChunk(slash);

	return true;
}