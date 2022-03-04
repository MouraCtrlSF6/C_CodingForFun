#include<stdio.h>
int main (void){
    char word[20]={};
    int i,j;
    printf("Type a word: ");
    gets(word);

    printf("\n");
    for(i=0;i<sizeof(word);i++){
        //Defines how many characters will be printed
        if(word[i]!=NULL){
            //If it's not a blank space
            for(j=0;j<=i;j++){
                //Prints the characters
                printf("%c",word[j]);
            }
        //Jumps to the next line
        printf("\n");
        }
    }
    printf("\n");
}
