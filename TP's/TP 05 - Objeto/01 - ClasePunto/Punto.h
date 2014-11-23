#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED
#include <iostream>
#include "matrizEsferica.h"

#define esValidoX(x) ((x)>0 && (x)<=1023 ? (x) : esferica(&x,1024))
#define esValidoY(y) ((y)>0 && (y)<=676  ? (y) : esferica(&y,768))

using namespace std;

class Punto{
    int coordX,
        coordY;

public:
    Punto();
	Punto(int x);
	Punto(int x, int y);
	Punto& operator= (const Punto &obj);
	friend ostream& operator<< (ostream &sal, const Punto &obj);  //   cout << p3 
	friend istream& operator>> (istream &ent, Punto &obj);			// cin >> p1 
	
	Punto operator+ (const Punto &obj) const; 				//p1+p2  	(1)
	Punto operator- (const Punto &obj) const; 				//p1+p2  	(1)
	
	Punto& operator++ (); 	//pre-incremento
	Punto  operator++ (int); //pos-incremento
	Punto& operator-- (); 	//pre-decremento
	Punto  operator-- (int); //pos-decremento

	Punto operator+= (const Punto &obj);
	Punto operator-= (const Punto &obj);
};



#endif // PUNTO_H_INCLUDED
