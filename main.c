#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(void){

    FILE *fileSl, *fileAdd, *fileTabelas;
    int opcao, opcao2, qtdCol;
    int i, cont;
    char nomeTabela[50], buscaTabela[50], checkBusca[50], **tamTabela, *busca;
    char *valorPesquisa;
    char arqVal[100];
    
    menu();
    printf("Escolha uma opção: ");
    //implementar função "getch()" para ocultar o número da opção digitada.
    scanf("%i", &opcao);
    do{
        if(opcao == 1){
            //Coleta parâmetros para proseguir com a criação da tabela.
            printf("Informe o nome da tabela a ser criada: ");
            scanf("%s", nomeTabela);
            fileSl = fopen(nomeTabela, "w");
            //arquivo para armazenar apenas o nome das tabelas,
            //para poder listar os nomes quando solicitado na opção 2.
            fileTabelas = fopen("nomeTabela.dsl", "a");
            fprintf(fileTabelas, "%s\n", nomeTabela);
            printf("Informe a quantidade de colunas da tabela: ");
            scanf("%i", &qtdCol);
            tamTabela = (char**)malloc(sizeof(char*)*qtdCol);
            for(i = 0; i < qtdCol; i++)
                tamTabela[i] = (char*)malloc(sizeof(char)*50);
            //Define os campos da tabela.
            printf("A 1ª coluna armazerá a chave primária.\n");
            cont = 1;
            for(i = 0; i < qtdCol; i++){
                printf("Informe o nome da %iª coluna: ", cont);
				scanf("%s", tamTabela[i]);
                fprintf(fileSl, "%s\n", tamTabela[i]);
				cont++;
            }
            fclose(fileSl);
            fclose(fileTabelas);
            printf("Tabela criada com sucesso.\n\n");
        }
        //Listar todas as tabelas.
        else if(opcao == 2){
            fileTabelas = fopen("nomeTabela.dsl", "r");
            if(fileSl == NULL)
                printf("Não foi possivel abrir o arquivo.\n");
            while(fgets(nomeTabela, 50, fileTabelas) != NULL)
                printf("%s", nomeTabela);
            fclose(fileTabelas);
            printf("\n");
        }
        //Criar uma nova linha na tabela.
        else if(opcao == 3){
            printf("Informe o nome da tabela: ");
            scanf("%s", buscaTabela);
            fileSl = fopen(buscaTabela, "r");
            concatenaArquivo(buscaTabela, arqVal);
            fileAdd = fopen(arqVal, "a");
            while(fgets(checkBusca, 50, fileSl) != NULL){    
                printf("Informe o valor da coluna %s", checkBusca);
                scanf("%s", nomeTabela);
                fprintf(fileAdd, "%s ", nomeTabela);
            }
            fprintf(fileAdd, "\n");
            fclose(fileSl);
            fclose(fileAdd);
            printf("\n");
        }
        //listar todos os dados de uma tabela.
        else if(opcao == 4){
            printf("Informe o nome da tabela a ser listada: ");
            scanf("%s", buscaTabela);
            concatenaArquivo(buscaTabela, arqVal);
				//if
            fileSl = fopen(arqVal, "r");
            if(fileSl == NULL)
                printf("Tabela não encontrada, por favor, verifique o nome digitado.\n");
            while(fgets(checkBusca, 50, fileSl) != NULL)
                printf("%s ", checkBusca);
            fclose(fileSl);
            printf("\n");
        }
        //buscar item na tabela.
        /*
        else if(opcao == 5){
            double valorPesquisa;
            printf("Informe o nome da tabela: ");
            scanf("%s", buscaTabela);
            fileSl = fopen(buscaTabela, "r");
            if(fileSl == NULL)
                printf("Tabela não encontrada, por favor, verifique o nome digitado.\n");
            else{
                printf("A tabela %s possui as seguintes colunas: \n", buscaTabela);
                while(fgets(checkBusca, 50, fileSl) != NULL)
                    printf("%s", checkBusca);
                printf("Informe a coluna a ser pesquisado: ");
                scanf("%s", checkBusca);
                menuBusa();
                fclose(fileSl);
                printf("\n");
            }
        }
        scanf("%i", &opcao2);
        if(opcao2 == 1){
            printf("Informe um valor a ser pesquisado: ");
            scanf("%s", valorPesquisa);
            char *arq_dados = malloc(sizeof(char) *(strlen(buscaTabela)+15));
            strcpy(arq_dados, buscaTabela);
            strcat(arq_dados, ".val");
            fileSl = fopen(arq_dados, "r");
            while(fgets(checkBusca, 50, fileSl) != NULL){
                busca = strstr(checkBusca, valorPesquisa);
                if(busca != NULL){
                    printf("%s\n", busca);
                }
            }
        } 
        */  
        else if(opcao == 6){

            printf("Informe o nome da tabela: ");
            scanf("%s", buscaTabela);
            concatenaArquivo(buscaTabela, arqVal);
            removeLinha(arqVal);
        }
        else if(opcao == 7){
            printf("Informe o nome da tabela ser apagada: ");
            scanf("%s", buscaTabela);
            concatenaArquivo(buscaTabela, arqVal);
            fileSl = fopen(buscaTabela, "r");
            if(fileSl == NULL)
                printf("Tabela não encontrada, por favor, verifique o nome digitado.\n");
            else{
                remove(buscaTabela);
                remove(arqVal);
                printf("Tabela %s apagada com sucesso.", buscaTabela);
            }
            printf("\n");
        }
        printf("Escolha uma opção: ");
        scanf("%i", &opcao);
        //Finalização do programa
        }while(opcao != 0);
        if(opcao == 0)
            printf("Finalizando programa...\nEXCELSIOR!\n");
 
    return 0;
}
