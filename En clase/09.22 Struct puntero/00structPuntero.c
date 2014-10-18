#include <stdio.h>
#include <string.h>

typedef struct{
	char nombre[20],
		 apellido[20];
	long	 dni;
} t_pers;

int llenarStruct (t_pers *p);
void mostrarSruct (t_pers *p, int);

/*--P. Principal--*/

int main ()
{
	// Varialbes
	t_pers pers[40];
	long   dni;
	int	   cant;

	// Programa
	cant = llenarStruct(&pers);

	mostrarSruct(&pers, cant);

	// Fin
	system("pause");
	return 0;
}

/*--Funciones--*/

//--llenarStruct--//
int llenarStruct (t_pers *p)
{
    int dni,
        cant=0;
    char nombre[20], apellido[20];
    t_pers *aux=p;

	printf("-----Ingreso de Datos-----\n---DNI=0 termina ingreso---");
	printf("\nDni: ");
	scanf("%ld",&dni);
	while(dni!=0)
	{
		printf("Nombre: ");
		fflush(stdin);
		scanf("%c",&aux->nombre);
		printf("Apellido: ");
	    fflush(stdin);
		scanf("%c",&aux->apellido);
		aux->dni = dni;
		printf("\nDni: ");
		fflush(stdin);
        scanf("%ld",&dni);
		aux++;
        cant++;
	}

	return cant;
}

//--mostrarSruct--//
void mostrarSruct (t_pers *p, int c)
{
	int i;

	printf("       Nombre       |       Apellido       |    Dni\n");
	for (i=0 ; i<c ; i++)
    {
	    printf("%20c %20c     %08d \n", p->nombre, p->apellido, p->dni);
	    p++;
    }
}
