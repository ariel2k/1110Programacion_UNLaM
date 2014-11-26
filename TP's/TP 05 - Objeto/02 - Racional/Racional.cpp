#include "Racional.h"
#define abs(x) ((x) < 0 ? -(x) : (x))

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

ostream& operator<< (ostream &sal, const Racional &obj)
{
    sal << obj.num << "/" << obj.den << endl;
    return sal;
}

int Racional::mcd (int a, int b)
{
	int c;
	while (a!=b)
	{
		if (a>b)
			a=a-b;
		else
			b=b-a;
	}
	c=a;
	return c;
}
