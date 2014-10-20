#include <stdio.h>
#define TAM_PILA 5

typedef struct
{
	int dni;
	char apyn[36];
	char sex;
}t_info;

typedef struct s_nodo
{
	t_info info[TAM_PILA];
	int tope;
}t_pila;

void crearPila 	 (t_pila *);
int  pilaLlena 	 (const t_pila *);
int  ponerEnPila (t_pila *, const t_info *);
void vaciarPila  (t_pila *);
void pedirDatos (t_info *p);

int main ()
{
	t_info info; //Datos
	t_pila pila; //Paquete: Datos + Sig

	crearPila(&pila);
	while(!pilaLlena(&pila))
	{
		pedirDatos(&info); //Llena los datos en la estructura info
		if (!ponerEnPila(&pila, &info))
		{
			printf("ERROR\n");
			return 2;
		}
		else
			printf("Ingreso exitoso\n");
	}
	return 0;
}

/*--Funciones--*/

void crearPila 	 (t_pila *p)
{
	p->tope = 0;
}

int  pilaLlena 	 (const t_pila *p)
{
	return p->tope == TAM_PILA;
}

int  ponerEnPila (t_pila *p, const t_info *d)
{
	if(p->tope == TAM_PILA)
		return 0;
	p->info[p->tope] = *d;
	p->tope++;
	return 1;
}

void pedirDatos (t_info *p)
{
	int dni;

	printf("----Ingresar Datos----\n");
	printf("DNI: ");
	scanf("%d",p->dni);
	printf("Apellido y nombre: ");
	fflush(stdin);
	scanf("%s",p->apyn);
	printf("Sexo: ");
	fflush(stdin);
	scanf("%c",p->sex);

	p++;
}
