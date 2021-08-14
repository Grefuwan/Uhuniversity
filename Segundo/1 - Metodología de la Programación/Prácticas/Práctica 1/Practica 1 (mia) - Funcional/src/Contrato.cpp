#include "Contrato.h"

unsigned int Contrato::nContrato=1;

Contrato::Contrato(long int d, Fecha f): idContrato(nContrato), fechaContrato(f){
    //idContrato=n; //ERROR: hay que ponerlo arriba porque es Const
    Contrato::nContrato++;
    this->dniContrato=d;
    //fechaContrato=f;  //Hay que ponerlo arriba porque es Fecha
}

Contrato::~Contrato(){
    //dtor
}

void Contrato::ver() const {
     cout << this->dniContrato << " (" << this->idContrato << " - ";
  this->fechaContrato.ver(); //llamo al ver del objeto fecha
  cout << ")";
}

std::ostream& operator<<(ostream &s, const Contrato &c){
    s << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << " )" << endl;
    return s;
}
