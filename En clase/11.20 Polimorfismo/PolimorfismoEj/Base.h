#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <iostream>
using namespace std;

class Base
{
    int edad;

public:
    Base()
    {
    	edad = 50;
    }

    Base::mostrar()const
    {
    	cout << "Mostrar de clase base" << endl;
    }
};

#endif // BASE_H_INCLUDED
