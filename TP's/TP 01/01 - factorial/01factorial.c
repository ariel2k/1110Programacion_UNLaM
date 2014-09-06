#include <stdio.h>

int factorial (int);

int main ()
{
	int	num;

	printf("----Factorial----\nNum: ");
	scanf("%d", &num);
	printf("\n----Resultado---\nRta: %d", num, factorial(num));

	system("pause");
	return 0;
}


/*---funciones---*/

//--factorial--//
int factorial (int n)
{
	int res = 1;

	while(n >1)
		res *= n--;

	return res;
}
