#include <stdio.h>
#include <math.h>
#define ENTER 13
#define ESC 27
void pares(float *num){
    int itg;
    while(*num != '\0'){
        itg = *num;
        if(itg%2 == 0.0)
            printf("%.0f ", *num);
        num++;
    }
}
void impares(float *num){
    int itg;
    while(*num != '\0'){
        itg = *num;
        if(itg%2 != 0.0)
            printf("%.0f ", *num);
        num++;
    }
}

int main (void){
    system("cls");
    char vet[10] = {};
    float num[20] = {}, b;
    int a = 0, i = 0, y = 0;

    printf("ESC - Encerrar digitacao\n");
    printf("ENTER - Separar valores\n");
    printf("Insira os valores: \n");

    while (y<20){
        vet[a] = getch();    
        while(vet[a] != ENTER && vet[a] != ESC){
            printf("\r%s", vet);
            if (vet[a] >= '0' && vet[a] <= '9') a++;
            else {
                printf("\n\n--- Apenas numeros sao aceitos! ---\n");
                printf("Insira o valor novamente: \n"); 
                for (i = 0; i < a+1; i++){
                    vet[i] = NULL;
                } a = 0;
            } vet[a] = getch();
        } printf("\n");
        for (i=0; i<a; i++){
            num[y] += (vet[i] - 48)*pow(10, (a - i - 1))/1.0;
        } y++;
        if(vet[a] == ESC) break;
        for (a = 0; a < i+1; a++){
            vet[a] = NULL;
        } a = 0;
    } 
    printf("\nPares: \n");
    pares(num);
    printf("\nImpares: \n");
    impares(num);

    printf("\n\nDigite a soma: ");
    scanf("%f", &b);
    for(i = 0; i<y; i++){
        for(int j = i; j<y; j++){
            if(num[i] + num[j] == b && i != j){
                printf("\nIndices %d --> %.0f AND %d --> %.0f. \n", i, num[i], j, num[j]);
                return 0;
            }
        }
    } printf("\nNenhuma combinacao disponivel. \n");
}