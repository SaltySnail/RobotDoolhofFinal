#ifndef MAZE_H
#define MAZE_H

#include "room.h"
#include "init.h"

#if SCREEN_WIDTH == TV_WIDTH
	#define ROOM_SIZE 30
#else
	#define ROOM_SIZE 32
#endif

//Mogelijke sizes op 2560x1440: 1, 2,4,5,8,10,16,20,32,40,80,160
//Mogelijke sizes op 3840x2160: 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 16, 20, 24, 30, 40, 48, 60, 80, 120, 240

namespace model {
	class maze {
			SDL_Point start, finish;
			room rooms[(SCREEN_WIDTH/ROOM_SIZE)][(SCREEN_HEIGHT/ROOM_SIZE)];
		public:
			void initRooms(void);
			void draw(SDL_Renderer *renderer);
			void generate(SDL_Point *counter, bool *end);
			void setStartEnd(SDL_Point setStart, SDL_Point setEnd);
			SDL_Point getStart(void);
			SDL_Point getEnd(void);
			model::room *getRoomByCoords(SDL_Point coords);
			void stupidlyCorrectBorders(SDL_Renderer *renderer);
	};
}

#endif
