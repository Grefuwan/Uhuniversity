#ifndef EMPRESA_H
#define EMPRESA_H

#include "Fecha.h"
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoTP.h"
#include "ContratoMovil.h"

using namespace std;

class Empresa{
    Cliente *clientes[100]; //Array estatico de 100, punteros a Clientes
    int ncli;               //Para saber cuantos clientes hay en el array (al principio 0)
    const int nmaxcli;      //Constante que indica cuantos caben en el array clientes (100)
    Contrato **contratos;   //Array dinamico de punteros a Contratos (capacidad ilimitada)
    int ncon;               //Para saber cuantos contratos hay en el array (al principio 0)
    int nmaxcon;            //Para saber cuantos caben en array Contratos. No constante

protected:
    int buscarCliente(long int dni) const;  //Si no existe devuelve -1 y si existe devuelve la posicion del cliente en el array Clientes
    int altaCliente (Cliente *c);   //Añade el cliente apuntado por c al array de clientes. Devuelve la posicion donde lo mete (-1 si no cabe)

public:
    Empresa();
    virtual ~Empresa();
        //El constructor de Copia y el Operador de Asignacion no lo implementamos
        //porque explicitamente se indica en la practica que no se haga

    void crearContrato();
    bool cancelarContrato(int idContrato);  //True si el Contrato existe, false si no
    bool bajaCliente(long int dni);         //True si el Cliente existe, false si no
    int descuento (float porcentaje) const; //Devuelve a cuantos se aplica el descuento
    int nContratosTP() const;
    void ver() const;
    void cargarDatos();                     //Carga 3 clientes y 7 contratos. Metodo creado para no
                                            //tener que meter datos cada vez que pruebo el programa
};

#endif // EMPRESA_H
