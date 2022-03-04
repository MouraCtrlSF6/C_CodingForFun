#include <stdio.h> //Incluir biblioteca stdio
int main (void){ //Função main
    int m1[10][10] = {}; //Declara Matriz 1
    int m2[10][10] = {}; //Declara Matriz 2
    int i, j; //Variáveis de linha/coluna
    system("cls"); //Limpa a tela
    printf("\nm1: \n\n"); //Anuncia o print da Matriz 1
    for (i=0; i<10; i++){ //Loop Seletor de linhas da Matriz 1
        for(j=0; j<10; j++){ //Loop Seletor de colunas da Matriz 1
            m1[i][j] = 1 + (10*i + j); //Atribui valores de 1 - 100 para Matriz 1
            printf(" %03d ", m1[i][j]); //Exibe esse valor com 3 digitos (001) 
        } printf("\n"); //Quebra de linha
    } //Fim do laço for
    printf("\nm2: \n\n"); //Anuncia o print da Matriz 2
    for (int z=0; z<10; z++){ //Loop Seletor de linhas da Matriz 2 
        for (i=0; i<10; i++){ //Loop Seletor de colunas da Matriz 2
            for (j=0; j<10; j++){ //Loop Somatório
                m2[z][i] += (m1[z][j] + m1[j][i]); //Soma do somatório dos elementos da linha z de Matriz 1 com o somatório dos elementos da coluna i de Matriz 1
            } //Fim do laço for
            m2[z][i] = 10000 - m2[z][i]; //Matriz 2 recebe 10mil menos o valor atual da posição
            printf(" %d ", m2[z][i]); //Exibe esse valor como um inteiro
        } printf("\n"); //Quebra de linha
    } printf("\n"); //Quebra de linha
}//Fim função main