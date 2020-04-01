#include<stdio.h> 
#include<string.h> // stricmp();
#include<conio2.h> // getche(), clrscr();
#include<ctype.h> // toupper();

#define MAX_ALBUM 3
#define MAX_SONGS 3

struct albumMusical{
	
	char nomeAlbum[50], musicas[MAX_SONGS][50], artista[50], genero[50];
	int anoLanc, vetQtdeMusicas[MAX_ALBUM];
};

bool buscaAlbum(struct albumMusical *estruAm, int &tamLgc, char *nome){
	
	int i = 0;
	while(i < tamLgc && stricmp(nome, estruAm[i].nomeAlbum) != 0)
		i++;
		
	if(i < tamLgc) // se i menor que tl significa que album já existe
		return false;
	return true;
}
bool albumTaCheio(int tamLgc){
    return tamLgc < MAX_ALBUM;
}
bool musicasTaCheio(int tamLgc){
	return tamLgc < MAX_SONGS;
}

int inserirMusicas(struct albumMusical *estruAm, int &tamLgc){
	
	//ENTRAR COM NOME DO ALBUM NOME DO ALBUM
	printf("\nNome do Album: ");
	char nome[50];
	if(!buscaAlbum(estruAm, tamLgc, gets(nome)))
		if(musicasTaCheio(estruAm[tamLgc].vetQtdeMusicas[tamLgc]))
	return false;
	
	//getch();
}

void cadastraNovoAlbum(struct albumMusical *estruAm, int &tamLgc){
	
	char nome[50];
	
	// If verifica se ha capacidade no vetor de structs
	if(albumTaCheio(tamLgc)){ 
		
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
			
			printf("\nMusicas\n");
			
			int i = 0;
			
			do{
				printf("%d Musica: ", i + 1);
				fflush(stdin);
				gets(nome);
				
				strcpy(estruAm[tamLgc].musicas[i++], nome);
				//i++; //tem que fazer um if
				
			}while(musicasTaCheio(i) && nome[0] != '\0');
			
			printf("\n%d", i);
			if(!musicasTaCheio(i))
				printf("Limite de musicas excedido\n");
				
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
	printf("\n[2] Inserir Musicas");
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
				
			case '2' :
				
				printf("Inserir Musicas");
				inserirMusicas(estruAm, albumQtde);
				
			case 27 :
				
				printf("Fim");
				break;
				
			default:
				printf("Opcao Invalida");
		}
		
	}while(opc != 27);
	printf("albumQtde: %d",albumQtde);
	printf("\nTL Musicas na 0: %d",estruAm[0].vetQtdeMusicas[0]);
	
	return 0;
}


