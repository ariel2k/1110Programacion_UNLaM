#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

int main()
{
    char nombre1[30]="Juan, Perez",
         nombre2[30]="Juan, Perez",
         nombre3[30]="Pepe Amato",
         nombre4[30],
         cadena[]="      hOlA          qUE    hAceS   POR ACA NenE   ?  D:|",
         dni[]=" 38700654",
         palindromo1 []="Soy jose",
         palindromo2 []="neuquen";
    int cmp;

    printf("=======Inicio programa=======\n");
    puts(nombre1);
    puts(nombre2);
    puts(nombre3);
    puts(cadena);
    puts(dni);

    printf("\n====Palindromo====\n");
    cmp = esPalindromo(palindromo1);
    if(cmp == 0)
        printf("%s <- No es palindromo.\n", palindromo1);
    else
        printf("%s <- Es palindromo.\n", palindromo1);
    cmp = esPalindromo(palindromo2);
    if(cmp == 0)
        printf("%s <- No es palindromo.\n", palindromo2);
    else
        printf("%s <- Es palindromo.\n", palindromo2);

    /* copiarCadena */
    printf("\n====Copiar Cadena=====\n");
    copiarCadena(nombre4, nombre1);
    printf("%s <- Cadena copiada\n",nombre4);

    /* compararCadena */
    printf("\n====Comparar Cadena n1 y n2====\n");
    cmp = compararCadena(nombre1, nombre2);
    if(cmp==0)
        printf("Cadena 1 igual a Cadena 2.\n");
    else
        if(cmp <0)
            printf("Cadena 1 menor a Cadena 2.\n");
        else
            printf("Cadena 1 mayor a Cadena 2.\n");
    printf("\n====Comparar Cadena n2 y n3====\n");
    cmp = compararCadena(nombre2, nombre3);
    if(cmp==0)
        printf("Cadena 1 igual a Cadena 2.\n");
    else
        if(cmp <0)
            printf("Cadena 1 menor a Cadena 2.\n");
        else
            printf("Cadena 1 mayor a Cadena 2.\n");

    /* normalizar */
    printf("\n====Normalizar====\n");
    puts(normalizar(cadena));

    /* aEntero */
    printf("\n====A Entero====\n");
    printf("DNI: %d / DNI*2: %d\n", aEntero(dni), 2*aEntero(dni) );

    return 0;
}
