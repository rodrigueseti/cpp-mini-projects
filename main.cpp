#include<stdio.h> 
#include<string.h> // stricmp();
#include<conio2.h> // getche(), clrscr();
#include<ctype.h> // toupper();

#define MAX_ALBUM 3 //Seta a quantidade maxima de albuns
#define MAX_SONGS 4	//Seta a quantidade maxima de musicacas em cada album
#define MAX_STR 50 //Seta o tamanho total de uma palavra

struct albumMusical{
	
	char nomeAlbum[MAX_STR], musicas[MAX_SONGS][MAX_STR], artista[MAX_STR], genero[MAX_STR];
	int anoLanc, QtdeMusicas;
};

int buscaAlbum(albumMusical estruAm[], int tamLgc, char nome[]){
	
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
bool existeMusica(int tamLgcMusic){
	return tamLgcMusic > 0;
}
bool existeAlbum(int tamLgc){
	return tamLgc > 0;
}

void lerMusicas(albumMusical estruAm[], int &tamLgc, int &i){
	
	
	printf("%d Musica: ", i + 1);
	char nome[MAX_STR];
	fflush(stdin);
	while(musicasTaCheio(i) && stricmp(gets(nome),"")){
		
		strcpy(estruAm[tamLgc].musicas[i++], nome);
		
		if(musicasTaCheio(i))
			printf("%d Musica: ", i + 1);
	}
	if(!musicasTaCheio(i))
				printf("Limite de musicas excedido\n");
}

int inserirMusicas(albumMusical estruAm[], int &tamLgc){
	
	printf("\nNome do Album: "); //Modularizavel(1)
	char nome[MAX_STR]; //Modularizavel(1)
	//fflush(stdin);
	int pos = buscaAlbum(estruAm, tamLgc, gets(nome));
	if(pos < 0) // se buscaAlbum retornar falso e porque encontrou album para inserir musicas.
		return 0; // 0 Nao encontrou album para inserir
	
	// (2) TALVEZ HA UMA REDUNDANCIA
	if(!musicasTaCheio(estruAm[pos].QtdeMusicas))
		return 1; // 1 Quando nao cabe musicas
	
	lerMusicas(estruAm, tamLgc, estruAm[pos].QtdeMusicas);
	return 2; //achoum, tem espaco e inseriu
}
///						estrutura				album
int buscaMusica(albumMusical estruAm[], int pos, int &tamLgcMusic, char nome[]){
	
	int i = 0;
	while(i < tamLgcMusic && stricmp(nome, estruAm[pos].musicas[i]) != 0)
		i++;
		
	if(i < tamLgcMusic)
		return i; //Encontrou a musica
	return -1; //Nao encontrou
}

int buscaGenero(albumMusical estruAm[], int &tamLgc, char nome[]){
	
	int i = 0;
	while(i < tamLgc && stricmp(nome, estruAm[i].genero) != 0)
		i++;
	
	if(i < tamLgc)
		return i; //Encontrou a musica
	return -1; //Nao encontrou
}


void excluirAlbum(albumMusical estruAm[], int &tamLgc, int pos){
	
	tamLgc--;
	for(int i = pos; i < tamLgc; i++)
		estruAm[i] = estruAm[i+1];
		
	printf("Album deletado");
	getch();
}
void listarAlbumMusica(albumMusical estruAm[], int pos);

char menuDinamico(albumMusical estruAm[], int pos, int i){
	
	clrscr();
	printf("Nome do album: %s", estruAm[pos].nomeAlbum);
	printf("\n[Cetra para baixo] proxima musica");
	printf("\n[Cetra para cima] musica anterior");
	printf("\n[DEL] Deletar musica");
	printf("\n[ESC] Finalizar\n");
	printf("\n%d %s", i + 1, estruAm[pos].musicas[i]);
	
	return toupper(getch());
}

void deletarMusica(albumMusical estruAm[], int pos, int &posMusic){
	
	estruAm[pos].QtdeMusicas--;
	for(int i = posMusic; i < estruAm[pos].QtdeMusicas; i++)
		strcpy(estruAm[pos].musicas[i], estruAm[pos].musicas[i + 1]);
	
	posMusic != 0 && posMusic == estruAm[pos].QtdeMusicas ? posMusic-- : NULL;
}

int excluirMusicas(albumMusical estruAm[], int pos){
	
	char opc;
	int i = 0;
	
	do{
		opc = menuDinamico(estruAm, pos, i);
		
		switch(opc){
			
			case 72 :
				if(i > 0)
					i--;
				break;
			
			case 80 :
				if(i < estruAm[pos].QtdeMusicas - 1)
					i++;
				break;
				
			case 83 : 
				deletarMusica(estruAm, pos, i);
				break;
		}
		
	}while(opc != 27 && existeMusica(estruAm[pos].QtdeMusicas));
	
	return existeMusica(estruAm[pos].QtdeMusicas);
}

char menuAlterar(albumMusical estruAm[], int pos){
	
	clrscr();
	printf("ESTROBOS'S SOM DASHBOARD (Alterar)\n");
	printf("\nAlbum: %s\n", estruAm[pos].nomeAlbum);
	printf("\n[1] Alterar nome do album");
	printf("\n[2] Alterar lancamento");
	printf("\n[3] Alterar artista");
	printf("\n[4] Alterar genero musical");
	printf("\n[5] Alterar musicas");
	printf("\n[ESC] Finalizar\n");
	
	return toupper(getch());	
}

char menuExcluir(){
	
	clrscr();
	printf("ESTROBOS'S SOM DASHBOARD (Excluir)\n");
	printf("\n[1] Excluir album completo");
	printf("\n[2] Excluir Musicas");
	//printf("\n[3] Excluir Tudo");
	printf("\n[ESC] Retornar");
	
	return toupper(getch());
}

int excluirDados(albumMusical estruAm[], int &tamLgc){
	
	char nome[MAX_STR], opc;
	int pos;
	
	if(tamLgc <= 0)
		return 1;
		
	do{
		
		opc = menuExcluir();
		
		clrscr();
		
		switch(opc) {
			
			case '1' :
				printf("Excluir album completo\nNome do album: ");
				
				pos = buscaAlbum(estruAm, tamLgc, gets(nome));
				
				if(pos == -1){
					printf("Album nao encontrado");
					getch();
					break;
				}
				
				excluirAlbum(estruAm, tamLgc, pos);
				break;
			
			case '2' :
				printf("Deletar Musicas\nNome do album: ");
				
				pos = buscaAlbum(estruAm, tamLgc, gets(nome));
				
				if(pos == -1){
					printf("Album nao encontrado");
					getch();
					break;
				}
				
				if(!existeMusica(estruAm[pos].QtdeMusicas)){
					printf("Album sem musica");
					getch();
					break;
				}
				if(!excluirMusicas(estruAm, pos)){
					clrscr();
					printf("Sem musicas");
					getch();
				}
		}
		
	}while(opc != 27 && existeAlbum(tamLgc));
	
	// Implementar aviso de todos as informacoes deletadas
	return 0;
}

int alterarDados(albumMusical estruAm[], int &tamLgc){
	
	printf("\nNome do Album: "); //Modularizavel(1)
	char nome[MAX_STR], opc; //Modularizavel(1)
	//fflush(stdin);
	int pos = buscaAlbum(estruAm, tamLgc, gets(nome)), posMusic;
	
	if(pos < 0) //Se entrar no If nao encontrou album para alterar dados
		return 0;
	
	do{
		opc = menuAlterar(estruAm, pos);
		clrscr();
		switch(opc){
			case '1' :
				printf("Alterar nome do album");
				printf("\nNovo nome: ");
				//fflush(stdin);
				if(buscaAlbum(estruAm, tamLgc, gets(nome)) >= 0)
					printf("\nNome ja existe");
				else{ strcpy(estruAm[pos].nomeAlbum, nome);
					printf("Alterado");
				} 
				getch();
				break;
			case '2' :
				printf("Alterar Lancamento (%s: %d)\nLancamento (Ano): ", estruAm[pos].nomeAlbum, estruAm[pos].anoLanc);
				scanf("%d",&estruAm[pos].anoLanc);
				printf("Alterado");
				getch();
				break;
			case '3' :
				fflush(stdin);
				printf("Alterar artista\nNome do artista: ");
				//fflush(stdin);
				strcpy(estruAm[pos].artista, gets(nome));
				printf("Alterado");
				getch();
				break;
			case '4' :
				printf("Alterar Genero Musical\nNome do artista: ");
				//fflush(stdin);
				strcpy(estruAm[pos].genero, gets(nome));
				printf("Alterado");
				getch();
				break;
			case '5' :
				printf("Alterar Musica\nNome: ");
				
				//  buscaMusica(struct albumMusical *estruAm, int pos, int &tamLgcMusic)
				//fflush(stdin);
				posMusic = buscaMusica(estruAm, pos, estruAm[pos].QtdeMusicas, gets(nome));
				if(posMusic >= 0){
					printf("Novo nome: ");
					//fflush(stdin);
					gets(estruAm[pos].musicas[posMusic]);
					printf("Alterado");
				}
				else 
					printf("\nMusica nao encontrada");
				getch();
				break;
			case 27 : //REMOVER
				break;
			default : // REMOVER
				printf("Invalid Input");	
		}
	}while(opc != 27);
	
	return true; //apenas retornanado para finalizar
	
	getch();
}



void cadastraNovoAlbum(albumMusical estruAm[], int &tamLgc){
	
	char nome[MAX_STR];
	
	// If verifica se ha capacidade no vetor de structs
	if(albumTaCheio(tamLgc)){ 
		
		printf("\nNome do Album: ");
		//fflush(stdin);
		gets(nome);
		
		if(buscaAlbum(estruAm, tamLgc, nome) == -1){ // se buscaAlbum retornar falso ja existe, entao nao cadastra
			strcpy(estruAm[tamLgc].nomeAlbum, nome);
			
			printf("Ano de lancamento: ");
			scanf("%d",&estruAm[tamLgc].anoLanc);
			
			printf("Artista: ");
			fflush(stdin);
			gets(estruAm[tamLgc].artista);
			
			printf("Genero: ");
			//fflush(stdin);
			gets(estruAm[tamLgc].genero);
			
			printf("\nMusicas (Enter para sair)\n");
			estruAm[tamLgc].QtdeMusicas = 0; // Sempre que e novo cadastro sera zerado!
			
			lerMusicas(estruAm, tamLgc, estruAm[tamLgc].QtdeMusicas); //passando zero pois sera nono album
			
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
void listarAlbum(albumMusical estruAm[], int &pos){
	
	printf("Ano de Lancamento: %d", estruAm[pos].anoLanc);
	printf("\nNome do Artista: %s", estruAm[pos].artista);
	printf("\nGenero Musical: %s", estruAm[pos].genero);
	printf("\nQuantidade de Musicas: %d", estruAm[pos].QtdeMusicas);
	getch();
}
void listarAlbumMusica(albumMusical estruAm[], int pos){
	
	for (int i = 0; i < estruAm[pos].QtdeMusicas; i++)
		printf("\n%d %s", i + 1, estruAm[pos].musicas[i]);
		
	getch();
}
void listarAlbumGenero(albumMusical estruAm[], int &tamLgc, char nome[]){
	
	for (int i = 0; i < tamLgc; i++)
		if(!stricmp(estruAm[i].genero, nome))
			printf("\n%d %s, Genero: %s", i + 1, estruAm[i].nomeAlbum, estruAm[i].genero);
	getch();
}
void listarTudo(albumMusical estruAm[], int &tamLgc){
	
	for(int i = 0; i < tamLgc; i++){
		printf("\n\nAlbum: %s", estruAm[i].nomeAlbum);
		printf("\nAno de Lancamento: %d", estruAm[i].anoLanc);
		printf("\nNome do Artista: %s", estruAm[i].artista);
		printf("\nGenero Musical: %s", estruAm[i].genero);
		printf("\nQuantidade de Musicas: %d", estruAm[i].QtdeMusicas);
		printf("\nMusicas");
		
		for(int j = 0; j < estruAm[i].QtdeMusicas; j++)		
			printf("\n%d %s", j + 1, estruAm[i].musicas[j]);
	}
	getch();
}


char menuListarDados(){
	
	clrscr();
	printf("ESTROBOS'S SOM DASHBOARD (Listar)\n");
	printf("\n[1] Informacoes do album");
	printf("\n[2] Album e musicas");
	printf("\n[3] Albuns por genero");
	printf("\n[4] Listar tudo");
	printf("\n[5] Listagem inteligente (coming soon ;-)");
	printf("\n[ESC] Finalizar\n");
	
	
	return toupper(getch());
}

int listarDados(albumMusical estruAm[], int &tamLgc){
	
	char nome[MAX_STR], opc;
	int pos, flag;
	
	if(tamLgc <= 0) //Retorna 0 se não ha nenhuma informacao a ser listada, ou nenhum album gravado
		return 0;
	
	do{
		opc = menuListarDados();
		clrscr();
		
		switch(opc){
			case '1' :
				printf("INFORMACOES DO ALBUM\n"); //Generalizar funcao de ler album
				printf("\nNome do album: ");
				//fflush(stdin);
				pos = buscaAlbum(estruAm, tamLgc, gets(nome));
				
				if(pos == -1){
					printf("Album nao encontrado");
					getch();
				}
				if(pos >= 0)
					listarAlbum(estruAm, pos);
				break;
			case '2' :
				printf("ALBUM E MUSICAS");
				printf("\nNome do album: ");
				//fflush(stdin);
				pos = buscaAlbum(estruAm, tamLgc, gets(nome));
				
				if(pos == -1){
					printf("Album nao encontrado");
					getch();
				}
				if(pos >= 0)
					listarAlbumMusica(estruAm, pos);
				break;
			case '3' :
				
				printf("ALBUNS POR GENERO");
				printf("\nGenero: ");
				//fflush(stdin);
				flag = buscaGenero(estruAm, tamLgc, gets(nome));
				
				if(flag == -1){
					printf("Genero nao encontrado");
					getch();
				}
				if(flag >= 0)
					listarAlbumGenero(estruAm, tamLgc, nome);
				break;
			case '4' : 
				printf("LISTAR TUDO");
				listarTudo(estruAm, tamLgc);
				//break;
		}
		
	}while(opc != 27);
	return 1; //Retorno para finalizar com sucesso
}

char menu(void){
	clrscr();
	printf("ESTROBOS'S SOM DASHBOARD\n");
	printf("\n[1] Cadastrar Novo Album");
	printf("\n[2] Inserir Musicas");
	printf("\n[3] Alterar Dados");
	printf("\n[4] Excluir Dados");
	printf("\n[5] Listar Dados");
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
				
				printf("CADASTRAR NOVO ALBUM");
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
				break;
				
			case '3' :
				
				printf("Alterar Dados");
				if(!alterarDados(estruAm, albumQtde))
					printf("Album nao encontrado ");
				printf("Finalizado");
				getch();
				break;
			case '4' :
				if(excluirDados(estruAm, albumQtde)){
					printf("Sem dados para deletar");
					getch();
				}
				break;
			case '5' :
				if(!listarDados(estruAm, albumQtde)){
					printf("Nada para listar");
					getch();
				}
					
				break;
			case 27 :
				
				printf("Fim");
				break;
				
			default:
				printf("Invalid Input");
				
		}
	}while(opc != 27);
	
	return 0;
}


