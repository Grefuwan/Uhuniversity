#include <cstdlib>
#include <cstring>
#include <iostream>
#include "cola.h"


cola::cola(){
    elementos = new Paciente[INCREMENTO];
    if(elementos == NULL){
        ne = fin = inicio = -1;
        Tama = -1;
    }else{
        ne = fin = inicio = 0;
        Tama = INCREMENTO;
    }
}
cola::~cola(){
    if(elementos != NULL)
        delete [] elementos;
    elementos = NULL;
    ne = fin = inicio = -1;
    Tama = 0;
}
void cola::insertar(Paciente e){
    if(ne == Tama){
        Paciente *elementosTMP = new Paciente[Tama+INCREMENTO];
        if(elementosTMP != NULL){
            for(int i = 0; i < ne; i++){
                elementosTMP[i] = elementos[inicio];
                inicio = (inicio+1)%Tama;
            }
            inicio = 0;
            fin = ne;
            Tama += INCREMENTO;
            if(elementos != NULL)
                delete [] elementos;
            elementos = elementosTMP;
        }
    }
    if(ne < Tama){
        fin -= fin/Tama;
        elementos[fin] = e;
        fin = (fin+1)%Tama;
        ne++;
    }
}
Paciente cola::sacar(){
    Paciente p; p.id = -1;

    if(ne == 0) return p;

    p = elementos[inicio];

    inicio = (inicio+1)%Tama;
    ne--;

    if(Tama-ne == INCREMENTO && Tama > INCREMENTO){
        Paciente *elementosTMP = new Paciente[Tama-INCREMENTO];
        if(elementosTMP != NULL){
            for(int i = 0; i < ne; i++){
                elementosTMP[i] = elementos[inicio];
                inicio = (inicio+1)%Tama;
            }
            Tama -= INCREMENTO;
            inicio = 0;
            fin = ne;
            if(elementos != NULL)
                delete [] elementos;
            elementos = elementosTMP;
        }
    }

    return p;
}
bool cola::esVacia(){
    return ne==0;
}
Paciente cola::consultar(){
    return elementos[inicio];
}
int cola::longitud(){
    return ne;
}
void cola::vaciar(){
    if(elementos != NULL)
        delete [] elementos;
    elementos = new Paciente[INCREMENTO];
    ne = fin = inicio = 0;
    Tama = INCREMENTO;
}
void cola::clonar(cola &c){
    vaciar();

    cola cTMP;
    while(!c.esVacia()){
        insertar(c.consultar());
        cTMP.insertar(c.consultar());
        c.sacar();
    }
    while(!cTMP.esVacia()){
        c.insertar(cTMP.consultar());
        cTMP.sacar();
    }
}
