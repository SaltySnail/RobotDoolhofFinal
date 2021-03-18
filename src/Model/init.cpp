#include "init.h"


void model::init::sdl(SDL_Window **window, SDL_Renderer **renderer)
{
	unsigned int window_flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	//unsigned int window_flags = SDL_WINDOW_BORDERLESS;
	unsigned int renderer_flags = SDL_RENDERER_ACCELERATED;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	if (SCREEN_WIDTH == TV_WIDTH) {
	*window = SDL_CreateWindow("Robots go brrrr", 
		MON_WIDTH*2, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, 
		SCREEN_HEIGHT, window_flags);
	} else {
	*window = SDL_CreateWindow("Robots go brrrr", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, 
		SCREEN_HEIGHT, window_flags);	
	}
	if (window == NULL)
	{
		printf("Failed to create window -- Error: %s\n",
			SDL_GetError());
		exit(1);
	}
	*renderer = SDL_CreateRenderer(*window, -1, renderer_flags);
	if (renderer == NULL)
	{
		printf("Failed to create renderer -- Error: %s\n",
			SDL_GetError());
		exit(1);
	}
	IMG_Init(IMG_INIT_PNG);	
}

