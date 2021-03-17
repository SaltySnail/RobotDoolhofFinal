#include "input.h"

SDL_bool model::input::update() {
                while (SDL_PollEvent(&event)) {
                    switch (event.type) {
				case SDL_QUIT: 
                        		return SDL_TRUE;
				/*case SDL_MOUSEWHEEL:
					if (event.wheel.y < 0)
						scroll_wheel = scroll_down;
					if (event.wheel.y > 0)
						scroll_wheel = scroll_up;
				case SDL_KEYUP:
				        if (event.key.keysym.sym == SDLK_RIGHT)
						right_key = up;
					if (event.key.keysym.sym == SDLK_LEFT)
						left_key = up;	
				        if (event.key.keysym.sym == SDLK_UP) 
						up_key = up;
					if (event.key.keysym.sym == SDLK_DOWN)
						down_key = up;	
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						return SDL_TRUE;
				        if (event.key.keysym.sym == SDLK_RIGHT)
						right_key = down;
					if (event.key.keysym.sym == SDLK_LEFT)
						left_key = down;	
				        if (event.key.keysym.sym == SDLK_UP)
						up_key = down;
					if (event.key.keysym.sym == SDLK_DOWN)
						down_key = down;*/	
				
					break;
				default:
					break;
		    }
                }
		return SDL_FALSE;
}
