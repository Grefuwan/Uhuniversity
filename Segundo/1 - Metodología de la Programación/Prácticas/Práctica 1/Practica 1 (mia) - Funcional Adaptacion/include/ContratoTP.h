#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <iostream>
//#include "Fecha.h"
#include "Contrato.h"

using namespace std;

class ContratoTP: public Contrato{
    static int minutosTP;       //Minutos que vienen con la Tarifa plana
    static float precioTP;      //Precio de la Tarifa plana
    static const float precioExcesoMinutos;
    //static int MinutosHablados; //No Borja

public:
    ContratoTP(long int dni, Fecha f, int minHab);
    ContratoTP(const ContratoTP& c);                        // -   ¿Es necesario? Pensar y reflexionar
    virtual ~ContratoTP();                                  // -   ¿Es necesario? Pensar y reflexionar
    //ContratoTP& operator=(const ContratoTP& c);           // -   ¿Es necesario? Pensar y reflexionar

    virtual void nada() const { ; }

    void ver() const;
    float factura() const;

    //--Setters
    static void setTarifaPlana(int min, float precio);  //MinutosTP=min, precioTP=precio - En el .cpp se pone la cabecera sin el static
    static void setPrecio(float p);
    static void setLimiteMinutos(int LimMin);
    //static void setMinutosHablados(int min); //No Borja
    //--Getters
    static int getLimiteMinutos()   {return ContratoTP::minutosTP;}
    static int getPrecio()          {return ContratoTP::precioTP;}   //No haria falta poner ContratoTP::
    //int getMinutosHablados() {return ContratoTP::MinutosHablados;} //No Borja
};

ostream& operator<<(ostream &s, const ContratoTP &c);

#endif // CONTRATOTP_H
