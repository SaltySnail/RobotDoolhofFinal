#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>

#include "Model/simulation.h"
#include "Controller/simulation.h"
#include "View/simulation.h"

int main(void) {
	srand(time(NULL));
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL; //moeten in main aangemaakt worden
	bool quit;
	model::simulation Model;
	controller::simulation Controller;
	view::simulation View;
	Model.properInit(); //objecten in headers werken niet altijd naar behoren
	Controller.control(&window, &renderer, &Model);

	while (!quit) {
		View.window(renderer, &Model, true);
		quit = Controller.control(&window, &renderer, &Model);
		View.window(renderer, &Model, false); 
		//SDL_Delay(5);
		/*if (endGenerating) {
			SDL_Delay(1);
		}
		else {
			//SDL_Delay(3); //1440p & 20 pixels/room
		}*/

	}
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();

	return 0;	
}
