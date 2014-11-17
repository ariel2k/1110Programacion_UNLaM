#include <iostream>
#include "empleado.h"
using namespace std;
void mostrar(const PersonaDos *obj){
    cout << *obj;
}

int main()
{
    Emple e0, e1(38662, 'm', "Pepe", 111, 345.4);
    PersonaDos p1(38412, 'F', "Pepa");
    mostrar(&e0);
    mostrar(&e1);
    mostrar(&p1);
    return 0;
}
