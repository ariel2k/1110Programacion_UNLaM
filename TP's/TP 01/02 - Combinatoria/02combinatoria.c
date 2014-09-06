#include <stdio.h>

int factorial (int);

int main()
{
	int n1,
		n2,
        res;

	printf("Ingrese dos numeros (el primero mayor que el segundo y positivos):\n");
	scanf("%d", &n1);
	scanf("%d", &n2);

	res = factorial(n1)/factorial(n2)*factorial(n1-n2);
	printf("El resultado de la combinatoria es: %d\n", res);

    return 0;
}

/*---------Funciones---------*/

/*---Factorial---*/
int factorial (int n)
{
	int res = 1;

	while(n >1)
		res *= n--;

	return res;
}
