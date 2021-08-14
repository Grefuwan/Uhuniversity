#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H

#include<Contrato.h>

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"
#include "Contrato.h"

using namespace std;


class ContratoMovil:public Contrato{
    float precioMinuto;
    int minutosHablados;
    char *nacionalidad;

public:
    ContratoMovil(long int dni, Fecha f, float p, int m, char *nac);
    virtual ~ContratoMovil();               //Necesario porque hay un atributo puntero char*
    ContratoMovil(const ContratoMovil& c);  //Necesario porque hay un atributo puntero char*

    virtual void nada() const {;}

    //ContratoMovil& operator= (const ContratoMovil& c);
    /*  Necesario si en el main pensamos usar = para asignar; si NUNCA vamos a usarlo no hace falta implementarlo.
        Como ContratoMovil hereda un atributo constante idContrato que no puede modificarse, no podemos usar el = en el main
        y, por tanto, no lo implementamos. */

    //--Getters--
    float getPrecioMinuto()         const {return this->precioMinuto;}
    int getMinutosHablados()        const {return this->minutosHablados;}
    const char* getNacionalidad()   const {return this->nacionalidad;}

    //--Setters--
    void setPrecioMinuto(float precio)  {this->precioMinuto=precio;}
    void setMinutosHablados(int m)      {this->minutosHablados=m;}
    void setNacionalidad(const char* nac);
    void ver()      const;
    float factura() const;
};

ostream& operator<<(ostream &s, const ContratoMovil &c);

#endif // CONTRATOMOVIL_H
