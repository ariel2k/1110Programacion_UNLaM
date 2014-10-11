#include <stdio.h>
#include "pilaEstatica.h"

int main ()
{
	t_info info; //Datos
	t_pila pila; //Paquete: Datos + Sig
	crearPila(&pila);
	while(!pilaLLena(&pila))
	{
		pedirDatos(&info); //Llena los datos en la estructura info
		if (!ponerEnPila(&pila, &info))
		{
			printf("ERROR\n");
			return 2;
		}
	}
	return 0;
}