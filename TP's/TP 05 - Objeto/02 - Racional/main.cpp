#include <iostream>
#include "racional.h"

using namespace std;

int main()
{
    Racional r1, r2(2,10);
    cout << r1 << r2 << r1.valorReal() << " - "<< r2.valorReal();
    return 0;
}
