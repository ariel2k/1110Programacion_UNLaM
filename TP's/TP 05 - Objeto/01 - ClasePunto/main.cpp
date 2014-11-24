#include <iostream>
#include "Punto.h"
using namespace std;

int main()
{
    Punto p1, p2(++p1);
    cout << "Punto 1: " << endl << p1;
    cout << "Punto 2: (solo): " << p2;
    cout << "Punto 2: (preIn): " << ++p2;
    cout << "Punto 2: (PosIn): " << p2++;
    cout << "Punto 2: (solo): " << p2;
    return 0;
}
