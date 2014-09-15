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
  if( fecha.anio>=1950 && fecha.anio<=2020)
    if ( fecha.mes>= 1 &&  fecha.mes<= 12 )
        if( fecha.dia >=1 && fecha.dia <= cantidadDiasDelMes(fecha.mes,fecha.anio) )
           return 1;

   return 0;
}

//--cantidadDiasDelMes--//
int cantidadDiasDelMes(int m,int a)
{
  if(m==4 || m==6 || m==9 || m==11)
     return 30;
  else
     if ( m== 2)
       return (28 +bisiesto(a));
     else
       return 31;
}

//--bisiesto--//
int bisiesto (int a)
{
	if (( a%4 == 0 && a%100 != 0 ) || (a%400 == 0) )
		return 1;
	else
		return 0;
}
