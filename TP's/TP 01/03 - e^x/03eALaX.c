/*
1) Ingresar X y TOL
2) Ejecutar funcino eALaX
  2.1) do { termino = X^n/n! } while (termino >= TOL)
*/
#include <stdio.h>

float eALaX (int, float);
int elevar (int, int);
int factorial (int);

int main ()
{
	//variables
	int	X;
	float 	TOL,
			resultado;

	//programa
	printf("---Ingresar valores iniciales---\n");
	printf("X: ");
	scanf("%d", &X);
	printf("\nTOL: ");
	scanf("%f", &TOL);
	resultado = eALaX(X,TOL);
	printf("\n----------\nResultado: %f\n----------\n", resultado);

	//fin
	system("pause");
	return 0;
}

/*---funciones---*/

//--eALaX--//
float eALaX (int x, float tol)
{
	int 	n=0;
	float 	termino,
			acum=0;

	do
	{
		termino = (float)elevar(x,n) / factorial(n);
		n++;
		acum += termino;
	}while (termino >= tol);

	return acum;
}

//--elevar--//
int elevar (int x, int n)
{
	int i=0,
		res=x;

	while(i<n)
	{
		res *= x;
		i++;
	}

	return res;
}

//--factorial--//
int factorial (int n)
{
	int res = 1;

	while(n >1)
		res *= n--;

	return res;
}
