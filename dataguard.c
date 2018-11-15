#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fileSl, *fileTabelas;
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

    printf("Escolha uma opção: ");
    //implementar função "getch()" para ocultar o número da opção digitada.
    scanf("%i", &opcao);
    do{
        if(opcao == 1){
            //Coleta parâmetros para proseguir com a criação da tabela.
            printf("Informe o nome da tabela a ser criada: ");
            scanf("%s", nomeTabela);
            fileSl = fopen(nomeTabela, "w");
            fprintf(fileSl, "%s\n", nomeTabela);
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
                if(i == qtdCol-1){
                    printf("Informe o nome da %iª coluna: ", cont);
                    scanf("%s", tamTabela[i]);
                    fprintf(fileSl, "%s\n", tamTabela[i]);
                }
                else{
                    printf("Informe o nome da %iª coluna: ", cont);
                    scanf("%s", tamTabela[i]);
                    fprintf(fileSl, "%s ", tamTabela[i]);
                }
                cont++;
            }
            fclose(fileSl);
            fclose(fileTabelas);
            printf("Tabela criada com sucesso.\n");
        }
        //Listar todas as tabelas.
        else if(opcao == 2){
            fileTabelas = fopen("nomeTabela.dsl", "r");
            if(fileSl == NULL)
                printf("Não foi possivel abrir o arquivo.\n");
            while(fgets(nomeTabela, 50, fileTabelas) != NULL)
                printf("%s", nomeTabela);
            fclose(fileTabelas);
        }
        /*
        else if(opcao == 3){
            Criar uma nova linha na tabela\n
        }
        else
            printf("Opção invalida\n");
        */
        printf("Escolha uma opção: ");
        scanf("%i", &opcao);
    }while(opcao != 0);
    if(opcao == 0)
        printf("Finalizando programa...\n");

    return 0;
}
