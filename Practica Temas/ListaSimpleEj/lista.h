#ifndef LISTA_H
#define LISTA_H

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macro remplazos*/
#define CLA_DUP 4
#define SIN_MEM 5
#define TODO_BIEN 1

/* Structs */
typedef struct
{
    int  legajo;
    char apyn[35],
         cargo[15];
}t_info;

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
int insertarEnOrden(t_lista *p, const t_info *d);
//void ordernarListaBurbu (t_lista *p);
int eliminarClave_desordenado(t_lista *p, const t_info *d);
int eliminarClave_ordenado(t_lista *p, const t_info *d);
void mostrarLista_Columna(const t_lista *p);
int compararINT(const int d1, const int d2);
int compararCHAR(const char *s1, const char *s2);
int eliminarUnicos(t_lista *p);
int eliminarDuplicados(t_lista *p);

#endif
