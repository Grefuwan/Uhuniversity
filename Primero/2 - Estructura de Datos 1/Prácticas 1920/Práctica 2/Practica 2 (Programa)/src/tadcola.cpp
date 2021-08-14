#include "tadcola.h"

cola::cola(){
    inicio=0;
    fin=-1;
}

void cola::encolar(Paciente Paci){
    if (fin+1<MAX){
    fin++;
    elementos[fin]=Paci;
    }
}

int cola::longitud() {
    return fin+1;
}

void cola::desencolar(){
    for(int i=inicio;i<fin;i++)
    elementos[i]=elementos[i+1]; //Desplazamiento
    fin--;
}

Paciente cola::primero(){
    return (elementos[inicio]);
}

bool cola::esvacia (){
    return (fin == -1);
}

void copiarPaciente(Paciente &destino,Paciente &origen){
    destino.Identificador = origen.Identificador;
    strcpy(destino.Nombre, origen.Nombre);
    strcpy(destino.Apellido, origen.Apellido);
    destino.Edad = origen.Edad;
}

bool compararPaciente(Paciente &p1,Paciente &p2){
    return p1.Identificador == p2.Identificador;
}

int prioridadPaciente(Paciente &p){
    return p.Edad/10 + 1;
}
