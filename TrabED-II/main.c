#include <stdio.h>
#include <stdlib.h> //strtof();
#include <string.h> //strcpy()
#include <time.h> //time(), localtime();
#include <conio2.h>

#include "display.h"
#include "tad_comandos.h"
#include "tad.h"
#include "operations.h"
#include "manipulations.h"



int main()
{
	system("title dBase III - Estruturas de Dados II - Help Other Devs");
	
	Dir *unid;
	Arq *arquivo_aberto = NULL;
	Entradas en;
	initDir(&unid); //Initializing
	
	buildUnit(&unid); //Build Unit C:
	buildUnit(&unid); //Build Unit D:
	buildUnit(&unid); //Build Unit E:
		
	int opc;
	char comando_field[50];
	char valor[50];
	valor[0] = '\0';
	
	//show();
	
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
			
			case 16 : {
				
				listarFields(arquivo_aberto, unid);
				break;
			}
			
			case 19 : {
				
				//Criar DBF
				novoArquivo(unid, valor);
				printf("Incluir dados ? <Y/N>: ");
				opc = toupper(getche());
				
				if(opc == 'Y')
				{
					arquivo_aberto = abrirArquivo(unid, valor);
					insertFields(arquivo_aberto);
				}
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
				arquivo_aberto = NULL;
				trocaUnidade(&unid, toupper(valor[0]));
				printf("Diretorio atual: [%c:]\n", unid->letter);
				break;
			}
			default :
				printf("Comando Invalido\n");
		}
		
		printf(". ");
		fflush(stdin);
		gets(comando_field);
		opc = Compara_String(comando_field, valor);
	}
	
	return 0;
}
