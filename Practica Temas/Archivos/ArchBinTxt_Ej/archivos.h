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
