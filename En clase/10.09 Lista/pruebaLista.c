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


/* Eliminar nodos de X clave */
//La lista no esta ordenada por la clave que queres eliminar
int eliminarClave_desordenado(t_lista *p, const t_info *d) 
{
	t_nodo *aux;
	int cant=0;
	
	while(*p)
	{
		if(comparar(&(*p)->info, d) == 0)
		{
			aux = *p;
			*p = aux->sig;
			free(aux);
			n++;
		}
		else
			p=&(*p)->sig;
	}

	return n;
}

int eliminarClave_ordenado(t_lista *p, const t_info *d) 
{
	t_nodo *aux;
	int cant=0;

	while(*p && comparar(d, &(*p)->si) > 0)
		p=&(*p)->sig;

	while(*p && comparar(d, &(*p)->si)==0)
	{
		aux = *p;
		*p = aux->sig;
		free(aux);
		n++;
	}

	return n;
}