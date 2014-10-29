#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	long dni;
	char apyn[36];
	char sex;
}t_info;

typedef struct s_nodo
{
	t_info info;
	struct s_nodo *sig;
}t_nodo, *t_lista;

void crearLista (t_lista *);
int  ListaLlena (const t_lista *);

int main ()
{
    t_lista lista;
	crearLista(&lista);
	if(!listaLlena(&lista))
        printf("Lista Vacia");
    else
        printf("Lista Llena");
	return 0;
}

void crearLista (t_lista *p)
{
	*p = NULL;
}

int listaLlena (const t_lista *p)
{
	t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo));
	free(aux);
	return aux == NULL;
}
