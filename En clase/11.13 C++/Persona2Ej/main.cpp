#include <iostream>
#include "PersonaDos.h"
using namespace std;

int main()
{
    PersonaDos p1;
    cin >> p1;
    PersonaDos p2(p1);
    cout << p1 << endl
         << p2 << endl;
    return 0;
}
