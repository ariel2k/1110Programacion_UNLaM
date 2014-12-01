#ifndef ARCHIVOSTEXTO_H_INCLUDED
#define ARCHIVOSTEXTO_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define CON_MSJ 1

typedef struct
{
	long dni;
	char apyn[13];
	int edad;
}t_pers;

int abrirArchivo (FILE **fp, const char *nombre, const char *modo, int conSin);

int leerYMostrarEstatico(FILE *fp);
int leeryMostrarDinamico(FILE *fp);

int validarCampos (const char *s, char sep, int cant);

#endif // ARCHIVOSTEXTO_H_INCLUDED
