#include <stdio.h>
#include <stdlib.h>

void llenarArbolAutomatico (t_arbol *p);

int main()
{
	t_arbol arbol;
  FILE *pf;
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
        case 1:
          agregarRegistro(&arbol, pf);
          break;
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


  scanf("%s",info.clave); 
  if(buscarEnArbol(&arbol, &info))
  {
    if(buscarEnArchivo(fpArch, &reg, info.nReg))
      mostrar(&reg);
    else
      //ERROR
  }
  fclose(pf);
  return 0;
}

/*----Funciones----*/

void llenarArbolAutomatico (t_arbol *p)
{
    int i=0;
    t_info aux[]={
                {1,"J"},
                {2,"G1"},
                {3,"L1"},
                {4,"J1"},
                {5,"O1"},
                {6,"L2"},
                {7,"J2"},
                {8,"G2"},
                {9,"L3"},
                {10,"J4"},
                {11,"L4"},
                 };
    while(i<11)
    {
        ponerEnArbol(p,&aux[i]);
        i++;
    }
}