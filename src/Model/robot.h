#ifndef ROBOT
#define ROBOT

#include "maze.h"
#include "path.h"

#define ROBOT_ZOOM -12
#define ROBOT_SPEED 2
#define ROBOT_TURN_SPEED 5

namespace model {
	enum directions {
			turning_right,
			turning_left
	};
	enum sideDegrees {
		degreesTop = 180,	
		degreesLeft = 90,
		degreesBottom = 0,
		degreesRight = 270	
	};
	class robot {
			int width, height, weight_counter;
			SDL_Point location;
			SDL_Texture *txtr;
			float angle, desired_angle;
			bool turning, driving, path_init, finished;
			room *current_room;
			path thePath;
			directions direction;
			SDL_Point counter;
			maze *myMaze;
		public:
			void draw(SDL_Renderer *renderer);
			void init(SDL_Renderer *renderer, maze *yourMaze);
			void turn(float degrees);
			void drive(float speed);
			bool isTurning(void);
			void setCurrentRoom(void);
			void getRoom(void);
			void setDesiredDegrees(void);
			void update(void);
	};	
}

#endif
