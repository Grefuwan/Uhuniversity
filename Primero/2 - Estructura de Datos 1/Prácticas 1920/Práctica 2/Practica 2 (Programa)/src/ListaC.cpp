#include "ListaC.h"
#include <iostream>
listaC::listaC(){
    elementos = NULL;
    n = 0;
}
listaC::~listaC(){
    vaciar();
}
listaC::listaC(Paciente &e){
    elementos = new TNodo_ListaC;
    //copiarPaciente(elementos->Datos, e);

    elementos->Datos.Identificador = e.Identificador;
    strcpy(elementos->Datos.Nombre, e.Nombre);
    strcpy(elementos->Datos.Apellido, e.Apellido);
    elementos->Datos.Edad = e.Edad;

    elementos->Sig = NULL;
    n = 1;
}
TNodo_ListaC* listaC::buscarNodo(int i){
    if(n == 0) return NULL;
    TNodo_ListaC *tmp = elementos;

    while(--i >= 0)
        tmp = tmp->Sig;

    return tmp;
}
void listaC::vaciar(){
    TNodo_ListaC *tmp;

    for(;n > 0; n--){
        tmp = elementos;
        elementos = elementos->Sig;
        delete tmp;
    }
}
bool listaC::esvacia(){
    return n == 0;
}
int listaC::longitud(){
    return n;
}
bool listaC::pertenece(Paciente &e){
    bool valor = false;
    if (posicion(e) != -1)
        valor = true;
    else
        valor = false;
    return valor;
}
void listaC::insertar(int i, Paciente &e){
    TNodo_ListaC *nuevoNodo = new TNodo_ListaC;
    //copiarPaciente(nuevoNodo->Datos, e);
    nuevoNodo->Datos.Identificador = e.Identificador;
    strcpy(nuevoNodo->Datos.Nombre, e.Nombre);
    strcpy(nuevoNodo->Datos.Apellido, e.Apellido);
    nuevoNodo->Datos.Edad = e.Edad;


    if(i == 1){
        nuevoNodo->Sig = elementos;
        elementos = nuevoNodo;
        n++;
        TNodo_ListaC *ultimo = buscarNodo(n-1);
        ultimo->Sig = nuevoNodo;
    }else{
        TNodo_ListaC *anterior = buscarNodo(i-2);
        nuevoNodo->Sig = anterior->Sig;
        anterior->Sig = nuevoNodo;
        n++;
    }
}
void listaC::eliminar(int i){
    TNodo_ListaC *tmp;

    if(i == 1){
        tmp = elementos;
        elementos = elementos->Sig;
    }else{
        TNodo_ListaC *anterior = buscarNodo(i-2);
        tmp = anterior->Sig;
        anterior->Sig = tmp->Sig;
    }
    delete tmp;

    n--;
}
void listaC::modificar(int i, Paciente &e){
    //copiarPaciente(buscarNodo(i-1)->Datos, e);
    buscarNodo(i-1)->Datos.Identificador = e.Identificador;
    strcpy(buscarNodo(i-1)->Datos.Nombre, e.Nombre);
    strcpy(buscarNodo(i-1)->Datos.Apellido, e.Apellido);
    buscarNodo(i-1)->Datos.Edad = e.Edad;

}
Paciente& listaC::observar(int i){
    return buscarNodo(i-1)->Datos;
}
int listaC::posicion(Paciente &e){
    TNodo_ListaC *tmp = elementos;
    int i = 0;

    while (e.Identificador!=tmp->Datos.Identificador)
        tmp = tmp->Sig;

    return (i==n?-1:i+1);
}
