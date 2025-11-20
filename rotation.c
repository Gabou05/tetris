#include <stdio.h>
#include <time.h>

#define LENGTH 10
#define X_ORIGIN 5
#define Y_ORIGIN 5

void display(int tab[LENGTH][LENGTH]){
    int i,j;
    for (i = 0; i < LENGTH;i++ ) {
        for (j = 0; j < LENGTH; j ++){
            printf("%d ", tab[i][j]);
        }
    printf("\n");
    }
}

void rotation_unite(int tab[LENGTH][LENGTH],int x, int y, int rotation){
    tab[x][y] = 0;
    switch(rotation){
        case 1 :
            tab[x + 2* (X_ORIGIN - x) - 1][y] = 1;
            break;
        case 2 :
            tab[x + 2*(X_ORIGIN - x) - 1][y + 2 *(X_ORIGIN - y) - 1] = 1;
            break;
        case 3 :
            tab[x][y + 2*(Y_ORIGIN - y) - 1] = 1;
            break;
        default:
            tab[x][y] = 1;
            break;
    }
}

void rotation(int tab[LENGTH][LENGTH], int rotation){
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
                rotation_unite(tab,i,j,rotation);
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
    rotation(tab,choice);
    display(tab);
    return 0;
}
