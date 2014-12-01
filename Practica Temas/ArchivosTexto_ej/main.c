#include <stdio.h>
#include <stdlib.h>
#include "archivosTexto.h"

int main()
{
    FILE *fp, *fp2;

    if(abrirArchivo(&fp,"Estatico.txt","rt",1))
        leerYMostrarEstatico(fp);

    puts("");
    if(abrirArchivo(&fp2,"Dinamico.txt","rt",1))
        leeryMostrarDinamico(fp2);

    fclose(fp2);
    fclose(fp);
    return 0;
}
