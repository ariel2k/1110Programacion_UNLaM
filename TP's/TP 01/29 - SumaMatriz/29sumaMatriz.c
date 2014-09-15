#include <stdio.h>

#define Fi_Co 4

void mostrarMatriz (int [][Fi_Co]);
int diagPrinc (int op, int m[][Fi_Co]);
int diagSec (int op, int m[][Fi_Co]);

int main ()
{
	// variables
	int mat[Fi_Co][Fi_Co]={
			{1,2,3,3},
			{1,4,3,1},
			{1,2,1,2},
			{2,2,2,2}},
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

	printf("\nOpcion: ");
	scanf ("%d", &op);

	while(op!=0)
    {
		if (op%2 == 1 && op!=0)
			printf("\nResultado: %d\n", diagPrinc(op, mat));
		else
			printf("\nResultado: %d\n", diagSec(op, mat));

        printf("\nOpcion: ");
        scanf ("%d", &op);
    }

	// fin
	system("pause");
	return 0;
}

/*---funciones---*/

//--mostrarMatriz--//
void mostrarMatriz (int m[][Fi_Co])
{
	int i,
		acum=0;

    printf("\n");
	while (acum <= Fi_Co-1)
	{
		printf("( ");
		for (i=0 ; i<Fi_Co ; i++)
		{
			printf("%02d", m[acum][i]);
			if (i<Fi_Co-1)
				printf(" | ");
			else
				printf(" )\n");
		}
		acum++;
	}
}

//--diagPrinc--//
int diagPrinc (int op, int m[][Fi_Co])
{
	int acum=0,
		fi,
		col;

	for(fi=0; fi<Fi_Co; fi++)
		for(col=fi; col<Fi_Co; col++)
            if(op<5)
            {
				if(col!=fi)
                    acum += m[fi][col];
				else
					if (op==3)
						acum += m[fi][col];
            }
			else
				if (col!= fi)
                {
                    printf ("col: %d, fila: %d\n", col, fi);
					acum += m[col][fi];
                }

	return acum;
}

//--diagSec--//
int diagSec (int op, int m[][Fi_Co])
{
	int acum=0,
		fi,
		col;

	for(fi=0; fi<Fi_Co; fi++)
		for(col=0; col<=Fi_Co-fi-1; col++)
			if(op!=6)
            {
                if(col+fi != Fi_Co-1)
					acum += m[fi][col];
				else
					if (op==4)
						acum += m[fi][col];
            }
            else
				if(col + fi < Fi_Co-1)
                    acum += m[Fi_Co-1-fi][Fi_Co-1-col];

	return acum;
}
