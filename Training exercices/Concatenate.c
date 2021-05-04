#include<stdio.h>

int main(void){
    char first[50]={};
    char last[50]={};
    char result[100]={};
    int aux = 0;

    printf("Type your first name: ");
    gets(first);
    printf("Type your last name: ");
    gets(last);
    for(int i=0;i<sizeof(result);i++){
        if(first[i]!=NULL){
            result[i]=first[i];
        }
        //Se a primeira palavra já acabou
        if(first[i]==NULL){
            //Se é a primeira vez que entra nesse if
            if (aux == 0){
                //aux armazena o valor de i em que a primeira palavra terminou
                aux = i;
                //Dá um espaço pra separar as duas palavras em result
                result[i] = ' ';
            }
            //Como result[i] recebeu espaço, trabalhamos com i+1 agora
            //Usando i - aux, podemos recomeçar a contagem.
            //Inicialmente, i - aux = 0. Sendo assim, começamos com last[0]
            //Logo após, temos last[1] e por aí vai
            result[i+1] = last[i - aux];
            //Se a segunda palavra acabar, termina o loop
            if(last[i - aux]==NULL)
                break;
        }
    }
    //Mostra result já terminado
    printf("%s",result);
}
