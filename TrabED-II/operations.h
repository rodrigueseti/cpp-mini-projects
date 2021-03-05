//TAD Manipulacoes



void buildUnit(Dir **uni, char letter)
{
	
	//Primeira Caixa
	Dir *newUnit = (Dir*) malloc(sizeof(Dir));
	newUnit->top = NULL;
	newUnit->unidade = letter;
	newUnit->arqs = NULL;
	newUnit->bottom = NULL;
	//Primeira Caixa
}
