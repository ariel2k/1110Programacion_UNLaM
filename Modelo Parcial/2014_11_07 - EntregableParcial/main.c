#include "main.h"
#include "string.h"

int buscarEnArbolMOLINA(const t_arbol *p,const t_info_colaC *d);
int  compararXClaveArbolMOLINA(const char *d1, const char *d2);
void actualizarArchivoMOLINA(FILE *fp,const t_info_colaC *d,const int linea);
void sacarDeColaCBuscarEnArbolActualizarArchivo(t_colaC *cola, t_arbol *arbol, FILE *fp);
void mostrarFaltantesYReposicion(FILE *fp);
void mostrarArchivoMOLINA (FILE *fp);
void mostrarArbolEnPreordenMOLINA (const t_arbol *p);
void verNodoMOLINA(const t_info_arbol *d);

int main(void)
{
    t_colaC colaC;
    t_arbol arbol;
    FILE  *fpStock;

    crearColaC(&colaC);
    crearArbol(&arbol);

/** esta función es necesaria para crear el maestro de productos y el árbol
 *      de índices del archivo, además carga la lista de pedidos en la cola
 *      a medida que los muestra
 */
    crearArchivoCargarListaCargarArbol(&colaC, &arbol);

/** la apertura del archivo ya está resuelta */
    if(!abrirArchivo(&fpStock, ARCH_NOM, "r+b", CON_MSJ))
    {
        fprintf(stderr, "El programa se cancela.\n");
        return 1;
    }
/** las siguientes funciones se encargan de mostrar el archivo y el árbol  */
    //mostrarArchivo(fpStock);
    mostrarArchivoMOLINA(fpStock);
    //mostrarArbolEnPreorden(&arbol, mostrarTInfoArbol);
    printf("\n=====ARBOL PRE ORDEN====\n");
    mostrarArbolEnPreordenMOLINA(&arbol);

/** las siguientes funciones deben ser reemplazadas por nuevas versiones
 *      al efecto puede escribir sus prototipos al comienzo de main y sus
 *      desarrollos al final de main.
 *  puede utilizar todas las primitivas salvo las que tienen sufijo _2
 */
    //sacarDeColaCBuscarEnArbolActualizarArchivo_2(&colaC, &arbol, fpStock);
    //mostrarFaltantesYReposicion_2(fpStock);
    sacarDeColaCBuscarEnArbolActualizarArchivo(&colaC, &arbol, fpStock);
    mostrarFaltantesYReposicion(fpStock);
/** las siguientes funciones le permiten comprobar si el resultado es el
 *      el esperado, además de vaciar el arbol y cerrar el archivo
 */
    //mostrarArchivo(fpStock);
    mostrarArchivoMOLINA(fpStock);
    vaciarArbol(&arbol);
    fclose(fpStock);

    return 0;
}



int buscarEnArbolMOLINA(const t_arbol *p,const t_info_colaC *d)
{
    if(*p)
    {
        int cmp = compararXClaveArbolMOLINA((*p)->info.clave, d->clave);
        if(cmp==0)
            return (*p)->info.nroReg;
        if(cmp>0)
            return buscarEnArbolMOLINA(&(*p)->izq, d);
        if(cmp<0)
            return buscarEnArbolMOLINA(&(*p)->der, d);
    }
    return 0;
}

int  compararXClaveArbolMOLINA(const char *d1, const char *d2)
{
    return strcmp(d1,d2);
}

void sacarDeColaCBuscarEnArbolActualizarArchivo(t_colaC *cola, t_arbol *arbol, FILE *fp)
{
    int encontro,
        correctas=0,
        incorrectas=0;
    t_info_colaC auxCola;
    printf("\n====Informe de No Encontrados====\n");
    while(!colaCVacia(cola))
    {
        sacarDeColaC(cola, &auxCola); //saca de cola
        encontro = buscarEnArbolMOLINA(arbol, &auxCola); //encontro tiene la linea que esta en el archivo
        if(encontro == 0)
        {
            printf("ERROR - La clave '%s' no se encuentra en el archivo\n", auxCola.clave);
            incorrectas++;
        }
        else
        {
            actualizarArchivoMOLINA(fp, &auxCola, encontro);
            correctas++;
        }
    }
    printf("\n===INFORME CLAVES===\n"
           "Total de Claves erroneas y correctas :\n"
           "Se encontraron:  %d claves erroneas y %d claves correctas.\n",
           incorrectas, correctas);
}

void mostrarFaltantesYReposicion(FILE *fp)
{
    rewind(fp);
    t_reg aux;
    printf("\n====ATENCION====\n");
    while(fread(&aux,sizeof(t_reg),1,fp))
    {
        if(aux.exist < aux.ptoRep && aux.exist > 0)
            printf("%s - REPONER\n", aux.clave);
        if(aux.exist < 0)
            printf("%s - FALTANTE\n", aux.clave);
    }
}

void actualizarArchivoMOLINA(FILE *fp,const t_info_colaC *d,const int linea)
{
    //lo que hay que restar: *d->cantPed
    t_reg aux;
    rewind(fp);
    fseek(fp,(linea-1)*sizeof(t_reg),0); //se para en la linea
    fread(&aux,sizeof(t_reg),1,fp); //copia el registro
    aux.exist -= d->cantPed;

    if(!feof(fp))
    {
        fseek(fp,-(sizeof(t_reg)),SEEK_CUR);
        fwrite(&aux,sizeof(t_reg),1,fp);
        fseek(fp,0,SEEK_CUR);
    }
}

void mostrarArchivoMOLINA(FILE *fp)
{
    t_reg aux;
    rewind(fp);
    printf("\n=================ARCHIVO=================\n"
           "Clave Prod Descripcion del Producto                   Existen Fecha Ingr  Precio Pto Rep\n");
    while(fread(&aux,sizeof(t_reg),1,fp))
    {
        printf("%-11s %-43s %5d %02d/%02d/%04d %6.2f %4d \n",
               aux.clave,
               aux.descr,
               aux.exist,
               aux.fecIng.di, aux.fecIng.me, aux.fecIng.an,
               aux.precio,
               aux.ptoRep);
    }
}

void mostrarArbolEnPreordenMOLINA (const t_arbol *p)
{
    if(*p)
    {
        verNodoMOLINA(&(*p)->info);
        mostrarArbolEnPreordenMOLINA(&(*p)->izq);
        mostrarArbolEnPreordenMOLINA(&(*p)->der);
    }
}

void verNodoMOLINA (const t_info_arbol *d)
{
    printf("%-11s %5d\n", d->clave, d->nroReg);
}
