#include "Complejo.h"

/*Complejo::Complejo()
{
    //ctor
}

Complejo::~Complejo()
{
    //dtor
}*/


Complejo::Complejo(float re, float im)
	:	re(re), im(im)
{
	/*this->re=re;
	this->im=im;*/
}

void Complejo::mostrar() const
{
	cout << re
         << " + "
         << im
         << "i "
         << endl;
}

ostream &operator<< (ostream &sal, const Complejo &obj)
{
	sal << obj.re << " + " << obj.im << "i " << endl;
	return sal;
}

Complejo Complejo::operator+ (const Complejo &obj) const	//c1+c2 (1)
{
	return Complejo(re + obj.re, im + obj.im);
}

Complejo Complejo::operator+ (float val) const		//c1+n (2)
{
	return Complejo(re+val, im);
}

Complejo operator+ (float val, const Complejo &obj) //n+c1 (3)
{
	return Complejo(obj.re + val, obj.im);
}

istream &operator>> (istream &ent, Complejo &obj)
{
	cout << "Parte real: ";
	cin >> obj.re;
	cout << "Parte imaginaria: ";
	cin >> obj.im;
	return ent;
}

Complejo &Complejo::operator++ () //pre-incremento
{
	re +=1;
	return *this;
}

Complejo Complejo::operator++ (int) //pos-incrementado
{
	Complejo aux(*this); //Es una copia para devolverlo y poder incrementar el original
	re +=1;
	return aux;
}
