#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct menudsl{
	printf("\n\t=======================================\n");
    printf("\t=          DataGuard Stn Lee          =\n");
    printf("\t=======================================\n");
    printf("\n\t             Menu de Opções\n\n");
    printf("\t1 - Criar tabela\n");
    printf("\t2 - Listar todas as tabelas\n");
    printf("\t3 - Criar uma nova linha na tabela\n");
    printf("\t4 - Listar todos os dados de uma tabela\n");
    printf("\t5 - Pesquisar valor em uma tabela\n");
    printf("\t6 - Apagar valor de uma tabela\n");
    printf("\t7 - Apagar uma tabela\n\n");
				} menudsl;
*/
int main(void){

    FILE *fileSl, *fileAdd, *fileTabelas;
    int opcao, opca2, qtdCol;
    int i, cont;
    char nomeTabela[50], buscaTabela[50], checkBusca[50], **tamTabela;

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
    printf("\t7 - Apagar uma tabela\n");\
	printf("\t8 - Ajuda\n\n");
	printf("\t0 - Finalizar o programa\n\n");

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
                if(i == qtdCol-1){
                    printf("Informe o nome da %iª coluna: ", cont);
                    scanf("%s", tamTabela[i]);
                    fprintf(fileSl, "%s\n", tamTabela[i]);
                }
                else{
                    printf("Informe o nome da %iª coluna: ", cont);
                    scanf("%s", tamTabela[i]);
                    fprintf(fileSl, "%s\n", tamTabela[i]);
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
        //Criar uma nova linha na tabela. 
        else if(opcao == 3){
            printf("Informe o nome da tabela: ");
            scanf("%s", buscaTabela);
            fileSl = fopen(buscaTabela, "r");
			char * arq_dados = malloc( sizeof(char) * (strlen(buscaTabela)+15));
			strcpy( arq_dados, buscaTabela);
			strcat( arq_dados, ".data" );
            while(fgets(checkBusca, 50, fileSl) != NULL){      
                printf("Informe o valor da coluna %s", checkBusca);
                scanf("%s", nomeTabela);
                fileAdd = fopen(arq_dados, "a");
                fprintf(fileAdd, "%s\n", nomeTabela);
            }
            fclose(fileSl);
            fclose(fileAdd);

// acao.data
        }
		//listar todos os dados de uma tabela.
		else if(opcao == 4){
        printf("Informe o nome da tabela a ser listada: ");
        scanf("%s", buscaTabela);
        fileSl = fopen("refBuscaTabela", "r");
        if(fileSl == NULL)
            printf("Tabela não encontrada, por favor, verifique o nome digitado.\n");
        while(fgets(checkBusca, 50, fileSl) != NULL)
            printf("%s", checkBusca);
        fclose(fileSl);
		}
		//buscar item na tabela.
		/*else if(opcao == 5){
		printf("Informe o nome da tabela: ");
            scanf("%s", buscaTabela);
			if(fileSl == NULL)
				printf("Tabela não encontrada, por favor, verifique o nome digitado.\n");
			else{ 
			double valorPesquisa;
            fileSl = fopen(buscaTabela, "r");
				fprintf(fileSl, "%s ", buscaTabela);
				printf("Informe a coluna a ser pesquizado: ");
					scanf("%s", checkBusca);   
                    printf("\t1 - Valores maior que o valor informado\n");
    				printf("\t2 - Valores maior ou igual que o valor informado\n");
    				printf("\t3 - Valores igual o valor informado\n");
    				printf("\t4 - Valores menor que o valor informado\n");
    				printf("\t5 - Valores menor ou igual que o valor informado\n");
    				printf("\t6 - Valores próximos ao valor informado\n");
    				printf("\t7 - Apagar uma tabela\n");
					if(opcao2 == 1){
						printf("Informe um valor numérico a ser pesquisado: ");
						scanf("%i", &valorPesquisa);

		//apaga o valor de umatabela.
		else if(opcao == 6){
						   
						   }


		//apaga uma tabela.
		else if(opcao == 7){

						   }
						
					}
            }
		}
            fclose(fileSl);
			fclose(fileAdd);
					

		
		//Opção ajuda, para listar novamente o menu.
        /*
        else if(opcao == 8){
		}*/
        printf("Escolha uma opção: ");
        scanf("%i", &opcao);
    	//Finalização do programa
        }while(opcao != 0);
        if(opcao == 0)
            printf("Finalizando programa...\nEXCELSIOR!\n");
 
    return 0;
}
//excelsior
//Com Grandes Poderes vem Grandes Responsabilidades
