#include "Hora.h"

Hora::Hora()
	:	segundos(0)
{
    //segundos=0;
}

/*Hora::~Hora()
{
    //dtor
}*/

Hora::Hora(int hh, int mm, int ss)
{
	segundos=(ss+mm*60+hh*3600)%86400;
	if(segundos < 0)
		segundos += 86400;
}

Hora& Hora::operator++ () //pre-incremento
{
	segundos++;
	if(segundos == 86400)
		segundos = 0;
	return *this;
}

Hora Hora::operator++ (int n) //pos-incremento
{
	Hora aux(*this);
	segundos++;
	if(segundos == 86400)
		segundos = 0;
	return aux;
}

Hora& Hora::operator-- () //pre-decremento
{
	segundos --;
	if(segundos < 0)
		segundos = 86399;
	return *this;
}

Hora  Hora::operator-- (int n) //pos-decremto
{
	Hora aux(*this);
	segundos--;
	if(segundos<0)
		segundos=86399;
	return aux;
}

Hora Hora::operator/ (int n) const 	// h1 / n	(06)
{
	if (n > 0)
		return Hora(0,0,segundos/n);
	return Hora(*this);
}

Hora operator+ (int n, const Hora &obj) // n + h1 (03)
{
	return Hora (0,0,obj.segundos + n);
}
