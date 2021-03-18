#ifndef INIT
#define INIT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define TV_WIDTH 3840
#define TV_HEIGHT 2160
#define MON_WIDTH  2560
#define MON_HEIGHT 1440
#define SCREEN_WIDTH  MON_WIDTH
#define SCREEN_HEIGHT MON_HEIGHT
#define TXTR_ROBOT (char *)"Model/Textures/robot.png"

namespace model {
	class init
	{
		public:
			void sdl(SDL_Window **window, SDL_Renderer **renderer);
	};
}

#endif
