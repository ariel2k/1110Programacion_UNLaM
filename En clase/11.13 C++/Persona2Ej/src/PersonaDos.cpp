#include "PersonaDos.h"

using namespace std;

//------------------------------Métodos públicos------------------------------//

PersonaDos::PersonaDos()
	:	dni(0), sex(' '), apyn(NULL) {}

PersonaDos::PersonaDos(long dni, char sex, const char* apyn)
	:	dni(dni), sex(sex)
{
    this->apyn = duplicarCadena(apyn);
	if(apyn && *apyn && this->apyn==NULL)
	{
		//Debería ejecutarse una excepción o al menos esto:
		cout << "Sin memoria - Constructor paramétrizado" << endl;
	}
}

PersonaDos::PersonaDos(const PersonaDos &obj)
	:	dni(obj.dni), sex(obj.sex), apyn(duplicarCadena(obj.apyn))
{
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
	ent.getline(aux, sizeof(aux), '\n');// .getline(aux, sizeof(aux), "\n");
	ent.ignore(1000, '\n');
	delete []obj.apyn;
	obj.apyn = duplicarCadena(aux);
	if(obj.apyn == NULL && aux[0]!='\n')
	{
		//Debería ejecutarse una excepción o al menos esto:
		cout << "Sin memoria - operator>>" << endl;
	}
	return ent;
}
