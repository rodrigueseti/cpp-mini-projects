#include<stdio.h>
#include<string.h>

//#define maxalbum 100


struct albumMusical{
	
	char nomeAlbum[50];

};


bool buscaAlbum(char *nome[], struct albumMusical *am[], int *tl){
	
	int i = 0;
	while(i < 100 && strcmp(*nome,(*am[i]).nomeAlbum) != 0)
		i++;
		
	if(i < *tl)
		return true;
	else 
		return false;
}

int cadastraNovoAlbum(struct albumMusical am[], int *tl){
	
	char nome[50];
	if(*tl < 100){
		gets(nome);
		
		if(buscaAlbum(nome, am, tl));
			printf("Cadatros realizado");
		else
			printf("Album não encontrado");
	}
	else
		printf("Limite atingido");
	

}
	
	

char menu(void){
	
	printf("Estrobos's Som Dashboard");
	printf("[1] Cadastrar Novo Album");
	printf("[ESC] Finalizar");
	
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
				cadastraNovoAlbum(am, &albumQtde);
				break;
			default:
				printf("Opcao Invalida");
		}
		
	}while(opc != 27);
	
	
	return 0;
}


