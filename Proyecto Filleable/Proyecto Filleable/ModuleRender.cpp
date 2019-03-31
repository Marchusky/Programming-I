#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"


#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

//Error detectado con el puntero externo a App
//Comentar al equipo y preguntar si no es resuelto

ModuleRender::ModuleRender() : Module() //rectangulo camera definido
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
}

// Destructor
ModuleRender::~ModuleRender()
{}

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
	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_UP] == 1)
		camera.y += speed;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == 1)
		camera.y -= speed;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == 1)
		camera.x += speed;

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == 1)
		camera.x -= speed;

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
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed) //dibuja
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

	return true; //si todo esta correcto retorna true y blit dibuja
}