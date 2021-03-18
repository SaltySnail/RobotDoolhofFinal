#ifndef CONTR_SIMULATION_H
#define CONTR_SIMULATION_H

#include "../Model/simulation.h"
#include <SDL2/SDL.h>

namespace controller {
    class simulation {
            bool init = 0, quit = 0, endGenerating = 0;
            SDL_Point counter;
            SDL_Point startMaze, endMaze;
        public:
            bool control(SDL_Window **window, SDL_Renderer **renderer, model::simulation *model); //returns 1 to quit the program
    };
}

#endif