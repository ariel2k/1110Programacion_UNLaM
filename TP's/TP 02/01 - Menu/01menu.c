#include <stdio.h>

//textos

        /* NOOOO MEEE SALEEE CON EL VECTOR EN FLOAT!!!! */

//tamaños
#define tam 200

int llenarArray(const int *);

int main ()
{
	// variables
	float vec[tam];
	int cElem, i, *pAux;

	// programa
	printf("-----Bienvenidos----\n");
	cElem = llenarArray(vec);
	//menu(texto, opciones);
	*pAux = vec;
	printf("%d", *pAux);
	for (i = 0; i < cElem; i++)
		printf("%d\n", vec[i]);
	// fin
	system("pause");
	return 0;
}

/*----Funciones----*/

//---llenarArray---//
int llenarArray (const int *posAct)
{
	float num;
	int *vec=posAct,
        cElem,
		i;

	printf("Ingrese cantidad de elementos que desea llenar: ");
	scanf("%d", &cElem);
    printf("\n-----Llenar Vector (float)-----\n");
	for (i = 0; i < cElem; i++)
	{
	    printf("Ingrese #%002d: ", i+1);
		scanf("%f", &num);
		*vec = num;
		vec++;
	}

    printf("Direccion: %d\n", *posAct);

	return cElem;
}
