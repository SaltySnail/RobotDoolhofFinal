#include "simulation.h"

bool controller::simulation::control(SDL_Window **window, SDL_Renderer **renderer, model::simulation *model) {
    if (!init) {
    	model->init.sdl(window, renderer);	
    	model->maze.initRooms();
		startMaze.x = 0;
		startMaze.y = 0;
		counter.x = 0;
		counter.y = 0;
		endMaze.x = SCREEN_WIDTH/ROOM_SIZE-1;
		endMaze.y = SCREEN_HEIGHT/ROOM_SIZE-1;
    	model->maze.setStartEnd(startMaze, endMaze);
		//model::maze *thisMaze = &model->maze;
		//printf("The maze is at: %p or %p\n", thisMaze, &model->maze);
	    model->robot.init(*renderer, &model->maze);
		init = true;
		quit = false;
    } else {
		quit = model->input.update();
		if (!endGenerating) { 	
			model->maze.generate(&counter, &endGenerating);
		}
		else {
			model->robot.update();
			//printf("robot Updating \n");
		}
    }
    return quit;
}