#include "arbol.h"

/* Árbol */
void crearArbol(t_arbol *p)
{
	*p = NULL;
}

void enOrden(const t_arbol *p, FILE *pf)
{
	if(*p)
	{
		enOrden(&(*p)->izq, pf);
		verNodo(p);
        fprintf(pf,"Nro cuenta: %d | Nro Registro: %04d // Nodo: %p\n",
           (*p)->info.nro_cta, (*p)->info.nro_reg, *p);
		enOrden(&(*p)->der, pf);
	}
}

int ponerEnArbol(t_arbol *p, const t_reg *d,const int linea)
{
	if(*p)
	{
		int cmp = comparar(&(*p)->info, d);
		if(cmp == 0) //son iguales
			return CLA_DUP;
		if(cmp > 0) //Primera más grande
			return ponerEnArbol(&(*p)->izq, d, linea);
		else
			return ponerEnArbol(&(*p)->der, d, linea);
	}
	*p = (t_nodo *)malloc(sizeof(t_nodo));
	if(*p == NULL)
		return SIN_MEM;
	(*p)->info.nro_cta = d->nro_cta;
	(*p)->info.nro_reg = linea;
	(*p)->izq = NULL;
	(*p)->der = NULL;
	verNodo(p);
	return TODO_BIEN;
}

void verNodo(const t_arbol *p)
{
    printf("Nro cuenta: %d | Nro Registro: %04d // Nodo: %p\n",
           (*p)->info.nro_cta, (*p)->info.nro_reg, *p);
}

int comparar(const t_info *d1, const t_reg *d2)
{
	return d1->nro_cta - d2->nro_cta;
}

/* Archivos */
void crearBinario()
{
	FILE *pf = fopen(n_arch, m_arch);
	int i=0;
	t_reg aux[] ={
				{100,"Ariel, Mol",{15,2,2012},{10,11,2014},1500.,'B'},
				{200,"Karen, Mol",{15,2,2012},{10,11,2014},3.5,'B'},
				{300,"Fede, Perez",{15,2,2012},{15,2,2013},0,'B'},
				{400,"Gaby, Bona",{15,2,2012},{15,2,2014},0.,'B'},
				{500,"Jess, Mol",{15,2,2012},{15,2,2014},5000.,'A'}
				};

	while(pf!=NULL && i<5)
    {
        fwrite(&aux[i], sizeof(t_reg), 1, pf);
        i++;
    }
    fclose(pf);
}

void mostrarArchivo (FILE *fp)
{
    t_reg aux2;
    rewind(fp);
    printf("----RegistrosBinarios----\n");
    while(fread(&aux2, sizeof(t_reg), 1, fp))
    {
        printf("%d | %-14s | %02d/%02d/%04d | %02d/%02d/%04d | %-6.1f | %c \n",
               aux2.nro_cta,
               aux2.nombre_titular,
               aux2.fch_alta.di, aux2.fch_alta.me, aux2.fch_alta.an,
               aux2.fch_ult_mov.di, aux2.fch_ult_mov.me, aux2.fch_ult_mov.an,
               aux2.saldo,
               aux2.estado);
    }
    rewind(fp);
}

int actualizarEstado(FILE *pf, t_reg d)
{
    d.saldo = 100;
    d.estado = 'B';

    if(!feof(pf))
    {
        fseek(pf,-(sizeof(t_reg)),SEEK_CUR);
        fwrite(&d,sizeof(t_reg),1,pf);
        fseek(pf,0,SEEK_CUR);
        return 1;
    }
    return 0;
}

int abrirArchivo(FILE **pf, const char *nombre, const char *modo, int MSJ)
{
	*pf=fopen(nombre, modo);

	if(*pf==NULL && MSJ == CON_MSJ)
		fprintf(stderr, "Error abriendo '%s' en modo '%s' \n", nombre, modo);

	return *pf!=NULL;
}

/*int guardar(t_info *d, FILE *pf)
{
	if(*pf!=NULL)
		fprintf(fp,"Nro cuenta: %d | Nro Registro: %04d // Nodo: %p\n", d->nro_cta, d->nro_reg, *d);
	return 0;
}*/
