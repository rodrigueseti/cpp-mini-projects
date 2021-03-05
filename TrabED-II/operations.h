//TAD Manipulacoes


void initDir(Dir **uni)
{
	*uni = NULL;
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
		newUnit->unidade = 'C';
		*uni = newUnit;
	}
	else{ //Demais caixas
	
		while (aux->bottom != NULL)
			aux = aux->bottom;
		
		newUnit->unidade = aux->unidade + 1; //Considerando que esteja na ultima letra
		*newUnit->top = aux;
		aux->bottom = newUnit;
	}
}
