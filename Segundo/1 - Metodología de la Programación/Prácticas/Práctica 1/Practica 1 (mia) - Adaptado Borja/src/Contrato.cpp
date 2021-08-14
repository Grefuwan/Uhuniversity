#include "Contrato.h"
#include <iostream>

unsigned int Contrato::contador = 1;

Contrato::Contrato(long int dni, Fecha f) : fechaContrato(f){
    this->dniContrato = dni;
    this->idContrato = contador++;
}

Contrato::~Contrato(){
}

void Contrato::ver() const{
    std::cout << dniContrato << "(" << idContrato << " - " << fechaContrato << ")";
}


std::ostream& operator<<(std::ostream& s, const Contrato &o) {
    s << o.getDniContrato() << "(" << o.getIdContrato() << " - " << o.getFechaContrato() << ")";
    return s;
}
