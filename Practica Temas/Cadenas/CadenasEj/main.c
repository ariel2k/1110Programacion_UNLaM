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
         palindromo2 []="neuquen",
         agregar1[33]="Hola. ",
         agregar2[]=".Que haces?",
         caracter = 'a',
         cad1[70]="HolaArielQueHaces",
         sub1[]="Ariel",
         nue1[]="Sebi",
         sub2[]="Sebi",
         nue2[]="Loportidio",
         deco[]="hola4todobien2que3haces4saludos";
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

    /* Agregar Cadena */
    printf("\n====Agrear cadena====\n");
    printf("cad1: %s \tcad2: %s\n",
           agregar1, agregar2 );
    printf("Resultado: %s\n",agregarCadena(agregar1, agregar2));

    /* encontrar caracter */
    printf("\n====Encontrar Caracter====\n"
            "Cad: %s // caracter: %c\n",cadena,caracter);
    printf("Resultado: %s\n", encontrarCaracter(cadena, caracter));

    /* longitud cadena */
    printf("\n====Longitud cadena====\n"
            "Cadena: %s -> Longitud: %d\n", nombre1, longitudCadena(nombre1));

    printf("\n====decodificar====\n");
    puts(decodificar(deco));

    /* reemplazar cadena */
    printf("\n====Reemplazar Cadena====\n");
    puts(cad1);
    puts(reemplazar(cad1,sub1,nue1));
    puts(reemplazar(cad1,sub2,nue2));

    return 0;
}
