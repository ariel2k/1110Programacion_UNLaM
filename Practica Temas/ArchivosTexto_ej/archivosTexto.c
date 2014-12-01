#include "archivosTexto.h"

//--abrirAchivo--//
int abrirArchivo (FILE **fp, const char *nombre, const char *modo, int conSin)
{
	*fp=fopen(nombre, modo);

	if(*fp==NULL && conSin == CON_MSJ)
		fprintf(stderr, "Error abriendo '%s' en modo '%s' \n", nombre, modo);

	return *fp!=NULL;
}


int leerYMostrarEstatico(FILE *fp)
{
	t_pers reg;
	char linea[50], *cad;
	rewind(fp);
	printf("DNI   Nombre     Edad\n");
	while(!feof(fp) && fgets(linea, sizeof(linea), fp))
	{
	    cad = strchr(linea, '\n');
		if(cad==NULL)
		{
			cad = strchr(linea, '\0');
			if(cad==NULL)
            {
			fprintf(stderr, "Error linea de txt muy larga\n");
			fclose(fp);
			return 2;
            }
		}
		*cad = '\0';

		//edad
		cad -= sizeof(int);
		sscanf(cad,"%d", &reg.edad);
		*cad = '\0';

		//apyn
		cad -= sizeof(char[13]);
		strcpy(reg.apyn, cad);
		*cad = '\0';

		//dni
		sscanf(linea,"%ld", &reg.dni);

		printf("%ld %-13s %d\n", reg.dni, reg.apyn, reg.edad);
	}
	return 0;
}

int leeryMostrarDinamico(FILE *fp)
{
    rewind(fp);
	t_pers reg;
	char linea[50],
		 *aux;
	rewind(fp);
	printf("DNI   Nombre     Edad\n");
	while(!feof(fp) && fgets(linea, sizeof(linea), fp))
	{
		aux = strchr(linea, '\n');
		if(aux==NULL)
		{
		    aux = strchr(linea, '\0');
            if(aux==NULL)
            {
			fprintf(stderr, "Error linea de txt muy larga\n");
			fclose(fp);
			return 2;
            }
		}
		*aux = '\0';

		//Cuando no me garantizan que el archivo viene bien armado
		if(!validarCampos(linea,'|',2))
		{
			fprintf(stderr, "ERROR, linea con campos erroneos\n");
			fclose(fp);
			return 4;
		}

		//edad
		aux = strrchr(linea,'|');
		sscanf(aux+1,"%d", &reg.edad);
		*aux = '\0';

		//apyn
		aux = strrchr(linea,'|');
		strcpy(reg.apyn, aux+1);
		*aux = '\0';

		//dni
		sscanf(linea,"%ld", &reg.dni);

		printf("%ld %-13s %d\n", reg.dni, reg.apyn, reg.edad);
	}
    return 0;
}

int validarCampos (const char *s, char sep, int cant)
{
    while(*s)
    {
        if(*s==sep)
            cant--;
        s++;
    }

    return cant==0;
}

