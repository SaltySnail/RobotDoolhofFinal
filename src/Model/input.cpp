#include "input.h"

bool model::input::update() {
                while (SDL_PollEvent(&event)) {
                    switch (event.type) {
				case SDL_QUIT: 
                        		return true;
						break;
				default:
					break;
		    }
                }
		return SDL_FALSE;
}
