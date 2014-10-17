#include <stio.h>

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
	p->pila[p->tope] = *d;
	p->tope++;
	return 1;
}

int  pilaVacia 	 (const t_pila *p)
{
	return p->tope == 0;
}

int  verTope 	 (const t_pila *p, t_info *d)
{
	if(p->tope == 0)
		return 0;
	*d = p->[p->tope-1];
	return 1;
}

int  sacarDePila (t_pila *p, t_info *d)
{
	if(p->tope == 0)
		return 0;
	p->tope--;
	*d = p->pila[p->tope];
	return 1;
}

void vaciarPila  (t_pila *p)
{
	p->tope = 0;
}
