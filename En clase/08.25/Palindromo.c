#include <stdio.h>

int esPalindromo(const char *s)
{
    const char *fin = s;

    while(*fin)
        fin ++;
    fin--;

    while(s < fin && *s==*fin)
    {
        s++;
        fin--;
    }

    return s>=fin;
}
