#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    FILE *archEnt;
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
            registros.saldo = 100;
            registros.estado = 'B';
            fseek(archEnt,-(long)archEnt,0);
            fwrite(&registros, sizeof(t_reg),1,archEnt);
    	}
    	linea++;
    }
    fclose(archEnt);
    return 0;
}
