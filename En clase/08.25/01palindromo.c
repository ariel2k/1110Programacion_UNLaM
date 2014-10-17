#include <stdio.h>
#include "Palindromo.h"

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
