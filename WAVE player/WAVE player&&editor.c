#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdint-gcc.h>
#include<locale.h>
#include<conio.h>

struct wav{
    char ChunkID[4];
    int ChunkSize;
    char Format[4];
    char SubChunk1ID[4];
    int SubChunk1Size;
    int16_t AudioFormat;
    int16_t NumChannels;
    int SampleRate;
    int ByteRate;
    int16_t BlockAlign;
    int16_t BitsPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    char Data[200000000];
}header;

void lista(void){
    printf("----------MÚSICAS DISPONÍVEIS----------");
    printf("\n1.    Bad Girlfriend");
    printf("\n2.    Birds");
    printf("\n3.    Come Together");
    printf("\n4.    Phoenix");
    printf("\n5.    The Less I Know The Better");
    printf("\n6.    Valse Hot");
}

int amplificacao(char nome[50]){
    char amplificado[50];
    int contador,multiplicador;
    FILE *fp,*am;
    strcat(nome,".wav");
    fp=fopen(nome,"rb");
    if(fp==NULL){
        printf("\nArquivo não existente. ");
        return 0;
    }
    printf("\nQual o nome do novo arquivo? ");
    gets(amplificado);
    strcat(amplificado,".wav");
    am=fopen(amplificado,"wb");

    printf("\nQuantas vezes deseja amplificar? ");
    scanf("%d",&multiplicador);
    fread(&header,sizeof(header),1,fp);
    for(contador=0;contador<header.ChunkSize+8;contador++){
        if(header.Data[contador]<0xff) header.Data[contador] = header.Data[contador]*multiplicador;
        if(header.Data[contador]>0xff) header.Data[contador] = 0xff;
    }
    fwrite(&header,header.ChunkSize+8,1,am);
    printf("\nPRONTO!");
    fclose(fp);
    fclose(am);
}

int corte (char nome[50]){
    char arquivo[50];
    int end,start,tempo,inicio,play,cortar;
    FILE *ar,*ptr;
    strcat(nome,".wav");
    ptr = fopen(nome,"rb");
    if(ptr==NULL){
        printf("\nArquivo não existente. ");
        return 0;
    }
    puts("\nDigite o nome do arquivo cortado: ");
    gets(arquivo);
    strcat(arquivo,".wav");
    ar = fopen(arquivo,"wb");

    fread(&header,sizeof(header),1,ptr);
    tempo = (header.ChunkSize)/(header.ByteRate);

    printf("\nA música tem %d segundos.",tempo);
    printf("\nInicio da faixa: ");
    scanf("%d",&start);
    while(start<0){
        printf("\nNão disponível. Por favor, selecione novamente: ");
        scanf("%d",&start);
    }
    printf("\nFim da faixa: ");
    scanf("%d",&end);
    while(start>end||end>tempo){
        printf("\nNão disponvel. Por favor, selecione novamente: ");
        scanf("%d",&end);
    }
    cortar = tempo-(end-start);
    inicio = (header.ByteRate)*start;
    play = header.ChunkSize - header.ByteRate*cortar - 36;
    header.SubChunk2Size = header.ByteRate*(end-start);
    header.ChunkSize = header.ByteRate*(end-start)+36;

    fseek(ptr,44+header.ByteRate*start,SEEK_SET);
    printf("Cortando.");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    fread(&header.Data,header.ChunkSize-36,1,ptr);
    fwrite(&header,play+44,1,ar);

    printf("\nPRONTO!");
    rewind(ptr);
    fclose(ptr);
    fclose(ar);
}

int informacoes (char nome[50]){
    FILE *fp;
    setlocale(LC_ALL, "Portuguese");
    strcat(nome,".wav");
    fp = fopen(nome,"rb");

    if(fp==NULL){
        printf("\nArquivo não existente. ");
        return 0;
    }
    fread(&header,sizeof(header),1,fp);

    printf("\nChunkID=%c%c%c%c",header.ChunkID[0],header.ChunkID[1],header.ChunkID[2],header.ChunkID[3]);
    printf("\nChunkSize=%i",header.ChunkSize);
    printf("\nFormat=%c%c%c%c",header.Format[0],header.Format[1],header.Format[2],header.Format[3]);
    printf("\nSubChunk1ID=%c%c%c%c",header.SubChunk1ID[0],header.SubChunk1ID[1],header.SubChunk1ID[2],header.SubChunk1ID[3]);
    printf("\nSubChunk1Size=%i",header.SubChunk1Size);
    printf("\nAudioFormat=%i",header.AudioFormat);
    printf("\nNumChannels=%i",header.NumChannels);
    printf("\nSampleRate=%i",header.SampleRate);
    printf("\nByteRate=%i",header.ByteRate);
    printf("\nBlockAlign=%i",header.BlockAlign);
    printf("\nBitsPerSample=%i",header.BitsPerSample);
    printf("\nSubChunk2ID=%c%c%c%c",header.SubChunk2ID[0],header.SubChunk2ID[1],header.SubChunk2ID[2],header.SubChunk2ID[3]);
    printf("\nSubChunk2Size=%i",header.SubChunk2Size);
}

int reproducao(char play[50]){
    FILE *fp;
    int fim;
    strcat(play,".wav");
    fp = fopen(play,"rb");
    if(fp==NULL){
        printf("\nArquivo não existente. ");
        return 0;
    }
    printf("\n\n-------ENJOY THE MUSIC-------\n\n");
    printf("\n\nPressione qualquer tecla para sair.\n");
    PlaySound(TEXT(play),NULL,SND_ASYNC);
        
    getch();
    PlaySound(NULL,NULL,NULL);
}

int main (void){
    int selecao, again;
    char musica[50];
    setlocale(LC_ALL, "Portuguese");
    while(1){
        system("cls");
        printf("1. Exibir cabeçalho;");
        printf("\n2. Reproduzir faixa;");
        printf("\n3. Cortar faixa;");
        printf("\n4. Amplificar;");
        printf("\n5. Músicas disponíveis;");
        printf("\n6. Sair.");
        printf("\n\nOlá, digite função que deseja fazer: ");
        scanf("%d",&selecao);
        fflush(stdin);
        while(selecao<1||selecao>5){
            printf("Comando nao disponível. Por favor, digite um comando válido.\n");
            printf("\n1. Exibir informações;");
            printf("\n2. Reproduzir faixa;");
            printf("\nOlá, digite função que deseja fazer: ");
            scanf("%d",&selecao);
            fflush(stdin);
        }
        if(selecao==1){
            printf("Digite o nome da música: ");
            gets(musica);
            printf("\nCarregando.");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf("\n");
            informacoes(musica);
            printf("\n\n\n");
            printf("1. Sim");
            printf("\n2. Não\n");
            printf("Deseja fazer mais alguma coisa? ");
            scanf("%d",&again);
            while(again<1||again>2){
                printf("Comando inválido. Por favor, tente novamente: ");
                scanf("%d",&again);
            }
            if(again==2) break;
        }

        if(selecao==2){
            printf("Digite o nome da música: ");
            gets(musica);
            printf("\nCarregando.");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf("\n");
            reproducao(musica);
            printf("\n\n\n");
            printf("1. Sim");
            printf("\n2. Não\n");
            printf("Deseja fazer mais alguma coisa? ");
            scanf("%d",&again);
            while(again<1||again>2){
                printf("Comando inválido. Por favor, tente novamente: ");
                scanf("%d",&again);
            }
            if(again==2) break;
        }
        if(selecao==3){
            printf("Digite o nome da música: ");
            gets(musica);
            printf("\nCarregando.");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            printf("\n");
            corte(musica);
            printf("\n\n\n");
            printf("1. Sim");
            printf("\n2. Não\n");
            printf("Deseja fazer mais alguma coisa? ");
            scanf("%d",&again);
            while(again<1||again>2){
                printf("Comando inválido. Por favor, tente novamente: ");
                scanf("%d",&again);
            }
            if(again==2) break;
        }
        if(selecao==4){
            printf("Digite o nome da música: ");
            gets(musica);
            printf("\nCarregando.");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            printf("\n");
            amplificacao(musica);
            printf("\n\n\n");
            printf("1. Sim");
            printf("\n2. Não\n");
            printf("Deseja fazer mais alguma coisa? ");
            scanf("%d",&again);
            while(again<1||again>2){
                printf("Comando inválido. Por favor, tente novamente: ");
                scanf("%d",&again);
            }
            if(again==2) break;
        }
        if(selecao==5){
            printf("\nCarregando.");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            printf("\n\n\n");
            lista();
            printf("\n\n\n");
            printf("1. Sim");
            printf("\n2. Não\n");
            printf("Deseja fazer mais alguma coisa? ");
            scanf("%d",&again);
            while(again<1||again>2){
                printf("Comando inválido. Por favor, tente novamente: ");
                scanf("%d",&again);
            }
            if(again==2) break;
        }
    if(selecao==6) return 0;
    }
    system("pause");
}
