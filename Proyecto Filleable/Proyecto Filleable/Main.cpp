//#include <stdio.h>
#include <iostream>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL_Image/SDL2_image.lib")
#pragma comment(lib, "SDL_mixer/SDL2_mixer.lib")

#include "Application.h"
#include "Globals.h"
//#include "MemLeaks.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

enum main_states //Enumera los diferentes estados posibles para los diferentes modulos
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = nullptr; //iniuzializa m.application a null.

int main(int argc, char* argv[])
{
	//ReportMemoryLeaks(); //llama funcion para saber si hay perdidas de memoria(punteros no borrados)

	int main_return = EXIT_FAILURE;
	main_states state = MAIN_CREATION;

	while (state != MAIN_EXIT) //mientras que el estado no sea exit...
	{
		switch (state) //dependiendo del estado hace segun que cosas
		{
		case MAIN_CREATION:  //cambia el estado a start
		{
			LOG("Application Creation --------------");
			App = new Application();
			state = MAIN_START;
		}	break;

		case MAIN_START:  //si startea bien pasa a update, sino a exit y el programa para
		{
			LOG("Application Init --------------");
			if (App->Init() == false)
			{
				LOG("Application Init exits with error -----");
				state = MAIN_EXIT;
			}
			else
			{
				state = MAIN_UPDATE;
				LOG("Application Update --------------");
			}

		}	break;

		case MAIN_UPDATE: //si update funciona la detiene y pasa a finish, sino a exit y el programa para
		{
			int update_return = App->Update();

			if (update_return == UPDATE_ERROR)
			{
				LOG("Application Update exits with error -----");
				state = MAIN_EXIT;
			}
			else if (update_return == UPDATE_STOP)
				state = MAIN_FINISH;
		}
		break;

		case MAIN_FINISH: //si el cleanUp funciona devuelve succes y pasa a exit, sino da error y programa para igualmente
		{
			LOG("Application CleanUp --------------");
			if (App->CleanUp() == false)
			{
				LOG("Application CleanUp exits with error -----");
			}
			else
				main_return = EXIT_SUCCESS;

			state = MAIN_EXIT;

		} break;

		}
	}

	delete App; //borra App para evitar memoryLeaks
	LOG("Bye :)\n"); //comentario innecesario totalmente
	return main_return; //retorno del main