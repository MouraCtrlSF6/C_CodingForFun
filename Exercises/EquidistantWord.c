#include<stdio.h>
#include<stdlib.h>
//Note that the alphabet has 26 letters, than "n" and "m" are the middle ones
int main (void){
    char word[40]={};
    int newLetter, i;
    system("cls");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("This program takes your word and changes each letter to the equidistant one in relation to the\nmiddle of the alphabet\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Type a word: ");
    gets(word);
    for(i=0; i<sizeof(word); i++){
        if(word[i]!=NULL){
            if(('a'>word[i] || word[i]>'z')&&('A'>word[i] || word[i]>'Z')){
                printf("Input %s not valid. Please, type a word: ", word);
                for (i=0; i<sizeof(word); i++){
                    word[i] = NULL;
                }
                gets(word);
                i=0;
            }
        }
    }
    printf("Resulting word: ");
    for(i=0; i<sizeof(word); i++){
        if('a'<=word[i] && word[i]<='z'){ 
            newLetter = 2*('n') - word[i] - 1;
            word[i] = newLetter;
        }
        if('A'<=word[i] && word[i]<='Z'){
            newLetter = 2*('N') - word[i] - 1;
            word[i] = newLetter;
        }
        printf("%c", word[i]);
    }
    printf("\n");
    system("pause");
}
