#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fileSl;
    int opcao, qtdCol;
    int i, cont;
    //unsigned int chavePrimaria;
    char nomeTabela[50];
    char **tamTabela;

    printf("\n\t=======================================\n");
    printf("\t=          DataGuard Stn Lee          =\n");
    printf("\t=======================================\n");

    //menu de opções
    printf("\n\t             Menu de Opções\n\n");
    printf("\t1 - Criar tabela\n");
    printf("\t2 - Listar todas as tabelas\n");
    printf("\t3 - Criar uma nova linha na tabela\n");
    printf("\t4 - Listar todos os dados de uma tabela\n");
    printf("\t5 - Pesquisar valor em uma tabela\n");
    printf("\t6 - Apagar valor de uma tabela\n");
    printf("\t7 - Apagar uma tabela\n\n");

    //implementar função "getch()" para ocultar o numero digitado
    fileSl = fopen("fileSl.txt", "w");
    scanf("%i", &opcao);
    if(opcao == 1){
        printf("Informe o nome da tabela a ser criada: ");
        scanf("%s", nomeTabela);
        printf("Quantidade de colunas da tabela: ");
        scanf("%i", &qtdCol);
        tamTabela = (char**)malloc(sizeof(char*)*qtdCol*2);
        for(i = 0; i < qtdCol*2; i++)
            tamTabela[i] = (char*)malloc(sizeof(char)*50);
        printf("Informe um ID para chave primária: ");
        scanf("%s", tamTabela[0]);
        fprintf(fileSl, "%s", tamTabela[0]);
    }
    cont = 1;
       for(i = 0; i < qtdCol*2; i+=2){
            printf("Informe o nome da %iª coluna: ", cont+1);
            scanf("%s", tamTabela[i]);
            fprintf(fileSl, "%s", tamTabela[i]);
            printf("Insira o dado da %iª coluna: ", cont+1);
            scanf("%s", tamTabela[i+1]);
            fprintf(fileSl, "%s", tamTabela[i+1]);
            cont++;
        }
    fclose(fileSl);
    
    //fprintf(fileSl, "%s", tamTabela[0]);
    /*
    else if(opcao == 2){
        printf("Listar todas as tabelas\n");
    }
    else if(opcao == 3){
        printf("Criar uma nova linha na tabela\n");
    }
    else
        printf("Opção invalida\n");
    */
    return 0;
}
