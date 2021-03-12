#include <stdio.h>
#include <stdlib.h> //strtof();
#include <string.h> //strcpy()
#include <time.h> //time(), localtime();
#include "tad_comandos.h"
#include "tad.h"
#include "operations.h"
#include "manipulations.h"


int main()
{
	system("title dBase III - Estruturas de Dados II");
	
	Dir *unid;
	Arq *arquivo_aberto;
	initDir(&unid); //Initializing
	
	buildUnit(&unid); //Build Unit C:
	buildUnit(&unid); //Build Unit D:
	buildUnit(&unid); //Build Unit E:
		
	int opc;
	char comando_field[50];
	char valor[50];
	valor[0] = '\0';
	
	printf("Diretorio atual: [%c:]\n", unid->letter);
	printf(". ");
	fflush(stdin);
	gets(comando_field);
	opc = Compara_String(comando_field, valor);
	
	while(opc != 3)
	{
		switch (opc)
		{
			case 2 : {
				listaArquivo(unid);
				break;
			}
			
			case 8 : {
				system("cls");
				break;
			}
			
			case 19 : {
				//Criar DBF
				
				novoArquivo(unid, valor);
				//printf("Arquivo: |%s|\n", unid->arqs->nomeDBF); 
				printf("Incluir dados ? <Y/N>: ");
				opc = toupper(getche());
				printf("\n");
				
				if(opc == 'Y')
					printf("Tela\n");
				
				break;
			}
			
			case 20 : {
				arquivo_aberto = abrirArquivo(unid, valor);
				
				//GOTO
				if(arquivo_aberto != NULL)
					printf("Aberto: [%s]\n", arquivo_aberto->nomeDBF);
				else
					printf("Not found\n");
					
				break;
			}
			
			case 22 : {
				//system("cls"); //Goto
				trocaUnidade(&unid, toupper(valor[0]));
				//printf("Letra atual: %c\n", unid->letter); //Goto
				printf("Diretorio atual: [%c:]\n", unid->letter);
				break;
			}
			default :
				printf("Comando Invalido\n");
		}
		
		/*printf("comando_field [%s]\n", comando_field);
		printf("valor [%s]\n", valor);*/
		
		printf(". ");
		fflush(stdin);
		gets(comando_field);
		opc = Compara_String(comando_field, valor);
	}
	
	return 0;
}
