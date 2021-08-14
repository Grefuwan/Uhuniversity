#include <string.h>
#include "Cliente.h"

Cliente::Cliente(long int dni, char *nombre, Fecha f):fechaAlta(f){
    this->dni = dni;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

Cliente::~Cliente(){
    delete [] this->nombre;
}

void Cliente::setNombre(char *nombre){
    delete [] this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}
void Cliente::setFecha(Fecha f){
    fechaAlta = f;
}

Cliente& Cliente::operator=(const Cliente& c) {
  if (this != &c) { //No se permite copiar a si mismo
    this->dni=c.dni;
    delete [] this->nombre;
    this->nombre=new char[strlen(c.nombre)+1];
    strcpy(this->nombre, c.nombre);
    this->fechaAlta=c.fechaAlta;
  }
  return *this;
}

bool Cliente::operator==(const Cliente &c) const{
    return this->dni == c.dni;
}

std::ostream& operator<<(std::ostream& s, const Cliente &o) {
    s << o.getNombre() << " (" <<  o.getDni() << " - " << o.getFecha() << ")";
    return s;
}
