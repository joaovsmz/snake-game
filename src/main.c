#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#include "../include/board.h"
#include "../include/snake.h"
#include "../include/position.h"
#include "../include/food.h"
#include "../include/array.h"

int main()
{
    BOARD board;
    SNAKE snake;
    int direction_array[MAX_LENGTH];
    int direction = KEY_UP;
    int input;
    char dificulty;
    int flag = MOVE_FLAG;

    initscr();
    noecho();
    cbreak(); 
    keypad(stdscr, TRUE);		

    //section: get difficulty
    printw("Bem vindo ao jogo Snake!\n\n");
    printw("Use as setas para jogar e Q para sair\n");
    printw("Escolha a dificuldade para jogar:\n");
    printw("1-Facil\t2-Medio\t3-Dificil:\n\n");
    refresh();
    dificulty = getch();
    printw("%c", dificulty);
    refresh();


    // //avoid error input
    while (dificulty != EASY && dificulty != MEDIUM && dificulty != HARD){
        clear();
        printw("Bem vindo ao jogo Snake!\n\n");
        printw("Use as setas para jogar e Q para sair\n");
        printw("Dificuldade invalida, escolha novamente\n");
        printw("1-Facil\t2-Medio\t3-Dificil:\n\n");
        refresh();
        dificulty = getch();
        printw("%c", dificulty);
        refresh();
    }

    //section: difficult obtained, create board accordingly
    switch (dificulty)
    {
    case EASY:
        printw("\nVoce escolheu facil\n");
        refresh();
        board = createBoard(EASY);
        break;
    case MEDIUM:
        printw("\nVoce escolheu medio\n");
        refresh();
        board = createBoard(MEDIUM);
        break;
    case HARD:
        printw("\nVoce escolheu dificil\n");
        refresh();
        board = createBoard(HARD);
    default:
        break;
    }
    
    //section: start game!
    snake = createSnake(&board);
    placeFood(&board);

    nodelay(stdscr, TRUE);

    while(1){
        clear();
        displayBoard(&board);
        refresh();

        input = getch();
        if (input == 'q')
            break;
        
        direction = updateDirection(direction, input);

        insertElement(direction_array, direction);
        flag = moveSnake(&snake,&board, direction_array[0], direction_array[snake.length]);

        if (flag == DIE_FLAG){
            clear();
            refresh();
            displayBoard(&board);
            printw("Voce morreu\n");
            refresh();
            break;
        }

        if (flag == ATE_FLAG)
            placeFood(&board);
        
        if(direction == KEY_LEFT || direction == KEY_RIGHT)
            usleep(COLUMN_DELAY_US); //different delay because columns are closer spaced than rows
        usleep(ROW_DELAY_US);

        clear();
        refresh();
    }
    nodelay(stdscr, FALSE);
    
    //section: end game :(
    printw("\n\nObrigado por jogar! Sua pontuacao foi %d pontos\n\n", snake.score);
    printw("Pressione qualquer tecla para sair");
    refresh();
    getch();

    endwin();
    deleteBoard(&board);
    

    return 0;
}