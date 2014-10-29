#include <stdio.h>
#include <stdlib.h>
#define TAM_CAD 300

char *reemplazar (char *cad, char *sub, char *nue);
int *tamCad (char *cad);
int comprobarCadena(char *sub, char *orig);
void reempIgual(char **cad, char **sub, char **nue);
void reempMayor(char **cad, char **sub, char **nue, int cadSub, int cadNue);
void reempMenor(char **cad, char **sub, char **nue, int cadSub, int cadNue);

int main ()
{
	// variables
	char cadena[TAM_CAD],
		 sub[TAM_CAD],
		 nue[TAM_CAD],
		 *cad;

	// programa
	printf("-----Ingrese cadena-----\n");
	gets(cadena);
	printf("-----Ingrese porcion de cadena a reemplazar-----\n");
	gets(sub);
	printf("-----Ingrese cadena a reemplazar-----\n");
	gets(nue);

	cad = reemplazar(&cadena, &sub, &nue);

	printf("Cadena final: \n");
	printf("%s\n",cadena);

	// fin
	system("pause");
	return 0;
}

char *reemplazar (char *cad, char *sub, char *nue)
{
	char *orig = cad;
	int cadSub = tamCad(&sub),
		cadNue = tamCad(&nue);

	while(*orig)
	{
		if(comprobarCadena(&sub, &orig))
		{
			if(cadSub==cadNue)
			{
				while(*orig2)
				{
					if(*sub2==*orig2)
						esCadena=1;
					else
						esCadena=0;

					orig2++;
				}
			}
			if(cadSub>cadNue)
			{
				while(*nue2)
					*cad2++=*nue2++;

				while(*(cad2+restar))
					*cad2++=*(cad2+restar);
			}				
			else
			{
				while(*cad2)
					cad2++;

				while(*(cad2+restar))
					*(cad2+sumar)=*cad2--;

				while(*nue)
					*cad3++=*nue;
			}
		}
		orig++;
	}

	return cad;
}

int *tamCad (char *cad)
{
	int cant=0;
	char *cad2 = cad;

	while(*cad2 && *cad2!='\n')
		cant++;
	return cant;
}

int comprobarCadena(char *sub, char *orig)
{
	char *sub2 = sub,
		 *orig2 = orig;
	int esCadena;

	

	return esCadena;
}

void reempIgual(char *cad, char *sub, char *nue)
{
	char *cad2 = cad;

	while(*nue2)
		*cad2++=*nue2++;
}

void reempMayor(char *cad, char *sub, char *nue, int cadSub, int cadNue)
{
	char *cad2 = cad;
	int restar;

	restar = cadSub - cadNue;
	

	*cad2='\n';
}

void reempMenor (char *cad, char *sub, char *nue, int cadSub, int cadNue)
{
	char *cad2 = cad,
		 *cad3 = cad,
		 *sub2 = sub;
	int restar;

	sumar = cadNue- cadSub;
	
}
