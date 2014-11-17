#include "Persona.h"
#include <string.h>

Persona::Persona()
{
    this->apyn[0] = '\0';
    // *apyn = '\0';
    // *this->apyn = '\0';
    // strcpy (apyn, "");
    this->sex = ' ';
    this->dni = 0;
}

/*Persona::~Persona()
{
    //dtor
}*/

Persona::Persona (long dni, const char* apyn, char sex)
{
	this->apyn[0] = '\0';
	if (apyn)
		strncat (this->apyn, apyn, sizeof(this->apyn)-1);
		//strcpy (this->apyn, apyn, sizeof(this->apyn)-1);
		//this->apyn[sizeof(this->apyn)-1] = '\0';
	this->dni=dni;
	this->sex=sex;
}
