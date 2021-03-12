#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include"tad_comandos.h"

int main(){
	
	char valor[50];
	valor[0] = '\0';
	
	char input[50] = {"   GOTO   3  "};
	//printf("\nString passada: |%s|", input);
	Compara_String(input, valor);
	//printf("\nField: |%s|", input);
	//printf("\nValor: |%s|", valor);
	
	gets(input);
	int opc = Compara_String(comando, valor);
	switch (opc)
	{
		case 1 : {
			
			
			
			break;
		}
		case 2 : {
			
			break;
		}
		case 3 : {
			
			break;
		}
		case 4 : {
			
			break;
		}
		case 5 : {
			
			break;
		}
		case 6 : {
			
			break;
		}
		case 7 : {
			
			break;
		}
		case 8 : {
			
			break;
		}
		default :
			printf("Comando Invalido");
	}

	return 0;
}
