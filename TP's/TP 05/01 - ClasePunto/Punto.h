#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED
#include <iostream>
#include "matrizEsferica.h"

#define esValidoX(x) ((x)>0 && (x)<=1023 ? (x) : esferica(&x,1024))
#define esValidoY(y) ((y)>0 && (y)<=676  ? (y) : esferica(&y,768))

using namespace std;

class Punto{
    int coordX,
        coordY;

public:
    Punto();
	Punto(int x);
	Punto(int x, int y);


};



#endif // PUNTO_H_INCLUDED
