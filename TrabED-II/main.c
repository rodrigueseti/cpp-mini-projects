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
	/*
	Dir *unid;
	initDir(&unid); //Initializing
	
	//Build Unit Test
	buildUnit(&unid); //Build Unit C:
	buildUnit(&unid); //Build Unit D:
	buildUnit(&unid); //Build Unit E:
	
	printf("LETRA: %c\n", unid->letter);
	printf("LETRA: %c\n", unid->bottom->letter);
	printf("LETRA: %c\n", unid->bottom->bottom->letter);
	createNewDBF(&unid, "CLIENTES.DBF");
	
	printf("\n%s", unid->arqs->nomeDBF);
	printf("\n%s", unid->arqs->data);
	printf("\n%s", unid->arqs->hora);
	*/
	menu();
	return 0;
}
