#include <stdio.h>
#include <stdlib.h>
#include "Tad.h"
#include "operations.h"

int main()
{
	Dir *unidade; 
	initDir(&unidade); //Initializing
	
	buildUnit(&unidade); //Build Unit C:
	buildUnit(&unidade); //Build Unit D:
	return 0;
}
