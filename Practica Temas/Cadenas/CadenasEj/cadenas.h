#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/* Macro remplazos */
#define esBlanco(X) ((X)==' '|| (X)=='\t'?1:0)
#define aMayusc(X) ((X)>='a' && (X) <='z' ? (X)-32 : (X))
#define aMinusc(X) ((X)>='A' && (X) <='Z' ? (X)+32 : (X))
#define esDigito(x) ((x)>='0' && (x)<='9' ? 1: 0)

/* Funciones */
int esPalindromo(const char *s);
char *copiarCadena(char *dest, const char *orig);
int compararCadena(const char *s1, const char *s2); // <-- Duda: si está bien hecha.
char *normalizar(char *cad);
int aEntero(const char *cad);

#endif // CADENAS_H_INCLUDED
