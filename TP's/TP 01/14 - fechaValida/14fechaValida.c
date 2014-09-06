#include <stdio.h>

typedef struct
{
	int dia,
		mes,
		anio;
} t_fecha;

int validarFecha (t_fecha);
int cantidadDiasDelMes(int, int);
int bisiesto (int);

int main()
{
	// variables
	t_fecha fch;
	int resultadoFecha;

	// programa
	printf("Ingresa una fecha:\n");
	printf("Dia: ");
	scanf("%d", &fch.dia);
	printf("Mes: ");
	scanf("%d", &fch.mes);
	printf("Anio: ");
	scanf("%d", &fch.anio);

	resultadoFecha = validarFecha(fch);

	if(resultadoFecha)
		printf("La fecha ingresada es correcta.\n\n");
	else
		printf("La fecha ingresada es incorrecta.\n\n");

	system("pause");

	// return
	return 0;
}

/*----funciones----*/

//--validarFecha--//
int validarFecha (t_fecha fecha)
{
  int r=0;

  if( fecha.anio>=1950 && fecha.anio<=2020)
    if ( fecha.mes>= 1 &&  fecha.mes<= 12 )
        if( fecha.dia >=1 && fecha.dia <= cantidadDiasDelMes(fecha.mes,fecha.anio) )
           r=1;

   return (r);
}

//--cantidadDiasDelMes--//
int cantidadDiasDelMes(int m,int a)
{
  int cdm;

  if(m==4 || m==6 || m==9 || m==11)
     cdm = 30;
  else
     if ( m== 2)
        cdm = 28 +bisiesto(a);
     else
        cdm = 31;

   return (cdm);
}

//--bisiesto--//
int bisiesto (int a)
{
	int r;

	if (( a%4 == 0 && a%100 != 0 ) || (a%400 == 0) )
		r=1;
	else
		r=0;

	return (r);
}
