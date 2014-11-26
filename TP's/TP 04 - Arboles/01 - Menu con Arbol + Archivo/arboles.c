#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

#define absoluto(x) ((x)<0? -(x):(x))


void crearArbol(t_arbol *p)
{
    *p= NULL;
}


void enOrden( const t_arbol *p)
{
    if(*p)
    {
        enOrden(&(*p)->izq);
        verNodo(&(*p)->info);
        enOrden(&(*p)->der);
    }
}


void preOrden( const t_arbol *p)
{
    if(*p)
    {
        verNodo(&(*p)->info);
        preOrden(&(*p)->izq);
        preOrden(&(*p)->der);
    }
}

void posOrden( const t_arbol *p)
{
    if(*p)
    {
        posOrden(&(*p)->izq);
        posOrden(&(*p)->der);
        verNodo(&(*p)->info);
    }
}

int ponerEnArbol(t_arbol *p, const t_info *d)
{
    int cmp;
    while(*p)
    {
        cmp = comparar(d,&(*p)->info);
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

int contarNodosArbol(const t_arbol *p)
{
    if(*p)
        return contarNodosArbol(&(*p)->izq) + contarNodosArbol(&(*p)->der) + 1;
    return 0;
}

int esCompleto(const t_arbol *p)
{
    int h= alturaArbol(p),
        c= contarNodosArbol(p);

    return dosAlaH(h)-1 == c;
}

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

int verSiEsCompleto(const t_arbol *p, int h) /**/
{
    if(*p)
        return verSiEsCompleto(&(*p)->izq, h-1) && verSiEsCompleto(&(*p)->der, h-1);

    return h==0;
}

int esBalanceado(const t_arbol *p)
{
    int h= alturaArbol(p),
        c= contarNodosHastaHmenos1(p,h);

    return dosAlaH(h-1)-1 == c;
}

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

int verSiEsBalanceado(const t_arbol *p, int h)
{
    if(*p)
        return verSiEsBalanceado(&(*p)->izq, h-1) && verSiEsBalanceado(&(*p)->der, h-1);

    return h<=1; // <-- h<=2 ^^Es balanceado cuando tiene hojas en su último nivel o nivel anterior^^
}

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

int contarNodosInternos(const t_arbol *p)
{
    if(*p)
        return contarNodosInternos(&(*p)->izq) + contarNodosInternos(&(*p)->der) + ((*p)->izq!=NULL && (*p)->der!=NULL); //el ultimo termino es el que va acumulando

    return 0;
}

int contarNodosRamaIzquierda(const t_arbol *p)
{
    if(*p)
        return contarNodosArbol(&(*p)->izq);

    return 0;
}

void vaciarArbol(t_arbol *p)
{
    FILE *fp = fopen("ELIMINADOS.TXT","a+");
    if(*p)
    {
        vaciarArbol(&(*p)->izq);
        vaciarArbol(&(*p)->der);
        fprintf(fp,"Legajo: %d | Apyn: %s | Cargo: %s | Nodo: %p //  Izq: %p | Der: %p \n",
            (*p)->info.legajo, (*p)->info.apyn, (*p)->info.cargo, *p,(*p)->izq, (*p)->der);
        free(*p);
        *p=NULL;
    }
}

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

int vaciarArbolMostrarEnOrdenGrabarEnPreYContar(t_arbol *p)//, FILE *fp)
{
    int cant;
    if(*p)
    {
        // fwrite(&(*p)->info, sizeof(t_info),1,fp);
        cant = vaciarArbolMostrarEnOrdenGrabarEnPreYContar(&(*p)->izq); //, fp);
        verNodo(&(*p)->info);
        cant += vaciarArbolMostrarEnOrdenGrabarEnPreYContar(&(*p)->der); //, fp);
        free(*p);
        *p = NULL;
        return cant+1;
    }
    return 0;
}

void verNodo(t_info *d)
{
    printf("Legajo: %d | Apyn: %s | Cargo: %s\n", (*d).legajo, (*d).apyn, (*d).cargo);
}

int comparar(const t_info *d1,const t_info *d2)
{
    return ((*d1).legajo - (*d2).legajo);
}

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

 int aQueAlturaORDENADO (const t_arbol *p, const t_info *d)
 {
    int comp;
    int h=0;

    while(*p)
    {
        cmp = comparar(d, &(*p)->info);
        h++;
        if(cmp==0)
            return h;
        if(cmp<0)
            p=&(*p)->izq;
        else
            p=&(*p)->der;
    }
    return 0;
 }

 int aQueAlturaDESORDENADO (const t_arbol *p, const t_infor *d)
 {
    return buscar(p, d, 0);
    //return buscar2(p, d, 0);
 }

 int buscar (const t_arbol *p, const t_infor *d, int h)
 {
    if(*p)
    {
        if(comparar(d, &(*p)->infor)==0)
            return h+1;
        return buscar(&(*p)->izq, d, h+1) || buscar(&(*p)->der, d, h+1);
    }
    return 0;
 }

 int buscar2 (const t_arbol *p, const t_infor *d, int h)
 {
    int cmp;
    if(*p)
    {
        cmp = comparar(d, &(*p)->infor);
        if(cmp==0)
            return h+1;

        if(cmp<0)
            buscar2(&(*p)->izq, d, h+1)
        else
            buscar2(&(*p)->der, d, h+1);
    }
    return 0;
 }


int podarAAlturaX(t_arbol *p, int h) //queres que quede a la altura 'h'
{
    if(*p)
    {
        if(h==0)
            return eliminarArbol(p);

        return podarAAlturaX(&(p)->izq, h-1) + podarAAlturaX(&(p)->der, h-1);
    }
    return 0;
}

int eliminarArbol(t_arbol *p)
{
    if(*p)
    {
        int cant = eliminarArbol(&(p)->izq) + eliminarArbol(&(*p)->der);
        free(*p);
        *p=NULL;
        return cant+1;
    }
    return 0;
}
*/

int mostrarNodosHojas (t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq == (*p)->der)
            verNodoCompleto(p);
        mostrarNodosHojas(&(*p)->izq);
        mostrarNodosHojas(&(*p)->der);
    }
    return 0;
}

int mostrarNodosNoHojas (t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq != (*p)->der)
            verNodoCompleto(p);
        mostrarNodosNoHojas(&(*p)->izq);
        mostrarNodosNoHojas(&(*p)->der);
    }
    return 0;
}

int mostrarNodosSoloHijosXIzq (t_arbol *p)
{
    if(*p)
    {
        if((*p)->der==NULL && (*p)->izq!=NULL)
            verNodo(&(*p)->info);
        mostrarNodosSoloHijosXIzq(&(*p)->izq);
        mostrarNodosSoloHijosXIzq(&(*p)->der);
    }
    return 0;
}

int mostrarNodosHijosXIzq (t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq!=NULL)
            verNodo(&(*p)->info);
        mostrarNodosHijosXIzq(&(*p)->izq);
        mostrarNodosHijosXIzq(&(*p)->der);
    }
    return 0;
}

int podarAAlturaX(t_arbol *p, int h) //queres que quede a la altura 'h'
{
    if(*p)
    {
        if(h==0)
            return eliminarArbol(p);

        return podarAAlturaX(&(*p)->izq, h-1) + podarAAlturaX(&(*p)->der, h-1);
    }
    return 0;
}

int eliminarArbol(t_arbol *p)
{
    if(*p)
    {
        int cant = eliminarArbol(&(*p)->izq) + eliminarArbol(&(*p)->der);
        free(*p);
        *p=NULL;
        return cant+1;
    }
    return 0;
}


int podarRamasAlturaX (t_arbol *p, int h)
{
    if(*p)
    {
        if(alturaArbol(p)<=h)
            vaciarArbol(p);
        else
        {
            podarRamasAlturaX(&(*p)->izq, h);
            podarRamasAlturaX(&(*p)->der, h);
        }
    }
    return 0;
}

void verNodoCompleto (t_arbol *p)
{
     printf("Legajo: %d | Apyn: %s | Cargo: %s | Nodo: %p //  Izq: %p | Der: %p \n",
            (*p)->info.legajo, (*p)->info.apyn, (*p)->info.cargo, *p,(*p)->izq, (*p)->der);
}

