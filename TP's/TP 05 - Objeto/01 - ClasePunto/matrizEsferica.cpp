#include "matrizEsferica.h"

/*
**MATRIZ ESFÉRICA**
Se fija si esta dentro del rango:
- 	Si es más que el rango, le resta la cantidad de elementos veces hasta que entre en el rango.
-	Si es menos que el rango, le suma la cantidad de elementos veces hasta que entre en el rango.
*/

int esferica(int *num, const int cantElem)
{
    while(*num > cantElem-1)
        *num -= cantElem;
    while(*num < 0)
        *num += cantElem;

    return *num;
}
