#include <stdio.h>

/*--Estructs--*/
typedef struct{
	int dia, mes, anio;
} t_fecha;

typedef struct{
	char nombre[20],
		 apellido[20];
	long	 dni;
	//t_fecha  fech;
} t_pers;

void llenarStruct (t_pers *p, long dni);
void mostrarSruct (t_pers *p);

/*--P. Principal--*/

int main ()
{
	// Varialbes
	t_pers pers[40];
	long   dni;

	// Programa
	printf("-----Ingreso de Datos-----\n---DNI=0 termina ingreso---");
	printf("\nDni: ");
	scanf("%ld",&dni);
	while (dni!=0)
	{
		llenarStruct(&pers, dni);
		printf("\n---Nuevo Reg---");
		printf("\nDni: ");
		fflush(stdin);
		scanf("%ld",&dni);
	}

	printf("//------Fin Ingreso------//\n");
	mostrarSruct(&pers);

	// Fin
	system("pause");
	return 0;
}

/*--Funciones--*/

//--llenarStruct--//
void llenarStruct (t_pers *p, long dni)
{
	p->dni = dni;
	printf("Nombre: ");
	fflush(stdin);
	scanf("%c",p->nombre);
	printf("\nApellido: ");
    fflush(stdin);
	scanf("%c",p->apellido);
	/*printf("\nFecha Nac:\n---dia: ");
	fflush(stdin);
	scanf("%d",p->fech.dia);
	printf("\n---mes: ");
	fflush(stdin);
	scanf("%d",p->fech.mes);
	printf("\n---anio: ");
	fflush(stdin);
	scanf("%d",p->fech.anio);*/
}

//--mostrarSruct--//
void mostrarSruct (t_pers *p)
{
	printf("       Nombre       |       Apellido       |    Dni    |    Fecha Nac\n");
    printf("%20c %20c %08d \n", p->nombre, p->apellido, p->dni);
}
