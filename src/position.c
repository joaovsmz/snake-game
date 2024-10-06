#include <stdlib.h>
#include <time.h>
#include "../include/position.h"

POSITION crateRandomPosition(int x_limit, int y_limit){
    //create a random 2D position within stablished limits
    POSITION position;
    srand(time(NULL));
    position.x = rand() % (x_limit);
    position.y = rand() % (y_limit);

    return position;

}

int getDesiredPosition(int desired_position, int limit){
    //calculate a one dimensional valid position between an interval
    //the position can flow to the other direction
    //example: desired position = 7 and limit = 5 returns 2
    if (desired_position < 0)
        return limit + desired_position;
    
    if (desired_position >= limit)
        return limit - desired_position;
    
    return desired_position;
}