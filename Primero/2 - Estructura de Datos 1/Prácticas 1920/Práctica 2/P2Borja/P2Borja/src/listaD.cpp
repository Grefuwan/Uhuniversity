#include "listaD.h"
#include <iostream>
listaD::listaD(){
    elementos = NULL;
    n = 0;
}
listaD::~listaD(){
    vaciar();
}
listaD::listaD(Paciente &e){
    elementos = new TNodo_ListaD;
    copiarPaciente(elementos->Datos, e);
    elementos->Sig = NULL;
    elementos->Ant = NULL;
    n = 1;
}
TNodo_ListaD* listaD::buscarNodo(int i){
    if(n == 0) return NULL;
    TNodo_ListaD *tmp = elementos;

    while(tmp != NULL && --i >= 0)
        tmp = tmp->Sig;

    return tmp;
}
void listaD::vaciar(){
    TNodo_ListaD *tmp;

    while(elementos != NULL){
        tmp = elementos;
        elementos = elementos->Sig;
        delete tmp;
    }

    n = 0;
}
bool listaD::esvacia(){
    return n == 0;
}
int listaD::longitud(){
    return n;
}
bool listaD::pertenece(Paciente &e){
    return posicion(e) != -1;
}
void listaD::insertar(int i, Paciente &e){
    TNodo_ListaD *nuevoNodo = new TNodo_ListaD;
    copiarPaciente(nuevoNodo->Datos, e);

    if(i == 1){
        nuevoNodo->Sig = elementos;
        nuevoNodo->Ant = NULL;
        if(elementos != NULL)
            elementos->Ant = nuevoNodo;
        elementos = nuevoNodo;
    }else{
        TNodo_ListaD *anterior = buscarNodo(i-2);
        nuevoNodo->Sig = anterior->Sig;
        nuevoNodo->Ant = anterior;
        anterior->Sig = nuevoNodo;
    }

    n++;
}
void listaD::eliminar(int i){
    TNodo_ListaD *tmp;

    if(i == 1){
        tmp = elementos;
        elementos->Ant = NULL;
        elementos = elementos->Sig;
    }else{
        TNodo_ListaD *anterior = buscarNodo(i-2);
        tmp = anterior->Sig;
        anterior->Sig = tmp->Sig;
        if(tmp->Sig != NULL)
            tmp->Sig->Ant = anterior;
    }
    delete tmp;

    n--;
}
void listaD::modificar(int i, Paciente &e){
    copiarPaciente(buscarNodo(i-1)->Datos, e);
}
Paciente& listaD::observar(int i){
    return buscarNodo(i-1)->Datos;
}
int listaD::posicion(Paciente &e){
    TNodo_ListaD *tmp = elementos;
    int i = 0;

    while(!compararPaciente(e, tmp->Datos))
        tmp = tmp->Sig;

    return (i==n?-1:i+1);
}
