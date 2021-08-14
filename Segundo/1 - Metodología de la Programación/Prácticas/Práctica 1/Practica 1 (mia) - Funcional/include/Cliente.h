#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include "Fecha.h"

using namespace std;

class Cliente
{
    long int dni;
    char *nombre;
    Fecha fechaAlta;

    public:
        Cliente(long int dni, char* nombre, Fecha fechaAlta);
        Cliente (const Cliente &c); //Constructor de Copia
        virtual ~Cliente(); //Como tiene puntero, sí hay que implementar destructor


        //--Setters--
        void setNombre (char *n);   //No lleva Const porque modifica el nombre
        void setFecha (Fecha f);

        //--Getters--
        long int getDni()       const{return dni;}
        const char *getNombre() const{return nombre;}       //Cuidado: fallo de Seguridad. Hay que ponerle const char, para que devuelva un puntero a una cadena de caracteres constante
        Fecha getFecha()        const{return fechaAlta;}


        //--Sobrecargas de Operator--
        bool operator==(Cliente &c) const; //if (c1 == c2)
        Cliente &operator=(const Cliente &c);       //Sobrecarga del operador de asignacion. Hacerlo con los setters getters

};

ostream& operator<<(ostream &s, const Cliente &c);  //Funcion no amiga de la clase
#endif // CLIENTE_H
