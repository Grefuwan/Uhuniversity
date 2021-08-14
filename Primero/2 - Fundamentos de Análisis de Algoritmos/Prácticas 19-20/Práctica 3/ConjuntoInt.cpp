#include <iostream>
using namespace std;
#include <ctime>  //para time
#include <cstdlib> // para srand, rand
#include "ConjuntoInt.h"

ConjuntoInt::ConjuntoInt(int max)
{
    tamano = max;
    datos = new int[max];
}
ConjuntoInt::~ConjuntoInt()
{
    delete[] datos;
}
void ConjuntoInt::vaciar()
{
    tamano = 0;
}
int* ConjuntoInt::getDatos()
{
    int* v = datos;
    for (int i = 0; i < tamano; i++) {
        v[i] = datos[i];
    }
    return v;
}

void ConjuntoInt::GeneraVector(int tam)
{
    tamano = tam;
    srand((unsigned)time(NULL)); //srand(time(0));
    for (int i = 0; i < tamano; i++) {
        datos[i] = rand() % 10; //genera un número aleatorio entre 1 y 999
    }
}

void ConjuntoInt::Clonar(int* v, int tam) {
    tamano = tam;
    for (int i = 0; i < tamano; i++) {
        datos[i] = v[i];
    }
}

void ConjuntoInt::escribe()
{
    for (int i = 0; i < tamano; i++)
        cout << datos[i] << (i < tamano - 1 ? ", " : "\n");
}

