#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <string.h>

#include "main.h"
#include "colacirc.h"
#include "arbol.h"


typedef struct
{
    int   di;
    int   me;
    int   an;
} t_fec;


typedef struct
{
    char   clave[11];
    char   descr[43];
    int    exist;
    t_fec  fecIng;
    double precio;
    int    ptoRep;
} t_reg;

void crearArchivoCargarListaCargarArbol(t_colaC *cola, t_arbol *arbol);

int mostrarArchivo(FILE *fp);

void mostrarTReg(const t_reg *d);

void sacarDeColaCBuscarEnArbolActualizarArchivo_2(t_colaC *cola, t_arbol *arbol,
                                                 FILE *fp);
void mostrarFaltantesYReposicion_2(FILE *fp);

void mostrarArbolEnPreorden(t_arbol *arbol, void (*mostrar)(const t_info_arbol *));

#endif
