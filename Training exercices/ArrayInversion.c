#include <stdio.h>
int main (void){
    char vet[10] = {};

    printf("ESC - Encerrar digitacao\n");
    printf("ENTER - Separar os valores\n");
    printf("Digite uma ordem de valores para serem invertidos.\n");
    
    for (int i = 0; i<sizeof(vet); i++){
        vet[i] = getch(); //Usuario insere dado
        if (vet[i] >= '0' && vet[i] <='9'){
            printf("\rvet.%d: %s \n", i+1, vet);
        } else {
            while(vet[i] <= '0' || vet[i] >='9'){
                printf("\n--- Valor invalido ---\n");
                printf("Digite novamente o dado: \n");
                vet[i] = getch();
            }
        }
    }
}