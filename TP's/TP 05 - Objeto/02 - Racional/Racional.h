#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED
#include <iostream>
using namespace std;

class Racional
{
	int num,
		den;

	int mcd (int a, int b);
	
public:
	Racional(int num=1, int den=1);
	Racional operator+ (const Racional &obj) const

	double valorReal(); 
};

#endif // RACIONAL_H_INCLUDED
