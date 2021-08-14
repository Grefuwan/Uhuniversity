#ifndef EMPRESA_H
#define EMPRESA_H


#include "Fecha.h" //definicion clase Fecha
#include "Cliente.h" // definicion clase Cliente
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil

using namespace std;

class Empresa{
    Cliente *clientes[100];//array estático (tamaño 100)de punteros a Clientes
    int ncli;           //para saber cuántosclientes hay en el array (al principio 0)
    const int nmaxcli;//para saber cuántoscaben en el arrayclientes(100)
    Contrato **contratos;//array dinámico de punteros a Contratos
    int ncon;            //para saber cuántosContratos hay en el array (al principio 0)
    int nmaxcon;//para saber cuántoscaben en el array Contratos
public:
    Empresa();
    virtual ~Empresa();
    //EL CONTRUCTOR DE COPIA Y EL OPERADOR DE ASIGNACION NO LO IMPLEMENTAMOS
    //PORQUE EXPLICITAMENTE SE INDICA EN LA PRACTICA QUE NO SE HAGA

    void crearContrato();
    bool cancelarContrato(int idContrato); //true si elContratoexiste, false si no
    bool bajaCliente(long int dni);        //truesi el Cliente existe, false si no
    int descuento(float porcentaje) const;//devuelve a cuantos aplica el descuento
    int nContratosTP() const;
    void ver() const;

    void cargarDatos();

};

#endif // EMPRESA_H
