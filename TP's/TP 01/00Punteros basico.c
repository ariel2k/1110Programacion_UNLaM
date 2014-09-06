#include <stdio.h>
int main ()
{
   int  numero = 12,
        *dirPunt,
        contPunt;

    dirPunt = &numero;
    contPunt = *dirPunt;

    printf("Contenido de numero: %d \n Direccion: %d", contPunt, dirPunt);

    return 0;

}
