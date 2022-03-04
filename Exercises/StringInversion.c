#include <stdio.h>
char inversa(char *sp){
    int len = 0;
    char i_str[20] = {};
    for(len; *sp!='\0'; len++){
        sp++;
    }
    sp--;
    for(int i = 0; i<len; i++){
        i_str[i] = *sp;
        sp--;
    } 
    sp++; 
    for(int i = 0; i<len; i++){
        *sp = i_str[i];
        sp++;
    }
}

int main (void){
    char str[20];
    printf("Insira uma string de ate 20 caracteres: ");
    gets(str);
    inversa(str); 
    printf("%s",str);
}