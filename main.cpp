#include<stdio.h> 
#include<string.h> // stricmp();
#include<conio2.h> // getche(), clrscr();
#include<ctype.h> // toupper();

#define MAX_ALBUM 3

struct albumMusical{
	
	char nomeAlbum[50];

};

bool buscaAlbum(struct albumMusical *am, int &tl, char *nome){
	
	int i = 0;
	while(i < tl && stricmp(nome,am[i].nomeAlbum) != 0)
		i++;
		
	if(i < tl) // se i menor que tl significa que album já existe
		return false;
	return true;
}

int cadastraNovoAlbum(struct albumMusical *am, int &tl){
	
	char nome[50];
	
	// If verifica se ha capacidade no vetor de structs
	if(tl < MAX_ALBUM){ 
		
		printf("\nNome: ");
		gets(nome);
		
		if(buscaAlbum(am, tl, nome)){
			printf("Cadastro realizado");
			strcpy(am[tl].nomeAlbum, nome);
			tl++;
			getch();
		}
		else{
			printf("Album ja existe");
			getch();
		}
	}
	else{
		printf("\nLimite atingido");
		getch();
	}
}

char menu(void){
	
	clrscr();
	printf("ESTROBOS'S SOM DASHBOARD\n");
	printf("\n[1] Cadastrar Novo Album");
	printf("\n[ESC] Finalizar\n");
	
	return toupper(getch());	
}

int main(){
	
	struct albumMusical am[MAX_ALBUM];
	int albumQtde = 0;
	char opc;
	
	do{
		opc = menu();
		clrscr();
		switch(opc){
			
			case '1' :
				printf("Cadastrar Novo Album");
				cadastraNovoAlbum(am, albumQtde);
				break;
			case 27 :
				printf("Fim");
				break;
			default:
				printf("Opcao Invalida");
		}
		
	}while(opc != 27);
	
	return 0;
}


