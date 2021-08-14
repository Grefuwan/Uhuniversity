#ifndef TADCOLAPRI_H
#define TADCOLAPRI_H
#include "tadcola.h"
#include <fstream>
#define MAXcolas 9

class TADColaPri
{
    cola tabla[MAXcolas];
    fstream fichero;
    int n;
    public:
        TADColaPri();
        virtual ~TADColaPri();

        void insertarColaPri(int i, Paciente p);    //Inserta el paciente p en la cola de prioridad i
        void sacarColaPri();                        //Elimina el paciente de mayor prioridad. En caso de misma prioridad, saldrá el que lleve más tiempo
        Paciente consultarColaPri();                //Devuelve el paciente de mayor prioridad almacenado sin quitarlo
        bool esvaciaColaPri();                      //Devuelve true si ColaPri está vacio
        int longitudColaPri();                      //Devuelve la longitud de ColaPri
        bool cargarfichero (cadena fich);           //Carga los datos almacenados en el fichero
        bool guardarfichero (cadena fich);          //Guarda los datos de ColaPri en el fichero
        //----------Anadidos Personales-----------
};

#endif // TADCOLAPRI_H
