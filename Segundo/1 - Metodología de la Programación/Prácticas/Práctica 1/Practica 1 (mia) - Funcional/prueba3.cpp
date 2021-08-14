#include <cstdlib>
#include <iostream>
#include <iomanip>  //std::setprecision
#include "Fecha.h"
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoTP.h"
#include "ContratoMovil.h"
#include "Empresa.h"

using namespace std;

int main (int argc, char *argv[]){
    bool ok;
    Empresa Yoigo;

    cout << setprecision(2) << fixed;   //A partir de aqui float se muestra con 2 decimales
    cout << endl << "APLICACION DE GESTION TELEFONICA\n" << endl;
    Yoigo.cargarDatos();    //Crea 3 clientes y 7 contratos. Metodo creado para
    Yoigo.ver();            //no tener que meter datos cada vez que pruebo el programa
    cout << "Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n\n";

    Yoigo.crearContrato();  //ContratoMovil a 37000017 el 01/01/2017 con 100m a 0.25
    Yoigo.crearContrato();  //ContratoTP a 22330014 (pepe luis) el 2/2/2017 con 305m

    ok=Yoigo.cancelarContrato(28);  //Este contrato no existe
    if(ok)
        cout << "Contrato 28 cancelado\n";
    else
        cout << "El Contrato 28 no existe\n";

    ok=Yoigo.cancelarContrato(4);   //Este contrato si existe
    if(ok)
        cout << "Contrato 4 cancelado\n";
    else
        cout << "El contrato 4 no existe\n";

    ok=Yoigo.bajaCliente(75547001); //Debe eliminar el cliente y sus 3 contratos
    if(ok)
        cout << "El cliente 75547001 y sus Contratos han sido cancelados\n";
    else
        cout << "El cliente 75547001 no existe\n";

    Yoigo.ver();

    Yoigo.descuento(20);
    cout << "\nTras rebajar un 20% la tarifa de los ContratosMovil...";
    Yoigo.ver();
    cout << "Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n" << endl;

    system("PAUSE");
    return 0;
}
