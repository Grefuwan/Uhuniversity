#include "ContratoTP.h"

int         ContratoTP::minutosTP           =300;
float       ContratoTP::precioTP            =10;
const float ContratoTP::precioExcesoMinutos =0.15;

ContratoTP::ContratoTP(long int dni, Fecha f, int minHab):Contrato(dni, f){
    this->minutosHablados=minHab;
}

ContratoTP::ContratoTP(const ContratoTP &c): Contrato(c.getDniContrato(), c.getFechaContrato()){
    this->minutosHablados=c.minutosHablados;
}

ContratoTP::~ContratoTP()
{
    //dtor
}

void ContratoTP::ver() const{
    Contrato::ver();
    cout << " Minutos Hablados: " << this->minutosHablados << ". MinutosTP: " << this->minutosTP << ". PrecioExcesoMinuto: " << this->precioTP << ". Factura: "<< this->factura() << "e" << endl;
}

float ContratoTP::factura() const{
    return precioTP + (minutosHablados>minutosTP?(minutosHablados-minutosTP)*precioExcesoMinutos:0);
}

void ContratoTP::setLimiteMinutos(int LimMin){
    minutosTP=LimMin;
}

void ContratoTP::setPrecio(float p){
    precioTP=p;
}

void ContratoTP::setTarifaPlana(int m, float p){
    ContratoTP::minutosTP=m;
    ContratoTP::precioTP=p;
}

/*void ContratoTP::setMinutosHablados(int min){
    ContratoTP::MinutosHablados=min;
}*/

ostream& operator<< (ostream& s, const ContratoTP &o){
    s << o.getDniContrato() << " (" << o.getIdContrato() << " - " << o.getFechaContrato() << ") " << o.getMinutosHablados() << "m, " << ContratoTP::getLimiteMinutos()<< "(" << ContratoTP::getPrecio() << ") " << " - " << o.factura() << "e";
}
