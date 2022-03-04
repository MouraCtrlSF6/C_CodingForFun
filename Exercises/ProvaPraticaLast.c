#include <stdio.h>
#include <string.h>
#define ENTER 13
#define ESC 27
int main (void){
    system("cls");
    char kboard;
    char ins[50] = {};
    char c;
    int i = 0, y = 0;
    FILE *num, *let;
    num = fopen("numeros.dat", "wb");
    let = fopen("letras.txt", "wb");

    printf("ESC - Encerrar programa\n");
    printf("ENTER - Separador de expressoes\n\n");
    kboard = getch();
    while (kboard != ESC){
        if(kboard == ENTER) kboard = '\n';
        printf("%c", kboard);
        ins[i] = kboard;
        i++;
        kboard = getch();
    }

    for (i=0; i<strlen(ins); i++){ //Enquanto i for menor que o número de palavras
        for (y=i; ins[y]!='\n'&&ins[y]!='\0'; y++){ //Enquanto a palavra não acabar
            if(ins[i]>='0'&&ins[i]<='9'){ //Se a primeira letra da palavra for um número
                fprintf(num, "%c", ins[y]); //Coloca no num
                if(ins[y+1] == '\n') fputs("\n", num);
            }
            else{
                fprintf(let, "%c", ins[y]); //Senão, coloca no let
                if(ins[y+1] == '\n') fputs("\n", let);
            }
        } i = y; //Reposiciona o cursos para a nova palavra
    }
    fclose(num);
    fclose(let);

    num = fopen("numeros.dat", "rb");
    let = fopen("letras.txt", "rb");
    printf("\nSalvo em numeros:\n");
    while((c = fgetc(num))!=EOF){
        printf("%c", c);
    }
    printf("\n\nSalvo em letras:\n");
    while((c = fgetc(let))!=EOF){
        printf("%c", c);
    }
    fclose(num);
    fclose(let);
}