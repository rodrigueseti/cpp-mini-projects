union ponteiroDadosUniao
{
    float ValorN;
    char ValorD[10];
    char ValorL;
    char ValorC[50];
    char ValorM[50];
};

struct ponteiroDados
{
    union ponteiroDadosUniao valor;
    struct ponteiroDados *prox;
};
typedef struct ponteiroDados pDados;

struct campos{
	
    struct campos *pAtual;
	
    char fieldName[20]; 
	char type; //Definir
    int width; //TL
	int dec;
    
	struct ponteiroDados *p_dados;
    
    struct campos *prox;
};
typedef struct campos Campos;

struct status {
    int status;
    struct status *prox;
};
typedef struct status Status;

struct arquivo {
	
    struct arquivo *ant; 
    char nomeDBF[40];
    char data[10]; //Pegar data atual do sistema
	char hora[5];  //Pegar hora atual do sistema 
	
	struct status *stts;
	struct campos *cmps;
	
    struct arquivo *prox;
}; 
typedef struct arquivo Arq;

struct unidade{
	
	struct unidade *top;
    char unidade; //Definir
    struct arquivo *arqs;
    struct unidade *bottom;
};
typedef struct unidade Dir;
