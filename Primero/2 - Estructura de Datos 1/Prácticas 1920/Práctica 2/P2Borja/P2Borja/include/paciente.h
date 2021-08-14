#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

const int TAM_CADENA = 30;
typedef char cadena[TAM_CADENA];

struct Paciente {
    int id;
    cadena nombre;
    cadena apellidos;
    int edad;
};

void copiarPaciente(Paciente &destino, Paciente &origen);
bool compararPaciente(Paciente &p1, Paciente &p2);
int prioridadPaciente(Paciente &p);

#endif // PACIENTE_H_INCLUDED
