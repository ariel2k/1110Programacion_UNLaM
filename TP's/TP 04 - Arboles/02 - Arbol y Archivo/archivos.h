#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#define nombreBinario "archivoBinario.txt"
#define nombreTexto "Registros.txt"
#define modo_binario "wb"
#define modo_texto "rt"
#define CON_MSJ 1
#define tam 200
#include "arbol.h"

typedef struct
{
	long dni;
	char apyn[36];
	char sex;
}t_pers;

int abrirArchivo (FILE **fp, const char *nombre, const char *modo, int conSin);
void mostrarArchivoBinario(FILE *);
void mostrarArchivoTexto(FILE *);
int llenarBinario();

int buscarEnArchivo(FILE *fp, t_reg *d, int nReg);

#endif // ARCHIVOS_H_INCLUDED
