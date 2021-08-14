#ifndef LISTA_H
#define LISTA_H
#include "cola.h"
#include <cstring>
typedef char cadena[50];


struct peluquero
{
    int Codigo;
    cadena Apellidos;
    cadena Nombre;
    int TipoServicio;
    cola Col;
};

class lista
{
peluquero *elementos; // elementos de la lista
int n; // nº de elementos que tiene la lista
int Tama; // tamaño de la tabla en cada momento
public:
    lista(); // constructor de la clase
    ~lista(); // destructor de la clase
    lista(peluquero &e);
    bool esvacia();
    int longitud();
    void anadirIzq(peluquero e);
    void anadirDch(peluquero e);
    void eliminarIzq();
    void eliminarDch();
    peluquero observarIzq();
    peluquero observarDch();
    void concatenar(lista l);
    bool pertenece(peluquero &e);
    void insertar(int i, peluquero &e);
    void eliminar(int i);
    void modificar(int i, peluquero &e);
    peluquero &observar(int i);
    int posicion(peluquero &e);
};

void copiarpeluquero(peluquero &destino,peluquero &origen);
#endif

