#include <stdio.h>
#include "comparar.h"
#include <string.h>

int compXApyn (const t_info *d1, const t_info *d2)
{
	int cmp=strcmp(d1->apyn, d2->apyn);
	if (cmp==0)
		cmp=d1->sex - d2->sex;
	if (cmp)
		return cmp;
	return IGUAL;
}