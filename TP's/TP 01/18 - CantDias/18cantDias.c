#include <stdio.h>

typedef struct
{
	int dia,
		mes,
		anio;
} t_fecha;

int cantDias (t_fecha, t_fecha);
int cantidadDiasDelMes(int, int);
int bisiesto (int);

int main ()
{
	// variables
	t_fecha fch1,
			fch2;

	// programa
	printf ("-----Cantidad de dias entre dos fechas-----\n");
	printf("//Primera fecha:\n");
	printf("Dia: ");
	scanf("%d", &fch1.dia);
	printf("\nMes: ");
	scanf("%d", &fch1.mes);
	printf("\nAnio: ");
	scanf("%d", &fch1.anio);
	printf("\n\n");
	printf("//Segunda fecha:\n");
	printf("Dia: ");
	scanf("%d", &fch2.dia);
	printf("\nMes: ");
	scanf("%d", &fch2.mes);
	printf("\nAnio: ");
	scanf("%d", &fch2.anio);
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
	t_fecha aux;
	int cd = (fecha2.anio-fecha1.anio)*365;

	if(fecha1.mes == fecha2.mes)
	{
		cd += fecha2.dia - fecha1.dia;
		return cd;
	}
	else
	{
		
	}
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