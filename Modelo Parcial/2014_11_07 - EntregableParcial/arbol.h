#ifndef ARBOL_H
#define ARBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define CLA_DUP         1
#define SIN_MEM         2
#define TODO_BIEN       0

typedef struct
{
    char            clave[11];
    int             nroReg;
} t_info_arbol;

typedef struct s_nodo_arbol
{
    t_info_arbol    info;
    struct s_nodo_arbol *izq,
                        *der;
} t_nodo_arbol, *t_arbol;

int  compararXClaveArbol_2(const t_info_arbol *d1, const t_info_arbol *d2);
void crearArbol(t_arbol *p);
int  arbolLleno(t_arbol *p);
int  ponerEnArbol(t_arbol *p, const t_info_arbol *d,
                  int (*comp)(const t_info_arbol *, const t_info_arbol *));
int  buscarEnArbol(const t_arbol *p, t_info_arbol *d,
                  int (*comp)(const t_info_arbol *, const t_info_arbol *));
void vaciarArbol(t_arbol *p);
int mostraEnPreorden(const t_arbol *p, void (*mostrar)(const t_info_arbol *));
void mostrarTInfoArbol(const t_info_arbol *d);

#endif
