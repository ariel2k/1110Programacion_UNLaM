#include <stdio.h>

typedef struct
{
	int dia,
		mes,
		anio;
} t_fecha;

int validarFecha (t_fecha);
int cantDias (t_fecha, t_fecha);
int cantidadDiasDelMes(int, int);
int bisiesto (int);

int main ()
{
	// variables
	t_fecha fch1,
			fch2;

	// programa
	printf ("-----Cantidad de dias entre dos fechas-----\n   ACLARACION: fecha 1 < fecha 2\n\n");
	printf("//Primera fecha:\n");
	printf("Dia: ");
	scanf("%d", &fch1.dia);
	printf("Mes: ");
	scanf("%d", &fch1.mes);
	printf("Anio: ");
	scanf("%d", &fch1.anio);
	if(validarFecha(fch1))
		printf("Fecha correcta.\n");
	else
	{
		printf("Error al ingresar la fecha. El programa finalizara.\n");
		return 1;
	}

	printf("\n//Segunda fecha:\n");
	printf("Dia: ");
	scanf("%d", &fch2.dia);
	printf("Mes: ");
	scanf("%d", &fch2.mes);
	printf("Anio: ");
	scanf("%d", &fch2.anio);
	if(validarFecha(fch2))
		printf("//Fecha correcta.\n");
	else
	{
		printf("Error al ingresar la fecha. El programa finalizara.\n");
		return 1;
	}

	printf("\n------Resultado------\n");
	printf("Cantidad de dias: %d\n\n", cantDias(fch1, fch2) );

	// fin
	system("pause");
	return 0;
}

/*---Funciones---*/

//--cantDias--//
int cantDias (t_fecha fecha1, t_fecha fecha2)
{
	int acum=0;

	if (fecha2.anio==fecha1.anio && fecha2.mes == fecha1.mes)
		return (fecha2.dia - fecha1.dia);
	else
	{
		acum += cantidadDiasDelMes(fecha1.mes, fecha1.anio) - fecha1.dia;
        acum += fecha2.dia;
		while (fecha1.anio <= fecha2.anio)
			if (fecha1.anio == fecha2.anio && (fecha1.mes == fecha2.mes-1 || fecha1.mes == fecha2.mes) )
				return acum;
			else
			{
				fecha1.mes++;
				if (fecha1.mes <= 12)
                    acum += cantidadDiasDelMes(fecha1.mes, fecha1.anio);
				else
				{
					fecha1.mes = 1;
					fecha1.anio++;
				}
			}
	}

	return acum;
}

//--validarFecha--//
int validarFecha (t_fecha fecha)
{
  if( fecha.anio>=0 && fecha.anio<=7000)
    if ( fecha.mes>= 1 &&  fecha.mes<= 12 )
        if( fecha.dia >=1 && fecha.dia <= cantidadDiasDelMes(fecha.mes,fecha.anio) )
           return 1;

   return 0;
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
