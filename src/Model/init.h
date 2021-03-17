#ifndef INIT
#define INIT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH  2560
#define SCREEN_HEIGHT 1440
#define TXTR_ROBOT (char *)"Model/Textures/robot.png"

namespace model {
	class init
	{
		public:
			void sdl(SDL_Window **window, SDL_Renderer **renderer);
	};
}

#endif
