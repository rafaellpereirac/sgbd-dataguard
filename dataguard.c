#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fileSl;
    int opcao, qtdCol;
    int i, cont;
    char nomeTabela[50], **tamTabela;

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

    fileSl = fopen("fileSl.txt", "w");
    //implementar função "getch()" para ocultar o número da opção digitada.
    scanf("%i", &opcao);
    if(opcao == 1){
        //Coleta parâmetros para proseguir com a criação da tabela.
        printf("Informe o nome da tabela a ser criada: ");
        scanf("%s", nomeTabela);
        printf("Informe a quantidade de colunas da tabela: ");
        scanf("%i", &qtdCol);
        tamTabela = (char**)malloc(sizeof(char*)*qtdCol);
        for(i = 0; i < qtdCol; i++)
            tamTabela[i] = (char*)malloc(sizeof(char)*50);
        //Define os campos da tabela.
        cont = 1;
        for(i = 0; i < qtdCol; i++){
            printf("Informe o nome da %iª coluna: ", cont);
            scanf("%s", tamTabela[i]);
            fprintf(fileSl, "%s ", tamTabela[i]);
            cont++;
        }
        fclose(fileSl);
        printf("Tabela criada com sucesso.\n");
    }
    //Listar todas as tabelas.
    else if(opcao == 2){
        fileSl = fopen("fileSl.txt", "r");
        if(fileSl == NULL)
            printf("Não foi possivel abrir o arquivo\n");
        else
            fscanf(fileSl, "%s %s %s", tamTabela[0], tamTabela[1], tamTabela[2]);
    }
    else if(opcao == 3){
        printf("Criar uma nova linha na tabela\n");
    }
    else
        printf("Opção invalida\n");
    return 0;
}
