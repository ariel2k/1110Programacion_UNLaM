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

	while(fgets(aux, sizeof(t_reg), fp))
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

int buscarEnArchivo(FILE *fp, t_reg *d, int nReg) //busca en archivo y devuelve la info del registro
{
    fseek(fp, sizeof(t_reg), SEEK_SET);  //Si el primer registro es el numero 1 y no 0, va el nReg-1
    fread(d, sizeof(t_reg), 1, fp);
    return !feof(fp); //si se dio fin de archivo, es porque no pudo leer
}
