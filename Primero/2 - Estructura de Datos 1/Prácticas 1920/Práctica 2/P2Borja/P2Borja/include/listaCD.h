#ifndef LISTACD_H_INCLUDED
#define LISTACD_H_INCLUDED

#include <cstdlib>
#include <cstring>
#include "paciente.h"

struct TNodo_ListaCD{
    Paciente Datos;
    TNodo_ListaCD *Ant;
    TNodo_ListaCD *Sig;
};

class listaCD{
    TNodo_ListaCD *elementos; // elementos de la lista
    int n;// nº de elementos que tiene la lista
    TNodo_ListaCD* buscarNodo(int i); //Busca el nodo anteior a uno dado. (indice 0)
public:
    listaCD(); // constructor de la clase
    ~listaCD();// destructor de la clase
    listaCD(Paciente &e);
    void vaciar();
    bool esvacia();
    int longitud();
    //void anadirIzq(peluquero e); No necesario implementar
    //void anadirDch(peluquero e); No necesario implementar
    //void eliminarIzq(); No necesario implementar
    //void eliminarDch();No necesario implementar
    //tecnico observarIzq(); No necesario implementar
    //tecnico observarDch(); No necesario implementar
    //void concatenar(lista l); No necesario implementar
    bool pertenece(Paciente &e);
    void insertar(int i, Paciente &e);
    void eliminar(int i);
    void modificar(int i, Paciente &e);
    Paciente& observar(int i);
    int posicion(Paciente &e);
};

#endif // LISTACD_H_INCLUDED
