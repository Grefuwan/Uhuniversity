#include "ContratoMovil.h"

//--Constructores y Destructores--
ContratoMovil::ContratoMovil(long int dni, Fecha f, float p, int m, char *nac): Contrato(dni, f){
    this->precioMinuto=p;
    this->minutosHablados=m;
    //this->nacionalidad=nac; MAL
    this->nacionalidad=new char[strlen(nac)+1];
    strcpy(this->nacionalidad, nac);
}

ContratoMovil::~ContratoMovil() //--Implementarlo
{
    delete[] this->nacionalidad;
}

/*ContratoMovil::ContratoMovil(const ConratoMovil& c):Contrato(c){  Si pongo esta cabecera y no implemento un constructor de copia en Contrato
                                                                    no da error al compilar porque el compilador genera un constructor de copia por su cuenta
                                                                    El problema es el que genera el compilador al no incrementar el contador y asignaria el
                                                                    mismo codigo a ambos contratos
                                                                    Solucion: Implementar constructor de Copia en Contrato y usar esta cabecera...
}*/

ContratoMovil::ContratoMovil(const ContratoMovil& c): Contrato(c.getDniContrato(), c.getFechaContrato()){    //...o usar esta otra cabecera
    this->precioMinuto=c.precioMinuto;  //cout << "Copia Precios" << endl;
    this->minutosHablados=c.minutosHablados; //cout << "Copia minutos" << endl;
    this->nacionalidad=new char[strlen(c.nacionalidad)+1]; //cout << "Crea nacionalidad" << endl;
    strcpy(this->nacionalidad,c.nacionalidad); //cout << "Copia nacionalidad" << endl;
}



//--Metodos--
void ContratoMovil::ver() const{
    Contrato::ver();    //Importante: Llamamos al ver que heredo de mi padre para que muestre lo del padre y a continuacion
                        //solo me preocupo de mostrar lo que es exclusivo del hijo
    cout << "Minutos hablados: " << this->minutosHablados << ". Nacionalidad: " << this->nacionalidad << ". Precio minuto: " << this->precioMinuto << ". Factura: " << this->factura() << "e" << endl;
}

float ContratoMovil::factura() const{
    return precioMinuto*minutosHablados;
}

void ContratoMovil::setNacionalidad(const char* nac){
    delete this->nacionalidad;
    this->nacionalidad = new char[strlen(nac)+1];
    strcpy(this->nacionalidad, nac);
}


//--Sobrecargas--
std::ostream& operator<<(std::ostream &s, const ContratoMovil &o) {
    s << o.getDniContrato() << " (" << o.getIdContrato() << " - " << o.getFechaContrato() << ") " << o.getMinutosHablados() << "m, " << o.getNacionalidad() << " " << o.getPrecioMinuto() << " - " << o.factura() << "e"; //TODO: Intentar imprimir el euro
    return s;
}


/*ContratoMovil& ContratoMovil::operator==(const ContratoMovil& rhs){
    if (this== &rhs)    // handle self assignment
        return *this;
        //assignment operator
    return *this;
}*/
