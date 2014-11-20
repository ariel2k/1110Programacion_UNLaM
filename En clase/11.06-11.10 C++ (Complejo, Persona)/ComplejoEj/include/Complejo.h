#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>
using namespace std;
class Complejo
{
    float re,
		  im;
    public:
        //Complejo();
        //virtual ~Complejo();
 		Complejo(float re=0, float im=0); //constructor
 		void mostrar() const;
 		friend ostream& operator<< (ostream &sal, const Complejo &obj);
 		friend istream& operator>> (istream &ent, Complejo &obj);

 		Complejo operator+ (const Complejo &obj) const; 			//c1+c2  	(1)
 		Complejo operator+ (float val) const;						//c1+n		(2)
 		friend Complejo operator+ (float val, const Complejo &obj); //n+c1		(3)

 		Complejo& operator++ (); 	//pre-incremento
 		Complejo  operator++ (int); //pos-incremento

};

#endif // COMPLEJO_H
