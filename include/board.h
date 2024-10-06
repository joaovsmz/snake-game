#ifndef BOARD_H_
#define BOARD_H_
#include "position.h"

#define EMPTY '.'

#define EASY '1'
#define MEDIUM '2'
#define HARD '3'

#define EASY_ROWS 10
#define EASY_COLUMNS 30
#define MEDIUM_ROWS 8
#define MEDIUM_COLUMNS 26
#define HARD_ROWS 6
#define HARD_COLUMNS 21

#define ROW_DELAY_US 400*1000 
#define COLUMN_DELAY_US ROW_DELAY_US/5 
        

struct board
{
    char** map;
    int columns;
    int rows;
};
typedef struct board BOARD;

char** allocateMatrix(int cols, int rows);
void fillBoard(BOARD* board);
void displayBoard(BOARD* board);
BOARD createBoard(char dificulty);
void deleteBoard(BOARD* board);
void placeElement(BOARD* board, POSITION* position, char sprite);
int isEmptyPlace(BOARD* board, POSITION* position);

#endif //BOARD_H_