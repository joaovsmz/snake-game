#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/board.h"
#include "../include/position.h"

char** allocateMatrix(int columns, int rows){
    char** matrix = malloc(rows * sizeof(char*));
    for (int row = 0;row < rows; row++)
        matrix[row] = malloc(columns * sizeof(char));

    return matrix;

}

BOARD createBoard(char dificulty){
    BOARD board;
    int board_columns, board_rows;
    switch (dificulty)
    {
    case EASY:
        board_columns = EASY_COLUMNS; 
        board_rows = EASY_ROWS;
        break;
    case MEDIUM:
        board_columns = MEDIUM_COLUMNS; 
        board_rows = MEDIUM_ROWS;
        break;
    case HARD:
        board_columns = HARD_COLUMNS; 
        board_rows = HARD_ROWS;
        break;
    default:
        break;
    }
    board.columns = board_columns;
    board.rows = board_rows;
    board.map = allocateMatrix(board_columns, board_rows);

    fillBoard(&board);
    return board;

}

void fillBoard(BOARD* board){
    for(int column = 0; column < board->columns; column++)
        for (int row = 0; row < board->rows; row++)
            board->map[row][column] = EMPTY;
    
    return;
}

void displayBoard(BOARD* board){
    for(int row = 0; row < board->rows; row++){
        for (int column = 0; column < board->columns; column++){
            printw("%c", board->map[row][column]);
        }
        printw("\n");
    }
    return;
}

void deleteBoard(BOARD* board)
{
    for(int row = 0; row < board->rows; row++)
        free(board->map[row]);
    free(board->map);
    return;
}

void placeElement(BOARD* board, POSITION* position, char sprite){
    //row -> y
    //column -> x
    board->map[position->y][position->x] = sprite;
    return;
}

int isEmptyPlace(BOARD* board, POSITION* position){
    //row -> y
    //column -> x
    if (board->map[position->y][position->x] == EMPTY)
        return 1;
    return 0;
}