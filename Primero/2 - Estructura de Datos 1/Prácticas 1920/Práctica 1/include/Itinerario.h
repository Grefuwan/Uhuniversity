#ifndef ITINERARIO_H
#define ITINERARIO_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

typedef char cadena[50];
#define SALTO 4

using namespace std;

struct Hora {
 int h;
 int m;
 bool am;
};
struct itinerario
{
 cadena nombre;
 cadena origen;
 cadena destino;
 Hora inicio;
 Hora fin;
 cadena matricula;
};


class Itinerario
{
itinerario *elementos;
fstream fichero;
int tam;        //tamaño de la tabla dinámica
int n;          //número de autobuses
bool cargado;   //indica si el fichero está cargado en memoria

public:
     Itinerario();
     ~Itinerario();
     void Insertar(itinerario i);
     void Borrar (cadena nombrei,cadena mat,int pos);
     void Modificar(itinerario a, cadena nombrei, cadena mat,int pos);
     int Buscar(cadena nombrei,cadena mat);
     void Mostrar(cadena nombrei, cadena mat,int pos);
     void Listar();
     bool Cargar();
     bool Guardar();
     void FranjaHoraria (Hora horaInicio, Hora horaFin);
};

#endif // ITINERARIO_H
