#ifndef AUTOBUSES_H
#define AUTOBUSES_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
typedef char cadena[50];
#define SALTO 4     //valor de constante usado para adaptar el tamaño de las tablas
                    // dinámicas, si éstas necesitan “crecer”
struct estado {
 bool activo;       //en servicio si/no
 float deposito;    //litros del depósito
 int plazas;        //capacidad
 bool itv;          //itv pasada si/no
};

struct autobus
{
 cadena matricula;  //formato NNNNLLL (Numero/ Letra)
 estado e;
 int conductor;     //identificador conductor
};


class Autobuses
{
autobus *elementos;
int tam;            //tamaño de la tabla dinámica
int n;              //número de autobuses
bool cargado;       //indica si el fichero está cargado en memoria
fstream fichero;

public:
    Autobuses();
    ~Autobuses();
    void Insertar(autobus a);
    void Borrar (cadena mat,int pos);
    void Modificar(autobus a, cadena mat,int pos);
    int Buscar(cadena mat);
    void Mostrar(cadena mat,int pos);
    void Listar();
    bool Cargar();
    bool Guardar();
};

#endif // AUTOBUSES_H
