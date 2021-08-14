#include <cstdlib>
#include <iostream>
#include "Fecha.h"
#include "Cliente.h"
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil
#include "Empresa.h" // definicion de la clase Empresa

using namespace std;

int main(){
    bool ok;
    Empresa Yoigo;

    //cout << setprecision(2) << fixed; //a partir de aqui float se muestra con2 decimales
    cout << endl << "APLICACION DE GESTION TELEFONICA\n" << endl;

    //Yoigo.crearContrato();
    Yoigo.cargarDatos();    //crea 3 clientes y 7 contratos. metodo creado para no
    Yoigo.ver();            //tener que meter datos cada vez que pruebo el programa
    cout <<"Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n\n";

    Yoigo.crearContrato();  //ContratoMovil a 37000017 el 01/01/2017 con 100m a 0.25
    Yoigo.crearContrato(); //ContratoTP a 22330014 (pepe luis) el 2/2/2017 con 305m

    ok=Yoigo.cancelarContrato(28); //este Contrato no existe
    if (ok) cout << "Contrato 28 cancelado\n"; else cout << "El Contrato 28 no existe\n";

    ok=Yoigo.cancelarContrato(4); //este Contrato si existe
    if (ok) cout << "El Contrato 4 ha sido cancelado\n"; else cout << "El Contrato 4 no existe\n";

    ok=Yoigo.bajaCliente(75547001); //debe eliminar el cliente y sus 3 Contratos
    if (ok) cout << "El cliente 75547001 y sus Contratos han sido cancelados\n\n"; else cout << "El cliente 75547001 no existe\n\n";

    Yoigo.ver();

    Yoigo.descuento(20);
    cout << "\nTras rebajar un 20% la tarifa de los ContratosMovil...\n\n";
    Yoigo.ver();
    cout <<"\nYoigo tiene " << Yoigo. nContratosTP () << " Contratos de Tarifa Plana\n\n";

    system("PAUSE");
    return 0;
}
