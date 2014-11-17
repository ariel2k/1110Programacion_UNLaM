#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include "dupcad.h"

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

class Emple : public PersonaDos
{
    public:
    long legajo;
    double sueldo;
    public:
        Emple(); //constructor
        Emple(long dni, char sex, const char *apyn, long legajo, double sueldo);
        Emple(const Emple &obj);
        Emple& operator= (const Emple &obj);
        friend ostream& operator<< (ostream &sal, const Emple &obj);

};

#endif // EMPLEADOS_H
