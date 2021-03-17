#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <SDL2/SDL.h>

namespace model {
	enum sides {
		right,
		top,
		left,
		bottom
	};
	enum square_corners {
		top_left,
		bottom_left,
		bottom_right,
		top_right
	};
	class room {
			int size;
			bool visited = 0;
			bool side_missing[bottom+1];
			SDL_Point corners[top_right+1];
			SDL_Point prev_room;	
		public:
			SDL_Point getPrev(void);
			void setPrev(int x, int y);
			bool isVisited(void);
			void setVisited(void);
			void setMissingWall(int side);
			void setCoords(SDL_Point);
			void setSize(int newSize);
			void draw(SDL_Renderer *renderer);
			bool isWallMissing(sides Side);
			void setWall(sides side);
	};	
}

#endif
