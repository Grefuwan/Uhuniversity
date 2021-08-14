#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha
{
    int dia, mes, anno;
    public:
        Fecha(const int &dia,const int &m,const int &anno);  //Al ponerle los mismos nombres que los atributos, en el .cpp no podré ponerle dia=dia, sino this->dia=dia
        //Al constructor tambien se le puede poner & a cada atributo para que sea más rápido
        virtual ~Fecha(); //Como no hay puntero, no hay por qué hacer el destructor
        //Tampoco hace falta el constructor de copia porque la clase no tiene punteros/ memoria dinamica

        int getDia()    const {return dia;}
        int getMes()    const {return mes;}
        int getAnno()   const {return anno;}

        void setFecha(const int &dia,const int &mes,const int &anno);  //Se le puede poner un & a cada atributo, para que fuera aun más eficiente

        bool bisiesto() const; //Como no modifica nada, se le pone la coletilla const
        void ver() const;

        Fecha operator++();                 //++Fecha
        Fecha operator++(int i);            //Fecha++
        Fecha operator+(int i) const;       //Suma Fecha+Entero

        friend Fecha operator+(const int &i, const Fecha &f);
        friend std::ostream& operator<<(std::ostream& s, const Fecha &o);

};

Fecha operator+(const int &i, const Fecha &f);
std::ostream& operator<<(std::ostream& s, const Fecha &o);

#endif // FECHA_H
