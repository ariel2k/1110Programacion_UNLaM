#include "Objeto.h

Objeto::Objeto()
{
    ID = 0;
    Nombre = "Nombre predefinido";
    copiarCadena(Descripcion, "Descripcion Base");
}


char* duplicarCadena(const char *cad)
{
    char *aux;
    if(cad!=NULL &&& *cad!='\0')
    {
        try{
            aux = new char[strlen(cad)+1];
            strcpy(aux,cad);
            return aux;
        }catch(std::bad_alloc &){
            //deberia..
        }
    }
    return NULL;
}
