#include <stdio.h>
//#include "funciones.h"

int esPrimo (int);

int main ()
{
	// variables
    int num;

	// programa
	printf ("------Numeros primos------\n");
	printf("Ingrese un numero: ");
	scanf("%d", &num);
	printf("\n");
	printf("-----Resultado-----\n");
	if(esPrimo(num)==0)
		printf("Es primo.\n\n");
	else
		printf("No es primo.\n\n");

	// fin
	system ("pause");
	return 0;
}


int esPrimo (int num)
{
	int i;

	for( i=2 ; i<num/2 ; i++ )
		if (num%i==0)
			return(1);

	return(0);
}
