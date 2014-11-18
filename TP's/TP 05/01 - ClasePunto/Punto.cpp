#include "Punto.h"

Punto::Punto()
{
    cout << "Constructor por defecto" << endl;
    coordX = 512;
    coordY = 384;
    cout << "Se creo el punto: (" << coordX << ", " << coordY << ") "
         << "direccion: " << this << endl << "-----------------------------"
         << endl << endl;
}

Punto::Punto(int x)
{
    cout << "Valores ingresados: x=" << x << endl;
    if(esValidoX(x))
    {
        coordX = x;
        coordY = (x*4/3);
    }
    cout << "Se creo el punto: (" << coordX << ", " << coordY << ") "
         << "direccion: " << this << endl << "-----------------------------"
         << endl << endl;
}

Punto::Punto(int x, int y)
{
    cout << "Valores ingresados: x= " << x << " y= " << y << endl;
    if(esValidoX(x) && esValidoY(y))
    {
        coordX = x;
        coordY = y;
    }
    cout << "Se creo el punto: (" << coordX << ", " << coordY << ") "
         << "direccion: " << this << endl << "-----------------------------"
         << endl << endl;
}
