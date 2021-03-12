
int trocaUnidade (Dir **unid, char letra)
{
	/*
	*return 1 - successfully
	*return 0 - unsuccessfully
	*/
	
	Dir *aux = *unid;
	while(aux->top != NULL && aux->letter != letra)
		aux = aux->top;
	
	if(aux->letter == letra)
	{
		*unid = aux;
		return 1;
	}
		
	aux = *unid;
	while(aux->bottom != NULL && aux->letter != letra)
		aux = aux->bottom;
		
	if(aux->letter == letra)
	{
		*unid = aux;
		return 1;
	}
	return 0;
}
