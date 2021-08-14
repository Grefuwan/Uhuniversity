#include <iostream>
#include <fstream>
#include "paciente.h"
#include "TADColaPri.h"

using namespace std;

ColaPri::ColaPri(){}
ColaPri::~ColaPri(){}

bool ColaPri::esvaciaColaPri(){
    bool vacia = true;

    int i = 0;
    while(vacia && i < MAXcolas)
        vacia = tabla[i++].esVacia();

    return vacia;
}
int ColaPri::longitudColaPri(){
    int longitud = 0;

    for(int i = 0; i < MAXcolas; i++)
        longitud += tabla[i++].longitud();

    return longitud;
}

void ColaPri::insertarColaPri(int i, Paciente p){
    if(i >= 0 && i < MAXcolas){
        tabla[i].insertar(p);
    }
}
void ColaPri::sacarColaPri(){
    int i = MAXcolas-1;

    //Buscar la cola más prioritaria que no está vacía
    while(i >= 0 && tabla[i].esVacia()) i--;

    if(i >= 0){
        tabla[i].sacar();
    }
}

Paciente ColaPri::consultarColaPri(){
    Paciente p; p.id = -1;
    int i = MAXcolas-1;

    //Buscar la cola más prioritaria que no está vacía
    while(i >= 0 && tabla[i].esVacia()) i--;

    if(i >= 0){
        p = tabla[i].consultar();
    }

    return p;
}

bool ColaPri::cargarfichero (cadena fich){
    ifstream fichero(fich, ios::binary);

    if(!fichero.fail()){
        Paciente p;
        int n;

        fichero.read((char*)&n, sizeof(int));

        for(int i = 0; i < n; i++){
            fichero.read((char*)&p, sizeof(Paciente));
            insertarColaPri(prioridadPaciente(p)-1, p);
        }
    }

    fichero.close();
}
bool ColaPri::guardarfichero (cadena fich){
    ofstream fichero(fich, ios::binary);

    if(!fichero.fail()){
        Paciente p;
        int n = 0;
        fichero.seekp(sizeof(int), ios::beg);

        for(int i = 0; i < MAXcolas; i++){
            int j = tabla[i].longitud();
            n += j;
            for(; j > 0; j--){
                p = tabla[i].consultar();
                tabla[i].sacar();
                tabla[i].insertar(p);
                fichero.write((char*)&p, sizeof(Paciente));
            }
        }

        fichero.seekp(0, ios::beg);
        fichero.write((char*)&n, sizeof(int));
    }
}


int ColaPri::longitudCola(int i){
    return tabla[i].longitud();
}

Paciente ColaPri::sacarCola(int i){
    return tabla[i].sacar();
}
