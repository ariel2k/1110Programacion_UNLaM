#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#define SIN_MEM  -1
#define CLA_DUP  0
#define TODO_BIEN 1

//ARBOL BINARIO --> si existe, tendria un nodo "raiz" que puede tener subarboles (si es < a la izq, si es > a la der)
//ARBOL BINARIO DE BUSQUEDA --> arbol binario que no puede tener claves duplicadas
//ARBOL COMPLETO --> (2^N) -1 = cantidad de nodos  (N=altura)
//ARBOL BALANCEADO --> cuando el nivel anterior al maximo es completo
//ARBOL AVL --> cuando la diferencia entre la altura de la rama izq y der es a lo sumo uno (en cada nodo)
//PREODEN: NID  /  POSORDEN: IDN  /  ENORDEN: IND


typedef struct
{
    int  legajo;
    char apyn[35],
         cargo[15];
}t_reg;

typedef struct
{
    int  nReg;
    char clave[2],
}t_info;

typedef struct s_nodo
{
    t_info info;
    struct s_nodo *izq,
                  *der;
}t_nodo, *t_arbol;

void crearArbol (t_arbol *p);
void enOrden (const t_arbol *p);
void preOrden (const t_arbol *p);
void posOrden (const t_arbol *p);
int ponerEnArbol (t_arbol *p, const t_info *d);
int ponerEnArbolR (t_arbol *p, const t_info *d);
int alturaArbol (const t_arbol *p);
int contarNodosArbol (const t_arbol *p);
int esCompleto (const t_arbol *p);
int dosAlaH (int h);
int esArbolCompleto (const t_arbol *p);
int verSiEsCompleto (const t_arbol *p, int h);
int esBalanceado (const t_arbol *p);
int contarNodosHastaHmenos1 (const t_arbol *p, int h);
int esArbolBalanceado (const t_arbol *p);
int verSiEsBalanceado (const t_arbol *p, int h);
int esArbolAVL (const t_arbol *p);
int contarHojas (const t_arbol *p);
int contarNodosInternos (const t_arbol *p);
int contarNodosRamaIzquierda (const t_arbol *p);
void vaciarArbol (t_arbol *p);
int vaciarArbolYContar (t_arbol *p);
int vaciarArbolMostrarEnOrdenGrabarEnPreYContar (t_arbol *p); //, FILE *fp);
void verNodo (t_info *d);
int comparar (const t_info *d1,const t_info *d2);

/* Extras ejercicio 01 */
int mostrarNodosHojas (t_arbol *p);
int mostrarNodosNoHojas (t_arbol *p);
int mostrarNodosSoloHijosXIzq (t_arbol *p);
int mostrarNodosHijosXIzq (t_arbol *p);
int podarAAlturaX(t_arbol *p, int h);
int eliminarArbol(t_arbol *p);
int podarRamasAlturaX(t_arbol *p, int h);
void verNodoCompleto (t_arbol *p);

/* Extras ejercicio 02 */


#endif // ARBOLES_H_INCLUDED