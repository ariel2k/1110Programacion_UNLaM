#include "colaCircular.h"

void crearCola 	 (t_cola *p)
{
	*p = NULL;
}

int  colaLlena 	 (const t_cola *p)
{
	t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo));
	free(aux);
	return aux==NULL;
}

int  ponerEnCola (t_cola *p, const t_info *d)
{
	t_nodo *nue = (t_nodo *)malloc(sizeof(t_nodo));
	if(nue==NULL)
		return 0;

	nue->info = *d;
	if (*p == NULL) //Si es el primer nodo que entra
		nue->sig = nue; //Se apunta a él mismo
		(*p) = nue;
	else //sino
	{
		(*p)->sig = nue; //el 'sig' de 'p' apunta al nuevo nodo creado
		nue->sig = *p; //el 'sig' de 'nue' apunta a la dirección de 'p'
		*p = nue; //p apunta al último
	}
	return 1;
}

int  colaVacia 	 (const t_cola *p)
{

}

int  sacarDeCola (t_cola *p, t_info *d)
{

}

void vaciarCola  (t_cola *p)
{

}

int  verPrimeroCola 	 (const t_cola *p, t_info *d)
{
	if((*p)->sig)
	*d = &(*p)->sig;
}
