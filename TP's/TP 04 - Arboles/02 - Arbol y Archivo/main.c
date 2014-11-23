#include <stdio.h>
#include <stdlib.h>

void llenarArbolAutomatico (t_arbol *p);

int main()
{
	t_arbol arbol;
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

    return 0;
}

void llenarArbolAutomatico (t_arbol *p)
{
    int i=0;
    t_info aux[]={
                 
                 };
    while(i<11)
    {
        ponerEnArbol(p,&aux[i]);
        i++;
    }
}