#ifndef PATH_H
#define PATH_H

#include "node.h"

namespace model {
	class path {
			maze *theMaze;
			node nodes[SCREEN_WIDTH/ROOM_SIZE][SCREEN_HEIGHT/ROOM_SIZE];
		public:
			void init(maze *yourMaze);
			void getNextRoom(SDL_Point *counter, int *weight_counter);
			void setWeightFinish(SDL_Point finish);	
			bool isFinished(SDL_Point counter);
			void setWeightStart(void);
	};
}

#endif
