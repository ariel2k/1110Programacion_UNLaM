#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED
#include <iostream>

class Objeto{
    long ID;
    char nombre[20],
         *descripcion;

   char* duplicarCadena(const char *cad);;

public:
    Objeto();
    Objeto(long ID, char nombre, char *descripcion);

};


#endif // OBJETO_H_INCLUDED
