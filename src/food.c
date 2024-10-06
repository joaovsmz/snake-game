#include <stdlib.h>
#include <stdio.h>
#include "../include/board.h"
#include "../include/position.h"
#include "../include/food.h"

void placeFood(BOARD* board){
    POSITION food_position;
    int valid_position;
    int iter = 0;
    do
    {
        food_position = crateRandomPosition(board->columns, board->rows);
        valid_position = isEmptyPlace(board, &food_position);
    } while (!valid_position || iter == MAX_ITER);
    
    placeElement(board, &food_position, FOOD_SPRITE);

}

