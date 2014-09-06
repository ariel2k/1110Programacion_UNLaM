#include <stdio.h>
#define validarIngreso(X) ( (X) < 5 && (X) > -1 ? ingresoArray(array, valor, (X)) : printf("Posicion erronea.\n") )

void ingresoArray (int [], int, int);

int main ()
{
	// variables
	int array[5]={0},
		valor,
		posicion;

	// programa
	printf ("-----Ingreso de valor en cierta posicion-----\n//Array: 5 pos (0 - 4)\n//Finaliza con valor=0\n\n");
	do
	{
		printf("--------\nValor: ");
		scanf ("%d", &valor);
		printf("Posicion: ");
		scanf ("%d", &posicion);
		printf("--------\n");
		validarIngreso(posicion);
	}while(valor);

	// fin
	system ("pause");
	return 0;
}

/*---Funciones---*/

//--ingresoArray--//
void ingresoArray (int array[], int n, int pos)
{
	array[pos]=n;
}
