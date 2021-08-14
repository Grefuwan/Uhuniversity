#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "paciente.h"

#define INCREMENTO 1

class cola{
    Paciente *elementos; //elementos de la cola
    int inicio, fin; //principio y fin de la cola
    int Tama; //Capacidad de la tabla
    int ne; //Nº de elementos
public:
    cola();
    ~cola();
    void insertar(Paciente e);
    Paciente sacar();
    bool esVacia();
    Paciente consultar();
    int longitud();
    void vaciar();
    void clonar(cola &c);
};

#endif // COLA_H_INCLUDED
