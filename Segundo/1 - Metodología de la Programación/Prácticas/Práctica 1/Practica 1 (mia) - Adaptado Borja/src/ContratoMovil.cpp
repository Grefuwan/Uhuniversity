#include "ContratoMovil.h"
#include "string.h"

ContratoMovil::ContratoMovil(long int dni, Fecha f, float precioMinuto, int minutosHablados, const char *nac) : Contrato(dni, f){
    this->precioMinuto = precioMinuto;
    this->minutosHablados = minutosHablados;
    this->nac = new char[strlen(nac)+1];
    strcpy(this->nac, nac);

}
ContratoMovil::ContratoMovil(const ContratoMovil &c) : Contrato(c.getDniContrato(), c.getFechaContrato()){
    this->precioMinuto = c.precioMinuto;
    this->minutosHablados = c.minutosHablados;
    this->nac = new char[strlen(c.nac)+1];
    strcpy(this->nac, c.nac);
}

ContratoMovil::~ContratoMovil(){
    delete [] this->nac;
}


void ContratoMovil::ver() const{
    std::cout << *this;
}
float ContratoMovil::factura() const{
    return precioMinuto*minutosHablados;
}

void ContratoMovil::setNacionalidad(const char *nac){
    delete this->nac;
    this->nac = new char[strlen(nac)+1];
    strcpy(this->nac, nac);
}


std::ostream& operator<<(std::ostream& s, const ContratoMovil &o) {
    s << o.getDniContrato() << " (" << o.getIdContrato() << " - " << o.getFechaContrato() << ") " << o.getMinutosHablados() << "m, " << o.getNacionalidad() << " " << o.getPrecioMinuto() << " - " << o.factura() << "e"; //TODO: Intentar imprimir el euro
    return s;
}
