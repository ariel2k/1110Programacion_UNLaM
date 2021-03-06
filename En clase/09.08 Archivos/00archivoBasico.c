#include <stdio.h>
#define nombreBinario "archivoBinario.txt"
#define nombreTexto "archivoTexto.txt"
#define tam 200
#define CON_MSJ 1

typedef struct
{
	long dni;
	char apyn[36];
	char sex;
}t_pers;

void crearArchivoBinario ();
void crearArchivoTexto ();
int abrirArchivo (FILE **fp, const char *nombre, const char *modo, int conSin);
void mostrarArchivoBinario(FILE *);
void mostrarArchivoTexto(FILE *);

int main ()
{
	// variables
	int cant=0;
	FILE *fpBin,
		 *fpTxt;


	crearArchivoBinario(nombreBinario);
	crearArchivoTexto(nombreTexto);


	if (abrirArchivo(&fpBin, nombreBinario, "rb", CON_MSJ)) //Si puede abrir archivo, que lo muestre
		mostrarArchivoBinario(fpBin);

	if (abrirArchivo(&fpTxt, nombreTexto, "rt", CON_MSJ))	//Si puede abrir archivo, que lo muestre
		mostrarArchivoTexto(fpTxt);

	// fin
	fclose(fpTxt);
	fclose(fpBin);
	system("pause");
	return 0;
}

/*---Funciones---*/

//--crearArchivoBinario--//
void crearArchivoBinario ()
{
	FILE *fp = fopen(nombreBinario, "wb");

	t_pers registros[]={
		{1122333, "Sa, Lia", 'F'},
		{4455666, "Lo, Pepe", 'M'},
		{1234124, "Cb, rde", 'M'}};

	if(fp!=NULL)
	{
		fwrite(registros, sizeof(registros), 1, fp);
		fclose(fp);
	}

}

//--crearArchivoTexto--//
void crearArchivoTexto ()
{
	FILE *fp = fopen(nombreTexto, "wt");
	int i=0;
	t_pers registros[]={
		{8838213, "Pp, Lia", 'F'},
		{9921394, "OO, Pepe", 'M'}};

	for(i=0; i<2 ; i++)
	{
		fprintf(fp,
			"%ld %-*s %c \n",
			registros[i].dni,
			sizeof(registros[i].apyn)-1,
			registros[i].apyn,
			registros[i].sex);
	}

	fclose(fp);
}

//--abrirArchivo--//
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
