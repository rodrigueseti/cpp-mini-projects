union PdadosU{
    float ValorN;
    char ValorD[10];
    char ValorL;
    char ValorC[50];
    char ValorM[50];
};

/*struct pdados{
    union PdadosU *valor;
    Pdados *Prox;
};*/
typedef struct pdados Pdados;

struct campos{
    struct campos *Patual, *Prox;
    char FieldName[20], Type;
    int Width, dec;
    Pdados *Pdados;
};
typedef struct campos Campos;

struct status{
    short int status;
    struct status *Prox;
};
typedef struct status Status;

struct Arquivo{
    struct Arquivo *ant, *arox;
    char nomeDBF[40], data[10], hora[5];
};
typedef struct Arquivo Arq;

struct Diretorio{
    char letra;
    struct Diretorio *top, *bottom;
    struct Arquivo *arq;
};
typedef struct Diretorio Dir;

