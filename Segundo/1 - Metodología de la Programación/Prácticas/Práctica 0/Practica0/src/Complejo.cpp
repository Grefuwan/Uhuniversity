#include "Complejo.h"
#include <iostream>

using namespace std;

Complejo::Complejo(int r, int i){
    real = r;
    imaginaria = i;

}

Complejo::~Complejo()
{
    //dtor
}

void Complejo::set(){
    cout << "Introduce la parte real: "; cin >> real;
    cout << "Introduce la parte imaginaria: "; cin >> imaginaria;

}

void Complejo::ver() const{ //Al implementarlo en el .cpp, tambien ha de llevar el const
    if (imaginaria>0){
        cout << real << " + " << imaginaria << "i" << endl;
    }
    else{
        cout << real << imaginaria << "i" << endl;
    }
}

Complejo Complejo::operator+(Complejo c){
    Complejo suma(0,0);
    suma.real=/*this->*/real+c.real;        //Cuando pongo a.operator+(b), a es el this, y b es el Complejo c
    suma.imaginaria=/*this->*/imaginaria+c.imaginaria;
    return suma;
}

