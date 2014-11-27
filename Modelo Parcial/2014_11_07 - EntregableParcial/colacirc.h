#ifndef COLACIRC_H
#define COLACIRC_H

#include <stdlib.h>
#include <stdio.h>


typedef struct
{
    char            clave[11];
    int             cantPed;
} t_info_colaC;

typedef struct s_nodo_colaC
{
    t_info_colaC            info;
    struct s_nodo_colaC    *sig;
} t_nodo_colaC, *t_colaC;

void crearColaC(t_colaC *p);
int  colaCLlena(const t_colaC *p);
int  ponerEnColaC(t_colaC *p, const t_info_colaC *d);
int  colaCVacia(const t_colaC *p);
int  sacarDeColaC(t_colaC *p, t_info_colaC *d);
void mostrarTInfoColaC(const t_info_colaC *d);
#endif
