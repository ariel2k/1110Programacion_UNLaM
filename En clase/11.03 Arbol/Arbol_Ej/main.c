#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"

int llenarArbol (t_arbol *p);

int main()
{
    t_arbol arbol;
    int cant, op;
    crearArbol(&arbol);
    cant = llenarArbol(&arbol);
    printf( "\n\n------Ingreso finalizado------\n"
            "//Cantidad de nodos: %d\n\n", cant);
    do{
        printf("-------Menu-------\n"
           "1-Muestre los nodos hoja.\n"
           "2-Muestre los nodos no-hoja.\n"
           "3-Muestre los nodos que sólo tienen hijo por izquierda.\n"
           "4-Muestre los nodos que tienen hijo por izquierda.\n"
           "5-Determine si es un nodo arbol.\n"
           "6-Determine si es un arbol balanceado.\n"
           "7-Elimine todos los nodos de un arbol.\n"
           "8-'Pode' las ramas de un arbol de modo que no supere una altura determinada.\n"
           "9-'Pode' las ramas de un arbol de una altura determinada o inferior.\n"
           "------------------\n"
           "Opcion: ");
          switch(op){
          case 1:

            break;
          case 2:
            break;
          case 3:
            break;
          case 4:
            break;
          case 5:
            break;
          case 6:
            break;
          case 7:
            break;
          case 8:
            break;
          case 9:
            break;
          default:
            break;
          }
        scanf("%d",&op);
    }while(op!=0);

    return 0;
}

int llenarArbol (t_arbol *p)
{
    int cant=0;
    t_info aux;
    printf("////////Llenar Arbol////////\n//Fin ingreso: LEGAJO=0\n\n");
    printf("-------------------Nodo nro %d\n",cant+1);
    printf("Legajo: ");
    scanf("%d", &aux.legajo);
    while(aux.legajo!=0)
    {
        printf("Apyn: ");
        fflush(stdin);
        gets(aux.apyn);
        printf("Cargo: ");
        fflush(stdin);
        gets(aux.cargo);
        ponerEnArbol(p,&aux);
        ++cant;
        printf("\n-------------------Nodo nro %d\n",cant+1);
        printf("Legajo: ");
        scanf("%d", &aux.legajo);
    }
    return cant;
}
