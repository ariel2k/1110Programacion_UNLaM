#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

#define absoluto(x) ((x)<0? -(x):(x))

//////////////////////////
void crearArbol(t_arbol *p)
{
    *p= NULL;
}
///////////////////////////
void enOrden( const t_arbol *p)
{
    if(*p)
    {
        enOrden(&(*p)->izq);
        verNodo(&(*p)->info);
        enOrden(&(*p)->der);
    }
}
////////////////////////////////
void preOrden( const t_arbol *p)
{
    if(*p)
    {
        verNodo(&(*p)->info);
        preOrden(&(*p)->izq);
        preOrden(&(*p)->der);
    }
}
///////////////////////////////
void posOrden( const t_arbol *p)
{
    if(*p)
    {
        posOrden(&(*p)->izq);
        posOrden(&(*p)->der);
        verNodo(&(*p)->info);
    }
}
///////////////////////////////
int ponerEnArbol(t_arbol *p, const t_info *d)
{
    int cmp;
    while(*p)
    {
        cmp = comparar(d,&(*p)->info);      //  <--- ¿Por qué "d" sin & y el otro con?
        if(cmp == 0)
            return CLA_DUP;
        if(cmp < 0)
            p = &(*p)->izq;
        else
            p = &(*p)->der;
    }
    *p = (t_nodo *) malloc(sizeof(t_nodo));
    if(*p == NULL)
        return SIN_MEM;
    (*p)->info = *d;
    (*p)->izq = NULL;
    (*p)->der = NULL;

    return TODO_BIEN;
}
///////RECURSIVA/////////
int ponerEnArbolR(t_arbol *p, const t_info *d)
{
    int cmp;
    if(*p)
    {
        cmp = comparar(d,&(*p)->info);
        if(cmp == 0)
            return CLA_DUP;
        if(cmp < 0)
            return ponerEnArbolR(&(*p)->izq,d);
        else
            return ponerEnArbolR(&(*p)->der,d);
    }
    *p = (t_nodo *) malloc(sizeof(t_nodo));
    if(*p == NULL)
        return SIN_MEM;
    (*p)->info = *d;
    (*p)->izq = NULL;
    (*p)->der = NULL;

    return TODO_BIEN;
}
///////////////////////////////
int alturaArbol(const t_arbol *p)
{
    if(*p)
    {
        int hi = alturaArbol(&(*p)->izq),
            hd = alturaArbol(&(*p)->der);

        return hi>=hd ? hi+1 : hd+1;  //ir contando cada vez que llego a una hoja
    }
    return 0;
}
//////////////////////////////
int contarNodosArbol(const t_arbol *p)
{
    if(*p)
        return contarNodosArbol(&(*p)->izq) + contarNodosArbol(&(*p)->der) + 1;
    return 0;
}
//////////////////////////////
int esCompleto(const t_arbol *p)
{
    int h= alturaArbol(p),
        c= contarNodosArbol(p);

    return dosAlaH(h)-1 == c;
}
/////////////////////////////
int dosAlaH (int h)
{
    int acum=1;
    while(h)
    {
        acum*=2;
        h--;
    }
    return acum;
}
/////OTRA FORMA/////////////
int esArbolCompleto(const t_arbol *p)
{
    int h= alturaArbol(p);

    return verSiEsCompleto(p,h);
}
////////////////////////////
int verSiEsCompleto(const t_arbol *p, int h) /**/
{
    if(*p)
        return verSiEsCompleto(&(*p)->izq, h-1) && verSiEsCompleto(&(*p)->der, h-1);

    return h==0;
}
////////////////////////////
int esBalanceado(const t_arbol *p)
{
    int h= alturaArbol(p),
        c= contarNodosHastaHmenos1(p,h);

    return dosAlaH(h-1)-1 == c;
}
///////////////////////////
int contarNodosHastaHmenos1(const t_arbol *p, int h)
{
    if(*p && h>1)
        return contarNodosHastaHmenos1(&(*p)->izq, h-1) + contarNodosHastaHmenos1(&(*p)->der, h-1) + 1;

    return 0;
}
/////OTRA MANENA////////////
int esArbolBalanceado(const t_arbol *p)
{
    int h= alturaArbol(p);

    return verSiEsBalanceado(p,h);
}
////////////////////////////
int verSiEsBalanceado(const t_arbol *p, int h)
{
    if(*p)
        return verSiEsBalanceado(&(*p)->izq, h-1) && verSiEsBalanceado(&(*p)->der, h-1);

    return h<=1;
}
////////////////////////////
int esArbolAVL( const t_arbol *p)
{
    if(*p)
    {
        int dif = alturaArbol(&(*p)->izq) - alturaArbol(&(*p)->der);

        if(absoluto(dif)>1)
            return 0;

        return esArbolAVL(&(*p)->izq) && esArbolAVL(&(*p)->der);
    }
    return 1;
}
////////////////////////////
int contarHojas(const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq == (*p)->der)  //cuando son iguales es xq es una hoja y del lado izq y derecho son nulos
            return 1;
        return (contarHojas(&(*p)->izq) + contarHojas(&(*p)->der));
    }
    return 0;
}
////////////////////////////
int contarNodosInternos(const t_arbol *p)
{
    if(*p)
        return contarNodosInternos(&(*p)->izq) + contarNodosInternos(&(*p)->der) + ((*p)->izq && (*p)->der); //el ultimo termino es el que va acumulando

    return 0;
}
////////////////////////////
int contarNodosRamaIzquierda(const t_arbol *p)
{
    if(*p)
        return contarNodosArbol(&(*p)->izq);

    return 0;
}
////////////////////////////
void vaciarArbol(t_arbol *p)
{
    if(*p)
    {
        vaciarArbol(&(*p)->izq);
        vaciarArbol(&(*p)->der);
        free(*p);
        *p=NULL;
    }
}
////////////////////////////
int vaciarArbolYContar(t_arbol *p)
{
    if(*p)
    {
        int cant = vaciarArbolYContar(&(*p)->izq) + vaciarArbolYContar(&(*p)->der);
        free(*p);
        *p=NULL;

        return cant+1;
    }
    return 0;
}
///////////////////////////
int vaciarArbolMostrarEnOrdenGrabarEnPreYContar(t_arbol *p)//, FILE *fp)
{
    int cant;
    if(*p)
    {
        // fwrite(&(*p)->info, sizeof(t_info),1,fp);
        cant = vaciarArbolMostrarEnOrdenGrabarEnPreYContar(&(*p)->izq); //, fp);
        mostrar(&(*p)->info);
        cant += vaciarArbolMostrarEnOrdenGrabarEnPreYContar(&(*p)->der); //, fp);
        free(*p);
        *p = NULL;
        return cant+1;
    }
    return 0;
}
//////////////////////////
void mostrar(t_info *d)
{
    printf(" %c |", (*d).n );
}
//////////////////////////
void verNodo(t_info *d)
{
    printf(" %d |", (*d).n );
}
//////////////////////////
int comparar(const t_info *d1,const t_info *d2)
{
    return ((*d1).n - (*d2).n);
}

////////////////////
/**FUNCION MATI**/
/*
int contIzquierda(t_arbol *p)
{
    if(*p)
        {
            int cant = contIzquierda(&(*p)->izq)+contIzquierda(&(*p)->der) + p->izq != NULL;
            return cant;
        }
    return cant;
}
*/
