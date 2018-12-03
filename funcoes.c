#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

//menu de opções
void menu(void){

    printf("\n\t=======================================\n");
    printf("\t=         DataGuard Stn Lee       =\n");
    printf("\t=======================================\n");
    
    printf("\n\t            Menu de Opções\n\n");
    printf("\t1 - Criar tabela\n");
    printf("\t2 - Listar todas as tabelas\n");
    printf("\t3 - Criar uma nova linha na tabela\n");
    printf("\t4 - Listar todos os dados de uma tabela\n");
    printf("\t5 - Pesquisar valor em uma tabela\n");
    printf("\t6 - Apagar valor de uma tabela\n");
    printf("\t7 - Apagar uma tabela\n");\
    printf("\t8 - Ajuda\n\n");
    printf("\t0 - Finalizar o programa\n\n");
}
//Menu de opçoes para busca
void menuBusca(void){
   
    printf("\t1 - Valores maior que o valor informado\n");
    printf("\t2 - Valores maior ou igual que o valor informado\n");
    printf("\t3 - Valores igual o valor informado\n");
    printf("\t4 - Valores menor que o valor informado\n");
    printf("\t5 - Valores menor ou igual que o valor informado\n");
    printf("\t6 - Valores próximos ao valor informado\n\n");

}

void concatenaArquivo(char *arqBase, char arqVal[]){

    //char *arqVal = malloc(sizeof(char) *(strlen(arqBase)+15));
    strcpy(arqVal, arqBase);
    strcat(arqVal, ".val");

}

int abreArquivo(char buscaTabela[]){
    
    FILE *arqEntrada;
    FILE *arqSaida;
    int line = 0;
    int linha = 1;
    int i;
    char textoArquivo[100];

    #define NULO '\0'
    
    if((arqEntrada = fopen(buscaTabela, "r")) == 0){
        printf("Impossivel abrir arquivo...\n");
    }
    char *arq_dados = malloc(sizeof(char) *(strlen(buscaTabela)+15));
    strcpy(arq_dados, buscaTabela);
    strcat(arq_dados, ".del");
    if((arqSaida = fopen(arq_dados, "w")) == 0){
        printf("Impossivel abrir arquivo...\n");
    }
    printf("Digite a linha a ser apagada no arquivo: ");
    scanf("%d", &line);
    rewind(arqEntrada);
    for(i = 0; !feof(arqEntrada);i++){
        memset(textoArquivo, NULO, 100);
        fgets(textoArquivo, 101, arqEntrada);
        if(linha == line){
            fputc('\n', arqSaida);
            linha = linha + 1;
        continue;
        }
        linha = linha + 1;
        fputs(textoArquivo, arqSaida);
    }
    fclose(arqEntrada);
    fclose(arqSaida);
}
