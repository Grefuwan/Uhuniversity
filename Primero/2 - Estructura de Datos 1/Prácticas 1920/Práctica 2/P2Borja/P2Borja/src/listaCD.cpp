#include "listaCD.h"
#include <iostream>
listaCD::listaCD(){
    elementos = NULL;
    n = 0;
}
listaCD::~listaCD(){
    vaciar();
}
listaCD::listaCD(Paciente &e){
    elementos = new TNodo_ListaCD;
    copiarPaciente(elementos->Datos, e);
    elementos->Sig = elementos;
    elementos->Ant = elementos;
    n = 1;
}
TNodo_ListaCD* listaCD::buscarNodo(int i){
    if(n == 0) return NULL;
    TNodo_ListaCD *tmp = elementos;

    if(i  > 0)
        while(--i >= 0)
            tmp = tmp->Sig;
    else if(i < 0)
        while(++i <= 0)
            tmp = tmp->Ant;

    return tmp;
}
void listaCD::vaciar(){
    TNodo_ListaCD *tmp;

    for(;n > 0; n--){
        tmp = elementos;
        elementos = elementos->Sig;
        delete tmp;
    }
}
bool listaCD::esvacia(){
    return n == 0;
}
int listaCD::longitud(){
    return n;
}
bool listaCD::pertenece(Paciente &e){
    return posicion(e) != -1;
}
void listaCD::insertar(int i, Paciente &e){
    TNodo_ListaCD *nuevoNodo = new TNodo_ListaCD;
    copiarPaciente(nuevoNodo->Datos, e);

    /*
    if(i == 1){
        nuevoNodo->Sig = elementos;
        nuevoNodo->Ant = elementos->Ant;
        elementos->Ant->Sig = nuevoNodo;
        elementos->Ant = nuevoNodo;
        elementos = nuevoNodo;
    }else if(i == n){
        nuevoNodo->Sig = elementos;
        nuevoNodo->Ant = elementos->Ant;
        elementos->Ant->Sig = nuevoNodo;
        elementos->Ant = nuevoNodo;
    }else{
        TNodo_ListaCD *anterior = buscarNodo(i-2);
        nuevoNodo->Sig = anterior->Sig;
        nuevoNodo->Ant = anterior;
        anterior->Sig->Ant = nuevoNodo;
        anterior->Sig = nuevoNodo;
    }
    */

    TNodo_ListaCD *anterior = buscarNodo(i-2);
    if(anterior == NULL){
        nuevoNodo->Sig = nuevoNodo;
        nuevoNodo->Ant = nuevoNodo;
        elementos = nuevoNodo;
    }else{
        nuevoNodo->Sig = anterior->Sig;
        nuevoNodo->Ant = anterior;
        anterior->Sig->Ant = nuevoNodo;
        anterior->Sig = nuevoNodo;
        if(i == 1)
            elementos = nuevoNodo;
    }

    n++;
}
void listaCD::eliminar(int i){
    TNodo_ListaCD *tmp;

    /*
    if(i == 1){
        tmp = elementos;
        elementos->Ant->Sig = elementos->Sig;
        elementos->Sig->Ant = elementos->Ant;
        elementos = elementos->Sig;
        delete tmp;
    }else{
        TNodo_ListaCD *anterior = buscarNodo(i-2);
        tmp = anterior->Sig;
        anterior->Sig = tmp->Sig;
        tmp->Sig->Ant = anterior;
        delete tmp;
    }
    */

    TNodo_ListaCD *anterior = buscarNodo(i-2);
    tmp = anterior->Sig;
    anterior->Sig = tmp->Sig;
    tmp->Sig->Ant = anterior;
    if(i == 1)
        elementos = tmp->Sig;
    delete tmp;

    n--;
}
void listaCD::modificar(int i, Paciente &e){
    copiarPaciente(buscarNodo(i-1)->Datos, e);
}
Paciente& listaCD::observar(int i){
    return buscarNodo(i-1)->Datos;
}
int listaCD::posicion(Paciente &e){
    TNodo_ListaCD *tmp = elementos;
    int i = 0;

    while(!compararPaciente(e, tmp->Datos))
        tmp = tmp->Sig;

    return (i==n?-1:i+1);
}
