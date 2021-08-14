#include <cstdlib>
#include <cstring>  //strlen, strcpy
#include <iomanip>  //std::setprecision
#include <sstream>  //stringstream

#include "Cliente.h"


//---Constructores y Destructor---
Cliente::Cliente(long int d, char *nom, Fecha F):fechaAlta(F){
    this->dni=d;
    this->nombre = new char[strlen(nom)+1];
    strcpy(this->nombre, nom);
}

Cliente::~Cliente(){
    delete [] this->nombre;
}

//---Metodos---
    //--Setters--
void Cliente::setNombre(char *nombre){
    delete[]this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cliente::setFecha(Fecha f){
    fechaAlta=f;
}

//---Sobrecargas---
Cliente& Cliente::operator=(const Cliente& c){
    if (this!=&c){
        this->dni=c.dni;
        delete[]this->nombre;
        this->nombre = new char [strlen(c.nombre)+1];
        strcpy(this->nombre, c.nombre);
        this->fechaAlta=c.fechaAlta;
    }
    return *this;
}

bool Cliente::operator==(Cliente &c) const{
    if (this->dni != c.dni)
        return false;
    if (strcmp(this->nombre,c.nombre)!=0)
        return false;
    if (this->fechaAlta.getDia() != c.fechaAlta.getDia() ||
        this->fechaAlta.getMes() != c.fechaAlta.getMes() ||
        this->fechaAlta.getAnno() != c.fechaAlta.getAnno() )
            return false;
    return true;
}

ostream& operator<<(ostream &s, const Cliente &c){
    cout << "Nombre: " << c.getNombre() << " - DNI: " << c.getDni() << " - Fecha: " << c.getFecha() << endl;
    return s;
}
