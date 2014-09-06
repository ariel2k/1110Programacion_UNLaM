#include <stdio.h>
#define Fi 4
#define Co 4
#define unaCifra(x) ( (x)>-1 && (x)<10 ? printf("0") : 0)

void mostrarMatriz (int [][Co]);
int sumaPrincipal (int [][Co], int, int, int, int);
int sumaSecundaria (int [][Co], int, int, int, int);

int main ()
{
	// variables
	int mat[Fi][Co]={{1,2,3,3},{1,4,3,1},{1,2,1,2,},{2,2,2,2}},
		op;

	// programa
	printf("--------Matriz--------");
	mostrarMatriz(mat);
	printf("\n------Opcion------\n");
	printf("1: Sumatoria sobre la diagonal principal.\n");
	printf("2: Sumatoria sobre la diagonal secundaria.\n");
	printf("3: Sumatoria incluyendo la diagonal principal.\n");
	printf("4: Sumatoria incluyendo la diagonal secundaria.\n");
	printf("5: Sumatoria debajo la diagonal principal.\n");
	printf("6: Sumatoria debajo la diagonal secundaria.\n");
	printf("//0: fin del programa.\n");
	do
	{
	printf("\nOpcion: ");
	scanf ("%d", &op);

	if(op==1)
		printf("\n------Resultado------\n%d\n",sumaPrincipal(mat,0,1,2,3));
	else
		if(op==2)
			printf("\n------Resultado------\n%d\n",sumaSecundaria(mat,2,0,0,2));
		else
			if(op==3)
				printf("\n------Resultado------\n%d\n",sumaPrincipal(mat,0,0,3,3));
			else
				if(op==4)
					printf("\n------Resultado------\n%d\n",sumaSecundaria(mat,0,3,3,0));
				else
					if(op==5)
						printf("\n------Resultado------\n%d\n",sumaPrincipal(mat,1,0,3,2));
					else
						if(op==6)
							printf("\n------Resultado------\n%d\n",sumaSecundaria(mat,3,1,1,3));
						else
							printf("Opcion incorrecta. Intente nuevamente.\n");
	}while(op!=0);
	// fin
	system("pause");
	return 0;
}

/*---funciones---*/

//--mostrarMatriz--//
void mostrarMatriz (int m[][Co])
{
	int i,
		acum=0;

    printf("\n");
	while (acum <= Co-1)
	{
		printf("( ");
		for (i=0 ; i<Co ; i++)
		{
		    unaCifra(m[acum][i]);
			printf("%d", m[acum][i]);
			if (i<Co-1)
				printf(" | ");
			else
				printf(" )\n");
		}
		acum++;
	}
}

//--sumaPrincipal--//
int sumaPrincipal (int m[][Co], int iX, int iY, int fX, int fY)
{
	int i, //filas
		j, //columnas
		acum=0;

	for (i=iX ; i<=fX ; i++ ) //for de filas
	{
	    printf("Acum 1er for: %d\n", acum);
		for (j=iY ; j<=fY ; j++) //for de col
        {
            acum += m[i][j];
            printf("acum: %d, Valor: %d, i: %d, j: %d\n", acum, m[i][j],i, j);
        }
		iY++;
	}

	return acum;
}

//--sumaSecundaria--//
int sumaSecundaria (int m[][Co], int iX, int iY, int fX, int fY)
{
	int i, //filas
		j, //columnas
		acum=0;

	for (i=iX ; i>=fX ; i-- ) //for de filas
	{
		for (j=iY ; j<=fY ; j++) //for de col
		{
            acum += m[i][j];
            printf("acum: %d, Valor: %d, i: %d, j: %d\n", acum, m[i][j],i, j);
        }
		iY++;
	}

	return acum;
}
