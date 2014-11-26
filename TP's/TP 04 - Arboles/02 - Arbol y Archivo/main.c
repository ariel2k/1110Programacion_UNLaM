#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "archivos.h"

void llenarArbolAutomatico (t_arbol *p);
void agregarRegistro(t_arbol *p, FILE *pf);
//int compararDupi (int nReg, t_arbol *p);
int buscarClave(t_arbol *p, FILE *pfArch);
void verNodoReg (t_reg *p);

int main()
{
    int op;
    t_arbol arbol;
    FILE *fpSal = fopen(nombreTexto, "wt");
    if (abrirArchivo(&fpSal, nombreTexto, "rt", CON_MSJ)) //Si puede abrir archivo, que lo muestre
       // mostrarArchivoTexto(fpSal);
    llenarArbolAutomatico (&arbol);
    do{
      printf("-------Menu-------\n"
         "1-Agregar nuevos registros de informacion.\n"
         "2-Ingresar clave, para buscar en arbol y con el numero de reg mostrar la informacion.\n"
         "3-Mostrar informacion de los registros del archivo en EN-ORDEN.\n"
         "4-Mostrar informacion de los registros del archivo en PRE-ORDEN\n"
         "5-Mostrar informacion de los registros del archivo en POS-ORDEN\n"
         "0-Fin.\n"
         "------------------\n\n"
         "Opcion: ");
      scanf("%d",&op);
      switch(op){
       // case 1:
       //   agregarRegistro(&arbol, pf);
       //   break;
        case 2:
            printf("=================Buscar Clave=================\n");
            buscarClave(&arbol, fpSal);
        case 0:
          printf("\n\n\n\n\n\n\n\n"
                 "            =================Programa finalizado=================\n"
                 "           |                                                     |\n"
                 "           |         Programa realizado por Molina Ariel.        |\n"
                 "           |                                                     |\n"
                 "           |             facebook.com/ariel.molina.h             |\n"
                 "           |             twitter.com/ariel2k                     |\n"
                 "           |                                                     |\n"
                 "            =====================================================\n"
                 "\n\n\n\n\n\n\n"
                 );
          break;
        default:
          printf("\n=================Opcion incorrecta=================\n");
          printf("=================Opcion incorrecta=================\n");
          printf("=================Opcion incorrecta=================\n\n");
          break;
      }
  }while(op!=0);

  fclose(fpSal);
  return 0;
}

/*----Funciones----*/

void llenarArbolAutomatico (t_arbol *p)
{
    int i=0;
    t_info aux[]={
                {500,"J"},
                {250,"G1"},
                {100,"L1"},
                {20,"J1"},
                {10,"O1"},
                {300,"L2"},
                {290,"J2"},
                {750,"G2"},
                {600,"L3"},
                {560,"J4"},
                {800,"L4"},
                 };
    while(i<11)
    {
        ponerEnArbol(p,&aux[i]);
        i++;
    }
}
 /*
void agregarRegistro(t_arbol *p, FILE *pf)
{
  t_reg aux;
  t_info aux2;
  printf("////////Ingresar registro////////\n");
  printf("Legajo: ");
  scanf("%d", &aux.legajo);
  printf("Apyn: ");
  fflush(stdin);
  gets(aux.apyn);
  printf("Cargo: ");
  fflush(stdin);
  gets(aux.cargo);
  if(compararDupi(aux.legajo,p))
  {
      fprintf(pf, "%d, %s, %s\n",aux.legajo, aux.apyn, aux.cargo);
      aux2.nReg = aux.legajo;
      printf("Ingrese clave: ");
      fflush(stdin);
      gets(aux2.clave);
      ponerEnArbol(p,&aux2);
  }
  else
    printf("CLAVE DUPLICADA");
}
*/

/*
int compararDupi (int nReg, t_arbol *p)
{
    if(*p) //while (*p)
    {
        int comp = nReg - (*p)->info.nReg;
        if(comp==0)
            return 1;
        if(comp<0)
            return compararDupi(nReg, &(*p)->izq);     //p=&(*p)->izq;
        else
            return compararDupi(nReg, &(*p)->der);     //p=&(*p)->der;
    }
    return 0;
}
*/

int buscarClave(t_arbol *p, FILE *fpArch)
{
  t_info info;
  t_reg  reg;
  printf("ingrese clave a buscar: ");
  fflush(stdin);
  scanf("%s",info.clave);
  if(buscarEnArbol(p, &info))
  {
    if(buscarEnArchivo(fpArch, &reg, info.nReg))
    {
      verNodoReg(&reg);
      return 1;
    }
    else
      printf("No se encontro en el archivo.\n");
  }
  else
    printf("No se encontro en el arbol.\n");

  return 0;
}

void verNodoReg (t_reg *p)
{
    printf("Legajo: %d | Apyn: %s | Cargo: %s  \n",
          (*p).legajo, (*p).apyn, (*p).cargo);
}
