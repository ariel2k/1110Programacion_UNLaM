#include "funciones.h"

int esPrimo (int num)
{
	int i;

	for( i=2 ; i<num/2 ; i++ )
		if (num%i==0)
			return(1);

	return(0);
}
