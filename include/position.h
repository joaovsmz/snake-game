#ifndef POSITION_H_
#define POSITION_H_

struct position
{
    int x;
    int y;
};
typedef struct position POSITION;

POSITION crateRandomPosition(int x_limit, int y_limit);
int getDesiredPosition(int desired_position, int limit);

#endif //POSITION_H_