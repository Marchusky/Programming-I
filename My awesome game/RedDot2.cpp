#include <iostream>
#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"

#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL_Image/SDL2_image.lib")
#pragma comment(lib, "SDL_Mixer/SDL2_Mixer.lib")


enum Key_State
{
	KEY_IDLE,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

SDL_Window*window = nullptr;
SDL_Renderer*render = nullptr;
SDL_Surface*surface = nullptr;
SDL_Surface*loadedImage = nullptr;

//Textures
SDL_Texture* bg_texture = nullptr;
SDL_Texture* object_texture = nullptr;
SDL_Texture* prjectile_texture = nullptr;

//Input
Key_State keys[300]; //ask wtf is this.

//Rectangles
SDL_Rect bg_rect = { 0, 0, 1920, 1080 };
SDL_Rect ship_rect = { 10, 10, 160, 160 };
SDL_Rect bullet_rect = { -50, -50, 36, 16 };
bool shot = false;

bool InitSDL{

}
int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 480, 0);

	if (window == NULL) {
		SDL_Log("Unable to create window: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == NULL) {
		SDL_Log("Unable to create renderer: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}


	// load support for the JPG and PNG image formats
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(IMG_INIT_PNG);
	if ((initted&flags) != flags) {
		SDL_Log("IMG_Init: Failed to init required jpg and png support!\n");
		SDL_Log("IMG_Init: %s\n", IMG_GetError());
		// handle error
	}

	// load sample.png into image
	SDL_Surface *image;
	image = IMG_Load("Game/head.png");
	if (!image) {
		printf("IMG_Load: %s\n", IMG_GetError());
		// handle error
	}
	
	//void Draw() {
	//	SDL_RenderCopy(renderer,/*head texture*/, nullptr, /*&head texture_rect*/)
	//}

	bool quit = false;
	//Struct (Event handler)
	SDL_Event event;

	const Uint8 *state = SDL_GetKeyboardState(NULL);


	int left = 1;
	SDL_Rect rectangle;
	rectangle.x = 240;
	rectangle.y = 240;
	rectangle.w = 50;
	rectangle.h = 50;

	bool laserCharged = true;

	SDL_Rect laser;
	laser.x = 253;
	laser.y = 260;
	laser.w = 25;
	laser.h = 5;


	// frame loop
	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (state[SDL_SCANCODE_ESCAPE])
			{
				quit = true;
			}
			if (state[SDL_SCANCODE_W]) {
				rectangle.y--;
				if (laserCharged)
				{
					laser.y--;
				}
			}
			if (state[SDL_SCANCODE_A]) {
				rectangle.x--;
				if (laserCharged)
				{
					laser.x--;
				}
			}
			if (state[SDL_SCANCODE_S]) {
				rectangle.y++;
				if (laserCharged)
				{
					laser.y++;
				}
			}
			if (state[SDL_SCANCODE_D]) {
				rectangle.x++;
				if (laserCharged)
				{
					laser.x++;
				}
			}
			if (state[SDL_SCANCODE_SPACE]) {
				laserCharged = false;
			}
		}
		if (!laserCharged) {
			laser.x++;
		}
		if (rectangle.x >= 430) {
			rectangle.x = 430;
		}
		if (rectangle.x <= 0) {
			rectangle.x = 0;
		}
		if (rectangle.y >= 480) {
			rectangle.y = 480;
		}
		if (rectangle.y >= 430) {
			rectangle.y = 430;
		}
		if (laser.x > 500)
		{
			laser.x = rectangle.x + 13;
			laser.y = rectangle.y + 20;
			laserCharged = true;
		}

		

		//render background
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		//render rectangle & laser
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		SDL_RenderFillRect(renderer, &laser);
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rectangle);

SDL_RenderPresent(renderer);
		
	}
	SDL_FreeSurface(image);
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}