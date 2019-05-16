#include "Globals.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "MemoryLeaks.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleHaohmaru.h"
#include "ModuleHaohmaru2.h"

//Error detectado con el puntero externo a App
//Comentar al equipo y preguntar si no es resuelto

ModuleRender::ModuleRender() : Module() //rectangulo camera definido
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
}

// Destructor
ModuleRender::~ModuleRender(){}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true; //return para empezar el init(mirar moduleRender.h)
	Uint32 flags = 0;

	if (REN_VSYNC == true) //preguntar que es VSYNC
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags); //crea renderer

	if (renderer == NULL) //comprueba error al crear renderer
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate() //cambia status a PreUpdate
{
	SDL_RenderClear(renderer); //limpia el render

	return update_status::UPDATE_CONTINUE; //continua ejecutando
}

update_status ModuleRender::Update() //funcion que realmente hace algo, crea y mueve camara dependiendo del keyboard
{
	return update_status::UPDATE_CONTINUE; //continua ejecutando
}

update_status ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE; //continua ejecutando
}

// Called before quitting
bool ModuleRender::CleanUp() //return para empezar CleanUp(mirar funcion CleanUp en moduleRender.h)
{
	LOG("Destroying renderer");

	//Destroy window
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
//bool ModuleRender::Blit(SDL_Texture * texture, int x, int y, const SDL_Rect * section, SDL_RendererFlip flip, float speed, bool use_camera, double angle, int pivot_x, int pivot_y) const //dibuja
bool ModuleRender::Blit(SDL_Texture * texture, int x, int y, const SDL_Rect * section, float speed) const //dibuja

{
	bool ret = true; //return para funcion blit(mirar moduleRender.h)
	SDL_Rect rect; //crea rectangulo
	rect.x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	rect.y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if (section != NULL) //si section no ha sido definida copia las stats de rect a section.
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else //si sectian esta definida, inicializa las stats para texture
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0) //diibuja el render con todos los componentes
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false; //si da errr retorna false y blit no dibuja.
	}

	return ret; //si todo esta correcto retorna true y blit dibuja
}

//Determina el color de los Colliders para poder verlos en pantalla y distinguirlos según el tipo
bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}
//TODO
//void ModuleRender::MoveCamera()
//{
//
//	iPoint player_1 = App->player->position;
//	iPoint player_2 = App->player2->position;
//
//	if ((player_1.x < left->rect.x + left->rect.w)) {
//		if (player_2.x + 50 < right->rect.x) {
//			right->rect.x -= App->player->speed;
//			left->rect.x -= App->player->speed;
//			camera.x -= App->player->speed * SCREEN_SIZE;
//		}
//	}
//	else if ((player_2.x > right->rect.x - 48)) {
//		if (player_1.x > left->rect.x + left->rect.w) {
//			right->rect.x += App->player->speed;
//			left->rect.x += App->player->speed;
//			camera.x += App->player->speed * SCREEN_SIZE;
//		}
//	}
//	if ((player_2.x < left->rect.x + left->rect.w)) {
//		if (player_1.x + 50 < right->rect.x) {
//			right->rect.x -= App->player->speed;
//			left->rect.x -= App->player->speed;
//			camera.x -= App->player->speed * SCREEN_SIZE;
//		}
//	}
//	else if ((player_1.x > right->rect.x - 50)) {
//		if (player_2.x > left->rect.x + left->rect.w) {
//			right->rect.x += App->player->speed;
//			left->rect.x += App->player->speed;
//			camera.x += App->player->speed * SCREEN_SIZE;
//		}
//	}
//}
//
//void ModuleRender::SetCamera()
//{
//	if ((!left) && (!right))
//	{
//		left = App->collision->AddCollider({ -50,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_LEFT);
//		right = App->collision->AddCollider({ camera.w,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_RIGHT);
//	}
//	left->SetPos(-50, 0);
//	right->SetPos(camera.w, 0);
//}