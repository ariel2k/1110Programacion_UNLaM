#include <stio.h>

void crearPila 	 (t_pila *p)
{
	*p = NULL;
}

int  pilaLlena 	 (const t_pila *p)
{
	t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo));
	free(aux);
	return aux==NULL;
}

int  ponerEnPila (t_pila *p, const t_info *d)
{
	t_nodo *nue = (t_nodo *)malloc(sizeof(t_nodo));
	if (nue == NULL)
		return 0;
	nue->info = *d;
	nue->sig = *p;
	*p = nue;
	return 1;
}

int  pilaVacia 	 (const t_pila *p)
{
	return *p == NULL;
}

int  verTope 	 (const t_pila *p, t_info *d)
{
	if (*p == NULL)
		return 0;
	*d = (*p)->info;
	return 1;
}

int  sacarDePila (t_pila *p, t_info *d)
{
	t_nodo *aux = *p;
	if (*p == NULL)
		return 0;
	*d = aux->info;
	*p = aux->sig;
	free(aux);
	return 1;
}

void vaciarPila  (t_pila *p)
{
	t_nodo *aux;
	while (*p)
	{
		aux = *p;
		*p = aux->sig;
		free(aux);
	}
}