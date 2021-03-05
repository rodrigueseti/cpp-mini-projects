#include <stdio.h>
#include <stdlib.h>
#include "Tad.h"
#include "operations.h"

int main()
{
	Dir *unidade; 
	initDir(&unidade); //Initializing
	
	//Build Unit Test
	/*buildUnit(&unidade); //Build Unit C:
	printf("LETRA: %c", unidade->unidade);
	
	
	buildUnit(&unidade); //Build Unit D:
	printf("\nLETRA: %c", unidade->unidade);
	printf("\nLETRA: %c", unidade->bottom->unidade);
	
	buildUnit(&unidade); //Build Unit E:
	printf("\nLETRA: %c", unidade->bottom->bottom->unidade);*/
	return 0;
}
