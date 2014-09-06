#include <stdio.h>
#define esBlanco(X) ((X)==' '|| (X)=='\t'?1:0)
#define aMayusc(X) ((X)>='a' && (X) <='z' ? (X)-32 : (X))
#define aMinusc(X) ((X)>='A' && (X) <='Z' ? (X)+32 : (X))

char *normalizar (char *);

int main ()
{
	// Variables
	char cadena[500];

	// programa
	printf("Ingrese una cadena para normalizarla:\n");
	gets(cadena);


	printf("\n------Cadena normalizada------\n\n");
	puts(normalizar(cadena));
	printf("\n-----Fin-----\n");


	// fin
	system("pause");
	return 0;
}

/*---funciones---*/

//--normalizar--//
char *normalizar (char *cad)
{
	char 	*orig = cad, //obtiene la dir de memoria del comienzo de la cadena
			*dest = cad;

	while(*orig)
	{
		while(esBlanco(*orig))
			orig++;

		if(*orig)
		{
			*dest = aMayusc(*orig);
			dest++;
			orig++;
			while(*orig && !esBlanco(*orig))
			{
				*dest = aMinusc(*orig);
				dest++;
				orig++;
			}

			if(esBlanco(*orig))
			{
				*dest =' ';
				dest++;
				orig++;
			}
		}
	}

	if(dest > cad && esBlanco(*(dest-1)))
		dest--;

	*dest = '\0';
	return cad;
}