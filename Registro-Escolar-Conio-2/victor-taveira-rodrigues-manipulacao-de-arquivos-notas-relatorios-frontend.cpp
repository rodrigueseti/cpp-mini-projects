#include <stdio.h> // Input Output
#include <ctype.h> // toupper();
//#include <conio.h>
#include <conio2.h> // clrscr(), textcolor(), getche();
#include <string.h> // stricmp();
#include <windows.h> // Sleep();, system("cls");

#define COR_TITULO		   BLACK
#define COR_FUNDO_TITULO   LIGHTGRAY 
#define COR_MOLDURA_TITULO RED		

#define COR_FUNDO_CORPO    WHITE     
#define COR_MOLDURA_CORPO  RED       

#define COR_TEXTO_RODAPE   BLACK
#define COR_FUNDO_RODAPE   LIGHTGRAY

#define COR_ALUNO 		   BLUE
#define COR_DIS			   BLUE
#define COR_NOTA           BLUE
#define COR_REL            BLUE

#define CKB_SWITCH 1
#define MSG_TIME   1500

struct tpAluno {
	
	char aluRa[13], aluNome[40];
	int qtdeReg; //Quantidade de vezes que um aluno foi registrado em Notas
};

struct tpDis {
	
	int disCod;
	char disNome[40];
	int qtdeReg; //Quantidade de vezes que notas de Disciplinas foram registrados em Notas
	float somaNotas; //Soma de todas as Notas Registradas em uma Disciplina ao todo
};

struct tpNotas {
	
	char notaRa[13];
	int notaDisCod;
	float nota;
	int status;
};

struct tpRel {
	
	int qtdeDis; // QUANTIDADE DE DISCIPLINAS COM ALUNOS COM NOTAS CADASTRADAS
	int qtdeAlu; //Quantidade de Alunos registrados em Notas
	int somaQtdeRegNotas; // QUANTIDADE TOTAL DE NOTAS CADASTRADAS
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
void clearkeybuf (void);

void criaArquivos(void);

void cadastroAlunos(char nomeArq[]);
void cadastroDisciplina(char nomeArq[]);
void cadastroNotas(char arqNota[], char arqDis[], char arqAlu[], char arqRel[]);

void altAlunos(char nomeArq[]);
void altDis(char nomeArq[]);
void altNotas(char nomeArq[]);

void excFisAlunos(char nomeArq[]);
void excFisDisciplina(char arqDis[], char arqAlu[], char arqNota[], char arqRel[]);
void excFisicaNotas(char nomeArq[]);
void excLogicaNotas(char nomeNota[], char nomeAlu[], char nomeDis[], char nomeRel[]);

void ordenaAlunos(char nomeArq[]);

void consAlunosRa(char nomeArq[]);
void consAlunosNome(char nomeArq[]);
void consDisCod(char nomeArq[]);
void consDisNome(char nomeArq[]);
void consNotas(char nomeArq[]);

void relAlunos(char nomeArq[]);
void relDis(char nomeArq[]);
void relNotas(char nomeArq[], char arqRel[]);

int buscaAluno(FILE *ptrAluno, char ra[]);
int buscaBinariaAluno(FILE *ptrAluno, char ra[]);
int buscaBinariaDis(FILE *ptrDis, int codAux);
int buscaSentinelaDisNome(FILE *ptrDis, char nome[]);
int buscaExaustivaNotas(FILE *ptrNota, char ra[], int codAux);
int buscaExaustivaNotasCod(FILE *ptrNota, int codAux);

void removerSentinela(char nomeArq[]);

void insercaoDireta(FILE *ptrDis);
void insercaoDiretaNotas(FILE *ptrNota);

void alunosReprovados(char nomeAlu[], char nomeDis[], char nomeNota[]);
void listagemPorIncial(char nomeArq[]);
void mediaDisciplinas(char nomeDis[], char nomeNota[]);
void alunoDisciplinas(char nomeAlu[], char nomeDis[], char nomeNota[], char arqRel[]);
void disciplinasAlunos(char nomeAlu[], char nomeDis[], char nomeNota[], char arqRel[]);


int main(){
	
	system("title MANIPULACAO DE ARQUIVOS VICTOR TAVEIRA RODRIGUES - RA: 261911759");
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
				excFisDisciplina("Disciplinas.dat", "Alunos.dat", "Notas.dat", "Relatorios.dat");
				break;
				
			case 'M' :
				consDisNome("Disciplinas.dat");
				break;
				
			case 'N' :
				cadastroNotas("Notas.dat", "Disciplinas.dat", "Alunos.dat", "Relatorios.dat");
				break;
				
			case 'O' :
				relNotas("Notas.dat", "Relatorios.dat");
				break;
				
			case 'P' :
				consNotas("Notas.dat");
				break;
				
			case 'Q' :
				altNotas("Notas.dat");
				break;
				
			case 'R' :
				excLogicaNotas("Notas.dat", "Alunos.dat", "Disciplinas.dat", "Relatorios.dat");
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
				alunoDisciplinas("Alunos.dat", "Disciplinas.dat", "Notas.dat", "Relatorios.dat");
				break;
				
			case 'W' :
				disciplinasAlunos("Alunos.dat", "Disciplinas.dat", "Notas.dat", "Relatorios.dat");
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

void disciplinasAlunos(char nomeAlu[], char nomeDis[], char nomeNota[],  char arqRel[])
{
	//FUNCAO OBRIGATORIAMENTE TERA QUE REALIZAR A EXCLUSAO FISICA DO Arquivo Notas PARA SER CONSIDERADO NO FOEF
	tpAluno regAlu;
	tpDis regDis;
	tpNotas regNota;
	tpRel regRel;
	
	int pos, posY = 6, posX = 4, aux;
	
	FILE *ptrAlu = fopen(nomeAlu, "rb");
	FILE *ptrDis = fopen(nomeDis, "rb");
	FILE *ptrNota = fopen(nomeNota, "rb");
	FILE *ptrRel = fopen(arqRel, "rb");
	
	fread(&regDis, sizeof(tpDis), 1, ptrDis);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	fread(&regRel, sizeof(tpRel), 1, ptrRel);
	
	/*clrCorpo();
	textcolor(COR_REL);
	gotoxy(posX, posY++); printf("qtdeDis: %d", regRel.qtdeDis);
	gotoxy(posX, posY++); printf("qtdeAlu: %d", regRel.qtdeAlu);
	gotoxy(posX, posY++); printf("somaQtdeRegNotas: %d", regRel.somaQtdeRegNotas);
	getch();*/
	
	if(feof(ptrNota)){
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(MSG_TIME);
		clrRodape();
		if(CKB_SWITCH) clearkeybuf();
	}
	else{
		
		aux = 1 + 2  * (regRel.qtdeDis - 1) + regRel.somaQtdeRegNotas;
		
		if(aux > 22){
			
			textbackground(BLACK);
			system("cls");
			desenharLayout(30 + (aux - 22));
		}
		
		clrTittle();
		gotoxy(51, 3); printf("DISCIPLINAS E ALUNOS");
		gotoxy(55, 4); printf("(VARREDURA)");
		
		clrCorpo();
		textcolor(COR_NOTA);
		while(!feof(ptrDis)) 
		{
			
			//Se quiser tratar se o campo tpDis.qtdeReg na verificacao se existe ou nao algum aluno com nota cadastrada na mesma disciplina
			//terei que realizar a exclusao fisica do arquivo de notas assim que encerrar a exclusao logica da mesma!
			
			while(!feof(ptrNota) && (regDis.disCod != regNota.notaDisCod || regNota.status == 0)) //VERIFICACAO PODERA SER ALTERADA
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
			
			if(!feof(ptrNota))
			{
				gotoxy(posX, posY++); printf("DISCIPLINA: %s", regDis.disNome);
				
				fseek(ptrNota, 0, SEEK_SET);
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				
				while(!feof(ptrNota))
				{
					if(regDis.disCod == regNota.notaDisCod && regNota.status == 1){
						
						pos = buscaAluno(ptrAlu, regNota.notaRa);
						
						fseek(ptrAlu, pos, SEEK_SET);
						
						fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
						
						gotoxy(posX, posY++); printf("NOME: %s", regAlu.aluNome);
					}
					fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				}
				posY++;
			}
			fseek(ptrNota, 0, SEEK_SET);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
		}
		if(aux > 22){
			
			posY = 30 + (aux - 23);
			clrRodape(posY);
			gotoxy(57, posY); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape(posY);
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
			
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
		else{
			
			clrRodape();
			gotoxy(57, 29); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
		}
	}
	fclose(ptrAlu);
	fclose(ptrDis);
	fclose(ptrNota);
	fclose(ptrRel);
}

void alunoDisciplinas(char nomeAlu[], char nomeDis[], char nomeNota[], char arqRel[])
{
	//FUNCAO OBRIGATORIAMENTE TERA QUE REALIZAR A EXCLUSAO FISICA DO Arquivo Notas PARA SER CONSIDERADO NO FOEF
	tpAluno regAlu;
	tpDis regDis;
	tpNotas regNota;
	tpRel regRel;
	
	int pos, posY = 6, posX = 4, aux;
	
	FILE *ptrAlu  = fopen(nomeAlu, "rb");
	FILE *ptrDis  = fopen(nomeDis, "rb");
	FILE *ptrNota = fopen(nomeNota, "rb");
	FILE *ptrRel  = fopen(arqRel, "rb");
	
	fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	fread(&regRel, sizeof(tpRel), 1, ptrRel);
	
	/*clrCorpo();
	textcolor(COR_REL);
	gotoxy(posX, posY++); printf("qtdeDis (Dis): %d", regRel.qtdeDis);
	gotoxy(posX, posY++); printf("qtdeAlu: %d", regRel.qtdeAlu);
	gotoxy(posX, posY++); printf("somaQtdeRegNotas: %d", regRel.somaQtdeRegNotas);*/
	
	if(feof(ptrNota)){
		
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(MSG_TIME);
		clrRodape();
		if(CKB_SWITCH) clearkeybuf();
	}
	else{
		
		aux = 1 + 2 * (regRel.qtdeAlu - 1) + regRel.somaQtdeRegNotas;
		
		if(aux > 22){
			
			textbackground(BLACK);
			system("cls");
			desenharLayout(30 + (aux - 22));
		}
		
		clrTittle();
		gotoxy(52, 3); printf("ALUNOS E DISCIPLINAS");
		gotoxy(51, 4); printf("(EXAUSTIVA - BINARIO)");
		
		clrCorpo();
		textcolor(COR_REL);
		while(!feof(ptrAlu)) {
			
			while(!feof(ptrNota) && (stricmp(regAlu.aluRa, regNota.notaRa) || regNota.status == 0))
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
			
			
			
			if(!feof(ptrNota))
			{
				gotoxy(posX, posY++); printf("NOME: %s", regAlu.aluNome);
				
				fseek(ptrNota, 0, SEEK_SET);
				fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				
				while(!feof(ptrNota))
				{
					if(stricmp(regAlu.aluRa, regNota.notaRa) == 0 && regNota.status == 1){
						
						pos = buscaBinariaDis(ptrDis, regNota.notaDisCod);
						
						fseek(ptrDis, pos, SEEK_SET);
						fread(&regDis, sizeof(tpDis), 1, ptrDis);
						
						gotoxy(posX, posY++); printf("DISCIPLINA: %s", regDis.disNome);
					}
					fread(&regNota, sizeof(tpNotas), 1, ptrNota);
				}
				posY++;
			}
			
			fseek(ptrNota, 0, SEEK_SET);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
		}
		
		if(aux > 22){
			
			posY = 30 + (aux - 23);
			clrRodape(posY);
			gotoxy(57, posY); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape(posY);
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
			
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
		else{
			
			clrRodape();
			gotoxy(57, 29); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
		}
	}
	fclose(ptrAlu);
	fclose(ptrDis);
	fclose(ptrNota);
	fclose(ptrRel);
}

void mediaDisciplinas(char nomeDis[], char nomeNota[])
{
	tpDis regDis;
	tpNotas regNota;
	float media;
	int pos, posY = 6, posX = 4, largura = 0;
	
	FILE *ptrDis = fopen(nomeDis, "rb");
	FILE *ptrNota = fopen(nomeNota, "rb");
	
	fread(&regDis, sizeof(tpDis), 1, ptrDis);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	if(feof(ptrDis) || feof(ptrNota)){
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(MSG_TIME);
		clrRodape();
		if(CKB_SWITCH) clearkeybuf();
	}else{
		
		while(!feof(ptrDis)){
			
			if(regDis.somaNotas / (float)regDis.qtdeReg < 6.0)
				largura++;
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
		}
			
		if(largura > 22){
			
			textbackground(BLACK);
			system("cls");
			desenharLayout(30 + (largura - 22));
		}
		
		clrTittle();
		gotoxy(47, 3); printf("DISCIPLINAS COM MEDIA [<6]");
		gotoxy(51, 4); printf("(BUSCA EXAUSTIVA)");
		
		
		clrCorpo();
		textcolor(COR_REL);
		
		fseek(ptrDis, 0, SEEK_SET);
		fread(&regDis, sizeof(tpDis), 1, ptrDis);
		
		while(!feof(ptrDis))
		{
			media = regDis.somaNotas / (float)regDis.qtdeReg;
			if(media < 6.0){
				gotoxy(posX, posY);      printf("COD.: %d", regDis.disCod);
				gotoxy(posX + 20, posY); printf("DIS.: %s", regDis.disNome);	
				gotoxy(posX + 40, posY++); printf("MEDIA GERAL: %.2f", media);
			}
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
		}
		
		if(largura > 22){
			
			//MODULARIZAR ESSAS SEQUENCIAS
			posY = 30 + (largura - 23);
			clrRodape(posY);
			gotoxy(57, posY); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape(posY);
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
			
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
		else{
			
			clrRodape();
			gotoxy(57, 29); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
		}
	}
	fclose(ptrDis);
	fclose(ptrNota);	
}



void listagemPorIncial(char nomeArq[])
{
	//F Completo
	tpAluno regAlu;
	int cont = 0, posY = 6, posX = 4;
	char c;
	
	FILE *ptrAlu = fopen(nomeArq, "rb");
	
	fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
	
	if(feof(ptrAlu)){
		
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(MSG_TIME);
		clrRodape();
		if(CKB_SWITCH) clearkeybuf();
		
	}else{
		
		clrTittle();
		gotoxy(51, 3); printf("BUSCA POR INICIAL");
		gotoxy(48, 4); printf("(VARREDURA - EXAUSTIVA)");
		
		clrCorpo();
		textcolor(COR_REL);
		gotoxy(posX, posY++); printf("LETRA: ");
		c = toupper(getche());
		
		while(!feof(ptrAlu))
		{
			if(toupper(regAlu.aluNome[0]) == c)
				cont++;
				
			fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);	
		}
		if(cont > 0){
			if(cont > 21)
			{	
				textbackground(BLACK);
				system("cls");
				desenharLayout(30 + (cont - 21));
				
				clrTittle();
				gotoxy(51, 3); printf("BUSCA POR INICIAL");
				gotoxy(48, 4); printf("(VARREDURA - EXAUSTIVA)");
				
				textbackground(COR_FUNDO_CORPO);
				textcolor(COR_REL);
				gotoxy(posX, 6); printf("LETRA: %c", c);
			}
			
			fseek(ptrAlu, 0, SEEK_SET);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
			while(!feof(ptrAlu))
			{
				if(toupper(regAlu.aluNome[0]) == c){
					gotoxy(posX, posY++); printf("NOME: %s", regAlu.aluNome);
				}
				fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);	
			}
			
			if(cont > 21)
			{
				posY = 30 + (cont - 22);
				clrRodape(posY);
				gotoxy(53, posY); printf("PRONTO!");
				Sleep(MSG_TIME);
				clrRodape(posY);	
			}
			else{
				clrRodape();
				gotoxy(53, 29); printf("PRONTO!");
				Sleep(MSG_TIME);
				clrRodape();
			}
			if(CKB_SWITCH) clearkeybuf();
			getch();
			
		}else{
			
			clrRodape();
			gotoxy(53, 29); printf("NAO ENCONTRADO!");
			Sleep(MSG_TIME);
			clrRodape();
		}
		
		if(cont > 21){
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
	}
	fclose(ptrAlu);
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
		Sleep(MSG_TIME);
		clrRodape();
		if(CKB_SWITCH) clearkeybuf();
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
		gotoxy(52, 3); printf("ALUNOS REPROVADOS");
		gotoxy(52, 4); printf("(BUSCA EXAUSTIVA)");
		
		clrCorpo();
		textcolor(COR_REL);
		
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
				textcolor(COR_REL);
				posY++;
			}
			fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		}
		
		if(regSize * 7 > 22){
			
			posY = 29 + (regSize * 7 - 23);
			
			clrRodape(posY);
			gotoxy(53, posY); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape(posY);	
			
		}
		if(CKB_SWITCH) clearkeybuf();
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
	Sleep(MSG_TIME);
	if(CKB_SWITCH) clearkeybuf();
	
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
	if(CKB_SWITCH) clearkeybuf();
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
				Sleep(MSG_TIME);
				if(CKB_SWITCH) clearkeybuf();
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
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
			clrRodape();
		}
	}
	else
		fclose(ptrAluno);
}
//excLogicaNotas("Notas.dat", "Alunos.dat", "Disciplinas.dat", "Relatorios.dat");
void excLogicaNotas(char nomeNota[], char nomeAlu[], char nomeDis[], char nomeRel[])
{
	tpNotas regNotas;
	tpRel   regRel;
	tpDis   regDis;
	tpAluno regAlu;
	
	int pos, posY = 6, posX = 4, codAux;
	
	FILE *ptrNota = fopen(nomeNota, "rb+");
	FILE *ptrAlu  = fopen(nomeAlu,  "rb+");
	FILE *ptrDis  = fopen(nomeDis,  "rb+");
	FILE *ptrRel  = fopen(nomeRel,  "rb+");
	
	clrTittle();
	gotoxy(49, 3); printf("EXCLUIR DADOS DE NOTAS");
	gotoxy(51, 4); printf("(BUSCA EXAUSTIVA)");
	
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
					
					fseek(ptrRel, 0, SEEK_SET);
					fread(&regRel, sizeof(tpRel), 1, ptrRel);
					
					textcolor(COR_NOTA);
					pos = buscaAluno(ptrAlu, regNotas.notaRa);
					fseek(ptrAlu, pos, SEEK_SET);
					fread(&regAlu, sizeof(tpAluno), 1, ptrAlu);
					regAlu.qtdeReg--;
					if(regAlu.qtdeReg == 0)
						regRel.qtdeAlu--;
					fseek(ptrAlu, pos, SEEK_SET);
					fwrite(&regAlu, sizeof(tpAluno), 1, ptrAlu);
					
					pos = buscaBinariaDis(ptrDis, regNotas.notaDisCod);
					fseek(ptrDis, pos, SEEK_SET);
					fread(&regDis, sizeof(tpDis), 1, ptrDis);
					regDis.somaNotas -= regNotas.nota;
					regDis.qtdeReg--;
					if(regDis.qtdeReg == 0)
						regRel.qtdeDis--;
					fseek(ptrDis, pos, SEEK_SET);
					fwrite(&regDis, sizeof(tpDis), 1, ptrDis);
					
					regRel.somaQtdeRegNotas--;
					fseek(ptrRel, 0, SEEK_SET);
					fwrite(&regRel, sizeof(tpRel), 1, ptrRel);
					
					clrRodape();
					gotoxy(49, 29); printf("REGISTRO DELETADO, OK!");
					Sleep(MSG_TIME);
					clrRodape();
					if(CKB_SWITCH) clearkeybuf();
				}
				clrRodape();
			}
			else{
				clrRodape();
				gotoxy(53, 29); printf("NAO ENCONTRADO!"); //TESTAR
				Sleep(MSG_TIME);
				clrRodape();
				if(CKB_SWITCH) clearkeybuf();
			}	
		}
		
	}
	fclose(ptrNota);
	fclose(ptrDis);
	fclose(ptrAlu);
	fclose(ptrRel);
}

void excFisicaNotas(char nomeArq[])
{
	
	tpNotas regNotas;
	
	FILE *ptrNota = fopen(nomeArq, "rb");
	FILE *ptrTemp = fopen("temp.dat", "wb");
	
	clrRodape();
	gotoxy(45, 29); printf("EXCLUSAO ARQUIVO: %s...", nomeArq);
	Sleep(MSG_TIME);
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
	
	gotoxy(57, 29); printf("PRONTO!");
	Sleep(1000);
	clrRodape();
	if(CKB_SWITCH) clearkeybuf();
	
}

//void cadastroNotas("Notas.dat", "Disciplinas.dat", "Alunos.dat", "Relatorios.dat");
void excFisDisciplina(char arqDis[], char arqAlu[], char arqNota[], char arqRel[])
{
	// FUNCAO COMPLETA
	tpDis regDis;
	int pos, posY = 6, posX = 4, codAux, posDis;   
	
	FILE *ptrDis = fopen(arqDis, "rb");
	FILE *ptrNota = fopen(arqNota, "rb");
	
	clrTittle();
	gotoxy(46, 3); printf("EXCLUIR DADOS DE DISCIPLINAS");
	gotoxy(42, 4); printf("(BUSCA BINARIA POR CODIGO ORDENADO)");
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY++); printf("CODIGO: ");
	scanf("%d", &codAux);
	
	if(codAux > 0) 
	{
		//Busca...
		pos = buscaBinariaDis(ptrDis, codAux);
		posY++;
		
		if (pos > -1) 
		{
			posDis = buscaExaustivaNotasCod(ptrNota, codAux);
			gotoxy(posX, posY); printf("posDis: %d", posDis);
			getch();
			
			if(posDis > -1){
				    clrRodape();
				    gotoxy(42, 29); printf("REMOVA O REGISTRO EM NOTAS PRIMEIRO");
				    Sleep(MSG_TIME);
				    if(CKB_SWITCH) clearkeybuf();
				    clrRodape();
				    fclose(ptrDis);
				    fclose(ptrNota);
			}
			else{
				fseek(ptrDis, pos, 0);
			    fread(&regDis, sizeof(tpDis), 1, ptrDis);
			
			    gotoxy(posX, posY);        printf("CODIGO: %d", regDis.disCod);
		    	gotoxy(posX + 30, posY++); printf("DISCIPLINA: %s", regDis.disNome);
			
		    	clrRodape();
		    	gotoxy(52, 29); printf("EXCLUIR ? (S/N)");
			
		    	if(toupper(getch()) == 'S') 
				{
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
				    fclose(ptrNota);
				
				    remove(arqDis);
				    rename("temp.dat", arqDis);
				
				    clrRodape();
				    gotoxy(49, 29); printf("REGISTRO DELETADO, OK!");
				    Sleep(MSG_TIME);
				    if(CKB_SWITCH) clearkeybuf();
				    clrRodape();
			    }
			    else{
				        clrRodape();
				        fclose(ptrDis);
				        fclose(ptrNota);
			        }
			}
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("NAO ENCONTRADO!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
			clrRodape();
			fclose(ptrDis);
			fclose(ptrNota);
		}
	}
	else{
		fclose(ptrDis);
		fclose(ptrNota);
	}
		
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
				Sleep(MSG_TIME);
				if(CKB_SWITCH) clearkeybuf();
				clrRodape();
				
				posY++;
			}
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTROS!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
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
	gotoxy(54, 3); printf("ALTERAR NOTAS");
	gotoxy(52, 4); printf("(BUSCA EXAUSTIVA)");
	
	
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
					gotoxy(55, 29); printf("ALTERADO!");
					Sleep(MSG_TIME);
					clrRodape();
					if(CKB_SWITCH) clearkeybuf();
					
					posY++;
				}
				clrRodape();
			}
			else{
				
				clrRodape();
				gotoxy(48, 29); printf("INFORMACAO NAO ENCONTRADA!");
				Sleep(MSG_TIME);
				clrRodape();
				if(CKB_SWITCH) clearkeybuf();
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
				Sleep(MSG_TIME);
				if(CKB_SWITCH) clearkeybuf();
				clrRodape();
				
				posY++;
			}
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTROS!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
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
	
	tpRel regRel;
	FILE *ptrArquivo = fopen("Alunos.dat", "ab");
	fclose(ptrArquivo);
	
	ptrArquivo = fopen("Disciplinas.dat", "ab");
	fclose(ptrArquivo);
	
 	ptrArquivo = fopen("Notas.dat", "ab");
	fclose(ptrArquivo);
	
	ptrArquivo = fopen("Relatorios.dat", "ab+");
	
	fread(&regRel, sizeof(tpRel), 1, ptrArquivo);
	
	if(feof(ptrArquivo)){
		
		regRel.qtdeDis = 0;
		regRel.qtdeAlu = 0;
		regRel.somaQtdeRegNotas = 0;
		
		fwrite(&regRel, sizeof(tpRel), 1, ptrArquivo);
		
		/*clrRodape();
		gotoxy(53, 29); printf("Arquivos Criados e Inicializados!");
		Sleep(MSG_TIME);
		clrRodape();
		if(CKB_SWITCH) clearkeybuf();*/
	}
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
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTRO!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
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
			Sleep(MSG_TIME);
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTRO!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
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
	gotoxy(53, 3); printf("CONSULTAR NOTAS");
	gotoxy(52, 4); printf("(BUSCA EXAUSTIVA)");
	
	
	clrCorpo();
	textcolor(COR_DIS);
	gotoxy(posX, posY++); printf("R.A.: ");
	fflush(stdin);
	gets(regNotas.notaRa);
	
	while(stricmp(regNotas.notaRa, "\0"))
	{
		if(!(posY < 26)){
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
				gotoxy(55, 29); printf("ENCONTRADO!");
				Sleep(MSG_TIME);
				if(CKB_SWITCH) clearkeybuf();
				clrRodape();
			}
			else{
				
				clrRodape();
				gotoxy(53, 29); printf("NAO ENCONTRADO!");
				Sleep(MSG_TIME);
				clrRodape();
				if(CKB_SWITCH) clearkeybuf();
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
	gotoxy(48, 3); printf("CONSULTA DISCIPLINA NOME");
	gotoxy(51, 4); printf("(BUSCA SENTINELA)");
	
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
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
			clrRodape();
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTRO!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
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
			Sleep(MSG_TIME);
			clrRodape();
			posY++;
		}
		else{
			clrRodape();
			gotoxy(53, 29); printf("SEM REGISTROS!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
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


int buscaExaustivaNotasCod(FILE *ptrNota, int codAux)
{
	tpNotas regNota;
	//rewind(ptrNota);
	fseek(ptrNota, 0, SEEK_SET);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	while(!feof(ptrNota) && (codAux != regNota.notaDisCod || regNota.status == 0))
		fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		
	if(feof(ptrNota))
		return -1;
	return ftell(ptrNota) - sizeof(tpNotas);
}

int buscaExaustivaNotasRa(FILE *ptrNota, char ra[])
{	
	tpNotas regNota;
	rewind(ptrNota);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	while(!feof(ptrNota) && (stricmp(ra, regNota.notaRa) != 0 || regNota.status == 0))
		fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		
	if(feof(ptrNota))
		return -1;
	return ftell(ptrNota) - sizeof(tpNotas);
}

int buscaExaustivaNotas(FILE *ptrNota, char ra[], int codAux)
{	
	tpNotas regNota;
	rewind(ptrNota);
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	while(!feof(ptrNota) && (stricmp(ra, regNota.notaRa) != 0 || codAux != regNota.notaDisCod || regNota.status == 0))
		fread(&regNota, sizeof(tpNotas), 1, ptrNota);
		
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
		Sleep(MSG_TIME);
		if(CKB_SWITCH) clearkeybuf();
		clrRodape();
		
	}else{
		
		if(regSize > 22)
		{	
			textbackground(BLACK);
			system("cls");
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
			gotoxy(posX + 55, posY);   printf("REG. EM NOTAS: %d", regAlu.qtdeReg);
			fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			posY++;
		}
		
		if(regSize > 22){
			
			posY = 29 + (regSize - 22);
			
			clrRodape(posY);
			gotoxy(53, posY); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape(posY);
			if(CKB_SWITCH) clearkeybuf();
		}
		else{
			
			clrRodape();
			gotoxy(53, 29); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
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

void relNotas(char nomeArq[], char arqRel[])
{
	tpNotas regNota;
	tpRel   regRel;
	
	FILE *ptrNota = fopen(nomeArq, "rb");
	FILE *ptrRel  = fopen(arqRel, "rb");
	
	fread(&regRel, sizeof(tpRel), 1, ptrRel);
	int pos, posY = 6, posX = 4;
		
	fread(&regNota, sizeof(tpNotas), 1, ptrNota);
	
	if(feof(ptrNota)){
		clrRodape();
		gotoxy(53, 29); printf("SEM REGISTROS!");
		Sleep(MSG_TIME);
		clrRodape();
		if(CKB_SWITCH) clearkeybuf();
	}
	else{
		
		if(regRel.somaQtdeRegNotas > 22)
		{	
			textbackground(BLACK);
			system("cls");
			desenharLayout(30 + (regRel.somaQtdeRegNotas - 22));
		}
		
		clrTittle();
		gotoxy(51, 3); printf("RELATORIO DE NOTAS");
		gotoxy(51, 4); printf("(METODO EXAUSTIVA)");
		
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
		if(regRel.somaQtdeRegNotas > 22){
			
			posY = 30 + (regRel.somaQtdeRegNotas - 23);
			clrRodape(posY);
			gotoxy(57, posY); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape(posY);
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
			
			textbackground(BLACK);
			system("cls");
			desenharLayout();
		}
		else{
			
			clrRodape();
			gotoxy(57, 29); printf("PRONTO!");
			Sleep(MSG_TIME);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
			
			getch();
		}
	}
	fclose(ptrRel);
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
		Sleep(MSG_TIME);
		if(CKB_SWITCH) clearkeybuf();
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
			gotoxy(posX + 50, posY); printf("NT. ACU.: %.2f", regDis.somaNotas);
			gotoxy(posX + 70, posY); printf("QTDE. DE NT. REGIS.: %d", regDis.qtdeReg);
			fread(&regDis, sizeof(tpDis), 1, ptrDis);
			posY++;
		}
		if(CKB_SWITCH) clearkeybuf();
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
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
			clrRodape();
		}
		else{
			
			gotoxy(posX + 30, posY); printf("NOME DISCIPLINA: ");
			fflush(stdin);
			gets(regDis.disNome);
			
			regDis.qtdeReg = 0;
			regDis.somaNotas = 0;
			
			fseek(ptrDis, 0, SEEK_END);
			fwrite(&regDis, sizeof(tpDis), 1, ptrDis);
			
			insercaoDireta(ptrDis);
			
			clrRodape();
			gotoxy(53, 29); printf("REGISTRO SALVO!");
			Sleep(MSG_TIME);
			if(CKB_SWITCH) clearkeybuf();
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

void cadastroNotas(char arqNota[], char arqDis[], char arqAlu[], char arqRel[])
{
	// CONTINUAR
	tpNotas regNotas;
	tpDis regDis;
	tpRel regRel;
	tpAluno regAlu;
	
	int pos, posY = 6, posX = 4, posDis, posAlu;
	
	FILE *ptrNota = fopen(arqNota, "rb+");
	FILE *ptrDis = fopen(arqDis, "rb+");
	FILE *ptrAluno = fopen(arqAlu, "rb+");
	FILE *ptrRel = fopen(arqRel, "rb+");
	
	clrTittle();	
	gotoxy(54, 3); printf("INSERIR NOTAS");
	gotoxy(35, 4); printf("(INSERCAO DIRETA - BUSCA EXAUSTIVA - BUSCA BINARIA)");
	
	clrCorpo();
	textcolor(COR_NOTA);
	gotoxy(posX, posY++); printf("R.A.: ");
	fflush(stdin);
	gets(regNotas.notaRa);
	
	while(stricmp(regNotas.notaRa, "\0") != 0)
	{
		//Busca Exaustiva...
		posAlu = buscaAluno(ptrAluno, regNotas.notaRa);
		
		if(posAlu > -1) 
		{
			
			// Ra encontrado no arquivo alunos...
			gotoxy(posX, posY++); printf("CODIGO DIS.: ");
			scanf("%d", &regNotas.notaDisCod);
			
			while(regNotas.notaDisCod > 0)
			{
				posDis = buscaBinariaDis(ptrDis, regNotas.notaDisCod);
				
				if(!(posY < 25)){	
					clrCorpo();
					posY = 6;
				}
				
				if(posDis > -1)
				{
					//Busca Exaustiva...
					pos = buscaExaustivaNotas(ptrNota, regNotas.notaRa, regNotas.notaDisCod);
					
					if(pos > -1)
					{
						regNotas.notaDisCod = 0;
						clrRodape();
						gotoxy(52, 29); printf("NOTA JA REGISTRADA!");
						Sleep(MSG_TIME);
						clrRodape();
						if(CKB_SWITCH) clearkeybuf();
						
					}
					else{
						
						clrRodape();
						gotoxy(54, 29); printf("ENCONTRADO, OK!");
						Sleep(700);
						clrRodape();
						if(CKB_SWITCH) clearkeybuf();
						
						textbackground(COR_FUNDO_CORPO);
						gotoxy(posX, posY++); textcolor(GREEN); printf("NOTA: ");
						textcolor(COR_NOTA);
						scanf("%f", &regNotas.nota);
						regNotas.status = 1;
						
						fseek(ptrNota, 0, SEEK_END);
						fwrite(&regNotas, sizeof(tpNotas), 1, ptrNota); //REGISTRA A NOTA COM STATUS 1
						
						insercaoDiretaNotas(ptrNota); //REPOSICIONA COM INSERCAO DIRETA
						
						fseek(ptrRel, 0, SEEK_SET);
						fread(&regRel, sizeof(tpRel), 1, ptrRel); //LE STRUCT RELATORIO
						
						fseek(ptrAluno, posAlu, SEEK_SET);
						fread(&regAlu, sizeof(tpAluno), 1, ptrAluno);
						if(regAlu.qtdeReg == 0) // QUANTAS VEZES DIFERENTES ALUNOS FORAM REGISTRADAS EM NOTAS, O VALOR MAXIMO, SERA O VALOR MAXIMO DE ALUNOS REGISTRADOS
						{
							regRel.qtdeAlu++;
							/*gotoxy(posX, posY++); printf("ENTROU");
							getch();*/
						}  
						regAlu.qtdeReg++; //QUANTAS VEZES CADA ALUNO TEVE SUA NOTA REGISTRADA EM DIFERENTES DISCIPLINAS
						fseek(ptrAluno, posAlu, SEEK_SET); //GRAVANDO INFORMACOES ATUALIZADAS EM ALUNOS
						fwrite(&regAlu, sizeof(tpAluno), 1, ptrAluno);
						
						
						fseek(ptrDis, posDis, SEEK_SET);
						fread(&regDis, sizeof(tpDis), 1, ptrDis);
						if(regDis.qtdeReg == 0) // QUANTAS VEZES DIFERENTES DISCIPLINAS FORAM REGISTRADAS EM NOTAS, O VALOR MAXIMO, SERA O VALOR MAXIMO DE DISCIPLINAS REGISTRADOS
						{
							regRel.qtdeDis++; 
						} 
						regDis.qtdeReg++; //QUANTAS VEZES CADA DISCIPLINA FOI USADA PARA CADASTRAR UMA NOTA EM DIFERENTES RA
						regDis.somaNotas += regNotas.nota; //NOTAS ACUMULADAS EM CADA DISCIPLINA, PARA CALCULO DAS MEDIAS						
						fseek(ptrDis, posDis, SEEK_SET);
						fwrite(&regDis, sizeof(tpDis), 1, ptrDis); //GRAVANDO INFORMACOES ATUALIZADAS EM DISCIPLINAS
						
						
						regRel.somaQtdeRegNotas++; // QUANTIDADE TOTAL DE REGISTROS EFETUADOS EM NOTAS
						fseek(ptrRel, 0, SEEK_SET); //GRAVANDO INFORMACOES ATUALIZADAS EM RELATORIOS, CONTEM UM REGISTRO APENAS QUE VAI SENDO MODIFICADO CONFORME O CADASTRO
						fwrite(&regRel, sizeof(tpRel), 1, ptrRel);
						
						clrRodape();
						gotoxy(53, 29); printf("REGISTRADO, OK!");
						Sleep(1000);
						clrRodape();
						if(CKB_SWITCH) clearkeybuf();
					}
				}
				else{
					clrRodape();
					gotoxy(49, 29); printf("DISCIPLINA NAO ENCONTRADA!");
					Sleep(MSG_TIME);
					clrRodape();
					if(CKB_SWITCH) clearkeybuf();
				}
				
				if(regNotas.notaDisCod > 0){
					
					textbackground(COR_FUNDO_CORPO);
					textcolor(COR_NOTA);
					gotoxy(posX, posY++); printf("CODIGO DIS.: ");
					scanf("%d", &regNotas.notaDisCod);		
				}
			}
		}
		else{ 
			clrRodape();
			gotoxy(51, 29); printf("RA NAO ENCONTRADO!");
			Sleep(1000);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
		}
		
		if(!(posY < 25)){	
			clrCorpo();
			posY = 6;
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
	fclose(ptrRel);
}

void cadastroAlunos(char nomeArq[]) {
	
	tpAluno regAlu;
	int pos, posY = 6, posX = 4;
	
	FILE *ptrAluno = fopen(nomeArq, "ab+");
	
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
			Sleep(MSG_TIME);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
		}
		else{
			gotoxy(posX + 18, posY++); printf("Nome: ");
			fflush(stdin);
			gets(regAlu.aluNome);
			regAlu.qtdeReg = 0;
			fwrite(&regAlu, sizeof(tpAluno), 1, ptrAluno);
			
			clrRodape();
			gotoxy(54, 29); printf("CADASTRO OK!");
			Sleep(MSG_TIME);
			clrRodape();
			if(CKB_SWITCH) clearkeybuf();
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
	gotoxy(28, 4); printf("by: Victor Taveira - github.com/rodrigueseti/cpp-mini-projects");
	
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
	gotoxy(26, posY++);   printf("DISCIPLINA");
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
	gotoxy(84, posY++);   printf("RELATORIOS");
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


