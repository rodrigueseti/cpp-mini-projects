#include<stdio.h> 
#include<string.h> // stricmp();
#include<conio2.h> // getche(), clrscr();
#include<ctype.h> // toupper();

#define MAX_ALBUM 3
#define MAX_SONGS 3
#define MAX_STR 50

struct albumMusical{
	
	char nomeAlbum[MAX_STR], musicas[MAX_SONGS][MAX_STR], artista[MAX_STR], genero[MAX_STR];
	int anoLanc, vetQtdeMusicas;
};

int buscaAlbum(struct albumMusical *estruAm, int &tamLgc, char *nome){
	
	int i = 0;
	while(i < tamLgc && stricmp(nome, estruAm[i].nomeAlbum) != 0)
		i++;
		
	if(i < tamLgc) // se i menor que tl significa que album já existe
		return i; //Encontrou, Modulariazar esse if
	return -1; //Não Encontrou!
}
bool albumTaCheio(int tamLgc){
    return tamLgc < MAX_ALBUM;
}
bool musicasTaCheio(int tamLgc){
	return tamLgc < MAX_SONGS;
}

int inserirMusicas(struct albumMusical *estruAm, int &tamLgc){
	
	//ENTRAR COM NOME DO ALBUM NOME DO ALBUM * continuar
	printf("\nNome do Album: ");
	char nome[MAX_STR];
	//int pos
	int pos = buscaAlbum(estruAm, tamLgc, gets(nome));
	if(pos < 0) // se buscaAlbum retornar falso é porque encontrou album para inserir musicas. TEM QUE NEGAR
		return 0; // 0 Não encontrou album para inserir
	
	printf("Nome digitado: %s", nome);
	printf("\nestruAm qtde musica: %d", estruAm[pos].vetQtdeMusicas);
	getch();
	
	
	if(!musicasTaCheio(estruAm[pos].vetQtdeMusicas)) // parei aqui
		return 1; // 1 Quando não cabe musicas
		
	getch();
	return 2; //2 Prossegue com a inserção
}

void cadastraNovoAlbum(struct albumMusical *estruAm, int &tamLgc){
	
	char nome[50];
	
	// If verifica se ha capacidade no vetor de structs
	if(albumTaCheio(tamLgc)){ 
		
		printf("\nNome do Album: ");
		gets(nome);
		
		if(buscaAlbum(estruAm, tamLgc, nome) == -1){ // se buscaAlbum retornar falso já existe, então não cadastra
			strcpy(estruAm[tamLgc].nomeAlbum, nome);
			
			printf("Ano de lancamento: ");
			scanf("%d",&estruAm[tamLgc].anoLanc);
			
			printf("Artista: ");
			fflush(stdin);
			gets(estruAm[tamLgc].artista);
			
			printf("Genero: ");
			gets(estruAm[tamLgc].genero);
			
			printf("\nMusicas\n");
			int i = 0;
				
			printf("%d Musica: ", i + 1);
			while(musicasTaCheio(i) && stricmp(gets(nome),"")){
				
				strcpy(estruAm[tamLgc].musicas[i++], nome);
				
				if(musicasTaCheio(i))
					printf("%d Musica: ", i + 1);
			}
			if(!musicasTaCheio(i))
				printf("Limite de musicas excedido\n");
				
			estruAm[tamLgc].vetQtdeMusicas = i; //Vetor Tamanho Logico de Musicas Recebendo Quantidade Exate de Musicas
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
				printf("\nFlag: %d",flag);
				getch();
			case 27 :
				
				printf("Fim");
				break;
				
			default:
				printf("Opcao Invalida");
		}
		
	}while(opc != 27);
	//printf("albumQtde: %d",albumQtde);
	//printf("\nTL Musicas na 0: %d",estruAm[0].vetQtdeMusicas);
	
	return 0;
}


