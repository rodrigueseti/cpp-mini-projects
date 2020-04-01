#include<stdio.h> 
#include<string.h> // stricmp();
#include<conio2.h> // getche(), clrscr();
#include<ctype.h> // toupper();

#define MAX_ALBUM 3 //Seta a quantidade maxima de albuns
#define MAX_SONGS 4	//Seta a quantidade maxima de musicacas em cada album
#define MAX_STR 50 //Seta o tamanho total de uma palavra

struct albumMusical{
	
	char nomeAlbum[MAX_STR], musicas[MAX_SONGS][MAX_STR], artista[MAX_STR], genero[MAX_STR];
	int anoLanc, vetQtdeMusicas;
};

int buscaAlbum(struct albumMusical *estruAm, int &tamLgc, char *nome){
	
	int i = 0;
	while(i < tamLgc && stricmp(nome, estruAm[i].nomeAlbum) != 0)
		i++;
		
	if(i < tamLgc) // se i menor que tl significa que album ja existe
		return i; //Encontrou, Modulariazar esse if
	return -1; //Nao Encontrou!
}
bool albumTaCheio(int tamLgc){
    return tamLgc < MAX_ALBUM;
}
bool musicasTaCheio(int tamLgc){
	return tamLgc < MAX_SONGS;
}
void lerMusicas(struct albumMusical *estruAm, int &tamLgc, int &i){
	
	
	printf("%d Musica: ", i + 1);
	char nome[MAX_STR];
	while(musicasTaCheio(i) && stricmp(gets(nome),"")){
		
		strcpy(estruAm[tamLgc].musicas[i++], nome);
		
		if(musicasTaCheio(i))
			printf("%d Musica: ", i + 1);
	}
	if(!musicasTaCheio(i))
				printf("Limite de musicas excedido\n");
}

int inserirMusicas(struct albumMusical *estruAm, int &tamLgc){
	
	printf("\nNome do Album: ");
	char nome[MAX_STR];
	
	int pos = buscaAlbum(estruAm, tamLgc, gets(nome));
	if(pos < 0) // se buscaAlbum retornar falso e porque encontrou album para inserir musicas. TEM QUE NEGAR
		return 0; // 0 Nao encontrou album para inserir
	
	// (2) TALVEZ HA UMA REDUNDANCIA
	if(!musicasTaCheio(estruAm[pos].vetQtdeMusicas))
		return 1; // 1 Quando nao cabe musicas
	
	// (1) FUNCAO LER MUSICA
	lerMusicas(estruAm, tamLgc, estruAm[pos].vetQtdeMusicas);
	return 2; //achoum, tem espaco e inseriu
}

void cadastraNovoAlbum(struct albumMusical *estruAm, int &tamLgc){
	
	char nome[50];
	
	// If verifica se ha capacidade no vetor de structs
	if(albumTaCheio(tamLgc)){ 
		
		printf("\nNome do Album: ");
		gets(nome);
		
		if(buscaAlbum(estruAm, tamLgc, nome) == -1){ // se buscaAlbum retornar falso ja existe, entao nao cadastra
			strcpy(estruAm[tamLgc].nomeAlbum, nome);
			
			printf("Ano de lancamento: ");
			scanf("%d",&estruAm[tamLgc].anoLanc);
			
			printf("Artista: ");
			fflush(stdin);
			gets(estruAm[tamLgc].artista);
			
			printf("Genero: ");
			gets(estruAm[tamLgc].genero);
			
			printf("\nMusicas\n");
			estruAm[tamLgc].vetQtdeMusicas = 0; // Sempre que e novo cadastro sera zerado!
			
			lerMusicas(estruAm, tamLgc, estruAm[tamLgc].vetQtdeMusicas); //passando zero pois sera nono album
			
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
	int albumQtde = 0, flag;
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
				
				flag = inserirMusicas(estruAm, albumQtde);
				if(flag == 0) 
					printf("Album nao encontrado");
				if(flag == 1)
					printf("\nLimite de musicas");
				if(flag == 2)
					printf("\nMusicas inseridas");
				getch();
			case 27 :
				
				printf("Fim");
				break;
				
			default:
				printf("Opcao Invalida");
		}
		
	}while(opc != 27);
	
	return 0;
}


