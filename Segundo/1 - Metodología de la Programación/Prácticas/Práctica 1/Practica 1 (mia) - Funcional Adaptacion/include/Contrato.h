#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
#include "Fecha.h"

using namespace std;

class Contrato
{
    static unsigned int nContrato;

protected:

    const int idContrato;
    long int dniContrato;
    Fecha fechaContrato;

    int minutosHablados;

public:
        Contrato(long int d, Fecha f);  //d=dni
        virtual ~Contrato();

        virtual void ver() const;   //Le añado virtual para que sea polimorfica: es el unico metodo que se redeclara en las clases hijas

        virtual void nada() const =0;   //Metodo Virtual Puro
        //--Getters
        const int getIdContrato()           const   {return this->idContrato;}
        const long int getDniContrato()     const   {return this->dniContrato;}
        Fecha getFechaContrato()            const   {return this->fechaContrato;}
        int getMinutosHablados()            const   {return minutosHablados;}

        //--Setters
        void setFechaContrato(Fecha f)                  {this->fechaContrato=f;}
        void setDniContrato(long int dni)               {this->dniContrato=dni;}
        void setMinutosHablados(int minutosHablados)    {this->minutosHablados=minutosHablados;}
};

#endif // CONTRATO_H
