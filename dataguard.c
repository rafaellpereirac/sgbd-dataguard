#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <excelsior.h>
//lembrar de implematar função

int main(void){

    FILE *fileSl, *fileAdd, *fileTabelas;
    int opcao, opcao2, qtdCol;
    int i, cont;
    char nomeTabela[50], buscaTabela[50], checkBusca[50], **tamTabela, *busca;
    char *valorPesquisa;
    char arqVal[100];
    //declaração das funções
    void menu(void);
    void menuBusca(void);
    void concatenaArquivo(char *arqBase, char arqVal[]);
    int abreArquivo(char arquivo[]);
    
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
            fclose(fileSl);
            fclose(fileAdd);
            printf("\n");
        }
        //listar todos os dados de uma tabela.
        else if(opcao == 4){
            printf("Informe o nome da tabela a ser listada: ");
            scanf("%s", buscaTabela);
            concatenaArquivo(buscaTabela, arqVal);
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

            printf("Informe a linha a ser apagada: ");
            scanf("%s", buscaTabela);
            abreArquivo(buscaTabela);
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
                remove(arq_dados);
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
    strcat(arq_dados, ".val");
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



