#ifndef LISTA_H
#define LISTA_H

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
}t_nodo, *t_lista;

/* Prototipos */
void crearLista(t_lista *);
int  ListaLlena(const t_lista *);
int ponerlAlComienzo(t_lista *p, const t_info *d);
int ponerAlFinal(t_lista *p, const t_info *d);
int insertarEnOrden(t_lista *p, const t_info *d, int (*comparar)(const t_info *, const t_info *));
void ordernarListaBurbu (t_lista *p);
int eliminarClave_desordenado(t_lista *p, const t_info *d);
int eliminarClave_ordenado(t_lista *p, const t_info *d);

#endif
