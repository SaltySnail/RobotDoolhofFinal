#include "simulation.h"

void view::simulation::window(SDL_Renderer *renderer, model::simulation *model, bool isBeginFrame) {
    if (!isBeginFrame) {
        model->maze.stupidlyCorrectBorders(renderer);
		model->robot.draw(renderer);
		model->maze.draw(renderer);
        SDL_RenderPresent(renderer);
    } else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
    }
}