#include "Punto.h"

Punto::Punto()
{
    coordX = 512;
    coordY = 384;
}

Punto::Punto(int x)
{
    if(esValidoX(x))
    {
        coordX = x;
        coordY = (x*4/3);
    }
}

Punto::Punto(int x, int y)
{
   if(esValidoX(x) && esValidoY(y))
    {
        coordX = x;
        coordY = y;
    }
}

Punto& Punto::operator= (const Punto &obj)
{
    coordX = obj.coordX;
    coordY = obj.coordY;
    return *this;
}

ostream& operator<< (ostream &sal, const Punto &obj)
{
    sal << "(" << obj.coordX << ", " << obj.coordY << ") "
        << "direccion: " << &obj << endl << "-----------------------------" << endl
        << endl;
    return sal;
}

istream& operator>> (istream &ent, Punto &obj)
{
    int x,y;
    cout << "Ingrese cordenada X: ";
    ent >> x;
    cout << "Ingrese cordenada Y: ";
    ent >> y;
    cout << "Valores ingresados: x= " << x << " y= " << y << endl;
    if(esValidoX(x) && esValidoY(y))
    {
        obj.coordX = x;
        obj.coordY = y;
    }
    cout << "Se creo el punto: (" << obj.coordX << ", " << obj.coordY << ") "
         << "direccion: " << &obj << endl << "-----------------------------" << endl
         << endl;

    return ent;
}


Punto Punto::operator+ (const Punto &obj) const              //p1+p2     (1)
{
    int x,y;
    x = coordX + obj.coordX;
    y = coordY + obj.coordY;
    return Punto(esValidoX(x) , esValidoY(y));
}

Punto Punto::operator- (const Punto &obj) const               //p1+p2     (1)
{
    int x,y;
    x = coordX - obj.coordX;
    y = coordY - obj.coordY;
    return Punto(esValidoX(x) , esValidoY(y));
}

Punto& Punto::operator++ ()  //pre-incremento
{
    coordX = esValidoX(coordX+1);
    coordY = esValidoY(coordY+1);
    return *this;
}

Punto  Punto::operator++ (int) //pos-incremento
{
    Punto aux(*this);
    esValidoX(coordX+1);
    esValidoY(coordY+1);
    return aux;
}

Punto& Punto::operator-- ()   //pre-decremento
{
    coordX = esValidoX(coordX-1);
    coordY = esValidoY(coordY-1);
    return *this;
}

Punto  Punto::operator-- (int) //pos-decremento
{
    Punto aux(*this);
    esValidoX(coordX-1);
    esValidoY(coordY-1);
    return aux;
}

Punto Punto::operator+= (const Punto &obj)
{
    coordX = esValidoX(coordX + obj.coordX);
    coordY = esValidoY(coordY + obj.coordY);
    return *this;
}

Punto Punto::operator-= (const Punto &obj)
{
    coordX = esValidoX(coordX - obj.coordX);
    coordY = esValidoY(coordY - obj.coordY);
    return *this;
}
