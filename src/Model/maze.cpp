#include "maze.h"


void model::maze::initRooms(void) {
	SDL_Point tmp;
	for (int j = 0; j < SCREEN_HEIGHT/ROOM_SIZE; j++) {
		for (int i = 0; i < SCREEN_WIDTH/ROOM_SIZE; i++) {
			rooms[i][j].setWall(right);
			rooms[i][j].setWall(top);
			rooms[i][j].setWall(left);
			rooms[i][j].setWall(bottom);
			rooms[i][j].setSize(ROOM_SIZE);
			tmp.x = i*ROOM_SIZE; 
			tmp.y = j*ROOM_SIZE; 
			rooms[i][j].setCoords(tmp);
		}
	}
}

void model::maze::draw(SDL_Renderer *renderer) {	
	for (int j = 0; j < SCREEN_HEIGHT/ROOM_SIZE; j++) {
		for (int i = 0; i < SCREEN_WIDTH/ROOM_SIZE; i++) {
			rooms[i][j].draw(renderer);
		}
	}
}
void model::maze::generate(SDL_Point *counter, bool *end) { 
	int chosen_neighbour;
	int i = counter->x;
	int j = counter->y;
			chosen_neighbour = rand() % 4;
			rooms[i][j].setVisited();
				if ((rooms[i+1][j  ].isVisited() == 1 && 
				    rooms[i  ][j-1].isVisited() == 1 &&
				    rooms[i-1][j  ].isVisited() == 1 &&
				    rooms[i  ][j+1].isVisited() == 1 ) && 
				    (i > 0 && j > 0 && i+1 < SCREEN_WIDTH/ROOM_SIZE && j+1 < SCREEN_HEIGHT/ROOM_SIZE)) {
					SDL_Point prev = rooms[i][j].getPrev();
					i = prev.x;
					j = prev.y;
				}
				if (//side cases
				  (rooms[i  ][j+1].isVisited() == 1 && rooms[i-1][j  ].isVisited() == 1 && rooms[i+1][j  ].isVisited() == 1 && j == 0) ||
				  (rooms[i  ][j-1].isVisited() == 1 && rooms[i  ][j+1].isVisited() == 1 && rooms[i+1][j  ].isVisited() == 1 && i == 0) ||
				  (rooms[i  ][j-1].isVisited() == 1 && rooms[i-1][j  ].isVisited() == 1 && rooms[i+1][j  ].isVisited() == 1 && j == SCREEN_HEIGHT/ROOM_SIZE-1) ||
				  (rooms[i  ][j-1].isVisited() == 1 && rooms[i  ][j+1].isVisited() == 1 && rooms[i-1][j  ].isVisited() == 1 && i == SCREEN_WIDTH/ROOM_SIZE-1) || 
				  //corner cases
				  (rooms[i  ][j+1].isVisited() == 1 && rooms[i+1][j  ].isVisited() == 1 && i == 0 && j == 0) ||
				  (rooms[i  ][j+1].isVisited() == 1 && rooms[i-1][j  ].isVisited() == 1 && i == SCREEN_WIDTH/ROOM_SIZE-1 && j == 0) || 
				  (rooms[i  ][j-1].isVisited() == 1 && rooms[i+1][j  ].isVisited() == 1 && i == 0 && j == SCREEN_HEIGHT/ROOM_SIZE-1) ||
				  (rooms[i  ][j-1].isVisited() == 1 && rooms[i-1][j  ].isVisited() == 1 && i == SCREEN_WIDTH/ROOM_SIZE-1 && j == SCREEN_HEIGHT/ROOM_SIZE-1)) {
					SDL_Point prev = rooms[i][j].getPrev();
					i = prev.x;
					j = prev.y;
					if (i == 0 && j == 0) {
						*end = 1;
					}
				}
				if (i+1 < SCREEN_WIDTH/ROOM_SIZE && rooms[i+1][j].isVisited() == 0 && chosen_neighbour == right) { //right side
				      	rooms[i][j].setMissingWall(right);
					rooms[i+1][j].setMissingWall(left);
					rooms[i+1][j].setPrev(i, j);
					i++;
				}
				if (j > 0 && rooms[i][j-1].isVisited() == 0 && chosen_neighbour == top) { //top side
				      	rooms[i][j].setMissingWall(top);
					rooms[i][j-1].setMissingWall(bottom);
					rooms[i][j-1].setPrev(i, j);
					j--;
				}
				if (i > 0 && rooms[i-1][j].isVisited() == 0 && chosen_neighbour == left) { //left side
				      	rooms[i][j].setMissingWall(left);
					rooms[i-1][j].setMissingWall(right);
					rooms[i-1][j].setPrev(i, j);
					i--;
				}
				if (j+1 < SCREEN_HEIGHT/ROOM_SIZE && rooms[i][j+1].isVisited() == 0 && chosen_neighbour == bottom) { //bottom side
				      	rooms[i][j].setMissingWall(bottom);
					rooms[i][j+1].setMissingWall(top);
					rooms[i][j+1].setPrev(i, j);

					j++;
				}
	counter->x = i;
	counter->y = j;
}

void model::maze::setStartEnd(SDL_Point setStart, SDL_Point setEnd) {
	start.x = setStart.x;
	start.y = setStart.y;
	finish.x = setEnd.x;
	finish.y = setEnd.y;
	rooms[start.x][start.y].setMissingWall(top);
	rooms[finish.x][finish.y].setMissingWall(bottom);
}

SDL_Point model::maze::getStart(void) {
	return start;
}

SDL_Point model::maze::getEnd(void) {
	return finish;
}

void model::maze::stupidlyCorrectBorders(SDL_Renderer *renderer) {
	SDL_Point line[2];
	int offset = 0;//, weird_offset = 0;
	if (SCREEN_WIDTH == TV_WIDTH) {
		offset = 1;//3;
		weird_offset = 4; 
	} else {
		offset = 1;
		weird_offset = 1; 
	}
	line[0].x = SCREEN_WIDTH-offset; //rechts
	line[0].y = SCREEN_HEIGHT-offset;
	line[1].x = SCREEN_WIDTH-offset;
	line[1].y = 0;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //RGBA
	SDL_RenderDrawLines(renderer, line, 2);

	line[0].x = 0; //onder
	line[0].y = SCREEN_HEIGHT-offset;//-weird_offset;
	line[1].x = SCREEN_WIDTH-ROOM_SIZE-offset;
	line[1].y = SCREEN_HEIGHT-offset;//-weird_offset;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //RGBA
	SDL_RenderDrawLines(renderer, line, 2);

	line[0].x = ROOM_SIZE; //boven
	line[0].y = 0;
	line[1].x = SCREEN_WIDTH-offset;
	line[1].y = 0;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //RGBA
	SDL_RenderDrawLines(renderer, line, 2);
	
	if (SCREEN_WIDTH == TV_WIDTH) { 
	//manjaro kan geen 4k, of LG cx is niet echt 4K, of OLED pixel shift verpest het, of het coordinaten systeem is zojuist in de soep gelopen (eerst deed hij het zonder deze rare dingen).
	//Een andere mogelijke oorzaak is X11 die de schermen aan elkaar naait.
	//of simplescreenrecorder is de boosdoener
	//of SDL maakt niet altijd de window op dezelfde positie aan
	line[0].x = ROOM_SIZE; //boven
	line[0].y = offset;
	line[1].x = SCREEN_WIDTH-offset;
	line[1].y = offset;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //RGBA
	SDL_RenderDrawLines(renderer, line, 2);
	

	line[0].x = offset; //links
	line[0].y = 0;//offset;
	line[1].x = offset;
	line[1].y = SCREEN_HEIGHT;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //RGBA
	SDL_RenderDrawLines(renderer, line, 2);
	}
}

model::room *model::maze::getRoomByCoords(SDL_Point coords) {
	if ((int)(coords.x/ROOM_SIZE) == coords.x/ROOM_SIZE &&
	    (int)(coords.y/ROOM_SIZE) == coords.y/ROOM_SIZE) {
		return &rooms[coords.x/ROOM_SIZE][coords.y/ROOM_SIZE];
	} 
}
