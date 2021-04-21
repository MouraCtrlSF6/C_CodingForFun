#include <stdio.h>
#include <stdlib.h>
#define SIZE 16

enum state{now=1, first=0};
void sort(int *ptr){
    int adress[2]={};
    adress[first] = ptr;
    
    for(ptr; ptr < (adress[first] + 4*(SIZE - 1)) + 1; ptr++){
        adress[now] = ptr;
        for(int i = 0; i < SIZE - (adress[now] - adress[first])/4 ; i++){
            if(*ptr > *(ptr + i)){
                *ptr += *(ptr + i);
                *(ptr + i) = *ptr - *(ptr + i);
                *ptr = *ptr - *(ptr + i);
            }
        }
    }
}

int main (void){
    int vet[SIZE] = {2,3,1,9,8,7,5,4,6,0,14,12,13,11,10,15};
    sort(vet);
    system("cls");
    printf("\n- ");
    for (int i=0; i<SIZE; i++){
        printf("%d - ", vet[i]);
    }
    printf("\n\n");
    while(0b00001101 != getch()){}
}