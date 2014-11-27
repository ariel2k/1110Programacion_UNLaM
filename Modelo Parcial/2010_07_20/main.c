#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    FILE *archEnt, *archSal = fopen("SALIDA.txt","wt");
    t_arbol arbol;
    int linea=1;
    t_reg registros;
    crearBinario();
    crearArbol(&arbol);
    if(abrirArchivo(&archEnt, n_arch, "r+b", CON_MSJ))
        mostrarArchivo(archEnt);

    while(!feof(archEnt))
    {
        fread(&registros, sizeof(t_reg), 1, archEnt);
    	if(registros.saldo==0.0 || registros.estado!='B') //Condiciones para guardar en arbol
    	{
    		ponerEnArbol(&arbol,&registros,linea);
            actualizarEstado(archEnt, registros);
    	}
    	linea++;
    }
    if(abrirArchivo(&archEnt, n_arch, "r+b", CON_MSJ))
        mostrarArchivo(archEnt);

    enOrden(&arbol, archSal);
    fclose(archSal);
    fclose(archEnt);
    return 0;
}
