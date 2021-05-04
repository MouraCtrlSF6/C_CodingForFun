#include<stdio.h>

int main(void){
    char word[100]={};
    int flag[2] = {0,0};
    printf("Say a sentece: ");
    gets(word);
    printf("\n");
    for(int i=0;i<sizeof(word);i++){
        if(word[i]!=NULL&&('a'<=word[i]&&word[i]<='z')&&flag=={0,0}){
            word[i]=word[i]-32;
            flag={1,0};
        }
        else{
            if(word[i]!=NULL&&('A'<=word[i]&&word[i]<='Z')&&flag=={1,0}){
                word[i]=word[i]+32;
            }
        }
        printf("%c",word[i]);
    }
    printf("\n");
}
