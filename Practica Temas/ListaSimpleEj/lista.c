#include "lista.h"


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

int ponerlAlComienzo (t_lista *p, const t_info *d)
{
	t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo));
	if (aux==NULL)
		return 0;
	aux->info = *d;
	aux->sig = *p;
	*p = aux;
	return 1;
}

int ponerAlFinal 	 (t_lista *p, const t_info *d)
{
	while(*p)
		p=&(*p)->sig;
	*p=(t_nodo *)malloc(sizeof(t_nodo));
	if(*p==NULL)
		return 0;
	(*p)->info = *d;
	(*p)->sig = NULL;
	return 1;
}

int insertarEnOrden  (t_lista *p, const t_info *d)
{
	t_nodo *nue;
	while (*p && compararINT(d->legajo, (*p)->info.legajo)>0)
		p = &(*p)->sig;
	if(*p && compararINT(d->legajo,(*p)->info.legajo)==0)
	{
		//acumular(&(*p)->info,d);
		return CLA_DUP;
	}
	nue=(t_nodo *)malloc(sizeof(t_nodo));
	if(nue==NULL)
		return SIN_MEM;
	nue->info = *d;
	nue->sig = *p;
	*p=nue;
	return TODO_BIEN;
}

/*void ordernarListaBurbu (t_lista *p)
{
	int marca=1;
	t_lista *q;
	t_nodo *act;
	if (*p)
		while(marca)
		{
			marca=0;
			q=p;
			while((*p)->sig)
			{
				if(compararINT((*p)->info.legajo, (*q)->info.legajo)>0)
				{
					marca=1;
					act=*q;
					*q=act->sig;
					act->sig=(*q)->sig;
					(*q)->sig=act;
				}
				q=&(*q)->sig;
			}
		}
}*/

/* Eliminar nodos de X clave */
//La lista no esta ordenada por la clave que queres eliminar
int eliminarClave_desordenado(t_lista *p, const t_info *d)
{
	t_nodo *aux;
	int cant=0;

	while(*p)
	{
		if(compararCHAR((*p)->info.cargo, d->cargo) == 0)
		{
			aux = *p;
			*p = aux->sig;
			free(aux);
			cant++;
		}
		else
			p=&(*p)->sig;
	}

	return cant;
}

int eliminarClave_ordenado(t_lista *p, const t_info *d)
{
	t_nodo *aux;
	int n=0;

	while(*p && compararINT((*p)->info.legajo, d->legajo) != 0)
		p=&(*p)->sig;

	while(*p && compararINT((*p)->info.legajo, d->legajo)==0)
	{
		aux = *p;
		*p = aux->sig;
		free(aux);
		n++;
	}

	return n;
}

int listaVacia (t_lista *p)
{
	return *p==NULL;
}

void mostrarLista_Columna(const t_lista *p)
{
    int i=0;
	printf("==========================================LISTA=========================================");
	printf("\n| Legajo     Apellido y nombre                  Cargo    Dir Nodo     Dir Sig          |\n");
	while(*p)
	{
		printf("| %5d   %-35s %-9s %9p %9p %9p  |\n",
         (*p)->info.legajo, (*p)->info.apyn, (*p)->info.cargo, *p, (*p)->sig, p);
		p = &(*p)->sig;
		i++;
	}
	printf("|Total: %2d nodos en la lista.                                                          |"
        "\n----------------------------------------------------------------------------------------\n",i);
}

int compararINT(const int d1, const int d2)
{
    return d1-d2;
}

int compararCHAR(const char *s1, const char *s2)
{
    return strcmp(s1, s2);
}

int cantidadNodos(t_lista *p)
{
	int cant=0;

	while(*p)
	{
		p=&(*p)->sig;
		cant++;
	}

	return cant;
}

int eliminarUnicos(t_lista *p)
{
	t_lista *q=p;
	t_nodo *aux;
	int cant,
        CantidadNodosBorrados=0;

	while(*q)
	{
	    cant=0;
	    aux = *p;

	    while(aux && cant<2) //recorro toda la lista exceptuando el q y busco si hay una coincidencia
        {
            if(compararCHAR(aux->info.cargo, (*q)->info.cargo )==0)
                cant++;
            aux = aux->sig;
        }

        if(cant==1) //Si no hay coincidencia, se borra
        {
            aux = *q;
            *q = aux->sig;
            free(aux);
            cant=0;
            CantidadNodosBorrados++;
        }
        else
            q = &(*q)->sig;
	}

	return CantidadNodosBorrados;
}

int eliminarDuplicados(t_lista *p)
{
	t_nodo *aux;
	t_lista *q;
	int marca,
        cont=0;
	while(*p)
	{
		q = &(*p) -> sig;
	    marca = 0;
	    while(*q)
	    {
	    	if(compararCHAR((*p)->info.cargo, (*q)->info.cargo) == 0)
	    	{
	            aux = *q;
	            *q = aux -> sig;
	            free(aux);
	            marca = 1;
	            cont++;
	        }
	        else
	            q = &(*q) -> sig;
	    }
	    if(marca)
	    {
	        aux = *p;
	        *p = aux -> sig;
	        free(aux);
	        cont++;
	    }
	    else
	        p = &(*p) -> sig;
	}
	return cont;
}