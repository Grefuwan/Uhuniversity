#include "Fecha.h"

Fecha::Fecha(const int &dia,const int &m,const int &anno)
{
    //this->dia = dia;
    //this->mes = m;
    //this->anno = anno;
    this->setFecha(dia, m, anno);
}

Fecha::~Fecha() //Como no hay ningun puntero, no hay que hacer destructor
{
    //dtor
}

void Fecha::setFecha(const int& dia,const int& mes,const int&anno){ //Rehacerlo como viene con la ayuda
    /*
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};   //El primer 0 es "para el mes 0"; el 31 es para el mes 1 (Enero)...
    this->anno=anno;
    if (bisiesto()){
        diaMes[2]=29;
    }

    if (mes<1)
        this->mes=1;
    else if (mes>12)
        this->mes=12;

    this->mes=mes;      //Corrige arriba el mes del parametro y se lo pone al objeto
    //Si lo comento, funciona bien; si no, me pone el mes a 0 ._.

    dmax=diaMes[mes];   //Seteo como dmax el dia tope de ese mes

    if (dia>dmax)
        this->dia=dmax;
    else if (dia<1)
        this->dia=1;

    this->dia=dia;

    //El anno no se toca, "no puede estar mal"
    */

    this->dia = dia;
    this->mes = mes;
    this->anno = anno;

    if (mes<1)
        this->mes=1;
    else if (mes>12)
        this->mes=12;

    int maxDias[] = {0,31,bisiesto()?29:28,31,30,31,30,31,31,30,31,30,31};

    if (dia<1)
        this->dia=1;
    else if (dia>maxDias[this->mes])
        this->dia=maxDias[this->mes];
}

bool Fecha::bisiesto() const{
    if (this->anno%4 == 0){
        if (this->anno%100 != 0)
            return true;
        else{
            if (this->anno%400 == 0)
                return true;
            else
                return false;
        }
    }
    else{
        return false;
    }
}

void Fecha::ver() const{
    if (this->dia <10)
        cout << "0";
    cout << this->dia << "/";
    if (this->mes < 10)
        cout << "0";
    cout << this->mes << "/" << this->anno;
}

Fecha Fecha::operator++(){
    int dmax, diaMes[]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->bisiesto())
        diaMes[2]=29;
    dmax=diaMes[this->mes];
    this->dia++;
    if(this->dia>dmax){         //Si al incrementar dia superamos el numero de dias de dicho mes
        this->dia=1;            //pasamos a 1
        this->mes++;            //del mes siguiente
        if(this->mes>12){       //Si al incrementar mes pasamos de 12 meses
            this->mes=1;        //pasamos al mes 1
            this->anno++;       //del anno siguiente
        }
    }
    return *this;               //Devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator++(int i){
    Fecha t(this->dia, this->mes, this->anno);
    ++(*this);
    return t;
}

Fecha Fecha::operator+(int i) const{
    Fecha f(*this);

    f.dia += i;

    int maxDias[]={0,31,bisiesto()?29:28,31,30,31,30,31,31,30,31,30,31};

    while (f.dia > maxDias[f.mes]){
        f.dia -= maxDias[f.mes];
        f.mes++;
        if (f.mes > 12){
            f.mes=1;
            f.anno++;
        }
    }

    return f;
}

Fecha operator+(const int &i, const Fecha &f){
    return f+i;
}

std::ostream& operator<<(std::ostream& s, const Fecha &o) {
    s << (o.getDia()<10?"0":"") << o.getDia() << " ";
    switch(o.getMes()){
        case 1: s << "ene"; break;
        case 2: s << "feb"; break;
        case 3: s << "mar"; break;
        case 4: s << "abr"; break;
        case 5: s << "may"; break;
        case 6: s << "jun"; break;
        case 7: s << "jul"; break;
        case 8: s << "ago"; break;
        case 9: s << "sep"; break;
        case 10: s << "oct"; break;
        case 11: s << "nov"; break;
        case 12: s << "dic"; break;
    }
    s << " " << o.getAnno();
}
