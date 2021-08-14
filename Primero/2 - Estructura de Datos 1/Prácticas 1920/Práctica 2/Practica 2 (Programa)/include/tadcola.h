#ifndef TADCOLA_H
#define TADCOLA_H

# define MAX 30
# include <iostream>
# include <stdlib.h>
# include <string.h>

typedef char cadena[30];

using namespace std;

struct Paciente{
    int Identificador;
    cadena Nombre;
    cadena Apellido;
    int Edad;
    //int n;  //Numero de Pacientes
};

class cola {
    Paciente elementos[MAX]; //elementos de la cola
    int inicio, fin;//principio y fin de la cola
public:
    cola(); // constructor de la clase
    void encolar(Paciente Paci);
    void desencolar();
    Paciente primero(); //Devuelve el primer paciente
    bool esvacia();
    int longitud();
    //------------------------------------------------
    void copiarPaciente (Paciente &destino, Paciente &origen);
    bool compararPaciente (Paciente &p1, Paciente &p2);
    int prioridadPaciente (Paciente &p);
};

#endif // TADCOLA_H
