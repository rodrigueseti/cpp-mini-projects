#include<stdio.h> 
#include<string.h> // stricmp();
#include<conio2.h> // getche(), clrscr();
#include<ctype.h> // toupper();

#define MAX_ALBUM 3

struct albumMusical{
	
	char nomeAlbum[50], musicas[100][50], artista[50], genero[50];
	int anoLanc, vetQtdeMusicas[100];
};

bool buscaAlbum(struct albumMusical *estruAm, int &tamLgc, char *nome){
	
	int i = 0;
	while(i < tamLgc && stricmp(nome, estruAm[i].nomeAlbum) != 0)
		i++;
		
	if(i < tamLgc) // se i menor que tl significa que album já existe
		return false;
	return true;
}

void cadastraNovoAlbum(struct albumMusical *estruAm, int &tamLgc){
	
	char nome[50];
	
	// If verifica se ha capacidade no vetor de structs
	if(tamLgc < MAX_ALBUM){ 
		
		printf("\nNome do Album: ");
		gets(nome);
		
		if(buscaAlbum(estruAm, tamLgc, nome)){
			
			strcpy(estruAm[tamLgc].nomeAlbum, nome);
			printf("Ano de lancamento: ");
			scanf("%d",&estruAm[tamLgc].anoLanc);
			
			
			printf("Artista: ");
			fflush(stdin);
			gets(estruAm[tamLgc].artista);
			
			printf("Genero: ");
			fflush(stdin);
			gets(estruAm[tamLgc].genero);
			
			printf("\nMusicas");
			
			int i = 0;
			
			printf("\n%d Musica: ", i + 1);
			
			nome[0] = '\0';
			
			fflush(stdin);
			gets(nome);
			
			while(nome[0] != '\0'){
				
				strcpy(estruAm[tamLgc].musicas[i], nome);
				i++;
				
				printf("%d Musica: ", i + 1);
				fflush(stdin);
				gets(nome);
			}
			estruAm[tamLgc].vetQtdeMusicas[tamLgc] = i;
			printf("\nCadastro realizado");
			tamLgc++;
		}
		else
			printf("Album ja existe");
	}
	else
		printf("\nLimite atingido");
	getch();
}

char menu(void){
	
	clrscr();
	printf("ESTROBOS'S SOM DASHBOARD\n");
	printf("\n[1] Cadastrar Novo Album");
	printf("\n[ESC] Finalizar\n");
	
	return toupper(getch());	
}

int main(){
	
	struct albumMusical estruAm[MAX_ALBUM];
	int albumQtde = 0;
	char opc;
	
	do{
		opc = menu();
		clrscr();
		switch(opc){
			
			case '1' :
				
				printf("Cadastrar Novo Album");
				cadastraNovoAlbum(estruAm, albumQtde);
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


