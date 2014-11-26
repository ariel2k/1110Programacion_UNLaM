#include "archivos.h"

//--abrirAchivo--//
int abrirArchivo (FILE **fp, const char *nombre, const char *modo, int conSin)
{
	*fp=fopen(nombre, modo);

	if(*fp==NULL && conSin == CON_MSJ)
		fprintf(stderr, "Error abriendo '%s' en modo '%s' \n", nombre, modo);

	return *fp!=NULL;
}

//--mostrarArchivoBinario--//
void mostrarArchivoBinario (FILE *fp)
{
	t_pers aux;
    rewind(fp);
	printf("----RegistrosBinarios----\n");
	while(fread(&aux, sizeof(t_pers), 1, fp))
		printf("%ld %s %c\n",aux.dni, aux.apyn, aux.sex );

}

//--mostrarArchivoTexto--//
void mostrarArchivoTexto (FILE *fp)
{
	char aux[tam];
    rewind(fp);
	printf("----RegistrosTexto----\n");

	while(fgets(aux, sizeof(t_pers), fp))
		printf("%s", aux);
}

int llenarBinario()
{
    FILE *fp=fopen(nombreBinario, modo_binario);

	t_pers aux[]={
				{311, "Ariel Molina", 'M'},
				{222, "Karen Molina", 'F'}};
	if(fp!=NULL)
	{
		fwrite(aux, sizeof(aux), 1, fp);
		fclose(fp);
	}

	return 0;
}
