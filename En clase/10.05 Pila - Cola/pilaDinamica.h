#ifndef PILA_H
#define PILA_H

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Directiva free.
#include "personas.h"

/* Macro remplazos */
#define t_info t_pers
#define TAM_PILA 5

/* Structs */
typedef struct s_nodo
{
	t_info info[TAM_PILA];
	struct s_nodo *sig;
}t_nodo, *t_pila;

/* Prototipos */
void crearPila 	 (t_pila *);
int  pilaLlena 	 (const t_pila *);
int  ponerEnPila (t_pila *, const t_info *);
int  pilaVacia 	 (const t_pila *);
int  verTope 	 (const t_pila *, t_info *);
int  sacarDePila (t_pila *, t_info *);
void vaciarPila  (t_pila *);

#endif