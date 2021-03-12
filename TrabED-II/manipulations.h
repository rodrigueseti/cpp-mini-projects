


void menu ()
{
	
	int opc;
	char comando_field[50];
	char valor[50];
	valor[0] = '\0';
	
	
	printf(". ");
	fflush(stdin);
	gets(comando_field);
	opc = Compara_String(comando_field, valor);
	
	printf("comando_field [%s]", comando_field);
	printf("\nvalor [%s]", valor);
	
	/*while(opc != 4))
	{
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
		
		puts(". ");
		fflush(stdin);
		gets(input);
		opc = Compara_String(comando, valor);
	}*/
}
