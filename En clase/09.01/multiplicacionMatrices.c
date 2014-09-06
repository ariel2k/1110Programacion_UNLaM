#include <stdio.h>

#define Fi_Co 	4
#define Fi 		3
#define Co 		2

void multiplicar (int [][Fi_Co], int [][Co], int [][Co]);
void mostrar (int [][Co], int, int);

int main ()
{
	// variables
	int	m1[Fi][Fi_Co] = {{2,1,2,3},{2,1,2,1},{3,1,1,1}},
		m2[Fi_Co][Co] = {{2,3},{1,1},{2,1},{3,1}},
		r[Fi][Co];

	// programa
	multiplicar(m1, m2, r);
	mostrar(r, Fi, Co);

	// fin
	system("pause");
	return 0;
}

/*---funciones---*/

//--multiplicar--//
void multiplicar (int m1[][Fi_Co], int m2[][Co], int r[][Co])
{
	int	fi,
		col,
		i;

	for (fi=0 ; fi<Fi ; fi++ )
		for (col=0 ; col<Co ; col++)
			for ( r[fi][col]=0, i=0 ; i<Fi_Co ; i++)
				r[fi][col] += m1[fi][i] * m2[i][col];
}

//--mostrar--//
void mostrar (int r[][Co], int fi, int col)
{
	int i;

	printf("\n-------Resultado-------\n\n");
	for ( i=0 ; i<fi ; i++)
		printf("( %d | %d )\n", r[i][0], r[i][1]);
	printf("\n-------Fin-------\n\n");
}
