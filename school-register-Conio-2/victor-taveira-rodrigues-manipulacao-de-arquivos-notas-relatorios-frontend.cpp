#include <stdio.h> // Input Output
#include <ctype.h> // toupper();
#include <conio.h>
#include <conio2.h> // clrscr(), textcolor(), getche();
#include <string.h> // stricmp();
#include <windows.h> // Sleep();

#define COR_TITULO		   BLACK
#define COR_FUNDO_TITULO   LIGHTGRAY 
#define COR_MOLDURA_TITULO GREEN		

#define COR_FUNDO_CORPO    WHITE     
#define COR_MOLDURA_CORPO  RED       

#define COR_TEXTO_RODAPE   BLACK
#define COR_FUNDO_RODAPE   LIGHTGRAY

#define COR_ALUNO 		   BLUE
#define COR_DIS			   BLUE
#define COR_NOTA           BLUE
#define COR_REL            BLUE

struct tpAluno {
	
	char aluRa[13], aluNome[40];
};

struct tpDis {
	
	int disCod;
	char disNome[40];
};

struct tpNotas {
	
	char notaRa[13];
	int notaDisCod;
	float nota;
	int status;
};

char menu(void);
void fullscreen(void);
void moldura(int col1, int lin1, int col2, int lin2,  int corMoldura, int corFundo, int fixMoldura);
void molduraTitulo(int col1, int lin1, int col2, int lin2,  int corMoldura, int corFundo, int corFundoPrimaria);
void molduraLinhaRodape(int col1, int lin1, int col2, int lin2,  int corMoldura, int corFundo);

void desenharLayout(int altura = 30);
void clrTittle();
void clrCorpo();
void clrRodape(int altura = 29);

void criaArquivos(void);

void cadastroAlunos(char nomeArq[]);
void cadastroDisciplina(char nomeArq[]);
void cadastroNotas(char arqNota[], char arqDis[], char arqAlu[]);

void altAlunos(char nomeArq[]);
void altDis(char nomeArq[]);
void altNotas(char nomeArq[]);

void excFisAlunos(char nomeArq[]);
void excFisDisciplina(char nomeArq[]);
void excFisicaNotas(char nomeArq[]);
void excLogicaNotas(char nomeArq[]);


void ordenaAlunos(char nomeArq[]);

void consAlunosRa(char nomeArq[]);
void consAlunosNome(char nomeArq[]);
void consDisCod(char nomeArq[]);
void consDisNome(char nomeArq[]);
void consNotas(char nomeArq[]);

void relAlunos(char nomeArq[]);
void relDis(char nomeArq[]);
void relNotas(char nomeArq[]);

int buscaAluno(FILE *ptrAluno, char ra[]);
int buscaBinariaAluno(FILE *ptrAluno, char ra[]);
int buscaBinariaDis(FILE *ptrDis, int codAux);
int buscaSentinelaDisNome(FILE *ptrDis, char nome[]);
int buscaExaustivaNotas(FILE *ptrNota, char ra[], int codAux);

void removerSentinela(char nomeArq[]);

void insercaoDireta(FILE *ptrDis);
void insercaoDiretaNotas(FILE *ptrNota);

void alunosReprovados(char nomeAlu[], char nomeDis[], char nomeNota[]);
void listagemPorIncial(char nomeArq[]);
void mediaDisciplinas(char nomeDis[], char nomeNota[]);
void alunoDisciplinas(char nomeAlu[], char nomeDis[], char nomeNota[]);
void disciplinasAlunos(char nomeAlu[], char nomeDis[], char nomeNota[]);


int main(){
	
	system("title MANIPULACAO DE ARQUIVOS VICTOR TAVEIRA RODRIGUES");
	char opcao;
	//fullscreen();
	desenharLayout();
	criaArquivos();
	do {
		
		opcao = menu();
		
		switch (opcao) {
			
			case 'A' :
				cadastroAlunos("Alunos.dat");
				break;
				
			case 'B' :
				relAlunos("Alunos.dat");
				break;
				
			case 'C' :
				consAlunosRa("Alunos.dat");
				break;
				
			case 'D' : 
				altAlunos("Alunos.dat");
				break;
			
			case 'E' :
				excFisAlunos("Alunos.dat");
				break;
				
			case 'F' :
				ordenaAlunos("Alunos.dat");
				break;
				
			case 'G' :
				ordenaAlunos("Alunos.dat");
				consAlunosNome("Alunos.dat");
				break;
				
			case 'H' :
				cadastroDisciplina("Disciplinas.dat");
				break;
				
			case 'I' :
				relDis("Disciplinas.dat");
				break;
				
			case 'J' :
				consDisCod("Disciplinas.dat");
				break;
				
			case 'K' :
				altDis("Disciplinas.dat");
				break;
				
			case 'L' :
				excFisDisciplina("Disciplinas.dat");
				break;
				
			case 'M' :
				consDisNome("Disciplinas.dat");
				break;
				
			case 'N' :
				cadastroNotas("Notas.dat", "Disciplinas.dat", "Alunos.dat");
				break;
				
			case 'O' :
				relNotas("Notas.dat");
				break;
				
			case 'P' :
				consNotas("Notas.dat");
				break;
				
			case 'Q' :
				altNotas("Notas.dat");
				break;
				
			case 'R' :
				excLogicaNotas("Notas.dat");
				break;
				
			case 'S' :
				//ordenaAlunos("Alunos.dat"); //OPCIONAL, CASO USE A BUSCA BINARIA DE ALUNOS NA FUNCAO DE ALUNOS REPROVADOS, Alunos.dat, DEVERA SER ORDENADO ANTES
				alunosReprovados("Alunos.dat", "Disciplinas.dat", "Notas.dat");
				break;
			
			case 'T' :
				listagemPorIncial("Alunos.dat");
				break;
				
			case 'U' :
				mediaDisciplinas("Disciplinas.dat", "Notas.dat");
				break;
				
			case 'V' :
				alunoDisciplinas("Alunos.dat", "Disciplinas.dat", "Notas.dat");
				break;
				
			case 'W' :
				disciplinasAlunos("Alunos.dat", "Disciplinas.dat", "Notas.dat");
				break;
				
			case 'X' :
				excFisicaNotas("Notas.dat");
				break;
		}
	}while (opcao != 27);
	
	
	return 0;
}
void clearkeybuf (void)
{
    while (kbhit()) {
        getch();
    }
}


void clrTittle()
{
	textbackground(COR_FUNDO_TITULO);
	gotoxy(5, 3); printf("                                                                                                                ");
	gotoxy(5, 4); printf("                                                                                                                ");
	textcolor(COR_TITULO);
}

void clrCorpo()
{
	textbackground(COR_FUNDO_CORPO);
	for(int posX = 3, posY = 6; posY < 28; posY++)
	{
		gotoxy(posX, posY); 
		printf("                                                                                                                    ");
	}
}
void moldura(int col1, int lin1, int col2, int lin2,  int corMoldura, int corFundo, int fixMoldura)
{
	int i;
	
	if(fixMoldura) {
		
		textbackground(corMoldura);
		
		for(int i = 0, posY = 2; i < 28; i++) {
				gotoxy(2, posY++); 
				printf("                                                                                                                      ");
			}
	}
	
	textcolor(corMoldura);
	//LINHAS
	for(i = col1; i <= col2; i++){
		
		gotoxy(i, lin1); printf("%c", 220);
		
		gotoxy(i, lin2); printf("%c", 223);
	}
	
	//COLUNAS
	for(i = lin1 + 1; i < lin2; i++)
	{
		gotoxy(col1, i); printf("%c", 219);
		//Sleep(10);
		gotoxy(col2, i); printf("%c", 219);
	}
	
	//FUNDO
	textbackground(corFundo);	
	for(int posX = col1 + 1, posY = lin1 + 1; posY < lin2; posY++)
	{
		gotoxy(posX, posY); 
		printf("                                                                                                                    ");
	}
}

void molduraTitulo(int col1, int lin1, int col2, int lin2,  int corMoldura, int corFundo, int corFundoPrimaria)
{
	int i;
	
	textbackground(corFundoPrimaria);
	textcolor(corMoldura);
	//LINHAS
	for(i = col1; i <= col2; i++){
		
		gotoxy(i, lin1); printf("%c", 220);
		//Sleep(15);
		gotoxy(i, lin2); printf("%c", 223);
	}
	//COLUNAS
	for(i = lin1 + 1; i < lin2; i++)
	{
		gotoxy(col1, i); printf("%c", 219);
		//Sleep(10);
		gotoxy(col2, i); printf("%c", 219);
	}
	
	textbackground(corFundo);
	for(int posX = col1 + 1, posY = lin1 + 1; posY < lin2; posY++)
	{
		gotoxy(posX, posY); 
		printf("                                                                                                                ");
	}
}

void molduraLinhaRodape(int col1, int lin1, int col2, int lin2,  int corMoldura, int corFundo)
{	

	textcolor(corMoldura);
	for(int i = col1 + 1; i < col2; i++){     
	
		gotoxy(i, lin2 - 2); 
		printf("%c", 220);                              
	}
	textbackground(corFundo);
	gotoxy(col1 + 1, lin2 - 1);
	printf("                                                                                                                    ");
}

void clrRodape(int altura){
	
	textbackground(COR_FUNDO_RODAPE);
	gotoxy(3, altura);
	printf("                                                                                                                    ");
	textcolor(COR_TEXTO_RODAPE);
}

void desenharLayout(int altura)
{
	moldura(2, 1, 119, altura, COR_MOLDURA_CORPO, COR_FUNDO_CORPO, 0);
	molduraLinhaRodape(2, 1, 119, altura, COR_MOLDURA_CORPO,  COR_FUNDO_RODAPE);
	molduraTitulo(4, 2, 117, 5, COR_MOLDURA_TITULO, COR_FUNDO_TITULO, COR_FUNDO_CORPO);
}

void disciplinasAlunos(char nomeAlu[], char nomeDis[], char nomeNota[])
{
	//FUNCAO OBRIGATORIAMENTE TERA QUE REALIZAR A EXCLUSAO FISICA DO Arquivo Notas PARA SER CONSIDERADO NO FOEF
	tpAluno regAlu;
	tpDis regDis;
	tpNotas regNota;
	
	int pos;
	
	FILE *ptrAlu = fopen(nomeAlu, "rb");
	FILE *ptrDis = fopen(nomeDis, "rb");
	FILE *ptrNota = fopen(nomeNota, "rb");
	
	clrscr();
	printf("DISCIPLINAS E ALUNOS\n");
	
	fread(&regDis, sizeof(tpDis), 1, ptrDis);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	if(feof(ptrNota))
		printf("Sem registros");
	else
		while(!feof(ptrDis))
		{
			while(!feof(ptrNota) && (regDis.disCod != regNota.notaDisCod || regNota.status == 0))
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
			
			if(!feof(ptrNota))
			{
				printf("\nDISCIPLINA: %s", regDis.disNome);
				
				fseek(ptrNota, 0, SEEK_SET);
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				
				while(!feof(ptrNota))
				{
					if(regDis.disCod == regNota.notaDisCod && regNota.status == 1){
						
						pos = buscaAluno(ptrAlu, regNota.notaRa);
						
						fseek(ptrAlu, pos, SEEK_SET);
						
						fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
						
						printf("\nNOME: %s", regAlu.aluNome);
					}
					fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				}
				printf("\n");
			}
			fseek(ptrNota, 0, SEEK_SET);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
		}
	fclose(ptrAlu);
	fclose(ptrDis);
	fclose(ptrNota);
	getch();
}

void alunoDisciplinas(char nomeAlu[], char nomeDis[], char nomeNota[])
{
	//FUNCAO OBRIGATORIAMENTE TERA QUE REALIZAR A EXCLUSAO FISICA DO Arquivo Notas PARA SER CONSIDERADO NO FOEF
	tpAluno regAlu;
	tpDis regDis;
	tpNotas regNota;
	
	int pos;
	
	FILE *ptrAlu = fopen(nomeAlu, "rb");
	FILE *ptrDis = fopen(nomeDis, "rb");
	FILE *ptrNota = fopen(nomeNota, "rb");
	
	clrscr();
	printf("ALUNOS E DISCIPLINAS\n");
	
	fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	if(feof(ptrNota))
		printf("Sem registros");
	else
		while(!feof(ptrAlu))
		{
			while(!feof(ptrNota) && (stricmp(regAlu.aluRa, regNota.notaRa) || regNota.status == 0))
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
			
			if(!feof(ptrNota))
			{
				printf("\nNOME: %s", regAlu.aluNome);
				
				fseek(ptrNota, 0, SEEK_SET);
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				
				while(!feof(ptrNota))
				{
					if(stricmp(regAlu.aluRa, regNota.notaRa) == 0 && regNota.status == 1){
						
						pos = buscaBinariaDis(ptrDis, regNota.notaDisCod);
						
						fseek(ptrDis, pos, SEEK_SET);
						fread(&regDis, sizeof(tpDis), 1, ptrDis);
						
						printf("\nDisciplina: %s", regDis.disNome);
					}
					fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				}
				printf("\n");
			}
			fseek(ptrNota, 0, SEEK_SET);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
		}
	fclose(ptrAlu);
	fclose(ptrDis);
	fclose(ptrNota);
	getch();
}

void mediaDisciplinas(char nomeDis[], char nomeNota[])
{
	tpDis regDis;
	tpNotas regNota;
	float soma;
	int cont;
	
	FILE *ptrDis = fopen(nomeDis, "rb");
	FILE *ptrNota = fopen(nomeNota, "rb");
	
	clrscr();
	printf("DISCIPLINAS COM MEDIA [<6]\n");
	
	fread(&regDis, sizeof(tpDis), 1, ptrDis);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	if(feof(ptrDis) || feof(ptrNota))
		printf("Sem registros");
		
	while(!feof(ptrDis) && !feof(ptrNota))
	{
		soma = 0;
		cont = 0;
		
		while(!feof(ptrNota))
		{
			if(regNota.status == 1 && regDis.disCod == regNota.notaDisCod )
			{
				soma = soma + regNota.nota;
				cont++;
			}
			fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		}
		
		soma = soma / (float) cont;
		
		if(cont > 0 && soma < 6)
		{
			printf("\nCodigo: %d", regDis.disCod);
			printf("\nDisciplina: %s", regDis.disNome);	
			printf("\nMedia Geral: %.2f\n", soma);
		}
		fread(&regDis, sizeof(tpDis), 1, ptrDis);
		
		fseek(ptrNota, 0, SEEK_SET);
		fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	}
	fclose(ptrDis);
	fclose(ptrNota);
	getch();
}



void listagemPorIncial(char nomeArq[])
{
	tpAluno regAlu;
	char c;
	
	FILE *ptrAlu = fopen(nomeArq, "rb");
	
	clrscr();
	printf("BUSCA POR INICIAL");
	
	fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
	
	if(feof(ptrAlu)){
		printf("\nSem registros");
	}else{
		printf("\nLetra: ");
		c = toupper(getche());
		printf("\n");
	}
	
	while(!feof(ptrAlu))
	{
		if(toupper(regAlu.aluNome[0]) == c)
			printf("\nNome: %s \t\t R.A.: %s", regAlu.aluNome, regAlu.aluRa);	
			
		fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);	
	}
	fclose(ptrAlu);
	getch();
}

void alunosReprovados(char nomeAlu[], char nomeDis[], char nomeNota[])
{
	//COMPLETO
	int pos, posY = 6, posX = 4, regSize = 0;
	
	tpAluno regAlu;
	tpDis regDis;
	tpNotas regNota;
	
	FILE *ptrAlu = fopen(nomeAlu, "rb");
	FILE *ptrDis = fopen(nomeDis, "rb");
	FILE *ptrNota = fopen(nomeNota, "rb");
	
	fseek(ptrNota, 0, SEEK_SET);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	if(feof(ptrNota)){
		
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(1500);
		clrRodape();
		clearkeybuf();
	}
	else{
		
		fseek(ptrNota, 0, SEEK_SET);
		fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		
		while(!feof(ptrNota))
		{
			if(regNota.status != 0 && regNota.nota < 6)
				regSize++;
				
			fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		}
		
		fseek(ptrNota, 0, SEEK_SET);
		fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		
		if(regSize * 7 > 22)
		{	
			//textbackground(BLACK);
			system("cls");
			desenharLayout(30 + (regSize * 7 - 23));
		}
		
		clrTittle();
		gotoxy(54, 3); printf("ALUNOS REPROVADOS %d", regSize);
		gotoxy(48, 4); printf("(BUSCA EXAUSTIVA - EXAUSTIVA)");
		
		clrCorpo();
		textcolor(COR_NOTA);
		
		while(!feof(ptrNota))
		{
			if(regNota.status != 0 && regNota.nota < 6){
				
				pos = buscaAluno(ptrAlu, regNota.notaRa);
				
				fseek(ptrAlu, pos, SEEK_SET);
				fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
				
				pos = buscaBinariaDis(ptrDis, regNota.notaDisCod);
				
				fseek(ptrDis, pos, SEEK_SET);
				fread(&regDis, sizeof(tpDis), 1, ptrDis);
				
				gotoxy(posX, posY++);    printf("NOME: %s", regAlu.aluNome);
				gotoxy(posX, posY++);    printf("REGISTRO ACAD. (RA): %s", regAlu.aluRa);
				gotoxy(posX, posY++);    printf("DISCIPLINA: %s", regDis.disNome);
				gotoxy(posX, posY++);    printf("DISCI. COD.: %d", regDis.disCod);
				gotoxy(posX, posY++);    printf("NOTA: %.2f", regNota.nota);
				gotoxy(posX, posY);      printf("SITUACAO: ");
				textcolor(RED); 
				gotoxy(posX + 10, posY++); printf("REPROVADO");
				textcolor(COR_NOTA);
				posY++;
			}
			fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		}
		
		if(regSize * 7 > 22){
			
			posY = 29 + (regSize * 7 - 23);
			
			clrRodape(posY);
			gotoxy(53, posY); printf("PRONTO!");
			Sleep(1500);
			clrRodape(posY);	
			
		}
		clearkeybuf();
		getch();
		
		if(regSize * 7 > 22)
		{
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
	}
	fclose(ptrAlu);
	fclose(ptrDis);
	fclose(ptrNota);
}


void insercaoDireta(FILE *ptrDis)
{
	tpDis regDisI, regDisJ;
	int pos = (ftell(ptrDis) - sizeof(tpDis)) / sizeof(tpDis); //Considerando que o ponteiro esta posicionado no final do arquivo
	if(pos > 0)
	{
		fseek(ptrDis, (pos - 1) * sizeof(tpDis), SEEK_SET);
		fread(&regDisI, sizeof(tpDis), 1, ptrDis);
		fread(&regDisJ, sizeof(tpDis), 1, ptrDis);
		while(pos > 0 && regDisJ.disCod < regDisI.disCod)
		{
			fseek(ptrDis, (pos - 1) * sizeof(tpDis), SEEK_SET);
			fwrite(&regDisJ, sizeof(tpDis), 1, ptrDis);
			fwrite(&regDisI, sizeof(tpDis), 1, ptrDis);
			pos--;
			
			fseek(ptrDis, (pos - 1) * sizeof(tpDis), SEEK_SET); 
			fread(&regDisI, sizeof(tpDis), 1, ptrDis); 
			fread(&regDisJ, sizeof(tpDis), 1, ptrDis);
		}
	}	
}

void insercaoDiretaNotas(FILE *ptrNota)
{
	tpNotas regNotaI, regNotaJ;
	
	int pos = (ftell(ptrNota) - sizeof(tpNotas)) / sizeof(tpNotas); //Considerando que o ponteiro esta posicionado no final do arquivo
	
	if(pos > 0)
	{
		fseek(ptrNota, (pos - 1) * sizeof(tpNotas), SEEK_SET);
		
		fread(&regNotaI, sizeof(tpNotas), 1, ptrNota);
		fread(&regNotaJ, sizeof(tpNotas), 1, ptrNota);
		
		while(pos > 0 && stricmp(regNotaI.notaRa, regNotaJ.notaRa) < 0)
		{
			//CONTINUAR
			
			fseek(ptrNota, (pos - 1) * sizeof(tpNotas), SEEK_SET);
			fwrite(&regNotaJ, sizeof(tpNotas), 1, ptrNota);
			fwrite(&regNotaI, sizeof(tpNotas), 1, ptrNota);
			
			pos--;
			
			fseek(ptrNota, (pos - 1) * sizeof(tpNotas), SEEK_SET); 
			fread(&regNotaI, sizeof(tpNotas), 1, ptrNota); 
			fread(&regNotaJ, sizeof(tpNotas), 1, ptrNota);
		}
	}	
}

int buscaBinariaDis(FILE *ptrDis, int codAux)
{
	tpDis regDis;
	
	fseek(ptrDis, 0, SEEK_END);
	
	
	int start = 0, end = ftell(ptrDis) / sizeof(tpDis) - 1, mid;
	mid = end / 2;
	
	/*printf("\n\nFtell (ptrDis): %d", ftell(ptrDis));
	printf("\nSizeof (ptr): %d", sizeof(ptrDis));
	printf("\nSizeof (tpDis): %d", sizeof(tpDis));
	printf("\nCodAux: %d", codAux); 
	printf("\nSTART: %d", start);
	printf("\nMID: %d", mid);
	printf("\nEND: %d\n\n", end);
	getch();*/
	
	fseek(ptrDis, mid * sizeof(tpDis), SEEK_SET);
	fread(&regDis, sizeof(tpDis), 1, ptrDis);
	
	while(start < end && codAux != regDis.disCod)
	{
		if(regDis.disCod < codAux)
			start = mid + 1;
		else
			end = mid - 1;
		
		mid = (start + end) / 2;
		
		fseek(ptrDis, mid * sizeof(tpDis), SEEK_SET);
		fread(&regDis, sizeof(tpDis), 1, ptrDis);
	}
	if(regDis.disCod == codAux)
		return mid * sizeof(tpDis);
	return -1;
}

int buscaBinariaAluno(FILE *ptrAluno, char nome[])
{
	tpAluno regMeio;
	
	fseek(ptrAluno, 0, SEEK_END);
	
	int start = 0;
	int end = ftell(ptrAluno) / sizeof(tpAluno) - 1;
	int mid = end / 2;
	
	/*printf("\nMID: %d", mid);
	printf("\nEND: %d", end);
	getch();*/
	
	fseek(ptrAluno, mid * sizeof(tpAluno), SEEK_SET);
	fread(&regMeio, sizeof(tpAluno), 1, ptrAluno);
	
	while(start < end && stricmp(nome, regMeio.aluNome) != 0)
	{
		if(stricmp(regMeio.aluNome, nome) < 0) 
			start = mid + 1;
		else
			end = mid - 1;
		
		mid = (start + end) / 2;
		
		fseek(ptrAluno, mid * sizeof(tpAluno), SEEK_SET);
	    fread(&regMeio, sizeof(tpAluno), 1, ptrAluno);
	}
	
	if(stricmp(nome, regMeio.aluNome) == 0)
		return mid * sizeof(tpAluno);
	return -1;
}
// Tentar passar estrutura no segundo parametro
int buscaSentinelaDisNome(FILE *ptrDis, char nome[])
{
	// CONTINUAR
	/*
	int i = 0;
	vetor[TL] = valor;
	
	while(valor != vetor[i])
		i++;
		
	if(i < TL)
		return i;
	else
		return -1;
	*/
	int pos;
	tpDis regDis;
	FILE *ptrTemp = fopen("temp.dat", "wb");
	
	//COPIANDO ARQUIVO ORIGINAL PARA ARQUIVO TEMPORARIO
	fseek(ptrDis, 0, SEEK_SET);
	fread(&regDis, sizeof(tpDis), 1, ptrDis);
	while(!feof(ptrDis))
	{
		fwrite(&regDis, sizeof(tpDis), 1, ptrTemp);
		fread(&regDis, sizeof(tpDis), 1, ptrDis);
	}
	fclose(ptrTemp);
	//COPIANDO ARQUIVO ORIGINAL PARA ARQUIVO TEMPORARIO
	
	
	strcpy(regDis.disNome, nome); // COPIANDO SENTINELA PARA REGISTRO AUXILIAR, PONTEIRO POSICIONADO NO FINAL APOS O LOOP ACIMA
	
	fwrite(&regDis, sizeof(tpDis), 1, ptrDis); //GRAVANDO REGISTRO AUXILIAR NO FINAL DO ARQUIVO
	
	fseek(ptrDis, 0, SEEK_SET); // POSICIONANDO O PONTEIRO NO COMECO DO ARQUIVO
	
	fread(&regDis, sizeof(tpDis), 1, ptrDis); // LENDO O PRIMEIRO REGISTRO
	
	while(stricmp(regDis.disNome, nome)) // LOOP ENQUANDO NAO ENCONTRA O NOME OU O SENTINELA
		fread(&regDis, sizeof(tpDis), 1, ptrDis);
	
	fread(&regDis, sizeof(tpDis), 1, ptrDis); //MAIS UMA LEITURA PARA INDENTIFICAR SE E O ELEMENTO OU O SENTINELA
	
	if(feof(ptrDis))
		return -1;
	return ftell(ptrDis) - 2 * sizeof(tpDis); 
}

void ordenaAlunos(char nomeArq[]) 
{
	
	
	clrRodape();
	gotoxy(54, 29); printf("(NOME CRESCENTE) ORDENANDO ARQUIVO: %s...", nomeArq);
	Sleep(1500);
	clearkeybuf();
	
	tpAluno regI, regJ;
	FILE *ptrAlu = fopen(nomeArq, "rb+");
	
	fseek(ptrAlu, 0, SEEK_END);
	
	int fileSize = ftell(ptrAlu) / sizeof(tpAluno);
	int regSize = sizeof(tpAluno);
	
	for(int i = 0, j; i < fileSize - 1; i++)
		for(j = i + 1; j < fileSize; j++) 
		{
			fseek(ptrAlu, i * sizeof(tpAluno), SEEK_SET);
			fread(&regI, sizeof(tpAluno), 1, ptrAlu);
			
			fseek(ptrAlu, j * sizeof(tpAluno), SEEK_SET);
			fread(&regJ, sizeof(tpAluno), 1, ptrAlu);
			
			if(strcmp(regI.aluNome, regJ.aluNome) > 0)
			{
				fseek(ptrAlu, i * sizeof(tpAluno), SEEK_SET);
				fwrite(&regJ, sizeof(tpAluno), 1, ptrAlu);
				
				fseek(ptrAlu, j * sizeof(tpAluno), SEEK_SET);
				fwrite(&regI, sizeof(tpAluno), 1, ptrAlu);
			}
		}
	clrRodape();
	gotoxy(54, 29); printf("ARQUIVO ORDENADO!");
	Sleep(1000);
	clearkeybuf();
	clrRodape();
	
	fclose(ptrAlu);
}

void fullscreen(void)
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void excFisAlunos(char nomeArq[]) {
	
	tpAluno regAlu;
	char auxRa[13];
	int pos, posY = 6, posX = 4;   
	
	FILE *ptrAluno = fopen(nomeArq, "rb");
	
	clrTittle();
	gotoxy(54, 3); printf("EXCLUIR DADOS DE ALUNOS");
	gotoxy(48, 4); printf("(BUSCA EXAUSTIVA)");
	
	clrCorpo();
	textcolor(COR_ALUNO);
	gotoxy(posX, posY); printf("R.A: ");
	fflush(stdin);
	gets(auxRa);
	
	if(stricmp(auxRa, "\0") != 0) {
		
		//Busca...
		pos = buscaAluno(ptrAluno, auxRa);
		posY++;
		
		if (pos > -1) {
			
			
			fseek(ptrAluno, pos, 0);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			
			gotoxy(posX, posY); printf("REGISTRO ACAD. (RA): %s", regAlu.aluRa);
			gotoxy(posX + 30, posY++); printf("NOME: %s", regAlu.aluNome);
			
			clrRodape();
			gotoxy(50, 29); printf("EXCLUIR ? (S/N)");
			
			if(toupper(getch()) == 'S') 
			{
				clrRodape();
				
				FILE *ptrTemp = fopen("temp.dat", "wb");
				
				rewind(ptrAluno); 
				//or 
				//fseek(ptrAluno, 0, 0);
				
				fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
				
				while(!feof(ptrAluno)) {
					
					if(stricmp(auxRa, regAlu.aluRa) != 0)
						fwrite(&regAlu, sizeof(tpAluno), 1, ptrTemp);
						
					fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
				}
				fclose(ptrAluno);
				fclose(ptrTemp);
				
				remove(nomeArq);
				rename("temp.dat", nomeArq);
				
				clrRodape();
				gotoxy(54, 29); printf("REGISTRO DELETADO, OK!");
				Sleep(1500);
				clearkeybuf();
				clrRodape();
			}
			else{
				clrRodape();
				fclose(ptrAluno);
			}
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("NAO ENCONTRADO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
	}
	else
		fclose(ptrAluno);
}




void excLogicaNotas(char nomeArq[])
{
	tpNotas regNotas;
	int pos, posY = 6, posX = 4, codAux;
	
	FILE *ptrNota = fopen(nomeArq, "rb+");
	
	clrTittle();
	gotoxy(54, 3); printf("EXCLUIR DADOS DE NOTAS");
	gotoxy(48, 4); printf("(BUSCA EXAUSTIVA)");
	
	
	clrCorpo();
	textcolor(COR_NOTA);
	gotoxy(posX, posY++); printf("R.A.: ");
	fflush(stdin);
	gets(regNotas.notaRa);
	
	if(stricmp(regNotas.notaRa, "\0"))
	{
		gotoxy(posX, posY++); printf("COD. DIS.: ");
		scanf("%d", &regNotas.notaDisCod);
		
		if(regNotas.notaDisCod > 0){
			
			pos = buscaExaustivaNotas(ptrNota, regNotas.notaRa, regNotas.notaDisCod);
		
			if(pos > -1)
			{
				fseek(ptrNota, pos, SEEK_SET);
				fread(&regNotas, sizeof(tpNotas), 1, ptrNota);
				
				
				gotoxy(posX, posY);        printf("REGISTRO ACAD. (RA): %s", regNotas.notaRa);
				gotoxy(posX + 34, posY);   printf("COD. DIS: %d", regNotas.notaDisCod);
				gotoxy(posX + 57, posY++); printf("NOTA: %.2f", regNotas.nota);
				
				clrRodape();
				gotoxy(50, 29); printf("EXCLUIR ? (S/N)");				
				if(toupper(getch()) == 'S')
				{
					regNotas.status = 0;
					fseek(ptrNota, pos, SEEK_SET);
					fwrite(&regNotas, sizeof(tpNotas), 1, ptrNota);
					
					clrRodape();
					gotoxy(54, 29); printf("REGISTRO DELETADO, OK!");
					Sleep(1500);
					clrRodape();
					clearkeybuf();
				}
				clrRodape();
			}
			else{
				clrRodape();
				gotoxy(53, 29); printf("NAO ENCONTRADO!");
				Sleep(1500);
				clrRodape();
				clearkeybuf();
			}	
		}
		
	}
	fclose(ptrNota);
}

void excFisicaNotas(char nomeArq[])
{
	
	tpNotas regNotas;
	
	FILE *ptrNota = fopen(nomeArq, "rb");
	FILE *ptrTemp = fopen("temp.dat", "wb");
	
	clrRodape();
	gotoxy(54, 29); printf("EXCLUSAO ARQUIVO: %s...", nomeArq);
	Sleep(1500);
	clrRodape();
				
	fread(&regNotas, sizeof(tpNotas), 1, ptrNota);
	
	while(!feof(ptrNota))
	{
		if(regNotas.status == 1)
			fwrite(&regNotas, sizeof(tpNotas), 1, ptrTemp);
			
		fread(&regNotas, sizeof(tpNotas), 1, ptrNota);
	}
	fclose(ptrNota);
	fclose(ptrTemp);
	
	remove(nomeArq);
	rename("temp.dat", nomeArq);
	
	gotoxy(54, 29); printf("FEITO!");
	Sleep(1000);
	clrRodape();
	clearkeybuf();
	
}

void excFisDisciplina(char nomeArq[])
{
	// FUNCAO COMPLETA
	tpDis regDis;
	int pos, posY = 6, posX = 4, codAux;   
	
	FILE *ptrDis = fopen(nomeArq, "rb");
	
	clrTittle();
	gotoxy(54, 3); printf("EXCLUIR DADOS DE DISCIPLINAS");
	gotoxy(48, 4); printf("(BUSCA BINARIA POR CODIGO ORDENADO)");
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY); printf("CODIGO: ");
	scanf("%d", &codAux);
	
	if(codAux > 0) 
	{
		//Busca...
		pos = buscaBinariaDis(ptrDis, codAux);
		posY++;
		
		if (pos > -1) 
		{
			
			fseek(ptrDis, pos, 0);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
			
			gotoxy(posX, posY);        printf("CODIGO: %d", regDis.disCod);
			gotoxy(posX + 30, posY++); printf("DISCIPLINA: %s", regDis.disNome);
			
			clrRodape();
			gotoxy(50, 29); printf("EXCLUIR ? (S/N)");
			
			if(toupper(getch()) == 'S') {
				
				clrRodape();
				FILE *ptrTemp = fopen("temp.dat", "wb");
				
				rewind(ptrDis); 
				//or 
				//fseek(ptrAluno, 0, 0);
				
				fread(&regDis, sizeof(tpDis), 1, ptrDis);
				
				while(!feof(ptrDis)) 
				{
					if(regDis.disCod != codAux)
						fwrite(&regDis, sizeof(tpDis), 1, ptrTemp);
						
					fread(&regDis, sizeof(tpDis), 1, ptrDis);
				}
				fclose(ptrDis);
				fclose(ptrTemp);
				
				remove(nomeArq);
				rename("temp.dat", nomeArq);
				
				clrRodape();
				gotoxy(54, 29); printf("REGISTRO DELETADO, OK!");
				Sleep(1500);
				clearkeybuf();
				clrRodape();
			}
			else{
				clrRodape();
				fclose(ptrDis);
			}
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("NAO ENCONTRADO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
	}
	else
		fclose(ptrDis);
}

void altDis(char nomeArq[]) 
{
	// FUNCAO COMPLETA
	tpDis regDis;
	int pos, posY = 6, posX = 4;   
	
	FILE *ptrDis = fopen(nomeArq, "rb+");
	
	clrTittle();
	gotoxy(54, 3); printf("ALTERAR DADOS DE DISCIPLINAS");
	gotoxy(48, 4); printf("(Busca binaria por codigo)");
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY); printf("CODIGO: ");
	scanf("%d", &regDis.disCod);
	
	while(regDis.disCod > 0) 
	{
		//Busca...
		pos = buscaBinariaDis(ptrDis, regDis.disCod);
		posY++;
		
		if(!(posY < 26))
		{
			clrCorpo();
			posY = 6;
		}
		
		if (pos > -1) {
			
			fseek(ptrDis, pos, 0);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
			
			gotoxy(posX, posY); printf("CODIGO: %d", regDis.disCod);
			gotoxy(posX + 20, posY++); printf("DISCIPLINA: %s", regDis.disNome);
			
			clrRodape();
			gotoxy(50, 29); printf("ALTERAR ? (S/N)");
			
			if(toupper(getch()) == 'S') {
				
				clrRodape();
				
				textbackground(COR_FUNDO_CORPO);
				textcolor(COR_DIS);
				gotoxy(posX, posY); printf("NOVO NOME: ");
				fflush(stdin);
				gets(regDis.disNome);
				
				fseek(ptrDis, pos, 0);
				fwrite(&regDis, sizeof(tpDis), 1, ptrDis);
				
				clrRodape();
				gotoxy(54, 29); printf("ALTERADO!");
				Sleep(1500);
				clearkeybuf();
				clrRodape();
				
				posY++;
			}
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTROS!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_DIS);
		gotoxy(posX, posY); printf("CODIGO: ");
		scanf("%d", &regDis.disCod);
	}
	fclose(ptrDis);
}

void altNotas(char nomeArq[])
{
	//PRONTO
	tpNotas regNotas;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrNota = fopen(nomeArq, "rb+");
	
	clrTittle();
	gotoxy(54, 3); printf("ALTERAR NOTAS - TERMINAR");
	gotoxy(48, 4); printf("(BUSCA EXAUSTIVA)");
	
	
	clrCorpo();
	textcolor(COR_NOTA);
	gotoxy(posX, posY++); printf("R.A.: ");
	fflush(stdin);
	gets(regNotas.notaRa);
	
	while(stricmp(regNotas.notaRa, "\0"))
	{
		gotoxy(posX, posY++); printf("CODIGO DISCIPLINA: ");
		scanf("%d", &regNotas.notaDisCod);
		
		if(!(posY < 26))
		{
			clrCorpo();
			posY = 6;
		}
		
		if(regNotas.notaDisCod > 0)
		{
			pos = buscaExaustivaNotas(ptrNota, regNotas.notaRa, regNotas.notaDisCod);
			
			if(pos > -1)
			{
				
				fseek(ptrNota, pos, SEEK_SET);
				fread(&regNotas, sizeof(tpNotas), 1, ptrNota);
				
				gotoxy(posX, posY); 	 printf("REGISTRO ACAD. (RA): %s", regNotas.notaRa);
				gotoxy(posX + 33, posY); printf("COD. DIS.: %d", regNotas.notaDisCod);
				gotoxy(posX + 55, posY++); printf("NOTA: %.2f", regNotas.nota);
				
				clrRodape();
				gotoxy(50, 29); printf("ALTERAR ? (S/N)");
				
				if(toupper(getch()) == 'S') {
					clrRodape();
					
					textbackground(COR_FUNDO_CORPO);
					textcolor(COR_DIS);
					
					gotoxy(posX, posY); printf("NOTA: ");
					scanf("%f", &regNotas.nota);
					
					
					fseek(ptrNota, pos, 0);
					fwrite(&regNotas, sizeof(tpNotas), 1, ptrNota);
					
					clrRodape();
					gotoxy(54, 29); printf("ALTERADO!");
					Sleep(1500);
					clrRodape();
					clearkeybuf();
					
					posY++;
				}
				clrRodape();
			}
			else{
				
				clrRodape();
				gotoxy(53, 29); printf("SEM REGISTROS!");
				Sleep(1500);
				clrRodape();
				clearkeybuf();
			}	
		}
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_NOTA);
		gotoxy(posX, posY++); printf("R.A.: ");
		fflush(stdin);
		gets(regNotas.notaRa);
	}
	fclose(ptrNota);
}

void altAlunos(char nomeArq[]) {
	
	//FUNCAO PRONTRA
	tpAluno regAlu;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrAluno = fopen(nomeArq, "rb+");
	
	clrTittle();
	gotoxy(54, 3); printf("ALTERAR DADOS DE ALUNOS");
	gotoxy(48, 4); printf("(BUSCA EXAUSTIVA)");
	
	clrCorpo();
	textcolor(COR_ALUNO);
	gotoxy(posX, posY); printf("R.A: ");
	fflush(stdin);
	gets(regAlu.aluRa);
	
	while(stricmp(regAlu.aluRa, "\0") != 0) {
		
		//Busca...
		pos = buscaAluno(ptrAluno, regAlu.aluRa);
		posY++;
		
		if(!(posY < 26))
		{
			clrCorpo();
			posY = 6;
		}
		
		if (pos > -1) {
			
			fseek(ptrAluno, pos, 0);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			
			gotoxy(posX, posY); printf("REGISTRO ACAD. (RA): %s", regAlu.aluRa);
			gotoxy(posX + 30, posY++); printf("NOME: %s", regAlu.aluNome);
			
			clrRodape();
			gotoxy(50, 29); printf("ALTERAR ? (S/N)");
			
			if(toupper(getch()) == 'S') 
			{
				clrRodape();
				textbackground(COR_FUNDO_CORPO);
				textcolor(COR_ALUNO);
				gotoxy(posX, posY); printf("NOVO NOME: ");
				fflush(stdin);
				gets(regAlu.aluNome);
				
				fseek(ptrAluno, pos, 0);
				fwrite(&regAlu, sizeof(tpAluno), 1, ptrAluno);
				
				clrRodape();
				gotoxy(54, 29); printf("ALTERADO!");
				Sleep(1500);
				clearkeybuf();
				clrRodape();
				
				posY++;
			}
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTROS!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
			
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_ALUNO);
		gotoxy(posX, posY); printf("R.A: ");
		fflush(stdin);
		gets(regAlu.aluRa);
	}
	fclose(ptrAluno);
}

void criaArquivos(void) {
	
	FILE *ptrArquivo = fopen("Alunos.dat","ab");
	fclose(ptrArquivo);
	
	ptrArquivo = fopen("Disciplinas.dat","ab");
	fclose(ptrArquivo);
	
 	ptrArquivo = fopen("Notas.dat","ab");
	fclose(ptrArquivo);
}

void consAlunosNome(char nomeArq[]) {
	//FUNCAO PRONTRA
	tpAluno regAlu;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrAluno = fopen(nomeArq, "rb");
	
	clrTittle();
	gotoxy(54, 3); printf("CONSULTAR ALUNOS PELO NOME");
	gotoxy(48, 4); printf("(BUSCA BINARIA POR NOME ORDENADO)");
	
	
	clrCorpo();
	textcolor(COR_ALUNO);
	gotoxy(posX, posY); printf("NOME: ");
	fflush(stdin);
	gets(regAlu.aluNome);
	
	while(stricmp(regAlu.aluNome, "\0") != 0) {
		
		//Busca...
		pos = buscaBinariaAluno(ptrAluno, regAlu.aluNome);
		posY++;
		
		if(!(posY < 27)){
			clrCorpo();
			posY = 6;
		}
		
		if (pos > -1){
			//printf("RA de aluno existente\n");
			fseek(ptrAluno, pos, 0);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			
			gotoxy(posX, posY); printf("REGISTRO ACAD. (RA): %s", regAlu.aluRa);
			gotoxy(posX + 35, posY++); printf("NOME: %s", regAlu.aluNome);
			
			clrRodape();
			gotoxy(54, 29); printf("ENCONTRADO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTRO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_ALUNO);
		gotoxy(posX, posY); printf("NOME: ");
		fflush(stdin);
		gets(regAlu.aluNome);
	}
	fclose(ptrAluno);
}

void consDisCod(char nomeArq[]) {
	//FUNCAO PRONTA
	tpDis regDis;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrDis = fopen(nomeArq, "rb");
	
	clrTittle();
	gotoxy(54, 3); printf("CONSULTA DISCIPLINA CODIGO");
	gotoxy(48, 4); printf("(BUSCA BINARIA POR CODIGO ORDENADO)");
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY); printf("CODIGO: ");
	scanf("%d", &regDis.disCod);
	
	while(regDis.disCod > 0) {
		
		//Busca...
		pos = buscaBinariaDis(ptrDis, regDis.disCod);
		posY++;
		
		if(!(posY < 28)){
			clrCorpo();
			posY = 6;
		}
		
		if (pos > -1){
			
			fseek(ptrDis, pos, 0);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
			
			gotoxy(posX, posY);        printf("CODIGO: %d", regDis.disCod);
			gotoxy(posX + 21, posY++); printf("DISCIPLINA: %s", regDis.disNome);
			
			clrRodape();
			gotoxy(54, 29); printf("ENCONTRADO!");
			Sleep(1500);
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTRO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_DIS);	
		
		gotoxy(posX, posY); printf("CODIGO: ");
		scanf("%d", &regDis.disCod);
	}
	fclose(ptrDis);
}
void removerSentinela(char nomeArq[])
{
	remove(nomeArq);
	rename("temp.dat", nomeArq);
}

void consNotas(char nomeArq[])
{
	tpNotas regNotas;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrNota = fopen(nomeArq, "rb");
	
	clrTittle();
	gotoxy(54, 3); printf("CONSULTAR NOTAS - VERIFICAR LIMITE");
	gotoxy(48, 4); printf("(BUSCA EXAUSTIVA)");
	
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY++); printf("R.A.: ");
	fflush(stdin);
	gets(regNotas.notaRa);
	
	while(stricmp(regNotas.notaRa, "\0"))
	{
		if(!(posY < 27)){
			clrCorpo();
			posY = 6;
		}
		
		gotoxy(posX, posY++); printf("COD. DIS.: ");
		scanf("%d", &regNotas.notaDisCod);
		
		if(regNotas.notaDisCod > 0)
		{
			pos = buscaExaustivaNotas(ptrNota, regNotas.notaRa, regNotas.notaDisCod);
		
			if(pos > -1)
			{
				
				fseek(ptrNota, pos, SEEK_SET);
				fread(&regNotas, sizeof(tpNotas), 1, ptrNota);
				
				gotoxy(posX, posY);        printf("REGISTRO ACAD. (RA): %s", regNotas.notaRa);
				gotoxy(posX + 34, posY);   printf("COD. DIS: %d", regNotas.notaDisCod);
				gotoxy(posX + 57, posY++); printf("NOTA: %.2f", regNotas.nota);
				
				clrRodape();
				gotoxy(54, 29); printf("ENCONTRADO!");
				Sleep(1500);
				clearkeybuf();
				clrRodape();
			}
			else{
				
				clrRodape();
				gotoxy(54, 29); printf("SEM REGISTRO!");
				Sleep(1500);
				clrRodape();
				clearkeybuf();
			}	
		}
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_ALUNO);
		gotoxy(posX, posY++); printf("R.A.: ");
		fflush(stdin);
		gets(regNotas.notaRa);
	}
	fclose(ptrNota);
}

void consDisNome(char nomeArq[])
{
	//FUNCAO COMPLETA
	tpDis regDis;
	int pos, posY = 6, posX = 4;
	
	clrTittle();
	gotoxy(54, 3); printf("CONSULTA DISCIPLINA NOME");
	gotoxy(48, 4); printf("(BUSCA SENTINELA)");
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY); printf("DISCIPLINA: ");
	fflush(stdin);
	gets(regDis.disNome);
	
	while(stricmp(regDis.disNome, "\0") != 0)
	{
		// Busca Sentinela
		FILE *ptrDis = fopen(nomeArq, "ab+");
		
		pos = buscaSentinelaDisNome(ptrDis, regDis.disNome);
		posY++;
		
		if(!(posY < 27)){
			clrCorpo();
			posY = 6;
		}
		
		if(pos > -1)
		{
			fseek(ptrDis, pos, SEEK_SET);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
			
			gotoxy(posX, posY); printf("CODIGO: %d", regDis.disCod);
			gotoxy(posX + 20, posY++); printf("DISCIPLINA: %s", regDis.disNome);
			
			clrRodape();
			gotoxy(54, 29); printf("ENCONTRADO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTRO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		fclose(ptrDis);
		
		removerSentinela(nomeArq);
		
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_DIS);
		gotoxy(posX, posY); printf("DISCIPLINA: ");
		fflush(stdin);
		gets(regDis.disNome);
	}
}

void consAlunosRa(char nomeArq[]) {
	// FUNCAO PRONTA
	tpAluno regAlu;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrAluno = fopen(nomeArq, "rb");
	
	clrTittle();
	gotoxy(54, 3); printf("CONSULTAR ALUNOS PELO R.A.");
	gotoxy(48, 4); printf("BUSCA EXAUSTIVA");
	
	clrCorpo();
	textcolor(COR_ALUNO);
	gotoxy(posX, posY); printf("R.A: ");
	fflush(stdin);
	gets(regAlu.aluRa);
	
	while(stricmp(regAlu.aluRa, "\0") != 0) {
		
		//Busca...
		pos = buscaAluno(ptrAluno, regAlu.aluRa);
		posY++;
		
		if(!(posY < 28))
		{
			clrCorpo();
			posY = 6;
		}
		if (pos > -1){
			
			fseek(ptrAluno, pos, 0);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			gotoxy(posX, posY); printf("REGISTRO ACAD. (RA): %s", regAlu.aluRa);
			gotoxy(posX + 30, posY); printf("NOME: %s", regAlu.aluNome);
			clrRodape();
			gotoxy(54, 29); printf("ENCONTRADO!");
			Sleep(1500);
			clrRodape();
			posY++;
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTROS!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
			 
		}
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_ALUNO);
		gotoxy(posX, posY); printf("R.A: ");
		fflush(stdin);
		gets(regAlu.aluRa);
	}
	fclose(ptrAluno);
}

int buscaAluno(FILE *ptrAluno, char ra[]) {
	
	// Busca Exaustiva
	tpAluno r;
	
	rewind(ptrAluno);
	
	fread(&r, sizeof(tpAluno), 1, ptrAluno);
	
	while(!feof(ptrAluno) && stricmp(r.aluRa, ra))
		fread(&r, sizeof(tpAluno), 1, ptrAluno);
		
	if(feof(ptrAluno))
		return -1;
	// fteel, posicaoo atual do ponteiro
	return ftell(ptrAluno) - sizeof(tpAluno);
}
int buscaExaustivaNotas(FILE *ptrNota, char ra[], int codAux)
{	
	//printf("\nStep1");
	tpNotas regNota;
	//printf("\nStep2");
	rewind(ptrNota);
	//printf("\nStep3");
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	//printf("\nStep4");
	//if(feof(ptrNota))
	//	printf("\nFim");
	
	while(!feof(ptrNota) && (stricmp(ra, regNota.notaRa) != 0 || codAux != regNota.notaDisCod || regNota.status == 0))
		fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		
	/*printf("\nStep5");
	if(feof(ptrNota))
		printf("\nNao encotrou primeiro reg");
	else
		printf("\nEncontrou Primeiro reg");
	getch();*/
	
	if(feof(ptrNota))
		return -1;
	return ftell(ptrNota) - sizeof(tpNotas);
}

void relAlunos(char nomeArq[]) {
	
	tpAluno regAlu;
	
	// Abrindo somente leitura, nao permitindo edicao, o arquivo precisa existir 
	FILE *ptrAluno = fopen(nomeArq, "rb");
	int pos, posY = 6, posX = 4;
	
	fseek(ptrAluno, 0, SEEK_END);
	int regSize = ftell(ptrAluno) / sizeof(tpAluno);
	fseek(ptrAluno, 0, SEEK_SET);
	
	fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
	if(feof(ptrAluno))
	{
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(1500);
		clearkeybuf();
		clrRodape();
		
	}else{
		
		if(regSize > 22)
		{	
			clrscr();
			desenharLayout(30 + (regSize - 22));
		}
		
		clrTittle();
		gotoxy(54, 3); printf("RELATORIO DE ALUNOS");
		gotoxy(48, 4); printf("BUSCA EXAUSTIVA");	
		
		clrCorpo();
		textcolor(COR_ALUNO);
		while(!feof(ptrAluno)) 
		{
			gotoxy(posX, posY);        printf("REGISTRO ACAD. (RA): %s", regAlu.aluRa);
			gotoxy(posX + 36, posY);   printf("NOME: %s", regAlu.aluNome);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			posY++;
		}
		
		if(regSize > 22){
			
			posY = 29 + (regSize - 22);
			
			clrRodape(posY);
			gotoxy(53, posY); printf("PRONTO!");
			Sleep(1500);
			clrRodape(posY);
			clearkeybuf();
		}
		else{
			
			clrRodape();
			gotoxy(53, 29); printf("PRONTO!");
			Sleep(1500);
			clrRodape();
			clearkeybuf();
		}
		getch();
		
		if(regSize > 22){
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
	}
	fclose(ptrAluno);
}

void relNotas(char nomeArq[])
{
	tpNotas regNota;
	
	FILE *ptrNota = fopen(nomeArq, "rb");
	int pos, posY = 6, posX = 4;
	
	
	fseek(ptrNota, 0, SEEK_END);
	int regSize = ftell(ptrNota) / sizeof(tpNotas);
	fseek(ptrNota, 0, SEEK_SET);
	
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	if(feof(ptrNota)){
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(1500);
		clrRodape();
		clearkeybuf();
	}
	else{
		
		if(regSize > 22)
		{	
			clrscr();
			desenharLayout(30 + (regSize - 22));
		}
		
		clrTittle();
		gotoxy(54, 3); printf("RELATORIO DE NOTAS");
		gotoxy(48, 4); printf("(METODO EXAUSTIVA)");
		
		clrCorpo();
		textcolor(COR_NOTA);
		
		while(!feof(ptrNota))
		{
			if(regNota.status != 0)
			{
				gotoxy(posX, posY);      printf("REGISTRO ACAD. (RA): %s", regNota.notaRa);
				gotoxy(posX + 32, posY); printf("COD. DIS: %d", regNota.notaDisCod);
				gotoxy(posX + 55, posY); printf("NOTA: %.2f", regNota.nota);
				posY++;
			}
			fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		}
		
		clrRodape();
		gotoxy(53, 29); printf("PRONTO!");
		Sleep(1500);
		clrRodape();
		clearkeybuf();
		getch();
		
		if(regSize > 22){
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
	}
	fclose(ptrNota);
}

void relDis(char nomeArq[])
{
	//FUNCAO COMPLETA
	tpDis regDis;
	
	FILE *ptrDis = fopen(nomeArq, "rb");
	int pos, posY = 6, posX = 4;
	
	fseek(ptrDis, 0, SEEK_END);
	int regSize = ftell(ptrDis) / sizeof(tpDis);
	fseek(ptrDis, 0, SEEK_SET);
	
	
	fread(&regDis, sizeof(tpDis), 1, ptrDis);
	
	if(feof(ptrDis))
	{
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(1500);
		clearkeybuf();
		clrRodape();
	}
	else
	{
		if(regSize > 22)
		{	
			system("cls");
			desenharLayout(30 + (regSize - 22));
		}
		
		clrTittle();
		gotoxy(54, 3); printf("RELATORIO DE DISCIPLINAS %d", regSize);
		gotoxy(48, 4); printf("BUSCA EXAUSTIVA");
		
		clrCorpo();
		textcolor(COR_DIS);
		
		while(!feof(ptrDis)){
			
			gotoxy(posX, posY);      printf("CODIGO: %d", regDis.disCod);
			gotoxy(posX + 21, posY); printf("DISCIPLINA: %s", regDis.disNome);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
			posY++;
		}
		clearkeybuf();
		getch();
		
		if(regSize > 22){
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
	}
	fclose(ptrDis);
}

void cadastroDisciplina(char nomeArq[])
{
	//FUNCAO COMPLETA
	tpDis regDis;
	int pos, posY = 6, posX = 4; 
	
	FILE *ptrDis = fopen(nomeArq, "rb+");
	
	clrTittle();
	gotoxy(54, 3); printf("INSERIR DISCIPLINAS");
	gotoxy(48, 4); printf("(INSERCAO DIRETA CODIGO)");
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY); printf("CODIGO: ");
	scanf("%d", &regDis.disCod);
	
	while(regDis.disCod > 0)
	{
		pos = buscaBinariaDis(ptrDis, regDis.disCod);
		
		if(pos > -1){
			clrRodape();
			gotoxy(54, 29); printf("DISCIPLINA EXISTENTE!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		else{
			
			gotoxy(posX + 30, posY); printf("NOME DISCIPLINA: ");
			fflush(stdin);
			gets(regDis.disNome);
			
			fseek(ptrDis, 0, SEEK_END);
			fwrite(&regDis, sizeof(tpDis), 1, ptrDis);
			
			insercaoDireta(ptrDis);
			
			clrRodape();
			gotoxy(53, 29); printf("REGISTRO SALVO!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		posY++;
		
		if(!(posY < 28))
		{
			clrCorpo();
			posY = 6;
		}
		
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_DIS);
		gotoxy(posX, posY); printf("CODIGO: ");
		scanf("%d",&regDis.disCod);
		
	}
	fclose(ptrDis);
}

void cadastroNotas(char arqNota[], char arqDis[], char arqAlu[])
{
	// CONTINUAR
	tpNotas regNotas;
	
	int pos, posY = 6, posX = 4;
	
	FILE *ptrNota = fopen(arqNota, "rb+");
	FILE *ptrDis = fopen(arqDis, "rb");
	FILE *ptrAluno = fopen(arqAlu, "rb");
	
	clrTittle();	
	gotoxy(54, 3); printf("INSERIR NOTAS - (INCOMPLETO)");
	gotoxy(30, 4); printf("(INSERCAO DIRETA POR RA - BUSCAS: EXAUSTIVA RA; BINARIA DIS; EXAUSTIVA NOTAS)");
	
	clrCorpo();
	textcolor(COR_NOTA);
	gotoxy(posX, posY++); printf("R.A.: ");
	fflush(stdin);
	gets(regNotas.notaRa);
	
	while(stricmp(regNotas.notaRa, "\0") != 0) 
	{
		//Busca Exaustiva...
		pos = buscaAluno(ptrAluno, regNotas.notaRa);
		
		if(pos > -1) 
		{
			// Ra encontrado no arquivo alunos...
			gotoxy(posX, posY); printf("CODIGO DIS.: ");
			scanf("%d", &regNotas.notaDisCod);
			
			while(regNotas.notaDisCod > 0)
			{
				pos = buscaBinariaDis(ptrDis, regNotas.notaDisCod);
				
				if(pos > -1)
				{
					//Busca Exaustiva...
					pos = buscaExaustivaNotas(ptrNota, regNotas.notaRa, regNotas.notaDisCod);
					
					if(pos > -1)
					{
						regNotas.notaDisCod = 0;
						clrRodape();
						gotoxy(53, 29); printf("NOTA JA REGISTRADA!");
						Sleep(1500);
						clrRodape();
						clearkeybuf();
						
					}
					else{
						
						clrRodape();
						gotoxy(54, 29); printf("ENCONTRADO, OK!");
						Sleep(700);
						clrRodape();
						clearkeybuf();
						
						textbackground(COR_FUNDO_CORPO);
						gotoxy(posX + 25, posY); textcolor(COR_NOTA);
						printf("NOTA: ");
						scanf("%f",&regNotas.nota);
						regNotas.status = 1;
						
						fseek(ptrNota, 0, SEEK_END);
						fwrite(&regNotas, sizeof(tpNotas), 1, ptrNota);
						
						insercaoDiretaNotas(ptrNota);
						
						clrRodape();
						gotoxy(53, 29); printf("REGISTRADO, OK!");
						Sleep(1000);
						clrRodape();
						clearkeybuf();
					}
				}
				else{
					clrRodape();
					gotoxy(53, 29); printf("DISCIPLINA NAO ENCONTRADA!");
					Sleep(1500);
					clrRodape();
					clearkeybuf();
				}
				
				if(regNotas.notaDisCod > 0){
					
					textbackground(COR_FUNDO_CORPO);
					textcolor(COR_NOTA);
					gotoxy(posX, posY); printf("CODIGO DIS.: ");
					scanf("%d", &regNotas.notaDisCod);		
				}
			}
		}
		else{ 
			clrRodape();
			gotoxy(53, 29); printf("RA NAO ENCONTRADO!");
			Sleep(1500);
			clrRodape();
			clearkeybuf();
		}
		
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_NOTA);
		gotoxy(posX, posY++); printf("R.A.: ");
		fflush(stdin);
		gets(regNotas.notaRa);
	}
	fclose(ptrDis);
	fclose(ptrNota);
	fclose(ptrAluno);
}

void cadastroAlunos(char nomeArq[]) {
	
	tpAluno regAlu;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrAluno = fopen(nomeArq, "ab+");
	
	//clrscr();
	clrTittle();
	gotoxy(54, 3); printf("INSERIR ALUNO");
	gotoxy(48, 4); printf("(INSERCAO SEM ORDENACAO)");
	
	
	clrCorpo();
	textcolor(COR_ALUNO);
	gotoxy(posX, posY); printf("R.A: ");
	fflush(stdin);
	gets(regAlu.aluRa);
	
	while(stricmp(regAlu.aluRa, "\0") != 0) {
		
		//Busca...
		pos = buscaAluno(ptrAluno, regAlu.aluRa);
		
		if (pos > -1){
			posY++;
			clrRodape();
			gotoxy(40, 29); printf("RA JA CADASTRADO, CADASTRO NAO EFETUADO!");
			Sleep(1500);
			clrRodape();
		}
		else{
			gotoxy(posX + 18, posY++); printf("Nome: ");
			fflush(stdin);
			gets(regAlu.aluNome);
			fwrite(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			
			clrRodape();
			gotoxy(54, 29); printf("CADASTRO OK!");
			Sleep(1500);
			clearkeybuf();
			clrRodape();
		}
		
		if(!(posY < 28))
		{
			clrCorpo();
			posY = 6;
		}
		
		textbackground(COR_FUNDO_CORPO);
		textcolor(COR_ALUNO);
		gotoxy(4, posY); printf("R.A: ");
		fflush(stdin);
		gets(regAlu.aluRa);
	}
	clrCorpo();
	fclose(ptrAluno);
}

char menu(void) 
{
	clrTittle();
	/*textbackground(COR_FUNDO_TITULO);
	textcolor(COR_TITULO);*/
	gotoxy(43, 3); printf("CADASTRO ALUNOS DISCIPLINAS E NOTAS");
	gotoxy(35, 4);  printf("Encoded by: Victor Taveira - github.com/taveiradev");
	
	short int posY = 9, posX = 20;
	
	// CLEAR  CORPO
	/*textbackground(COR_FUNDO_CORPO);
	textcolor(COR_ALUNO);*/
	clrCorpo();
	textcolor(COR_ALUNO);
	gotoxy(28, 7);        printf("ALUNOS");
	gotoxy(posX, posY++); printf("[A] INSERIR");
	gotoxy(posX, posY++); printf("[B] RELATORIO");
	gotoxy(posX, posY++); printf("[C] CONSULTA (RA)");
	gotoxy(posX, posY++); printf("[D] ALTERAR DADOS");
	gotoxy(posX, posY++); printf("[E] EXCLUIR DADOS");
	gotoxy(posX, posY++); printf("[F] ORDENAR POR NOME");
	gotoxy(posX, posY++); printf("[G] CONSULTAR POR NOME");
	
	posY++;
	textcolor(COR_DIS);
	gotoxy(26, posY++); printf("DISCIPLINA");
	posY++;
	gotoxy(posX, posY++); printf("[H] INSERIR (CODIGO)");   
	gotoxy(posX, posY++); printf("[I] RELATORIO");
	gotoxy(posX, posY++); printf("[J] CONSULTA (CODIGO)");
	gotoxy(posX, posY++); printf("[K] ALTERAR DADOS");
	gotoxy(posX, posY++); printf("[L] EXCLUIR DADOS");
	gotoxy(posX, posY++); printf("[M] CONSULTA (NOME)");
	
	textcolor(COR_NOTA);
	posY = 7;
	gotoxy(87, posY++);   printf("NOTA");
	posX = 76;
	posY++;
	gotoxy(posX, posY++); printf("[N] INSERIR");
	gotoxy(posX, posY++); printf("[O] RELATORIO");
	gotoxy(posX, posY++); printf("[P] CONSULTA");
	gotoxy(posX, posY++); printf("[Q] ALTERAR DADOS");
	gotoxy(posX, posY++); printf("[R] EXCLUIR DADOS");
	gotoxy(posX, posY++); printf("[X] EXCLUSAO FISICA (NOTAS)");
	
	textcolor(COR_REL);
	posY += 2;
	gotoxy(84, posY++); printf("RELATORIOS");
	posX = 76;
	posY++;
	gotoxy(posX, posY++); printf("[S] ALUNOS REPROVADOS");
	gotoxy(posX, posY++); printf("[T] LISTAR POR INICIAL");
	gotoxy(posX, posY++); printf("[U] DIS. C. MEDIA MENOR QUE 6.0");
	gotoxy(posX, posY++); printf("[V] GERAL: ALUNOS E DISCIPLINAS");
	gotoxy(posX, posY++); printf("[W] GERAL ORD: DISCIP. E ALUNOS");
	gotoxy(posX, posY++); printf("[ESC] SAIR");
	gotoxy(120, 30);
	textbackground(BLACK);
	
	
	return toupper(getch());
}


