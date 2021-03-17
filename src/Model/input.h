#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

namespace model {
	class input {
			SDL_Event event;
		public:
			SDL_bool update(void);
		};
}

#endif
