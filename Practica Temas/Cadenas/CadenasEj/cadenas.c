#include "cadenas.h"

int esPalindromo(const char *s)
{
    const char *fin = s;

    while(*fin)
        fin++;

    fin--;

    while(s < fin && *s==*fin)
    {
        s++;
        fin--;
    }

    return s>=fin;
}

char *copiarCadena(char *dest, const char *orig)
{
	char *inicio = dest;

	while(*orig)
		*dest++ = *orig++;
	*dest = '\0';

	return inicio;
}

int compararCadena(const char *s1, const char *s2)
{
/* Pre condición: s1 y s2 del mismo tamaño */
	while(*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}

	if(*s1==*s2)
		return 0;
	if(*s1 < *s2)
		return -1;
	else
		return 1;
}

char *normalizar (char *cad)
{
	char *orig = cad, //obtiene la dir de memoria del comienzo de la cadena
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

int aEntero(const char *cad)
{
	int acum = 0;
	char signo = '+';

	while(esBlanco(*cad))
		cad++;

	if(*cad=='+')
		cad++;
	if(*cad=='-')
	{
		signo='-';
		cad++;
	}

	while(esDigito(*cad))
	{
		acum = acum * 10 + *cad - '0';
		cad++;
	}

	return signo=='-' ? -acum : acum;
}

