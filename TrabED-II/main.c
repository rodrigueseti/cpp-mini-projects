#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcpy()
#include <time.h> //time(), localtime();
#include "Tad.h"
#include "operations.h"

int main()
{
	Dir *unid; 
	initDir(&unid); //Initializing
	
	//Build Unit Test
	buildUnit(&unid); //Build Unit C:
	buildUnit(&unid); //Build Unit D:
	buildUnit(&unid); //Build Unit E:
	
	printf("LETRA: %c\n", unid->letter);
	printf("LETRA: %c\n", unid->bottom->letter);
	printf("LETRA: %c\n", unid->bottom->bottom->letter);
	create(&unid, "CLIENTES.DBF");
	
	printf("\n%s", unid->arqs->nomeDBF);
	printf("\n%s", unid->arqs->data);
	printf("\n%s", unid->arqs->hora);
	
	return 0;
}
