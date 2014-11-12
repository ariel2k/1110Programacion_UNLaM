#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>

class Complejo
{
    float re,
		  im;
    public:
        //Complejo();
        //virtual ~Complejo();
 		Complejo(float re=0, float im=0); //constructor
 		void mostrar() const;
 		friend iostream& operator<< (iostream &sal, const Complejo &obj);

 		Complejo operator+ (const Complejo &obj) const; 			//c1+c2  	(1)
 		Complejo operator+ (float val) const;						//c1+n		(2)
 		friend Complejo operator+ (float val, const Complejo &obj); //n+c1		(3)

 		friend istream& operator>> (istream &ent, Complejo &obj);
 		Complejo& operator++ (); 	//pre-incremento
 		Complejo  operator++ (int); //pos-incremento

};

#endif // COMPLEJO_H
