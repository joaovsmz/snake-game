#include <stdio.h>
#include <ncurses.h>
#include "../include/snake.h"
#include "../include/board.h"
#include "../include/position.h"
#include "../include/food.h"

SNAKE createSnake(BOARD* board){
    //default: create snake at origin
    SNAKE snake;
    POSITION head_position;
    POSITION tail_position;
    head_position.x = 0;
    head_position.y = 0;
    tail_position.x = 0;
    tail_position.y = 0;
    snake.refresh_delay = -1;
    snake.length = 0;
    snake.score = 0;
    snake.head_sprite = HEAD_UP;
    snake.head = head_position;
    snake.tail = tail_position;
    placeElement(board, &head_position, snake.head_sprite);
    return snake;
}

int moveSnake(SNAKE* snake, BOARD* board, int head_direction, int tail_direction){
    int move_flag = MOVE_FLAG; //normally moves

    POSITION current_snake_head = snake->head;
    POSITION current_snake_tail = snake->tail;

    POSITION next_head_position;
    POSITION next_tail_position;

    //get new head and tail position
    next_head_position = nextElementPosition(&current_snake_head, head_direction, board->columns, board->rows);
    next_tail_position = nextElementPosition(&current_snake_tail, tail_direction, board->columns, board->rows);

    //dies
    if (snakeDies(board, &next_head_position)){
        return DIE_FLAG;
    }

    //eats
    if (snakeEats(board, &next_head_position)){
        move_flag = ATE_FLAG;
        snake->score = snake->score + 1;
        snake->refresh_delay = snake->length;
    }

    //update position
    updateSnakeHead(snake, board, head_direction, next_head_position);

    updateSnakeTail(snake, board, next_tail_position);

    //printw("refresh delay %d\r\n", snake->refresh_delay);

    if(snake->refresh_delay >= 0) //after each move, the refresh delay decreases
        snake->refresh_delay = snake->refresh_delay - 1;

    return move_flag;
}

int snakeEats(BOARD* board, POSITION* snake_head_position){
    char sprite;
    sprite = board->map[snake_head_position->y][snake_head_position->x];
    if(sprite == FOOD_SPRITE)
        return 1;
    return 0;
}

int snakeDies(BOARD* board, POSITION* snake_head_position){
    char sprite;
    sprite = board->map[snake_head_position->y][snake_head_position->x];
    if(sprite == BODY_SPRITE)
        return 1;
    return 0;
}

POSITION nextElementPosition(POSITION* old_position, int direction, int x_limit, int y_limit){
    POSITION next_position;
    switch (direction)
    {
    case KEY_UP:
        next_position.x = old_position->x;
        next_position.y = getDesiredPosition(old_position->y - 1, y_limit);
        break;
    case KEY_DOWN:
        next_position.x = old_position->x;
        next_position.y = getDesiredPosition(old_position->y + 1, y_limit);
        break;
    case KEY_RIGHT:
        next_position.x = getDesiredPosition(old_position->x + 1, x_limit);
        next_position.y = old_position->y;
        break;
    case KEY_LEFT:
        next_position.x = getDesiredPosition(old_position->x - 1, x_limit);
        next_position.y = old_position->y;
        break;
    default:
        next_position.x = old_position->x;
        next_position.y = old_position->y;
        break;
    }

    return next_position;
}

void updateSnakeHead(SNAKE* snake, BOARD* board, int direction, POSITION next_head_position){
    char next_head_sprite;
    char last_position_sprite = EMPTY;
    POSITION current_snake_head = snake->head;

    switch (direction)
    {
    case KEY_UP:
        next_head_sprite = HEAD_UP;
        break;
    case KEY_DOWN:
        next_head_sprite = HEAD_DOWN;
        break;
    case KEY_RIGHT:
        next_head_sprite = HEAD_RIGHT;
        break;
    case KEY_LEFT:
        next_head_sprite = HEAD_LEFT;
        break;
    default:
        next_head_sprite = snake->head_sprite;
        break;
    }

    snake->head = next_head_position;
    snake->head_sprite = next_head_sprite;
    if (snake->length <= 1)
        last_position_sprite = EMPTY;   
    else
        last_position_sprite = BODY_SPRITE;
        
    // printw("next_head_sprite %c\r\n", snake->head_sprite);
    // printw("next_head_position %d %d\r\n", current_snake_head.y, current_snake_head.x);
    // printw("head func:\r\n");
    placeElement(board, &current_snake_head, last_position_sprite);
    placeElement(board, &next_head_position, next_head_sprite);
    return;

}

void updateSnakeTail(SNAKE* snake, BOARD* board, POSITION next_tail_position){
    POSITION current_snake_tail = snake->tail;
    //printw("tail func:\r\n");
    //printw("next_tail_position %d %d\r\n", next_tail_position.y, next_tail_position.x);

    placeElement(board, &current_snake_tail, EMPTY);

    if(snake->length > 0)
        placeElement(board, &next_tail_position, BODY_SPRITE);

    if(snake->refresh_delay == 0){//update only when the refresh_delay flag is zero
        snake->length = snake->length + 1;
        return;
    }
    
    snake->tail = next_tail_position;

    
    return;
}

int updateDirection(int current_direction, int desired_direction){
    if(desired_direction == ERR)
        return current_direction;
    //does not accept 
    if( desired_direction != KEY_UP && 
        desired_direction != KEY_DOWN &&
        desired_direction != KEY_LEFT &&
        desired_direction != KEY_RIGHT)
        return current_direction;
    //cant go fully backwards, ignore the desired position    
    if(current_direction == KEY_UP && desired_direction == KEY_DOWN)
        return current_direction;
    if(current_direction == KEY_DOWN && desired_direction == KEY_UP)
        return current_direction;
    if(current_direction == KEY_LEFT && desired_direction == KEY_RIGHT)
        return current_direction;
    if(current_direction == KEY_RIGHT && desired_direction == KEY_LEFT)
        return current_direction;

    return desired_direction;
    
}