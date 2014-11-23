#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"

int main()
{
	// varialbes
	FILE *fpABinario,
		 *fpATexto;

	// programa
	crearBinario(nomBin);
	crearText(nomText);

	if(abrirArchivo(&fpABinario, nomBin, "rb", CON_MSJ))
		llenarBinario(&fpABinario);

	if(abrirArchivo(&fpATexto, nomText, "rt", CON_MSJ))
		llenarText(fpATexto);

	//mostrarArchivoBinario(fpABinario);
	mostrarArchivoTexto(fpATexto);

	// fin
	fclose(fpABinario);
	fclose(fpATexto);
	system("pause");
	return 0;    
    return 0;
}
