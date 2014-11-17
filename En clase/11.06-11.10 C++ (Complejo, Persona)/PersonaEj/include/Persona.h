#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
   	char apyn[41];
   	char sex;
   	long dni;

	public:
		Persona();
		Persona(long dni, const char* apyn, char sex);
};

#endif // PERSONA_H
