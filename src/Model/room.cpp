#include "room.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void model::room::setMissingWall(int side) {
		side_missing[side] = 1;
}

void model::room::setCoords(SDL_Point newPoint) {
	corners[top_left].x = newPoint.x;
	corners[top_left].y = newPoint.y;

	corners[bottom_left].x = newPoint.x;
	corners[bottom_left].y = newPoint.y + size;

	corners[bottom_right].x = newPoint.x + size;
	corners[bottom_right].y = newPoint.y + size;

	corners[top_right].x = newPoint.x + size;
	corners[top_right].y = newPoint.y;
}

void model::room::draw(SDL_Renderer *renderer) {
	SDL_Point line[2];
	//for (int i = 0; i < 2; i++) {
	if (side_missing[right] == 0) {
		line[0].x = corners[top_right].x;
		line[0].y = corners[top_right].y;
		line[1].x = corners[bottom_right].x;
		line[1].y = corners[bottom_right].y;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //RGBA
		SDL_RenderDrawLines(renderer, line, 2);
	}
	if (side_missing[top] == 0) {
		line[0].x = corners[top_right].x;
		line[0].y = corners[top_right].y;
		line[1].x = corners[top_left].x;
		line[1].y = corners[top_left].y;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLines(renderer, line, 2);
	}
	if (side_missing[left] == 0) {
		line[0].x = corners[top_left].x;
		line[0].y = corners[top_left].y;
		line[1].x = corners[bottom_left].x;
		line[1].y = corners[bottom_left].y;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLines(renderer, line, 2);
	}
	if (side_missing[bottom] == 0) {
		line[0].x = corners[bottom_left].x;
		line[0].y = corners[bottom_left].y;
		line[1].x = corners[bottom_right].x;
		line[1].y = corners[bottom_right].y;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLines(renderer, line, 2);
	}
	//}	
}

void model::room::setSize(int newSize) {
	size = newSize;
}

void model::room::setVisited() {
	visited = 1;
}

bool model::room::isVisited() {
	return visited;
}
void model::room::setPrev(int x, int y) {
	prev_room.x = x;
	prev_room.y = y;
}
SDL_Point model::room::getPrev() {
	return prev_room;
}

bool model::room::isWallMissing(sides Side) {
	return side_missing[Side];
}

void model::room::setWall(sides side) {
	side_missing[side] = 0;
}
