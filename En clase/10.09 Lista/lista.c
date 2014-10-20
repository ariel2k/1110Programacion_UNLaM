void crearLista 	 (t_lista *p)
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
	if(*p==NUL)
		return 0;
	(*p)->info = *d;
	(*p)->sig = NULL;
	return 1;
}

int insertarEnOrden  (t_lista *p, const t_info *d, int (*comparar)(const t_info *, const t_info *))
{
	t_nodo *nue;
	while (*p && comparar(d, &(*p)->info)>0)
		p = &(*p)->sig;
	if(*p && comparar(d,&(*p)->infor)==0)
	{
		acumular(&(*p)->info,d);
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

void ordernarListaBurbu (t_lista *p)
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
				if(compara(&(*p)->info, &(*q)->info)>0)
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
}