#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "TADColaPri.h"
#include "tadcola.h"
#include "ListaC.h"
#include "ListaD.h"
#include "ListaCD.h"



using namespace std;

int RetornoPrioridad (int edad){
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

int main()
{
    srand((unsigned) time(NULL));
    int N = (rand()%100)+1;

    Paciente PaciObjeto;
    int opcionmenuprincipal;
    TADColaPri TCP, TCPAux;
    listaD LD;
    listaC LC;
    listaCD LCD;
    cadena NombreFich;
    int n;
    do{
        system("cls");
        cout << "---- Menu Principal ----" << endl;
        cout << "1- Cargar datos desde fichero" << endl;
        cout << "2- Admision de un nuevo Paciente" << endl;
        cout << "3- Atender un paciente" << endl;
        cout << "4- Listar Pacientes esperando para atender" << endl;
        cout << "5- Listar Pacientes segun prioridad" << endl;
        cout << "6- Listar Pacientes Atendidos" << endl;
        cout << "7- Salir" << endl;
        cout << "8- Division por apellidos" << endl;
        cout << "-----------------------" << endl;
        cout << "Inserte opcion: "; cin >> opcionmenuprincipal;
        cout << "-----------------------" << endl;

    switch (opcionmenuprincipal){
    case 1:{
        system ("cls");
        cout << "Opcion 1: Cargar datos desde fichero" << endl;
        cout << "Indique el nombre del fichero a cargar (Incluir el .dat): "; cin>> NombreFich;
        TCP.cargarfichero(NombreFich);
        }
        break;

    case 2:{
        system ("cls");
        Paciente PaciOpcDos;
        int PrioridadOpcDos;
        cout << "Opcion 2: Admision de un nuevo Paciente" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Indique los siguientes datos del paciente: " << endl;
        cout << "\t-ID: "; cin >> PaciOpcDos.Identificador;
        cout << "\t-Nombre: "; cin >> PaciOpcDos.Nombre;
        cout << "\t-Apellido: "; cin >> PaciOpcDos.Apellido;
        cout << "\t-Edad: "; cin >> PaciOpcDos.Edad;

        PrioridadOpcDos = RetornoPrioridad(PaciOpcDos.Edad);

        TCP.insertarColaPri(PrioridadOpcDos, PaciOpcDos);
    }
        break;

    case 3:{
        system ("cls");
        PaciObjeto = TCP.consultarColaPri();
        TCP.sacarColaPri();
        cout << "Opcion 3: Atender un Paciente" << endl;
        cout << "Nombre: " << PaciObjeto.Nombre << endl;
        cout << "Apellido: " << PaciObjeto.Apellido << endl;
        cout << "Edad: " << PaciObjeto.Edad << endl;
        cout << "Identificador: " << PaciObjeto.Identificador << endl;

        if(rand()%2 == 0)
            LD.insertar(1, PaciObjeto);  // Masculino
        else
            LC.insertar(1, PaciObjeto);  // Femenino

        system("pause");

    }
        break;


    case 4:{
        int longitud;
        system ("cls");
        cout << "Opcion 4: Listar Pacientes esperando para atender" << endl;
        longitud = TCP.longitudColaPri();
        for (int i=0; i<longitud;i++){
            PaciObjeto=TCP.consultarColaPri();
            TCPAux.insertarColaPri(RetornoPrioridad(TCP.consultarColaPri().Edad), PaciObjeto);
            cout << "Identificador: " << PaciObjeto.Identificador << endl;
            cout << "Nombre: " << PaciObjeto.Nombre << endl;
            cout << "Apellido: " << PaciObjeto.Apellido << endl;
            cout << "Edad: " << PaciObjeto.Edad << endl;
            cout << "Prioridad: " << RetornoPrioridad(PaciObjeto.Edad) << endl;
            cout << "---------------------------" << endl;

            TCP.sacarColaPri();
        }

        for (int i=0; i<longitud; i++){
            PaciObjeto = TCPAux.consultarColaPri();
            TCP.insertarColaPri(RetornoPrioridad(TCPAux.consultarColaPri().Edad), PaciObjeto);
            TCPAux.sacarColaPri();
        }
        system("pause");
    }
        break;

    case 5:{
        system ("cls");
        int pri, longitud;

        cout << "Opcion 5: Listar Pacientes segun prioridad" << endl;
        cout << "Indique la prioridad que desea listar: "; cin >> pri;
        longitud = TCP.longitudColaPri();

        for (int i=0;i<longitud;i++){
            PaciObjeto=TCP.consultarColaPri();
            TCPAux.insertarColaPri(RetornoPrioridad(TCP.consultarColaPri().Edad), PaciObjeto);
            TCP.sacarColaPri();
            if (pri==RetornoPrioridad(PaciObjeto.Edad)){
                cout << "Identificador: " << PaciObjeto.Identificador << endl;
                cout << "Nombre: " << PaciObjeto.Nombre << endl;
                cout << "Apellido: " << PaciObjeto.Apellido << endl;
                cout << "Edad: " << PaciObjeto.Edad << endl;
                cout << "Prioridad: " << RetornoPrioridad(PaciObjeto.Edad) << endl;
                cout << "---------------------------" << endl;
            }
        }

        for (int i=0; i<longitud; i++){
            PaciObjeto = TCPAux.consultarColaPri();
            TCP.insertarColaPri(RetornoPrioridad(TCPAux.consultarColaPri().Edad), PaciObjeto);
            TCPAux.sacarColaPri();
        }

        system("pause");
    }
        break;

    case 6:{
        system("cls");
        cout << "Opcion 6: Listar pacientes atendidos por sexo" << endl;
        if (!LD.esvacia()){
            cout << "\n\n--------------------" << endl;
            cout << "Pacientes masculinos: " << endl;
            for (int i=0; i<LD.longitud(); i++){
                PaciObjeto = LD.observar(i+1);
                cout << "ID: " << PaciObjeto.Identificador << endl;
                cout << "Nombre: " << PaciObjeto.Nombre << endl;
                cout << "Apellido: " << PaciObjeto.Apellido << endl;
                cout << "Edad: " << PaciObjeto.Apellido << endl;
                cout << "Prioridad: " << RetornoPrioridad(PaciObjeto.Edad) << endl;
                cout << " ~~~~~~~~~~~~ " << endl;
            }
        }

        if (!LC.esvacia()){
            cout << "\n\n--------------------" << endl;
            cout << "Pacientes femeninos: " << endl;
            for (int i=0; i<LC.longitud(); i++){
                PaciObjeto = LC.observar(i+1);
                cout << "ID: " << PaciObjeto.Identificador << endl;
                cout << "Nombre: " << PaciObjeto.Nombre << endl;
                cout << "Apellido: " << PaciObjeto.Apellido << endl;
                cout << "Edad: " << PaciObjeto.Apellido << endl;
                cout << "Prioridad: " << RetornoPrioridad(PaciObjeto.Edad) << endl;
                cout << " ~~~~~~~~~~~~ " << endl;

            }
        }
        system("pause");
        }
        break;

    case 7:{
        cadena NombreFich;
        cout << "Indique el nombre del fichero donde guardar: "; cin >> NombreFich;
        TCP.guardarfichero(NombreFich);
        }
        break;

    case 8:{
        cadena apell;
        cola apellmayor;
        cola apellmenor;
        int longitud = TCP.longitudColaPri();
        system("cls");
        cout << "Opcion 8: Division por apellidos" << endl;
        cout << "Indique el apellido a buscar: "; cin>> apell;

        for (int i=0; i<longitud; i++){
            PaciObjeto=TCP.consultarColaPri();
            TCPAux.insertarColaPri(RetornoPrioridad(TCP.consultarColaPri().Edad), PaciObjeto);
            TCP.sacarColaPri();

            if (strcmp(apell, PaciObjeto.Apellido )>0){
                apellmenor.encolar(PaciObjeto);
            }
            else{
                apellmayor.encolar(PaciObjeto);
            }
        }

        for (int i=0; i<longitud; i++){
            PaciObjeto = TCPAux.consultarColaPri();
            TCP.insertarColaPri(RetornoPrioridad(TCPAux.consultarColaPri().Edad), PaciObjeto);
            TCPAux.sacarColaPri();
        }

        for (int j=0; j<apellmenor.longitud();j++){
            cout << "Apellidos menores: " << endl;
            cout << "Nombre: " << apellmenor.primero().Nombre << endl;
            cout << "Apellido: " << apellmenor.primero().Apellido << endl;
            cout << "Edad: " << apellmenor.primero().Edad << endl;
            apellmenor.desencolar();
        }

        for (int j=0; j<apellmayor.longitud();j++){
            cout << "Apellidos mayores: " << endl;
            cout << "Nombre: " << apellmayor.primero().Nombre << endl;
            cout << "Apellido: " << apellmayor.primero().Apellido << endl;
            cout << "Edad: " << apellmayor.primero().Edad << endl;
            apellmayor.desencolar();
        }

        system("pause");
        }
        break;
    }
    }while (opcionmenuprincipal!=7);
    return 0;
}
