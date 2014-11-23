#include "Racional.h"

Racional::Racional(int num, int den)
{
	if (den<0)
	{
		den = -den;
		num = -num;
	}
	int div = mcd(abs(num), den);
	this->num = num/div;
	this->den = den/div;
}

Racional Racional::operator+ (const Racional &obj) const
{
	return Racional(num*obj.den + obj.num*den , den*obj.den); 
	//Como llama al constructor parametrizado lo devuelve simplificado
}

double Racional::valorReal()
{
	return double(num)/den;
}