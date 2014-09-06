#include <stdio.h>

int main()
{
    int a=7,
        b=-5;

    printf("a=%d y b=%d\n", a, b);
    intercambiar(&a,&b);
    printf("Después del intercambio: \n a=%d y b=%d", a, b);

    return 0;
}

void intercambiar (int *p1, int *p2)
{
    int aux = *p1;

    *p1=*p2;
    *p2=aux;
}
