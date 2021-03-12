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
	initDir(&unid); //Initializing
	
	buildUnit(&unid); //Build Unit C:
	buildUnit(&unid); //Build Unit D:
	
	//Build Unit Test
	/*
	
	buildUnit(&unid); //Build Unit E:
	
	printf("LETRA: %c\n", unid->letter);
	printf("LETRA: %c\n", unid->bottom->letter);
	printf("LETRA: %c\n", unid->bottom->bottom->letter);
	createNewDBF(&unid, "CLIENTES.DBF");
	
	printf("\n%s", unid->arqs->nomeDBF);
	printf("\n%s", unid->arqs->data);
	printf("\n%s", unid->arqs->hora);
	*/
	
	int opc;
	char comando_field[50];
	char valor[50];
	valor[0] = '\0';
	
	printf(". ");
	fflush(stdin);
	gets(comando_field);
	opc = Compara_String(comando_field, valor);
	
	while(opc != 4)
	{
		switch (opc)
		{
			case 22 : {
				trocaUnidade(&unid, toupper(valor[0]));
				printf("Letra atual: %c\n", unid->letter);
				break;
			}
			default :
				printf("Comando Invalido");
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
