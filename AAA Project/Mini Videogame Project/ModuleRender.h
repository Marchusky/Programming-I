#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"
#include "SDL\include\SDL_rect.h"

struct SDL_Renderer;
struct SDL_Texture;

class ModuleRender : public Module //Crea el moduleRender como hija de module
{
public:
	ModuleRender(); //constructor sin inizializar
	~ModuleRender(); //destructor

	typedef enum {

		SDL_FLIP_NONE = 0x00000000,     /**< Do not flip */
		SDL_FLIP_HORIZONTAL = 0x00000001,    /**< flip horizontally */
		SDL_FLIP_VERTICAL = 0x00000002     /**< flip vertically */
	} SDL_RendererFlip;
	

	bool Init(); //inicializa el init dependiendo del return(mirar moduleRender.cpp)
	update_status PostUpdate(); //funcion PostUpdate
	update_status Update();     //funcion Update
	update_status PreUpdate();  //funcion PreUpdate
	bool CleanUp(); //inicializa el cleanUp dependiendo del return(mirar moduleRender.cpp)

	//funcion para dibujar todo rectangulo
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);

public: // preguntar porque hay dos public
	SDL_Renderer* renderer = nullptr; //crea y inicializa renderer a nullptr
	SDL_Rect camera; // crea el rectangulo para camera
};

#endif //__ModuleRenderer_H__