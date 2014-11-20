#ifndef DERIVADA_H_INCLUDED
#define DERIVADA_H_INCLUDED
#include <iostream>
#include "Base.h"
using namespace std;

class Derivada : public Base
{
	int pepe;

public:
	Derivada()
	{
		Base();
		pepe = 5;
	}

	Derivada::mostrar() const
	{
		cout << "Mostrar de Derivada. " << endl;
	}
};

#endif // DERIVADA_H_INCLUDED
