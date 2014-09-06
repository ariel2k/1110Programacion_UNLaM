/*Las fechas calculadas tiene una limitacion:
-Solo puede llegar al proximo mes o al proximo año.
Esto quiere decir que si se le agregan tantos dias como para avanzar dos meses no lo hará.*/
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
	int 	agregarDias;

	// programa
	printf("Ingresa una fecha:\n");
	printf("Dia: ");
	scanf("%d", &fch.dia);
	printf("Mes: ");
	scanf("%d", &fch.mes);
	printf("Anio: ");
	scanf("%d", &fch.anio);

	if(validarFecha(fch))
		printf("\n//Fecha correcta.\n");

	printf("\n----Fecha ingresada----\n%d/%d/%d\n-----------------------\n", fch.dia, fch.mes, fch.anio);
	printf("\nIngrese la cantidad de dias que desea sumarle: ");
	scanf("%d",&agregarDias);
	fch.dia += agregarDias;
	if (validarFecha(fch))
    {
        printf("\n----Fecha proxima----\n%d/%d/%d\n---------------------\n\n", fch.dia, fch.mes, fch.anio);
        system ("pause");
        return 0;
    }
	else
		while(!validarFecha(fch))
		{
			agregarDias = fch.dia - cantidadDiasDelMes(fch.mes, fch.anio);
			fch.dia = agregarDias;
			fch.mes++;
			if (fch.mes > 12)
			{
				fch.mes = 1;
				fch.anio++;
			}
		}
	printf("\n----Fecha proxima----\n%d/%d/%d\n---------------------\n\n", fch.dia, fch.mes, fch.anio);

	// return
	system ("pause");
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
