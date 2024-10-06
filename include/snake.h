#ifndef SNAKE_H_
#define SNAKE_H_
#include "board.h"
#include "position.h"

#define HEAD_UP '^'
#define HEAD_DOWN 'v'
#define HEAD_LEFT '<'
#define HEAD_RIGHT '>'
#define BODY_SPRITE 'o'

#define ATE_FLAG 1
#define DIE_FLAG -1
#define MOVE_FLAG 0

struct snake
{
    POSITION head;
    POSITION tail;
    char head_sprite; 
    int length;
    int refresh_delay;
    int score;
};
typedef struct snake SNAKE;

SNAKE createSnake(BOARD* board);
int moveSnake(SNAKE* snake, BOARD* board, int head_direction, int tail_direction);
int getDesiredPosition(int desired_position, int limit);
int snakeEats(BOARD* board, POSITION* snake_head_position);
int snakeDies(BOARD* board, POSITION* snake_head_position);
POSITION nextElementPosition(POSITION* old_position, int direction, int x_limit, int y_limit);
void updateSnakeHead(SNAKE* snake, BOARD* board, int direction, POSITION next_head_position);
void updateSnakeTail(SNAKE* snake, BOARD* board, POSITION next_tail_position);
int updateDirection(int current_direction, int desired_direction);


#endif //SNAKE_H_