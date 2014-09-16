/*Proceso obtenido de: 
http://www.taringa.net/posts/info/928508/Como-calcular-el-dia-que-cae-una-fecha.html
*/

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
int diaDelMes(t_fecha fecha);
int obtenerClave (int mes);
int ultimosDos (int anio);
int siglo(int anio);

int main ()
{
	//variabes
	t_fecha fch;

	//programa
	printf("Ingresa una fecha:\n");
	printf("Dia: ");
	scanf("%d", &fch.dia);
	printf("Mes: ");
	scanf("%d", &fch.mes);
	printf("Anio: ");
	scanf("%d", &fch.anio);

	if(validarFecha(fch))
		printf("\n//Fecha correcta.\n");
	else
		return 1;

	printf("\n----------Resultado----------\n");

	switch(diaDelMes(fch))
	{
		case 0:
			printf("El dia de la fecha '%02d/%02d/%d' es: Domingo\n\n", fch.dia, fch.mes, fch.anio);
			break;
		case 1:
			printf("El dia de la fecha '%02d/%02d/%d' es: Lunes\n\n", fch.dia, fch.mes, fch.anio);
			break;
		case 2:
			printf("El dia de la fecha '%02d/%02d/%d' es: Martes\n\n", fch.dia, fch.mes, fch.anio);
			break;
		case 3:
			printf("El dia de la fecha '%02d/%02d/%d' es: Miercoles\n\n", fch.dia, fch.mes, fch.anio);
			break;
		case 4:
			printf("El dia de la fecha '%02d/%02d/%d' es: Jueves\n\n", fch.dia, fch.mes, fch.anio);
			break;
		case 5:
			printf("El dia de la fecha '%02d/%02d/%d' es: Viernes\n\n", fch.dia, fch.mes, fch.anio);
			break;
		case 6:
			printf("El dia de la fecha '%02d/%02d/%d' es: Sabado\n\n", fch.dia, fch.mes, fch.anio);
			break;
		defalut:
			printf("Ocurrio un error inesperado.\n\n");
			break;
	}

	//fin
	system ("pause");
	return 0;
}

/*----funciones----*/
//--diaDelMes--//
int diaDelMes(t_fecha fecha)
{
	int dia;

	dia = fecha.dia + obtenerClave(fecha.mes) + ultimosDos(fecha.anio) + (int)(ultimosDos(fecha.anio)/4) + siglo(fecha.anio);

	dia %= 7;

	return dia;
}

//--obtenerClave--//
int obtenerClave (int mes)
{
	switch(mes)
	{
		case 1:
			return 0;
		case 2:
			return 3;
		case 3:
			return 3;
		case 4:
			return 6;
		case 5:
			return 1;
		case 6:
			return 4;
		case 7:
			return 6;
		case 8:
			return 2;
		case 9:
			return 5;
		case 10:
			return 0;
		case 11:
			return 3;
		case 12:
			return 5;
		default:
			return 0;
	}
}

//--siglo--//
int siglo(int anio)
{
	if (anio >1899 && anio < 2000)
		return 0;
	if (anio > 1999 && anio < 3000)
		return 6;

	return 0;
}

//--ultimosDos--//
int ultimosDos (int anio)
{
	if(anio>1999 && anio <2100)
		return anio-2000;
	if(anio>1899 && anio <2000)
		return anio-1900;
	if(anio>2099 && anio <2200)
		return anio-2100;
	if(anio>1799 && anio <1900)
		return anio-1800;

	return 0;
}

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
