#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>

using namespace std;


class Complejo
{
    int real;
    int imaginaria;

    public:
        Complejo(int r, int i);
        virtual ~Complejo();

        int getr() const { return real; }   //El const hay que ponerlo en esa posicion
        int geti() const { return imaginaria; }

        void set (int r, int i) { real = r, imaginaria = i; }
        void set ();

        void ver() const;

        Complejo operator+(Complejo c);  //Como el error que da al hacer es "error: no match for 'operator+' (operand types are 'Complejo' and 'Complejo')
            //sobrecargo ese 'operator+' del propio C++


};

#endif // COMPLEJO_H
