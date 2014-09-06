#include <stdio.h>
#define cant 5

void mostrarVector (int []);
void insertarNum (int [], int);

int main ()
{
	// variables
	char	op;
	int num,
		vec[cant]={20,10,5,2,1};

	// programa
	printf ("-----Inicio vectores-----\n");
	mostrarVector(vec);
	do
	{
		printf("\n------------------\nIngresar un numero (0 para finalizar): ");
		scanf("%d", &num);
		insertarNum(vec, num);
		mostrarVector(vec);
	}while(num);

	// fin
	system("pause");
	return 0;
}

/*---funciones---*/

//--mostrarVector--//
void mostrarVector (int v[])
{
	int i;
	printf("------Vector------\n");
	for (i=0;i<cant;i++)
		printf("%d: [%d]\n", i+1, v[i]);
	printf("------------------\n");
}

//--insertarNum--//
void insertarNum (int v[], int n)
{
	int i=0;
	while (n<v[i])
		i++;
	v[i]=n;
}
