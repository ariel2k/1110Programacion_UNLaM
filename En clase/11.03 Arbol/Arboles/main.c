#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"

int main()
{
    FILE *archivo = fopen("arbol_arch","wb");
    t_info datos[]= {
                    {4},{7},{9},{2},{0},{1},{6},{8},{3}};

    if(archivo!=NULL)
    {
        fwrite(&datos,sizeof(datos),1,archivo);
        fclose(archivo);
    }

    t_arbol arb;
    t_info info;
    int dato=5;

    crearArbol(&arb);
    archivo = fopen("arbol_arch","rb");
    fread(&info,sizeof(t_info),1,archivo);
    while(!feof(archivo))
    {
        if(!ponerEnArbol(&arb,&info))
            printf("ERROR, NO SE PUDO PONER EN ARBOL");

        fread(&info,sizeof(t_info),1,archivo);
    }
    fclose(archivo);
    ponerEnArbol(&arb,&dato);

    enOrden(&arb);
    // printf("\n\n La cantidad de nodos internos es : %d \n", contarNodosInternos(&arb));
    if(esArbolAVL(&arb))
        printf("\nES");
    else
        printf("\nNO ES");
    printf("\n %d", contarNodosRamaIzquierda(&arb));

    return 0;
}
