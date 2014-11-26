#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define CLA_DUP 1
#define SIN_MEM -1
#define TODO_BIEN 0
#define n_arch "Registros.bin"
#define m_arch "wb"
#define CON_MSJ 1
//Parcial obtenido de: https://www.dropbox.com/sh/9bszozcz587y8nr/AABAOQ84WVpvRQcGU0j5umeoa/Programaci%C3%B3n%20II/2do%20parcial/P_2010_RP2_02.doc?dl=0

typedef struct{
	int di, me, an;
}t_fecha;

typedef struct{
	int nro_cta;
	char nombre_titular[30];
	t_fecha fch_alta,
			fch_ult_mov;
	float saldo;
	char estado;
}t_reg;

typedef struct{
	int nro_cta,
		nro_reg;
}t_info;

typedef struct s_nodo
{
	t_info info;
	struct  s_nodo *izq,
				   *der;
}t_nodo, *t_arbol;

/* Árbol */
void crearArbol(t_arbol *p);
void enOrden(const t_arbol *p, FILE *pf);
int ponerEnArbol(t_arbol *p, const t_reg *d,const int linea);
int comparar(const t_info *d1, const t_reg *d2);
void verNodo(const t_arbol *p);

/* Archivos */
void crearBinario();
int actualizarEstado(FILE *pf, t_reg d);
int abrirArchivo(FILE **pf, const char *nombre, const char *modo, int MSJ);
//int guardar(FILE *pf, t_info *d);
void mostrarArchivo (FILE *fp);

#endif // ARBOL_H_INCLUDED
