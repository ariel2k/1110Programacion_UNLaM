#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"

int main()
{
    // varialbes
	FILE *fpBin=fopen(nombreBinario,modo_binario),
		 *fpTxt=fopen(nombreTexto, modo_texto);

	llenarBinario();

	if (abrirArchivo(&fpBin, nombreBinario, "rb", CON_MSJ)) //Si puede abrir archivo, que lo muestre
		mostrarArchivoBinario(fpBin);

	if (abrirArchivo(&fpTxt, nombreTexto, "rt", CON_MSJ))	//Si puede abrir archivo, que lo muestre
		mostrarArchivoTexto(fpTxt);

    // fin
	fclose(fpBin);
	fclose(fpTxt);
	system("pause");
	return 0;
}

