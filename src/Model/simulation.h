#ifndef MODEL_SIMULATION_H
#define MODEL_SIMULATION_H

#include "maze.h"
#include "init.h"
#include "robot.h"
#include "input.h"

namespace model {
    class simulation {
        public:
            void properInit(void);
            model::init init;
            model::maze maze;
            model::robot robot;
            model::input input;
    };
}

#endif