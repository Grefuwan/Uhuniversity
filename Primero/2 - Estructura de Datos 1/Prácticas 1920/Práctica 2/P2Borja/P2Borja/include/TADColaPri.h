#ifndef TADCOLAPRI_H_INCLUDED
#define TADCOLAPRI_H_INCLUDED

#include "cola.h"

#define MAXcolas 9

class ColaPri {
    cola tabla[MAXcolas];
public:
    //Constructor: crea un objeto ColaPri vac�o
    ColaPri();

    //Destructor: libera la memoria din�mica del objeto ColaPri
    ~ColaPri();

    //Insertar� el paciente p en la cola de prioridad i de la ColaPri*/
    void insertarColaPri(int i, Paciente p);

    //Elimina el paciente de mayor prioridad. Si hay varios con la misma prioridad saldr� aquel que lleve m�s tiempo en el objeto ColaPri
    void sacarColaPri();

    //Devuelve el paciente de mayor prioridad almacenado en el objeto ColaPri original sin quitarlo. Si hay varios con la misma prioridad saldr� aquel que lleve m�s tiempo en el objeto ColaPri
    Paciente consultarColaPri();

    //Devuelve si el objeto ColaPri est� vac�o
    bool esvaciaColaPri();

    //Devuelve la longitud del objeto ColaPri
    int longitudColaPri();

    //Cargar� los datos almacenados en el fichero cuyo nombre se pasa como par�metro en el objeto ColaPri. Devuelve true si no hay error en la carga
    bool cargarfichero(cadena fich);

    //Guardar� los datos del objeto ColaPri en el fichero cuyo nombre se pase como par�metro. Devuelve true si no hay error al guardar el objeto
    bool guardarfichero(cadena fich);


    ///Estos metodos los pongo porque no hay otra forma de realizar el main

    //Devuelve el numero de pacientes en una cola espec�fica
    int longitudCola(int i);

    //Devuelve un paciente de una cola espec�fica y lo elimina
    Paciente sacarCola(int i);
};

#endif // TADCOLAPRI_H_INCLUDED
