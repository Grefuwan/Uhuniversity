#ifndef FECHA_H
#define FECHA_H

#include <iostream>

class Fecha{
    int dia;
    int mes;
    int anio;
public:
    Fecha(const int &dia, const int &mes, const int &anio);

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }

    bool bisiesto() const;
    void setFecha(const int &dia, const int &mes, const int &anio);
    void ver() const;

    Fecha operator++();
    Fecha operator++(int flag);
    Fecha operator+(int a) const;

    void verBonita(std::ostream& s);

friend Fecha operator+(const int &a, const Fecha &f);
friend std::ostream& operator<<(std::ostream& s, const Fecha &o);
};


Fecha operator+(const int &a, const Fecha &f);

std::ostream& operator<<(std::ostream& s, const Fecha &o);


#endif // FECHA_H
