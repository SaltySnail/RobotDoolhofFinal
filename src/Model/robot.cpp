#include "robot.h"

void model::robot::init(SDL_Renderer *renderer, maze *yourMaze) {
	txtr = IMG_LoadTexture(renderer, TXTR_ROBOT);
	location.x = 0;//start.x*ROOM_SIZE;
	location.y = 0;//start.y*ROOM_SIZE;
	myMaze = yourMaze;
	weight_counter = 0;
	SDL_Point tmp;
	tmp.x = (SCREEN_WIDTH/ROOM_SIZE)-1;
	tmp.y = (SCREEN_HEIGHT/ROOM_SIZE)-1;
	thePath.setWeightFinish(tmp);
}

void model::robot::draw(SDL_Renderer *renderer) {	
	SDL_Rect dest;
	dest.x = location.x;
	dest.y = location.y;
	SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
	dest.w /= -ROBOT_ZOOM; //zoom out
	dest.h /= -ROBOT_ZOOM;
	dest.x -= dest.w / 2; //center of robot
	dest.y -= dest.h / 2;
	dest.x += ROOM_SIZE / 2; //center of room
	dest.y += ROOM_SIZE / 2;
	SDL_RenderCopyEx(renderer, txtr, NULL, &dest, angle, NULL,
		SDL_FLIP_NONE);
}

void model::robot::turn(float degrees) {
	if (desired_angle || desired_angle == 0) {
		if ((int)angle%360 == 0) { //limit angle to be between 0 and 360
			angle = 0;
		}
		if (angle < 0) {
			angle = 360+angle; //count down from 360
		}	
		if (sqrt(desired_angle * desired_angle) > sqrt(angle*angle))
			direction = turning_right;
		else 
			direction = turning_left;
		if ((int)angle == (int)desired_angle || (int)(sqrt((angle) * (angle))) == (int)(sqrt(desired_angle * desired_angle))) { //|| (int)(sqrt((angle+360) * (angle+360))) == (int)(sqrt(desired_angle * desired_angle))) {
			(void)desired_angle;
			angle = (int)angle;
			turning = false;
			driving = true;
		}
		else {
			//printf("\t\tangle: %.2f \t desired_angle: %.2f\n", angle, desired_angle);	
			if (direction == turning_left) {	
				angle -= ROBOT_TURN_SPEED;
			}
			else {
				angle += ROBOT_TURN_SPEED;
			}
		}
	}
	else {
		turning = true;
		desired_angle = angle + degrees;
	}
}

void model::robot::setDesiredDegrees() { //deze eerst
	if (location.x == counter.x*ROOM_SIZE && location.y == counter.y*ROOM_SIZE) {
	SDL_Point tmp;
	tmp.x = counter.x;
	tmp.y = counter.y;
	setCurrentRoom();
	thePath.getNextRoom(&counter, &weight_counter);
	//printf("Got the next room boss: %d, %d\n", counter.x, counter.y);
	if (counter.x > tmp.x) { 
		desired_angle = degreesRight; 
		//printf("I chose right, with angle %.2f\n", desired_angle);
	}
	if (counter.y > tmp.y) {
		desired_angle = degreesBottom;
		//printf("I chose bottom, with angle %.2f\n", desired_angle);
	}
	if (counter.x < tmp.x) {
		desired_angle = degreesLeft;
		//printf("I chose left, with angle %.2f\n", desired_angle);
	}
	if (counter.y < tmp.y){
		desired_angle = degreesTop;
		//printf("I chose top, with angle %.2f\n", desired_angle);
	}
		turning = true;
	}	
} 

void model::robot::drive(float speed) { //dan deze
	if (driving == true) { 
		location.x += speed*cos((angle+90)*M_PI/180);
		location.y += speed*sin((angle+90)*M_PI/180);
		if (location.x == counter.x*ROOM_SIZE && location.y == counter.y*ROOM_SIZE) {
		//if (location.x/ROOM_SIZE == (int)(location.x/ROOM_SIZE) && location.y/ROOM_SIZE == (int)(location.y*ROOM_SIZE)) {
			driving = false;
		}
	}
}

bool model::robot::isTurning() {
	return turning;
}

void model::robot::setCurrentRoom(void) {
	current_room = myMaze->getRoomByCoords(location);
}

void model::robot::update(void) {
	if (!path_init) {
		thePath.init(myMaze);
		path_init = true;
	}
	if (!finished) {
	 //&& counter.y < SCREEN_HEIGHT/ROOM_SIZE) {
		if (!driving) {	
			finished = thePath.isFinished(counter);
			setDesiredDegrees();
		}
		if (turning) {
			turn(0);
			//printf("turning\n");
		}
		if (driving) {
			drive(ROBOT_SPEED);
			//printf("driving\n");
		}
	} else {
		angle++;
	}	
}
