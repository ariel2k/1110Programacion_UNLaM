#include <stdio.h>
#include <math.h>

double raizCudrada(int, double);

int main ()
{
	int x;
	double 	tol,
			res;

	printf("-------Reiz cuadrada-------\n");
	printf("Ingrese un numero: ");
	scanf("%d", &x);
	printf("\nIngrese una tolerancia: ");
	scanf("%lf", &tol);

	res = raizCudrada(x, tol);
	printf("\n--------Resultado-------\n");
	printf("La raiz es: %lf\n\n", res);

	system("pause");
	return 0;
}

/*---Funciones---*/

//--raizCudrada--//
double raizCudrada(int num, double tol)
{
	double 	rAnt=1,
			rAct=(rAnt+num/rAnt)/2;

	while(fabs(rAnt - rAct) > tol)
	{
		rAnt = rAct;
		rAct = (rAnt+num/rAnt)/2;
	}

	return rAct;
}
