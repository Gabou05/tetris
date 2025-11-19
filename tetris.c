#include <stdio.h>
#include <stdlib.h>

#define GRID_ROW 20
#define GRID_COLUMN 10
#define MAX_BLOCK 200

typedef struct square{
    int coordinates[2];
}square;

typedef struct block{
    square archi[5];
}block;

int grid_game[20][10]; /* Playground */
int ** block_placed; /* List of block in the grid */
block block_list[7]; /* List of possible block which can appear */

void init(){
    // INIT all the blocks
    square q0 = {{0,0}};
    square q1 = {{0,1}};
    square q2 = {{0,2}};
    square q3 = {{0,3}};
    square q5 = {{1,0}};
    square q6 = {{1,1}};
    square q7 = {{1,2}};
    
    block I = {{q0,q1,q2,q3}};
    block J = {{q0,q5,q6,q7}};
    block L = {{q5,q6,q7,q2}};
    block O = {{q0,q1,q5,q6}};
    block S = {{q5,q6,q1,q2}};
    block T = {{q5,q6,q7,q1}};
    block Z = {{q0,q1,q6,q7}};
    
    block_list[0] = I;
    block_list[1] = J;
    block_list[2] = L;
    block_list[3] = O;
    block_list[4] = S;
    block_list[5] = T;
    block_list[6] = Z;

    int i;
    int j;
    for(i = 0; i < GRID_ROW; i++) {
        for(j = 0; j < GRID_COLUMN; j++){
            grid_game[i][j] = 0;
        }
    }
    block_placed = malloc(200*sizeof(int *));
}

void print_grid(){
    int i; 
    int j;
    for (j = 0; j < GRID_COLUMN; j++){
        printf("--");
    }
    printf("\n");
    for(i = 0; i < GRID_ROW; i++){
        for(j = 0; j < GRID_COLUMN; j++){
            if(j == 0){
                printf("|%d|", grid_game[i][j]);
            } else {
                printf("%d|", grid_game[i][j]);
            }
        }
        printf("\n");
    }
    for (j = 0; j < GRID_COLUMN; j++){
        printf("--");
    }
    printf("\n");
}

block spawn_block(){
    
}

int main() {
    init();
    while(1){
        spawn_block();
        print_grid();
    }
    return 0;
}
