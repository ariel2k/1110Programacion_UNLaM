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

char *aCaracter(char *s, int n, int base)
{
	char *ini,
		 *fin,
		 aux;
	unsigned num,
			 resto;
	static char digito[]={"0123456789ABCDEFGHIJKLMÑNOPQRSTUVWXYZ"};

	if(n<0 && base==10)
	{
		num = -n;
		*s ='-';
		fin = s++;
	}
	else
	{
		num=(unsigned)n;
		fin = s;
	}
	ini=fin;
	do{
		resto = num%base;
		num /= base;
		*fin = digito[resto];
	}while(num);

	*fin='\0';
	fin--;

	while(ini<fin)
	{
		aux = *ini;
		*ini = *fin;
		*fin = aux;
		ini++;
		fin--;
	}

	return s;
}


/* Ej parcial */
char *decodificar (char *cad)
{
	char *orig = cad,
		 *dest = cad;
	while(*orig)
	{
		while(*orig < '1' || *orig > '9')
			*dest++=*orig++;

		if(*orig >= '2' && *orig <= '9')
		{
			int cant = *orig - '0'; //obtengo el valor numerico
			copiarCadena(orig, orig+1);
			invertir(orig, cant);
			decrementar(orig, cant);
			//mover(dest, orig, cant);
			dest += cant;
			orig += cant;
		}
	}
	*dest = '\0';
	return cad;
}

void invertir (char *s, int n)
{
	char *fin = s+n-1,
		 aux;

	while(s<fin)
	{
		aux = *s;
		*s = *fin;
		*fin = aux;
		s++;
		fin--;
	}
}

void decrementar(char *s, int n)
{
	int val=1;
	while(val<=n && *s)
	{
		*s -= val;
		s++;
		val++;
	}
}

char *cortarCadena(char *s, int pos)
{
	char *cad = s;

	while(*cad && pos-- > 0)
		cad++;

	*cad = '\0';

	return s;
}

char *agregarCadena(char *s1, const char *s2)
{
//Precondicion: s1 tiene que tener lugar sufiente para agregar s2
	char *orig = s1;

	while(*orig)
		orig++;

    orig++;
    if(*orig=='\0')
        orig--;

	while(*s2 != '\0' && *s2)
		*orig++ = *s2++;

	*orig = '\0';

	return s1;
}

char *encontrarCaracter(char *s, const char letra)
{
	while(*s && *s!=letra)
		s++;

	if(*s=='\0')
		return NULL;

	return s;
}

int longitudCadena(const char *s)
{
	int cant=0;

	while(*s++)
		cant++;

	return cant;
}

char *reemplazar(char *cad, char *sub, char *nue)
{
	char *orig = cad;
	int tamNue = longitudCadena(nue),
		tamSub = longitudCadena(sub),
		dif = tamNue - tamSub;
    while(cad && *cad)
	{
		cad = encontrarCadena(cad, sub);
        if(cad && *cad)
        {
            if(dif==0)
                copiar1a1(cad,nue);
            if(dif>0)
            {
                desplazarCadena(cad+tamSub, dif);
                copiar1a1(cad,nue);
            }
            else
            {
                copiarCadena(cad+tamNue, cad+tamSub);
                copiar1a1(cad,nue);
            }
        }
	}

	return orig;
}

char *encontrarCadena(char *cad, char *s)
{
	char *sub = s,
		 *posSub;
	int tamS = longitudCadena(s),
		cont=0;

	while(*cad!=*s && *cad!='\0')
		cad++;

	while(*cad!='\0')
	{
		posSub = cad;
		while(*cad==*s)
		{
			cad++;
			s++;
			cont++;
		}

		if(cont==tamS)
			return posSub;

        s = sub;
		cont=0;
	}

	return NULL;
}

void copiar1a1(char *dest, const char *orig)
{
    char *s = dest;
	while(*orig)
		*s++ = *orig++;
}

void desplazarCadena(char *orig, int desp)
{
    char *s = orig, //a orig no lo toco.
         *finCad;

    while(*s) //s va al final de la cadena
        s++;

    finCad = s+desp; //finCad va al final mas el desplazamiento

    while(s >= orig)
        *finCad-- = *s--;
}
