#ifndef HORA_H
#define HORA_H


class Hora
{
    long segundos; //Interpreto a la hora como seg y luego para mostrar le pongo formato.
    public:
        Hora();
        Hora (int hh, int mm, int ss);
        //virtual ~Hora();

        Hora& operator++ (); 	//pre-incremento
        Hora  operator++ (int);	//pos-incremento
        Hora& operator-- ();	//pre-decremento
        Hora  operator-- (int); //pos-decremento

        Hora  operator+ (const Hora &obj) const; 	// h1 + h2 		(01)
        Hora  operator- (const Hora &obj) const;	// h1 - h2		(02)
        friend Hora operator + (int, const Hora &obj); // n + h1	(03)
      	Hora  operator- (int n) const;				// h1 + n		(04)
        Hora& operator+= (const Hora &obj); 		// h1 += h2  	(05)
        Hora  operator/ (int n) const;				// h1 / n 		(06)

};

#endif // HORA_H
