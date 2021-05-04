#include<stdio.h>
int main (void){
    char word[20]={};
    bool first=0, ask=1;
    int j=0;

    while(ask){
        printf("Enter a word or sentence: ");
        gets(word);

        printf("\n");
        for(int i=0; i<sizeof(word);i++){
            if(('a'<=word[i]&&word[i]<='z')||('A'<=word[i]&&word[i]<='Z')){
                 //If it's a letter
                 if(first==0){
                    //If it's the FIRST letter
                    if('a'<=word[i]&&word[i]<='z')
                        //If the FIRST letter is a lowercase letter
                        word[i]=word[i]-32; //Changes it to an uppercase letter
                        first=1; //Mark the first letter as read
                        j++;
                 }
                 else{
                    //If it's not the first letter
                    if('A'<=word[i]&&word[i]<='Z'){
                        //If the following letters are uppercase case letters
                        word[i]=word[i]+32; //Changes it to a lowercase latter
                    }
                 }
            }
            else
                //If it's not a letter
                first=0; //Then start a new word
            printf("%c",word[i]);
        }
        printf("\nThis sentence has %d words",j);
        printf("\n");
        printf("Wanna continue? ");
        scanf("%d",&ask);
        if(ask){
            for(int i=0; i<sizeof(word);i++){
                word[i]={};
            }
            gets(word);
            j=0;
        }
    }
}
