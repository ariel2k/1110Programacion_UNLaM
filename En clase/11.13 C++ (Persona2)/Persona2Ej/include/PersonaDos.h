#ifndef PERSONADOS_H
#define PERSONADOS_H
#include <iostream>
#include "../dupcad.h"

using namespace std;

class PersonaDos
{
	long dni;
	char *apyn;
	char sex;

    public:
		PersonaDos();
		//virtual ~PersonaDos();
		PersonaDos(long dni, char sex, const char* apyn);
		~PersonaDos();
		PersonaDos(const PersonaDos &obj);		//constructor de copia
		PersonaDos& operator= (const PersonaDos &obj); //p1=p2
		friend ostream& operator<< (ostream &sal, const PersonaDos &obj);
		friend istream& operator>> (istream &ent, PersonaDos &obj);

};

#endif // PERSONADOS_H
