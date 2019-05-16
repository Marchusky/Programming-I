#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"

#include "SDL/include/SDL.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_Mixer/SDL2_mixer.lib" )

#define JUMP_TIME 1150
#define ATTACK_TIME 450
#define KICK_TIME 350
#define TORNADO_TIME 1000

struct SDL_Texture;

class ModuleHaohmaru2 : public Module
{
private:
	enum Player2_States {

		ST_UNKNOWN,

		ST_IDLE,
		ST_FORWARD,
		ST_BACKWARD,
		ST_ATTACK_STANDING,
		ST_KICK_STANDING,
		ST_CROUCH,
		ST_CROUCH_ATTACK,
		ST_CROUCH_KICK,
		ST_JUMP_NEUTRAL,
		ST_JUMP_ATTACK,
		ST_JUMP_KICK,
		ST_JUMP_FORWARD,
		ST_JUMP_FORWARD_ATTACK,
		ST_JUMP_FORWARD_KICK,
		ST_JUMP_BACKWARD,
		ST_JUMP_BACKWARD_ATTACK,
		ST_JUMP_BACKWARD_KICK,
		ST_TORNADO
	};

	enum Player2_Inputs {

		IN_h_DOWN,
		IN_h_UP,
		IN_k_DOWN,
		IN_k_UP,
		IN_h_AND_k,
		IN_JUMP,
		IN_CROUCH_UP,
		IN_CROUCH_DOWN,
		IN_JUMP_AND_CROUCH,
		IN_1,
		IN_3,
		IN_5,
		IN_JUMP_FINISH,
		IN_ATTACK_FINISH,
		IN_KICK_FINISH,
		IN_TORNADO_FINISH
	};

	Uint32 jump_timer = 0;
	Uint32 attack_timer = 0;
	Uint32 kick_timer = 0;
	Uint32 tornado_timer = 0;

	bool input_ex(p2Qeue<Player2_Inputs>&);
	void input_in(p2Qeue<Player2_Inputs>&);

	Player2_States process_fsm(p2Qeue<Player2_Inputs>& inputs) {

		static Player2_States state = ST_IDLE;
		Player2_Inputs last_input;

		while (inputs.Pop(last_input))
		{
			switch (state)
			{
			case ST_IDLE: {

				switch (last_input)
				{
				case IN_k_DOWN: state = ST_BACKWARD; break;
				case IN_h_DOWN: state = ST_FORWARD; break;
				case IN_JUMP: state = ST_JUMP_NEUTRAL; jump_timer = SDL_GetTicks(); break;
				case IN_CROUCH_DOWN: state = ST_CROUCH; break;
				case IN_1: state = ST_ATTACK_STANDING; attack_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_KICK_STANDING; kick_timer = SDL_GetTicks(); break;
				case IN_5: state = ST_TORNADO; tornado_timer = SDL_GetTicks(); break;
				}
			}
						  break;

			case ST_FORWARD:
			{
				switch (last_input)
				{
				case IN_h_UP: state = ST_IDLE; break;
				case IN_h_AND_k: state = ST_BACKWARD; break;
				case IN_JUMP: state = ST_JUMP_FORWARD; jump_timer = SDL_GetTicks();  break;
				case IN_CROUCH_DOWN: state = ST_CROUCH; break;
				case IN_1: state = ST_ATTACK_STANDING; attack_timer = SDL_GetTicks();  break;
				case IN_3: state = ST_KICK_STANDING; kick_timer = SDL_GetTicks(); break;
				}
			}
			break;

			case ST_BACKWARD:
			{
				switch (last_input)
				{
				case IN_k_UP: state = ST_IDLE; break;
				case IN_h_AND_k: state = ST_BACKWARD; break;
				case IN_JUMP: state = ST_JUMP_BACKWARD; jump_timer = SDL_GetTicks();  break;
				case IN_CROUCH_DOWN: state = ST_CROUCH; break;
				case IN_1: state = ST_ATTACK_STANDING; attack_timer = SDL_GetTicks();  break;
				case IN_3: state = ST_KICK_STANDING; kick_timer = SDL_GetTicks(); break;
				}
			}
			break;

			case ST_JUMP_NEUTRAL:
			{
				switch (last_input)
				{
				case IN_JUMP_FINISH: state = ST_IDLE; break;
				case IN_1: state = ST_JUMP_ATTACK; attack_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_JUMP_KICK; kick_timer = SDL_GetTicks(); break;
				}
			}
			break;

			case ST_JUMP_FORWARD:
			{
				switch (last_input)
				{
				case IN_JUMP_FINISH: state = ST_IDLE; break;
				case IN_1: state = ST_JUMP_FORWARD_ATTACK; attack_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_JUMP_FORWARD_KICK; kick_timer = SDL_GetTicks(); break;
				}
			}
			break;

			case ST_JUMP_BACKWARD:
			{
				switch (last_input)
				{
				case IN_JUMP_FINISH: state = ST_IDLE; break;
				case IN_1: state = ST_JUMP_BACKWARD_ATTACK; attack_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_JUMP_BACKWARD_KICK; kick_timer = SDL_GetTicks(); break;
				}
			}
			break;

			case ST_JUMP_ATTACK:
			{
				switch (last_input)
				{
				case IN_ATTACK_FINISH: state = ST_JUMP_NEUTRAL; break;
				case IN_JUMP_FINISH: state = ST_IDLE; break;

				}
			}
			break;

			case ST_JUMP_KICK:
			{
				switch (last_input)
				{
				case IN_KICK_FINISH: state = ST_JUMP_NEUTRAL; break;
				case IN_JUMP_FINISH: state = ST_IDLE; break;

				}
			}
			break;

			case ST_JUMP_FORWARD_ATTACK:
			{
				switch (last_input)
				{
				case IN_ATTACK_FINISH: state = ST_JUMP_FORWARD; break;
				case IN_JUMP_FINISH: state = ST_IDLE; break;

				}
			}
			break;

			case ST_JUMP_FORWARD_KICK:
			{
				switch (last_input)
				{
				case IN_KICK_FINISH: state = ST_JUMP_FORWARD; break;
				case IN_JUMP_FINISH: state = ST_IDLE; break;

				}
			}
			break;

			case ST_JUMP_BACKWARD_ATTACK:
			{
				switch (last_input)
				{
				case IN_ATTACK_FINISH: state = ST_JUMP_BACKWARD; break;
				case IN_JUMP_FINISH: state = ST_IDLE; break;

				}
			}
			break;

			case ST_JUMP_BACKWARD_KICK:
			{
				switch (last_input)
				{
				case IN_KICK_FINISH: state = ST_JUMP_BACKWARD; break;
				case IN_JUMP_FINISH: state = ST_IDLE; break;

				}
			}
			break;

			case ST_ATTACK_STANDING:
			{
				switch (last_input)
				{
				case IN_ATTACK_FINISH: state = ST_IDLE; break;
				}
			}
			break;

			case ST_KICK_STANDING:
			{
				switch (last_input)
				{
				case IN_KICK_FINISH: state = ST_IDLE; break;
				}
			}
			break;

			case ST_TORNADO:
			{
				switch (last_input)
				{
				case IN_TORNADO_FINISH: state = ST_IDLE; break;
				}
			}
			break;

			case ST_CROUCH:
			{
				switch (last_input)
				{
				case IN_CROUCH_UP: state = ST_IDLE; break;
				case IN_1: state = ST_CROUCH_ATTACK; attack_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_CROUCH_KICK; kick_timer = SDL_GetTicks(); break;
				}
			}
			break;

			case ST_CROUCH_ATTACK:

				switch (last_input)
				{
				case IN_ATTACK_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					break;
				}

				break;

			case ST_CROUCH_KICK:

				switch (last_input)
				{
				case IN_KICK_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					break;
				}
			}
		}

		return state;
	}

public:
	ModuleHaohmaru2();
	~ModuleHaohmaru2();

	bool Start();
	update_status Update();
	bool CleanUp();

	void Player2OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphicsf = nullptr;
	SDL_Texture* graphicsb = nullptr;
	SDL_Texture* graphicsj = nullptr;
	SDL_Texture* graphicsa = nullptr;
	SDL_Texture* graphicst = nullptr;
	SDL_Texture* graphicsk = nullptr;
	SDL_Texture* graphicsc = nullptr;
	SDL_Texture* graphicsca = nullptr;
	SDL_Texture* graphicsjk = nullptr;
	SDL_Texture* graphicsja = nullptr;
	SDL_Texture* graphicsjf = nullptr;
	SDL_Texture* graphicsjb = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	Animation fall;
	Animation jumpK;
	Animation jumpA;
	Animation jumpF;
	Animation fallF;
	Animation jumpFA;
	Animation jumpFK;
	Animation jumpB;
	Animation fallB;
	Animation jumpBA;
	Animation jumpBK;
	Animation crouchd;
	Animation crouchA;
	Animation crouchK;
	Animation tornado;
	Animation attack;
	Animation kick;
	iPoint position;

	Mix_Chunk* CharacterJump = nullptr;
	Mix_Chunk* CharacterGround = nullptr;
	Mix_Chunk* kickS = nullptr;
	Mix_Chunk* slash = nullptr;
	Mix_Chunk* bef_tornado = nullptr;
	Mix_Chunk* while_tornado = nullptr;

	//player collider
	Collider* P2MainCollider;

	Collider* p2IdleCollider;
	Collider* p2CrouchCollider;
	Collider* attackCollider;

	int font_score = -1;
	char score_text2[10];
	uint score2 = 0;

	int jumped = 0;

	bool MCol_ToActivate = false;
	bool collider = true;
	bool tornado_Once = false;
	bool GodMode = false;
	bool maxpos = false;
	bool minpos = false;
};

#endif