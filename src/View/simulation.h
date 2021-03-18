#ifndef VIEW_SIMULATION_H
#define VIEW_SIMULATION_H

#include "../Model/simulation.h"
#include <SDL2/SDL.h>

namespace view {
    class simulation {
            bool init;
        public:
            void window(SDL_Renderer *renderer, model::simulation *model, bool isBeginFrame);
    };
}

#endif