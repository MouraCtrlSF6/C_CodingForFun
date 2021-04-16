#include<stdio.h>
#include<windows.h>

int table(char *p){
    int game = 1;
    printf(" %c | %c | %c\n", *p, *(p+1), *(p+2));
    printf("--------\n");
    printf(" %c | %c | %c\n", *(p+3), *(p+4), *(p+5));
    printf("--------\n");
    printf(" %c | %c | %c\n", *(p+6), *(p+7), *(p+8));

    for (int i = 0; i<9; i++){
        if (*(p+i) != 'X' && *(p+i) != 'O') break;
        if(i == 8) game = 2;
    }
    for (int i = 0; i<2; i++){
        if (*(p+i) == *(p+i+3) && *(p+i) == *(p+i+6) && *(p+i) != NULL){
            game = 0;
            break;
        }
        if (*(p+(i*3)) == *(p+1+(i*3)) && *(p+(i*3)) == *(p+2+(i*3)) && *(p+(i*3)) != NULL){
            game = 0;
            break;
        }
    }
    if ((*p == *(p+4) && *p == *(p+8) && *p != NULL) || (*(p+2) == *(p+4) && *(p+2) == *(p+6) && *(p+2) != NULL)) game = 0;
    return game;
}

int main (void){
    system("cls");
    char sim[2] = {'X', 'O'};
    int player = 0;
    int lin, col;
    char vet[9] = {};
    table(vet);

    while(table(vet) == 1){
        system("cls");
        table(vet);
        printf("\nPlayer %d turn\n\n", player+1);
        printf("Type the line: ");
        scanf("%d", &lin);
        if (lin == 99) break;
        while(lin<1 || lin>3 ){
            printf("Line value not valid. Please, type again: ");
            scanf("%d", &lin);
        }

        printf("Type the column: ");
        scanf("%d", &col);
        while(col<1 || col>3){
            printf("Column value not valid. Please, type again: ");
            scanf("%d", &col);
        }

        if(vet[(lin-1)*3 + (col-1)] != 'X' && vet[(lin-1)*3 + (col-1)] != 'O'){
            vet[(lin-1)*3 + (col-1)] = sim[player];
            player++;
            if(player==2) player = 0;
        } else {
        printf("Position already chosen! Type another one.\n");
        Sleep(2000);}
    } system("cls"); 
    if (table(vet) == 2) printf("\nGame over! It's a draw.\n\n");
    else{;
        if(player == 1) player = 0;
        else player = 1;
        printf("\nGame over! player %d is the WINNER!", player+1);
        Sleep(500); 
        printf("!");
        Sleep(500);
        printf("!");
    }
}   
