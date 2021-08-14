#include "TADColaPri.h"

typedef char cadeno[30];

struct PacienteDat{
    int Identificador;
    cadeno Nombre;
    cadeno Apellido;
    int Edad;
    //int n;  //Numero de Pacientes
};

int RetornoPrioridades (int edad){
        int Prioridad;
        if (edad<=9){
            Prioridad = 0;
        }
        else if (edad>=10 && edad<=19){
            Prioridad = 1;
        }
        else if (edad>=20 && edad<=29){
            Prioridad = 2;
        }
        else if (edad>=30 && edad<=39){
            Prioridad = 3;
        }
        else if (edad>=40 && edad<=49){
            Prioridad = 4;
        }
        else if (edad>=50 && edad<=59){
            Prioridad = 5;
        }
        else if (edad>=60 && edad<=69){
            Prioridad = 6;
        }
        else if (edad>=70 && edad<=79){
            Prioridad = 7;
        }
        else if (edad>=80){
            Prioridad = 8;
        }

        return Prioridad;
}

TADColaPri::TADColaPri()
{
    //ctor
}

TADColaPri::~TADColaPri()
{
    //dtor
}

void TADColaPri::insertarColaPri(int i, Paciente p){
    tabla[i].encolar(p);
}

void TADColaPri::sacarColaPri(){
    int i = MAXcolas -1;
    while ((tabla[i].esvacia())&& (i>0)){
        i--;
    }
    tabla[i].desencolar();
}

Paciente TADColaPri::consultarColaPri(){
    int i = MAXcolas - 1;
    while ((tabla[i].esvacia()) && (i>0)){
        i--;
    }
    return tabla[i].primero();
}

bool TADColaPri::esvaciaColaPri(){
    int i = MAXcolas -1;
    bool vacia = false;
    while ((tabla[i].esvacia()) && (i>0)){
        i--;
    }
    if (tabla[i].esvacia()){
        vacia = true;
    }
    return vacia;
}

int TADColaPri::longitudColaPri(){
    int lon = 0;
    for (int i = 0; i < MAXcolas; i++){
        lon = lon + tabla[i].longitud();
    }
    return lon;
}

bool TADColaPri::cargarfichero(cadena fich){

    ifstream fichero(fich, ios::binary|ios::in| ios::out);

    if(!fichero.fail()){
        Paciente paci;
        //int n;

        fichero.seekg(sizeof(int), ios::beg);
        //fichero.read((char*)&n, sizeof(int));

        /*for(int i = 0; i < n; i++)*/
        while(!fichero.eof()){
            //fichero.seekg(sizeof(int)+sizeof(Paciente)*i, ios::beg);
            fichero.read((char*)&paci, sizeof(Paciente));
            cout << paci.Nombre << endl;
            insertarColaPri(RetornoPrioridades(paci.Edad), paci);
        }
    }

    fichero.close();
    system("pause");
}

bool TADColaPri::guardarfichero(cadena fich){
    bool guardado = true;
    int n;
    Paciente Paci;
    fstream fichero;

    fichero.open(fich, ios::binary | ios::out | ios::trunc);
    if (!fichero.fail()){
        n = longitudColaPri();
        fichero.seekp(0, ios::beg);
        fichero.write ((char*)&n, sizeof(int));

        for (int i=0; i<n; i++){
            Paci = consultarColaPri();
            fichero.seekp(sizeof(int)+sizeof(Paciente)*i, ios::beg);
            fichero.write((char*)&Paci, sizeof(Paciente));
            sacarColaPri();
        }

        fichero.close();
    }
    else guardado = false;

    return guardado;
}
