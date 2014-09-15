/*Pasos:
1) Ingresa un numero
2) Armo la serie de fibonacci con los dos primeros numeros
3) Me fijo si el numero ingresado es mayor o si pertenece a alguno de esos.
	3.1) Sigo haciendo la serie y sigo preguntando.
	3.2) Es igual -> pertenece
	3.3) Mi numero es mas chico -> no pertence
*/

#include <stdio.h>

int main ()
{
	// variables
	int num,
		n1 =1,
		n2 =1,
		res = 1;

	// programa
	printf ("Ingresa un numero para comprobar si pertenece a la serie de Fibonacci: \n");
	scanf("%d", &num);
	while(num > res)
	{
	    res = n1 + n2;
		n1 = res;
		res = n1 + n2;
		n2 = res;
	}

	if(num == n1 || num == n2)
		printf("Pertenece a la serie de Fibonacci.\n");
	else
		printf("No pertenece a la serie de Fibonacci.\n");

	// return
	return 0;
}
