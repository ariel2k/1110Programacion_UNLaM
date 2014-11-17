#include "dupcad.h"

char* duplicarCadena(const char *cad)
{
	char *aux;
	if(cad!=NULL && *cad!='\0')
	{
		try{
			aux = new char [strlen(cad)+1];
			strcpy(aux,cad);
			return aux;
		}catch(std::bad_alloc &){
			//Debería llamara a una excepción
		}
	}
	return NULL;
}

///


