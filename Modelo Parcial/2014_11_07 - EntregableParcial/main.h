#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#include "colacirc.h"
#include "arbol.h"
#include "funciones.h"


#define ARCH_NOM        "maeprod"


#define CON_MSJ         1

#define CON_MACRO
#ifndef CON_MACRO
int abrirArchivo(FILE **fp, const char *nombre, const char *modo, int conSinMsj)
{
    if((*fp = fopen(nombre, modo)) == NULL)
    {
        if(conSinMsj == CON_MSJ)
            fprintf(stderr,
                    "ERROR - abriendo \"%s\" en modo \"%s\".\n",
                    nombre, modo);
        return 0;
    }
    return 1;
}
#else
/** el siguiente macro reemplaza el uso de la función;
 *      int abrirArchivo(FILE **fp, const char *nombre,
 *                       const char *modo, int conSinMsj):
 */

#define abrirArchivo(X, Y, Z, W)                                    \
    (((*(X) = fopen(Y, Z)) == NULL) ? (((W) == CON_MSJ) ?           \
           !fprintf(stderr,                                          \
                   "ERROR - abriendo \"%s\" en modo \"%s\".\n",     \
                   Y, Z) & 0 : 0)                                       \
        :                                                           \
           1 )
#endif // CON_MACRO

#endif
