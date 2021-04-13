#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (void){
    int index=0, freed=0;
    char cell[20] = {};
    printf("Type a cell combination: ");
    gets(cell);
    
    for(int i=0; i<strlen(cell); i++){
        if(cell[i]!='1' && cell[i]!='0'){
            printf("\nOnly binary arguments are accepted!");
            exit(1);
        }
    }
    for(int i=0;index+i<strlen(cell);i++){
        if(cell[index+i]=='1'){
            index+=i;
            freed++;
            i=0;
            for(int j=0;j<strlen(cell);j++){
                if(cell[j]=='1') cell[j] = '0';
                else cell[j] = '1';
            }
        }01
    }
    printf("You freed %d prisioners!", freed);
    getch();
}