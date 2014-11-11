#include <stdio.h>
#include <stdlib.h>
#define nomBin "RegistrosBin.bin"
#define nomText "RegistrosText.txt"
#define TAM 300
#define CON_MSJ 1

typedef struct
{
	long dni;
	char apyn[36];
	char sex;
}t_pers;

void crearBinario (char *nombre);
void crearText (char *nombre);
int abrirArchivo (FILE **fp, char *nombre, char *modo, int msj);
void mostrarBin (FILE *fp);
void mostrarText (FILE *fp);

int main ()
{
	// varialbes
	FILE *fpABinario,
		 *fpATexto;

	// programa
	// crearBinario(nomBin);
	crearText(nomText);

	/*if(abrirArchivo(&fpABinario, nomBin, "rb", CON_MSJ))
		llenarBinario(&fpABinario);*/

	if(abrirArchivo(&fpATexto, nomText, "rt", CON_MSJ))
		llenarText(fpATexto);

	//mostrarArchivoBinario(fpABinario);
	mostrarArchivoTexto(fpATexto);

	// fin
	fclose(fpABinario);
	fclose(fpATexto);
	system("pause");
	return 0;
}

void crearBinario (char *nombre)
{
	FILE *fp = fopen(nombre, "wb");
}

void crearText (char *nombre)
{
	FILE *fp = fopen(nombre, "wt");
}

int abrirArchivo (FILE **fp, char *nombre, char *modo, int msj)
{
	if(*fp==NULL && CON_MSJ == msj)
		printf("Error al abrir '%s' en modo '%s'.\n", nombre, modo);

	return *fp!=NULL;
}
/*
void llenarBinario (FILE **fp)
{
	t_pers aux;
	long dni;

	printf("-----Ingreso de datos------\nDNI:0 (FIN INGRESO)\n");
	printf("//--DATOS--//\n");
	printf("DNI: ");
	scanf("%ld", dni);
	while (dni != 0)
	{
		aux.dni = dni;
		printf("NOMBRE: ");
		gets(aux.apyn);
		printf("\nSEXO: ");
		sscanf("%c", aux.sex);
		fwrite(aux, sizeof(aux), 1, fp);
		printf("\n//--DATOS--//\n");
		printf("DNI: ");
		scanf("%ld", dni);
	}
}
*/
void llenarText (FILE *fp)
{
	long dni;
	char apyn[36];
	char sex;

	printf("-----Ingreso de datos------\nDNI:0 (FIN INGRESO)\n");
	printf("//--DATOS--//\n");
	printf("DNI: ");
	scanf("%ld", dni);
	while (dni != 0)
	{
		printf("NOMBRE: ");
		gets(apyn);
		printf("\nSEXO: ");
		sscanf("%c", sex);
		fprintf(fp, "%08ld %-s %c", dni, apyn, sex);
		printf("\n//--DATOS--//\n");
		printf("DNI: ");
		scanf("%ld", dni);
	}
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
	char aux[TAM];
    rewind(fp);
	printf("----RegistrosTexto----\n");

	while(fgets(aux, sizeof(t_pers), fp))
		printf("%s", aux);

}
