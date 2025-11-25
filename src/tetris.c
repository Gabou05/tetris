#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "rotation.h"

#define GRID_ROW 20
#define GRID_COLUMN 10
#define MAX_BLOCK 200
#define NB_BLOCK 7

typedef struct square{
    int coordinates[2];
}square;

typedef struct block{
    square archi[5];
    square pivot;
    int nb_square;
}block;

int grid_game[20][10]; /* Playground */
int ** block_placed; /* List of block in the grid */
block block_list[NB_BLOCK]; /* List of possible block which can appear */

void init(){
    int i;
    int j;
    square q0 = {{0,4}};
    square q1 = {{0,5}};
    square q2 = {{0,6}};
    square q3 = {{0,7}};
    square q5 = {{1,4}};
    square q6 = {{1,5}};
    square q7 = {{1,6}};
    
    block I = {{q0,q1,q2,q3},q2,4};
    block J = {{q0,q5,q6,q7},q6,4};
    block L = {{q5,q6,q7,q2},q6,4};
    block O = {{q0,q1,q5,q6},q1,4};
    block S = {{q5,q6,q1,q2},q6,4};
    block T = {{q5,q6,q7,q1},q6,4};
    block Z = {{q0,q1,q6,q7},q6,4};
    
    block_list[0] = I;
    block_list[1] = J;
    block_list[2] = L;
    block_list[3] = O;
    block_list[4] = S;
    block_list[5] = T;
    block_list[6] = Z;

    for(i = 0; i < GRID_ROW; i++) {
        for(j = 0; j < GRID_COLUMN; j++){
            grid_game[i][j] = 0;
        }
    }
    block_placed = malloc(200*sizeof(int *));
    srand(time(NULL));
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
}

void print_grid(){
    int i; 
    int j;
    for (j = 0; j < GRID_COLUMN; j++){
        printw("--");
    }
    printf("\n");
    for(i = 0; i < GRID_ROW; i++){
        for(j = 0; j < GRID_COLUMN; j++){
            if(j == 0){
                printw("|%d|", grid_game[i][j]);
            } else {
                printw("%d|", grid_game[i][j]);
            }
        }
        printw("\n");
    }
    for (j = 0; j < GRID_COLUMN; j++){
        printw("--");
    }
    printw("\n");
    refresh();
}

block choose_random_block(){
    int rdm = rand()%7;
    block chosen_block = block_list[rdm];
    return chosen_block;
}

void place_block(block b){
    int i;
    for(i = 0; i < b.nb_square; i++){
        grid_game[b.archi[i].coordinates[0]][b.archi[i].coordinates[1]] = 1;
    }
}

int block_is_placed(block b){
    int i;
    for(i = 0; i < b.nb_square; i++){
        if(grid_game[b.archi[i].coordinates[0]][b.archi[i].coordinates[1]-1] == 2){
            return 1;
        }
    }
    return 0;
}

void remove_block_grid(block b){
    int i;
    for(i = 0; i < b.nb_square; i++){
        grid_game[b.archi[i].coordinates[0]][b.archi[i].coordinates[1]] = 0;
    }  
}

bool is_moveable(block b, int depl){
    int i;
    for(i = 0; i < b.nb_square; i++){
        if(b.archi[i].coordinates[1] + depl < 0 || b.archi[i].coordinates[1]+depl > GRID_COLUMN){
            return FALSE;
        }
    }
    return TRUE;
}


void move_block(block b, int depl){
    int i;
    if(is_moveable(b,depl) == TRUE){
        for(i = 0; i < b.nb_square; i++){
            b.archi[i].coordinates[1] += depl;
        }
    }
}

void rotate_90(block b){
    int i;
    for(i = 0; i < b.nb_square;i++){
        square * ptr = &b.archi[i];
        rotation(ptr,1,b.pivot.coordinates[0],b.pivot.coordinates[1]);
    }
}

void play_block(block b){
    remove_block_grid(b);
     switch(getch()) {
        case KEY_UP:
            rotate_90(b);
        case KEY_RIGHT:
            move_block(b,1);
        case KEY_LEFT:
            move_block(b,-1);
        default:
    }
}

int main() {
    block b;
    init();
    while(1){
        b = choose_random_block();
        place_block(b);
        while(block_is_placed(b) == 0){
            play_block(b);
        }
        print_grid();
    }
    return 0;
}
