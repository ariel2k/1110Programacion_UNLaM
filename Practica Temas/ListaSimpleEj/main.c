#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void llenarLista(t_lista *p);

int main()
{
    t_lista lista;
    //t_info info;
    crearLista(&lista);
    llenarLista(&lista);
    mostrarLista_Columna(&lista);
    /*printf("\n======Eliminar Legajo======\nIngrese legajo: ");
    scanf("%d",&info.legajo);
    eliminarClave_ordenado(&lista, &info);
    mostrarLista_Columna(&lista);
    printf("\n======Eliminar Cargo======\nIngrese cargo: ");
    fflush(stdin);
    gets(info.cargo);
    eliminarClave_desordenado(&lista, &info);
    mostrarLista_Columna(&lista);
    puts("");
    puts("Eliminar Unicos: ");
    printf("%d Nodos eliminados\n", eliminarUnicos(&lista));
    mostrarLista_Columna(&lista);
    puts("");
    puts("Eliminar Duplicados: ");
    printf("%d Nodos eliminados\n", eliminarDuplicados(&lista));
    mostrarLista_Columna(&lista);
    */
    return 0;
}

void llenarLista(t_lista *p)
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
        insertarEnOrden(p,&aux[i]);
        i++;
    }
}
