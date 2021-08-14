#include <cstdlib>
#include <iostream>
#include <iomanip>  //std::setprecision
#include "Fecha.h"
#include "Contrato.h"
#include "ContratoTP.h"
#include "ContratoMovil.h"

using namespace std;

int main (int argc, char *argv[]){
    Fecha f1(29,2,2001), f2(f1), f3(29,2,2004);
    cout << "Fechas: " << endl;
        cout << "F1: "; f1.ver(); cout << endl;
        cout << "F2: "; f2.ver(); cout << endl;
        cout << "F3: "; f3.ver(); cout << endl;

    Contrato *p = new Contrato (75547111, f1), c(23000111, Fecha(2,2,2002));
    cout << "p: "; p->ver();
    //--ContratoTP--
    cout << "\n" << ContratoTP::getLimiteMinutos() << " - " << ContratoTP::getPrecio() << endl;
    ContratoTP ct1 (17333256, f1, 250); //cout << "Construye CT1" << endl;     //Habla 250min
    ContratoTP ct2 (12555100, f3, 320); //cout << "Construye CT2" << endl;     //Habla 320min
    ContratoTP ct3 (ct1);               //cout << "Construye CT3" << endl;

    //--ContratoMovil
    ContratoMovil cm1 (17333256, f1, 0.12, 100, "ESPANOL");                 //cout << "Construye CM1" << endl;            //Habla 100min
    ContratoMovil cm2 (17000000, Fecha(3,3,2003), 0.10, 180, "FRANCES");    //cout << "Construye CM2" << endl;            //Habla 180min
    ContratoMovil cm3 (cm2);                                                //cout << "Construye CM3" << endl;

    cout << "p: "; p->ver();
    cout << "\nc: "; c.ver();
    cout << endl;
    cout << "CT1: "; ct1.ver(); cout << endl;
    cout << "CT2: "; ct2.ver(); cout << "\n";
    cout << "CT3: "; ct3.ver(); cout << "\n\n";
    cout << "CM1: "; cm1.ver();
    cout << "CM2: "; cm2.ver();
    cout << "CM3: "; cm3.ver();
    cout << p->getIdContrato() << ct2.getIdContrato() << cm2.getIdContrato() << endl;

    cout << setprecision(2) << fixed;   //A partir de aqui float se muestra con 2 decimales

    cout << "\nFacturas: " << endl;
    cout << "\tCT1: "<< ct1.factura() << "\n\tCT2: " << ct2.factura() << "\n\tCM1: " << cm1.factura() << endl;
    ContratoTP::setTarifaPlana(350, 12); //350min por 12euros
    p->setDniContrato(cm1.getDniContrato());
    ct3.setFechaContrato(p->getFechaContrato()+1);
    cm3.setNacionalidad(cm1.getNacionalidad());
    cm2.setPrecioMinuto(cm1.getPrecioMinuto()+0.02);
    cm1.setMinutosHablados(ct2.getMinutosHablados()/2);
    ct1.setMinutosHablados(cm3.getMinutosHablados()*2);

    cout << "*p: "; *p;                 //--Falla de esta linea para abajo--
    cout <<"\nc: ";  c; cout << endl;
    cout << "CT1: " << ct1 << endl;
    cout << "CT2: " << ct2 << endl;
    cout << "CT3: " << ct3 << endl;
    cout << "CM1: " << cm1 << endl;
    cout << "CM2: " << cm2 << endl;
    cout << "CM3: " << cm3 << endl;

    system("PAUSE");
    return 0;

    }
