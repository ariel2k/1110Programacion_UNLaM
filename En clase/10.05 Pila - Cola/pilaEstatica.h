#ifndef PILA_H
#define PILA_H

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "pilaEstatica.c"

/* Macro remplazos */
//#define t_info t_pers
#define TAM_PILA 5

/* Structs */
//typedef t_pers t_info;
typedef struct s_nodo
{
	t_info info[TAM_PILA];
	int tope;
}t_pila;

/* Prototipos */
void crearPila 	 (t_pila *);
int  pilaLlena 	 (const t_pila *);
int  ponerEnPila (t_pila *, const t_info *);
int  pilaVacia 	 (const t_pila *);
int  verTope 	 (const t_pila *, t_info *);
int  sacarDePila (t_pila *, t_info *);
void vaciarPila  (t_pila *);

#endif
