#include "empleado.h"

using namespace std;

PersonaDos::PersonaDos()
//	:	dni(0), sex(' '), apyn(NULL)
{
    dni=0;
    sex=' ';
    apyn=NULL;
}

PersonaDos::PersonaDos(long dni, char sex, const char* apyn)
//	:	dni(dni), sex(sex)
{
    this->dni = dni;
    this->sex = sex;
    this->apyn = duplicarCadena(apyn);
	if(apyn && *apyn && this->apyn==NULL)
	{
		//Debería ejecutarse una excepción o al menos esto:
		cout << "Sin memoria - Constructor paramétrizado" << endl;
	}
}

PersonaDos::PersonaDos(const PersonaDos &obj)
//	:	dni(obj.dni), sex(obj.sex), apyn(duplicarCadena(obj.apyn))
{
    dni = obj.dni;
    sex = obj.sex;
    apyn = duplicarCadena(obj.apyn);
	if(obj.apyn && *obj.apyn && this->apyn==NULL)
	{
		//Debería ejecutarse una excepción o al menos esto:
		cout << "Sin memoria - constructo de copia" << endl;
	}
}

PersonaDos::~PersonaDos()
{
    delete []apyn;
    apyn = NULL; //Después de destruirlo le asigna NULL para cuando se ejecute el proximo destructor, no haga nada.
}


PersonaDos& PersonaDos::operator= (const PersonaDos &obj)
{
    dni = obj.dni;
    sex = obj.sex;
	delete []apyn;
	apyn = duplicarCadena(obj.apyn);
	if(obj.apyn && *obj.apyn && this->apyn==NULL)
	{
		//Debería ejecutarse una excepción o al menos esto:
		cout << "Sin memoria - operator=" << endl;
	}
	return *this;
}

ostream& operator<< (ostream &sal, const PersonaDos &obj)
{
	sal << "DNI: " << obj.dni << endl
		<< "APyN: " << (duplicarCadena(obj.apyn) ? obj.apyn : "") << endl
		<< "Sexo: " << obj.sex << endl;
	return sal;
}

istream& operator>> (istream &ent, PersonaDos &obj)
{
	cout << "DNI: ";
	ent	 >> obj.dni;
	cout << "Sexo: ";
	ent	 >> obj.sex;
	char aux[500];
	cout << "APyN: ";
	ent.ignore(1000, '\n');
	ent.getline(aux, sizeof(aux), '\n');// .getline(aux, sizeof(aux), "\n");
	//ent.ignore(1000, '\n');
	delete []obj.apyn;
	obj.apyn = duplicarCadena(aux);
	if(obj.apyn == NULL && aux[0]!='\n')
	{
		//Debería ejecutarse una excepción o al menos esto:
		cout << "Sin memoria - operator>>" << endl;
	}
	return ent;
}

///////////////

Emple :: Emple()
// :legajo(0), sueldo(0), PersonaDos()
{
        PersonaDos();
        legajo=0;
        sueldo=0.;
}

Emple :: Emple(long dni, char sex, const char *apyn, long legajo, double sueldo)
//  :PersonaDos(dni, sex, apyn), legajo(legajo), sueldo(sueldo)
{
    (PersonaDos &)*this=PersonaDos(dni, sex, apyn);
    this->legajo=legajo;
    this->sueldo=sueldo;
}

Emple :: Emple(const Emple &obj)
 //   :PersonaDos((PersonaDos&)obj)
{
    PersonaDos((PersonaDos &)obj);
    legajo=obj.legajo;
    sueldo=obj.sueldo;
}

Emple &Emple::operator=(const Emple &obj)
{
    legajo=obj.legajo;
    (PersonaDos &)*this=(PersonaDos &)obj;
    sueldo= obj.sueldo;
    return *this;
}

ostream &operator<<(ostream &sal, const Emple &obj)
{
    sal<<(PersonaDos &)obj
    <<"Legajo: "<<obj.legajo<<endl
    <<"sueldo: "<<obj.sueldo<<endl;
    return sal;
}
