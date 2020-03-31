#include<stdio.h> 
#include<string.h> // stricmp();
#include<conio.h> // getche();
#include<ctype.h> // toupper();

//#define maxalbum 100


struct albumMusical{
	
	char nomeAlbum[50];

};


bool buscaAlbum(struct albumMusical *am, int tl, char *nome){
	
	int i = 0;
	while(i < tl && stricmp(nome,am[i].nomeAlbum) != 0)
		i++;
		
	if(i < tl){
		printf("true");
		return true;
	}
	return false;
}

int cadastraNovoAlbum(struct albumMusical *am, int tl){
	
	char nome[50];
	
	if(tl < 100){
		
		gets(nome);
		
		if(buscaAlbum(am, tl, nome)){
		printf("Cadastro");
		}
		else
			printf("\nAlbum nao encontrado");
	}
	else
		printf("\nLimite atingido");
}
	
	

char menu(void){
	
	printf("\nEstrobos's Som Dashboard");
	printf("\n[1] Cadastrar Novo Album");
	printf("\n[ESC] Finalizar");
	
	return toupper(getche());	
}

int main(){
	
	struct albumMusical am[100];
	int albumQtde = 0;
	char opc;
	
	do{
		opc = menu();
		
		switch(opc){
			
			case '1' :
				printf("Cadastrar Novo Album");
				cadastraNovoAlbum(am, albumQtde);
				break;
			default:
				printf("Opcao Invalida");
		}
		
	}while(opc != 27);
	
	
	return 0;
}


