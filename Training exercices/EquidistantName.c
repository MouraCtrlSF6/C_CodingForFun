#include<stdio.h>
#include<stdlib.h>

int main (void){
    char word[40]={};
    int a, i;
    while(1){
        printf("Type a word: ");
        gets(word);
        for(i=0;i<sizeof(word);i++){
            if(word[i]!=NULL){
                if(('a'>word[i]&&word[i]>'z')||('A'>word[i]&&word[i]>'Z')){
                    printf("Input not valid. Please, type a word: ");
                    gets(word);
                    i=0;
                }
            }
        }
        printf("Resulting word: ");
        for(i=0;i<sizeof(word);i++){
            if('a'<=word[i] && word[i]<='z'){
                a = 'n' - word[i];
                a = 'n' + a - 1;
                word[i] = a;
            }
            if('A'<=word[i]&&word[i]<='Z'){
                a = 'N' - word[i];
                a = 'N' + a - 1;
                word[i] = a;
            }

            printf("%c",word[i]);
        }
        printf("\n\n");
        for(i=0;i<sizeof(word);i++){
            word[i]=NULL;
        }
    }
}
