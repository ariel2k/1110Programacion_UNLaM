#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"

int llenarArbol (t_arbol *p);
void llenarArbolAutomatico (t_arbol *p);

int main()
{
    t_arbol arbol;
    int cant=11, op, alturaPodar;
    crearArbol(&arbol);
    //cant = llenarArbol(&arbol);
    llenarArbolAutomatico (&arbol);
    printf( "\n\n------Ingreso finalizado------\n"
            "//Cantidad de nodos: %d\n\n", cant);
    do{
        printf("-------Menu-------\n"
           "1-Muestre los nodos hoja.\n"
           "2-Muestre los nodos no-hoja.\n"
           "3-Muestre los nodos que sólo tienen hijo por izquierda.\n"
           "4-Muestre los nodos que tienen hijo por izquierda.\n"
           "5-Determine si es un arbol semi balanceado (AVL).\n"
           "6-Determine si es un arbol balanceado.\n"
           "7-Elimine todos los nodos de un arbol.\n"
           "8-'Pode' las ramas de un arbol de modo que no supere una altura determinada.\n"
           "9-'Pode' las ramas de un arbol de una altura determinada o inferior.\n"
           "------------------\n"
           "Opcion: ");
        scanf("%d",&op);
        switch(op){
          case 0:
            printf("            =================Muestra arbol=================\n");
            printf("En orden: \n");
            enOrden(&arbol);
            printf("            ===============================================\n");
            printf("Pre Orden: \n");
            preOrden(&arbol);
            printf("            ===============================================\n");
            printf("Pos Orden: \n");
            posOrden(&arbol);
            printf("            ===============================================\n");
            printf("\n\n\n\n\n\n\n\n"
                   "            =================Programa finalizado=================\n"
                   "           |                                                     |\n"
                   "           |         Programa realizado por Molina Ariel.        |\n"
                   "           |                                                     |\n"
                   "           |             facebook.com/ariel.molina.h             |\n"
                   "           |             twitter.com/ariel2k                     |\n"
                   "           |                                                     |\n"
                   "            =====================================================\n"
                   "\n\n\n\n\n\n\n"
                   );
            break;
          case 1:
            printf("\n=================Nodos hoja=================\n");
            mostrarNodosHojas(&arbol);
            printf("============================================\n\n");
            break;
          case 2:
            printf("\n=================Nodos NO hoja=================\n");
            mostrarNodosNoHojas(&arbol);
            printf("===============================================\n\n");
            break;
          case 3:
            printf("\n=================Solo Hijos por izquierda=================\n");
            mostrarNodosSoloHijosXIzq(&arbol);
            printf("==========================================================\n\n");
            break;
          case 4:
            printf("\n=================Hijos por izquierda=================\n");
            mostrarNodosHijosXIzq(&arbol);
            printf("=====================================================\n\n");
            break;
          case 5:
            printf("\n=================Arbol AVL (semi-balanceado)=================\n");
            if(esArbolAVL(&arbol)!=0)
              printf("Es arbol AVL\n");
            else
              printf("No es arbol AVL\n");
            printf("=============================================================\n\n");
            break;
          case 6:
            printf("\n=================Es arbol Balanceado=================\n");
            if(esArbolBalanceado(&arbol))
              printf("Es arbol Balanceado\n");
            else
              printf("No es arbol Balanceado\n");
            printf("=====================================================\n\n");
            break;
          case 7:
            printf("\n=================Vaciar arbol=================\n");
            vaciarArbol(&arbol);
            printf("Arbol Vacio\n");
            printf("===============================================\n\n");
            break;
          case 8:
            printf("\n=================Podar Arbol altura N=================\n");
            printf("Ingrese a que altura N quiere podar el arbol: ");
            scanf("%d", &alturaPodar);
            podarAAlturaX(&arbol, alturaPodar);
            printf("Arbol podado\n");
            printf("=======================================================\n\n");
            break;
          case 9:
            printf("\n=================Podar Ramas a altura N=================\n");
            printf("Ingrese a que altura N quiere podar la rama: ");
            scanf("%d", &alturaPodar);
            podarRamasAlturaX(&arbol, alturaPodar);
            printf("Ramas de Arbol podado\n");
            printf("========================================================\n\n");
            break;
          default:
            printf("\n=================Opcion incorrecta=================\n");
            printf("=================Opcion incorrecta=================\n");
            printf("=================Opcion incorrecta=================\n\n");
            break;
        }
    }while(op!=0);

    return 0;
}

/*
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
}*/

void llenarArbolAutomatico (t_arbol *p)
{
    int i=0;
    t_info aux[]={
                 {500,"Ariel","Jefe"},
                 {250,"Fede","Gerente"},
                 {100,"Nico","Lider"},
                 {20,"Mati","Jr."},
                 {10,"Ivan","Op."},
                 {300,"Lucas","Lider"},
                 {290,"Mica","Jr."},
                 {750,"Gaby","Gerente"},
                 {600,"Augusto","Lider"},
                 {560,"Rocio","Jr."},
                 {800,"Cami","Lider"}
                 };
    while(i<11)
    {
        ponerEnArbol(p,&aux[i]);
        i++;
    }
}
