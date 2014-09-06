#include <stdio.h>

int main()
{
    char cad[50];

    printf("Ingrese cadena: ");
    scanf("%s", &cad);

    if (esPalindromo(cad))
        puts("\nEs palindromo.");
    else
        puts("\nNo es palindromo.");

    return 0;
}

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
