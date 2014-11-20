#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include "personas.h"

/* Macro remplazos */
#define t_info t_pers

/* Structs */
typedef struct s_nodo
{
	t_info info;
	struct s_nodo *sig;
}t_nodo, *t_cola;

/* Prototipos */
void crearCola 	 (t_cola *p);
int  colaLlena 	 (const t_cola *p);
int  ponerEnCola (t_cola *p, const t_info *d);
int  colaVacia 	 (const t_cola *p);
int  sacarDeCola (t_cola *p, t_info *d);
void vaciarCola  (t_cola *p);
int  verPrimeroCola 	 (const t_cola *p, t_info *d);

#endif // COLACIRCULAR_H_INCLUDED
