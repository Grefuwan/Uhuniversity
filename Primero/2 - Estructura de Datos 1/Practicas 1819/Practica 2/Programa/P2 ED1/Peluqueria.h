#ifndef PELUQUERIA_H
#define PELUQUERIA_H

#include "cola.h"
#include "lista.h"

#include <iostream>


using namespace std;


struct peluquerof
{
	int Codigo;
	cadena Apellidos;
	cadena Nombre;
	int TipoServicio;
};

class peluqueria
{
lista L; //lista de los peluqueros que están atendiendo a los clientes

public:
    void AbrirPeluqueria(char *nombrefichero);
    void IncorporarPeluquero(peluquero t);
    bool RetirarPeluquero(int codigo);
    bool EliminarCliente(cadena Nombre, cadena Apelllidos);
    bool IncorporarCliente(cliente cli);
    void Mostrar();
    bool AtenderCliente(int CodigoPeluquero);
    void VolcarPeluqueria(char *nombrefichero);

    int pelmenosocupado(int servicio, int codigo);
    int pelmasocupado (int servicio, int codigo);
};
#endif // PELUQUERIA_H
