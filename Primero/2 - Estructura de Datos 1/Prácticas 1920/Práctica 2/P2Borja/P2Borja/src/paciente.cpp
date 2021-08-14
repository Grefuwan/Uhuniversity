#include <string.h>
#include "paciente.h"

void copiarPaciente(Paciente &destino,Paciente &origen){
    destino.id = origen.id;
    strcpy(destino.nombre, origen.nombre);
    strcpy(destino.apellidos, origen.apellidos);
    destino.edad = origen.edad;
}

bool compararPaciente(Paciente &p1,Paciente &p2){
    return p1.id == p2.id;
}

int prioridadPaciente(Paciente &p){
    return p.edad/10 + 1;
}
