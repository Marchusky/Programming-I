#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

// TODO 2: Init the library and check for possible error
// using SDL_GetError()
bool ModuleWindow::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO)!=0) {
	SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	return true;
	}
	else 
	{
		return false;
	}
	// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
	// then create the window and check for errors
	SDL_Window* window = SDL_CreateWindow("TODO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

}

bool ModuleWindow::CleanUp()
{

	return false;
}


// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)


