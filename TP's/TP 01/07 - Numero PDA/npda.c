/*Pasos del programa:
	1) Ingresar el numero
	2) Buscar sus divisores e ir sumandolos
		2.1) Obtengo un divisor y lo incremento con el anterior
	3) comparar el numero con el divisor
*/
#include <stdio.h>

int main()
{
	// variables
	int num,
		i,
		total=0;

	// programa
	printf("Ingresar un numero para comprobar si es:\n  *Natural.\n  *Perfecto.\n  *Abundante. \n\n");
	printf("Numero: ");
	scanf("%d",&num);
	printf("\n\n-----Divisores-----\n");
	for(i=1;i<=num/2;i++)
		if(num%i==0)
		{
			printf("%d, es divisor de %d \n",i,num);
			total += i;
		}
    printf("-------------------");
	printf("\n\n-----Resultado-----\nNumero: %d\nLa suma de los divisores es: %d\nEl numero es: ", num, total);
	if (num == total)
		printf("Perfecto.\n");
	else
		if (total < num)
			printf("Deficiente.\n");
		else
			printf("Abundante.\n");
    printf("-------------------\n");


	// return
	return 0;
}
