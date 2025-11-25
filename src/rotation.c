#include <stdio.h>
#include <time.h>

#define LENGTH 10

void display(int tab[LENGTH][LENGTH]){
    int i,j;
    for (i = 0; i < LENGTH;i++ ) {
        for (j = 0; j < LENGTH; j ++){
            printf("%d ", tab[i][j]);
        }
    printf("\n");
    }
}

void rotation_unite(int tab[LENGTH][LENGTH],int x, int y, int rotation,int origin_x,int origin_y){
    tab[x][y] = 0;
    switch(rotation){
        case 1 :
            tab[x + 2* (origin_x - x) - 1][y] = 1;
            break;
        case 2 :
            tab[x + 2*(origin_x - x) - 1][y + 2 *(origin_y - y) - 1] = 1;
            break;
        case 3 :
            tab[x][y + 2*(origin_y - y) - 1] = 1;
            break;
        default:
            tab[x][y] = 1;
            break;
    }
}

void rotation(int tab[LENGTH][LENGTH], int rotation,int origin_x,int origin_y){
    /* Récup le pattern à rotate */ 
    int tmp[LENGTH][LENGTH];
    int i;
    int j;
    for(i = 0; i < LENGTH;i++){
        for (j = 0; j < LENGTH;j++ ){
            tmp[i][j] = tab[i][j];
        }
    }
    for(i = 0; i < LENGTH; i++){
        for(j=0; j < LENGTH;j ++){
            if(tmp[i][j] == 1){
                tab[i][j] = 0;
                rotation_unite(tab,i,j,rotation,origin_x,origin_y);
            }
        }
    }
}

int main(){
    int i;
    int j;
    int choice;
    int tab[LENGTH][LENGTH];
    for(i = 0; i < LENGTH; i++){
        for(j =0; j < LENGTH; j++){
            tab[i][j] = 0;
        }
    }
    tab[1][1] = 1;
    display(tab);
    printf("Quelle rotation faire ? : \n");
    printf("1- 90°\n");
    printf("2- 180°\n");
    printf("3- 270°\n");
    scanf(" %d",&choice);
    printf("\n");
    rotation(tab,choice,5,5);
    display(tab);
    return 0;
}
