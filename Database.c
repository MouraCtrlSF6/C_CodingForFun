/*----------------------------------------------------------
Coisas pra fazer:
->Add funcao delete_from_database
->Add funcao delete_table
->Add funcao update_from_table
->Add local/pasa para os bancos
----------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define TAM 10

FILE *fp;
int d = 0;
int n = 0;
bool keep;

struct Database{
    int mat;
    char nome[30];
    float tri[3];
    float ra;
    char con[4];
}row[TAM];

int posi(char nome[20]){
    fp = fopen(nome, "rb");
    int y=0;
    char aux;
    //aux recebe caracter por caracter do arquivo, enquanto ele n acabar
    //EOF = End of File
    while( (aux = fgetc(fp)) != EOF ){
        //Se achar um \n, registra que deu uma nova linha
        if(aux=='\n'){
            y++;
        }
    }
    //Cada registro no arquivo tem 7 linhas. Dividindo o total do linhas por 7 e adicionando
    //1, conseguimos definir a partir de onde devemos começar a inserir informação
    fclose(fp);
    return (y/8);
}

void menu(char nome[20]){
    int i = strlen(nome) - 4;
    nome[i] = NULL;

    system("cls"); //Limpa a tela
    printf("-------------------- Acessando: %s --------------------\n", nome);
    printf("----------------------------------------------------------------\n");
    printf("\n1. Cadastrar um novo estudante");
    printf("\n2. Exibir todos dados cadastrados");
    printf("\n3. Procurar por um estudante especifico");
    printf("\n4. Voltar ao menu de selecao");
    printf("\n5. Encerrar programa\n");
    printf("----------------------------------------------------------------\n\n");
    nome[i] = '.';
}

int continua(){
    int ret = 1;
    char var;

    printf("Sim(X)    Nao( )");
    var = getch();
    while(var != 0b00001101){
        if(var == 'a' || var == 'A'){
            printf("\rSim(X)    Nao( )");
            ret = 1;
        }
        if(var == 'd' || var == 'D'){
            printf("\rSim( )    Nao(X)");
            ret = 0;
        }
        var = getch();
    }
    printf("\n");
    return ret;
}

void exibe_esp(char nome[20]){
    int y=0, search;
    char aux;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &search);
    fp = fopen(nome, "rb");
    //aux recebe caracter por caracter do arquivo, enquanto ele n acabar
    //EOF = End of File
    if(search == 1) printf("\n");
    while( (aux = fgetc(fp)) != EOF ){
        //Se achar um \n, registra que deu uma nova linha
        if(aux=='\n') y++; // Vai contando as linhas
        if(y >= (search-1)*8) printf("%c", aux);
        if(y == search*8) break;
    }

    printf("\nDeseja fazer mais algumas coisa? \n");
    keep = continua();
    if(!keep){
        printf("\nEncerrando.");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500); //Espera 2seg antes de fechar
        exit(1);
    }
}

void exibe_all(char nome[20]){
    fp = fopen(nome, "rb");
    char aux;
    printf("\n");
    //aux recebe caracter por caracter do arquivo, enquanto ele n acabar
    //EOF = End of File
    while( (aux = fgetc(fp)) != EOF ){
        printf("%c", aux);
    }

    printf("Deseja fazer mais algumas coisa? \n");
    keep = continua();
    if(!keep){
        printf("\nEncerrando.");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500); //Espera 2seg antes de fechar
        exit(1);
    }
}

void cadastro(char nome[20]){
    //Abre o arquivo no modo append (adicionar mais informações)
    fp = fopen(nome, "a");
    //Continua de onde parou
    for (n; n<TAM; n++){
        row[n].mat = n+1;
        printf("\nDigite o nome do aluno: ");
        gets(row[n].nome);
        //Check nome valido
        for(d = 0; d<strlen(row[n].nome); d++){
            while((row[n].nome[d]<'a' || row[n].nome[d]>'z') && (row[n].nome[d]<'A' || row[n].nome[d]>'Z')){
                printf("\nNome nao valido. Por favor, insira apenas caracteres alfabeticos.");
                printf("\nDigite o nome do aluno: ");
                setbuf(stdin,NULL); //Remove lixo
                gets(row[n].nome);
            }
        }

        for (d = 0; d<3; d++){
            printf("Digite a nota do %d trimestre: ", d+1);
            scanf("%f", &row[n].tri[d]);

            while(row[n].tri[d] < 0 || row[n].tri[d] > 10){
                printf("\nA nota deve estar sobre 10. Por favor, insira uma nota valida: ");
                scanf("%f", &row[n].tri[d]);
            }
            setbuf(stdin,NULL);

            if (row[n].tri[d] >= 9) row[n].con[d] = 'A';
            if (row[n].tri[d] >= 7.5 && row[n].tri[d] < 9) row[n].con[d] = 'B';
            if (row[n].tri[d] >= 6 && row[n].tri[d] < 7.5) row[n].con[d] = 'C';
            if (row[n].tri[d] < 6) row[n].con[d] = 'R';   

            if(d == 2){
                row[n].ra = (25*row[n].tri[0] + 35*row[n].tri[1] + 40*row[n].tri[2])/100;
                if (row[n].ra >= 9) row[n].con[d+1] = 'A';
                if (row[n].ra >= 7.5 && row[n].ra < 9) row[n].con[d+1] = 'B';
                if (row[n].ra >= 6 && row[n].ra < 7.5) row[n].con[d+1] = 'C';
                if (row[n].ra < 6) row[n].con[d+1] = 'R';
            }
        }

        //Bota a informação no arquivo
        fputs("Aluno: ", fp);
        for(int y = 0; y<strlen(row[n].nome); y++){
            fprintf(fp, "%c", row[n].nome[y]);
        }
        fprintf(fp, "\nMatricula: %d", row[n].mat);
        fprintf(fp, "\nResultados anuais: %.1f", row[n].ra);
        fprintf(fp, "\nConceito 1 tri: %c", row[n].con[0]);
        fprintf(fp, "\nConceito 2 tri: %c", row[n].con[1]);
        fprintf(fp, "\nConceito 3 tri: %c", row[n].con[2]);
        fprintf(fp, "\nConceito anual: %c", row[n].con[3]);
        fputs("\n\n", fp);

        printf("\nDeseja cadastrar um novo aluno? \n");
        d = continua();
        if(n+1 == TAM){
            printf("\nLimite de alunos alcançado. Encerrando.\n");
            break;
        }
        if(!d){
            break;
        }
    }
    setbuf(stdin,NULL); //Remove lixo
}

int main (void){
    system("cls");
    //Variaveis locais
    char a;
    bool b = 1;
    bool aux = 0;
    char nome[20] = {};
    
    while(1){
        //Tela inicial
        b = 1;
        printf("O que deseja fazer? \n");
        printf("\r(X) Acessar um banco de dados ja existente   ");
        printf("( ) Criar um novo banco de dados  ");

        //Selecao inicial
        a = getch();
        while(a != 0b00001101){
            if(a=='a'||a=='A'){
                printf("\r(X) Acessar um banco de dados ja existente   ");
                printf("( ) Criar um novo banco de dados  ");
                b = 1;
            }
            if(a=='d'||a=='D'){
                printf("\r( ) Acessar um banco de dados ja existente   ");
                printf("(X) Criar um novo banco de dados  ");
                b = 0;           
            }
            a = getch();
        }

        //Se selecionar um banco já existente
        if(b){   
            printf("\n\nDigite o nome da base de dados que deseja acessar: ");
            gets(nome);
            strcat(nome,".txt");
            //Abre o banco selecionado como modo leitura (arquivo de texto)
            fp = fopen(nome, "rb");
            //Se o banco nao existir, fecha o programa
            if(fp == NULL){
                printf("\nBanco inexistente!!!\n");
                Sleep(2000); //Espera 2seg antes de fechar
                exit(1);
            }
            menu(nome);
            fclose(fp);
            
            while(1){
                printf("O que deseja fazer? ");
                scanf("%d", &d);
                setbuf(stdin,NULL); //Remove lixo

                //Sair do programa
                if(d == 5){
                    printf("\nObrigado por usar o programa");
                    Sleep(500); 
                    printf("!");
                    Sleep(500); 
                    printf("!");
                    Sleep(500);
                    printf("!\n");
                    Sleep(1000);
                    exit(1); 
                }
                if(d == 4){
                    system("cls");
                    break;
                }
                if(d == 1){
                    //Pega qual a ultima matricula cadastrada no banco selecionado
                    n = posi(nome);
                    if(n != TAM){
                        cadastro(nome);
                        //Fecha o arquivo
                        fclose(fp);
                        menu(nome);
                    }
                    else printf("\nBanco de dados cheio.\nSelecione outra opcao ou libere espaco no banco.\n\n");
                }
                if(d == 2){
                    exibe_all(nome);
                    //Fecha o arquivo
                    fclose(fp);
                    menu(nome);
                }            
                if(d == 3){
                    exibe_esp(nome);
                    //Fecha o arquivo
                    fclose(fp);
                    menu(nome);
                }
            }
        }
        if(!b){
            printf("\n\nDigite o nome da base dados a ser criada: ");
            gets(nome);
            strcat(nome,".txt");
            fp = fopen(nome, "rb");

            if(fp == NULL){
                fclose(fp);
                fp = fopen(nome,"wb");
                menu(nome);
                fclose(fp);
                aux = 0;
            }
            else aux = 1;

            while(1){
                if(aux){
                    printf("\nBanco de dados ja existente!!!\n\n");
                    break;
                }
                printf("O que deseja fazer? ");
                scanf("%d", &d);
                setbuf(stdin,NULL); //Remove lixo

                if(d == 5){
                    printf("\nObrigado por usar o programa");
                    Sleep(500); 
                    printf("!");
                    Sleep(500); 
                    printf("!");
                    Sleep(500);
                    printf("!\n");
                    Sleep(1000);
                    exit(1); 
                }
                if(d == 4){
                    system("cls");
                    break;
                }
                if(d == 1){
                //Pega qual a ultima matricula cadastrada no banco selecionado
                    n = posi(nome);
                if(n != TAM){
                    cadastro(nome);
                    //Fecha o arquivo
                    fclose(fp);
                    menu(nome);
                }
                else printf("\nBanco de dados cheio.\nSelecione outra opcao ou libere espaco no banco.\n\n");
                }
                if(d == 2){
                    exibe_all(nome);
                    //Fecha o arquivo
                    fclose(fp);
                    menu(nome);
                }            
                if(d == 3){
                    exibe_esp(nome);
                    //Fecha o arquivo
                    fclose(fp);
                    menu(nome);
                }
            }
        }
    }
}