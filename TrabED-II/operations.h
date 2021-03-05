//TAD Manipulacoes


void initDir(Dir **uni)
{
	*uni = NULL;
}

const char getDate(char date[])
{
	struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);
    sprintf(date, "%d/%d/%d\0", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900);
}

void getHour(char hour[])
{
	struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);
    
    sprintf(hour, "%d:%d:%d\0", p->tm_hour, p->tm_min, p->tm_sec);
}


void buildUnit(Dir **uni)
{
	Dir *newUnit = (Dir*) malloc(sizeof(Dir));
	newUnit->bottom = NULL;
	newUnit->arqs = NULL;
	Dir *aux = *uni;
	
	//Primeira Caixa
	if(*uni == NULL)
	{
		newUnit->letter = 'C';
		*uni = newUnit;
	}
	else{ //Demais caixas
	
		while (aux->bottom != NULL)
			aux = aux->bottom;
		
		newUnit->letter = aux->letter + 1; //Considerando que esteja na ultima letra
		newUnit->top = aux;
		aux->bottom = newUnit;
	}
}

//Apos criado, o arquivo.DBF é aberto, para insercoes de dados
void create (Dir **uni, char name[])
{
	char date[9];
	char hour[9];
	
	getDate(date);
	getHour(hour);
	
	Arq *newDBF = (Arq*) malloc (sizeof(Arq));
	newDBF->ant = NULL;
	strcpy(newDBF->nomeDBF, name);
	strcpy(newDBF->data, date);
	strcpy(newDBF->hora, hour);
	newDBF->stts = NULL;
	newDBF->cmps = NULL;
	newDBF->prox = NULL;
	
	(*uni)->arqs = newDBF;
}
