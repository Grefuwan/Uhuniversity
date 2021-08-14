#ifndef TADCOLAPRI_H_INCLUDED
#define TADCOLAPRI_H_INCLUDED

#include "cola.h"

#define MAXcolas 9

class ColaPri {
    cola tabla[MAXcolas];
public:
    //Constructor: crea un objeto ColaPri vacío
    ColaPri();

    //Destructor: libera la memoria dinámica del objeto ColaPri
    ~ColaPri();

    //Insertará el paciente p en la cola de prioridad i de la ColaPri*/
    void insertarColaPri(int i, Paciente p);

    //Elimina el paciente de mayor prioridad. Si hay varios con la misma prioridad saldrá aquel que lleve más tiempo en el objeto ColaPri
    void sacarColaPri();

    //Devuelve el paciente de mayor prioridad almacenado en el objeto ColaPri original sin quitarlo. Si hay varios con la misma prioridad saldrá aquel que lleve más tiempo en el objeto ColaPri
    Paciente consultarColaPri();

    //Devuelve si el objeto ColaPri está vacío
    bool esvaciaColaPri();

    //Devuelve la longitud del objeto ColaPri
    int longitudColaPri();

    //Cargará los datos almacenados en el fichero cuyo nombre se pasa como parámetro en el objeto ColaPri. Devuelve true si no hay error en la carga
    bool cargarfichero(cadena fich);

    //Guardará los datos del objeto ColaPri en el fichero cuyo nombre se pase como parámetro. Devuelve true si no hay error al guardar el objeto
    bool guardarfichero(cadena fich);


    ///Estos metodos los pongo porque no hay otra forma de realizar el main

    //Devuelve el numero de pacientes en una cola específica
    int longitudCola(int i);

    //Devuelve un paciente de una cola específica y lo elimina
    Paciente sacarCola(int i);
};

#endif // TADCOLAPRI_H_INCLUDED
