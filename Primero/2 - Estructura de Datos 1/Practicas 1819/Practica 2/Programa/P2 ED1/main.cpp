#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

#include "Peluqueria.h"
#include "cola.h"
#include "lista.h"

typedef char cadena[50];


using namespace std;

int main()
{
    int opcionmenuprincipal;
	peluqueria pelu;
	peluquero pelador;
	cliente cli;


    do{
    system ("cls");

    cout << "Peluqueria Corte 2.0 Huelva\n" << endl;
    cout << "_______________________________________________________" << endl;
    cout << "1. Leer fichero (rescatar copia)" << endl;
    cout << "2. Insertar Peluquero" << endl;
    cout << "3. Insertar cliente" << endl;
    cout << "4. Retirar peluquero" << endl;
    cout << "5. Atender cliente" << endl;
    cout << "6. Mostrar peluqueria" << endl;
    cout << "7. Eliminar cliente" << endl;
    cout << "8. Volcar a fichero (crear copia)" << endl;
    cout << "9. Salir\n\n" << endl;
    cout << "Pulse la opcion deseada: ";
    cin >> opcionmenuprincipal;

    switch (opcionmenuprincipal){

    case 1: {
        system("cls");
        pelu.AbrirPeluqueria("inicial.dat");
        cout << "Carga correcta" << endl;
        system ("pause");
		break;
    }

    case 2: {
		system("cls");
        peluquero pel;      //Original
    cout << "Introduzca el nombre del peluquero: ";
    cin >> pel.Nombre;
    cout << "Introduzca sus apellidos: ";
    cin >> pel.Apellidos;
    cout << "Introduzca su codigo: ";
    cin >> pel.Codigo;
    cout << "Introduzca su tipo de servicio: ";
    cin >> pel.TipoServicio;
		pelu.IncorporarPeluquero(pel);
		break;
    }

    case 3: {
		system("cls");
		cliente cliTMP;
        cadena Apellido1, Apellido2;

        cout << "Introduzca el nombre del cliente: "; cin >> cliTMP.Nombre;
        cout << "Introduzca los apellidos: "; cin >> Apellido1 >> Apellido2;
        strcpy(Apellido1, strcat(Apellido1, " "));
        strcpy(cliTMP.Apellidos, strcat(Apellido1, Apellido2));
        cout << "Introduzca la edad: "; cin >> cliTMP.Edad;
        cout << "Introduzca el tipo de servicio solicitado: "; cin >> cliTMP.TipoServicio;
        cout << "Introduzca la hora de llegada en minutos: "; cin >> cliTMP.HoraLlegada;
        pelu.IncorporarCliente(cliTMP);
		break;
    }

	case 4: {
		system("cls");
		int x;
		pelu.RetirarPeluquero(x);
		break;
	}

	case 5: {
		system("cls");
		//pelu.AtenderCliente(/*codigopeluquero*/);
		break;
	}

	case 6: {
		system("cls");
		pelu.Mostrar();
		system ("pause");
		break;
	}

	case 7: {
		system("cls");
		cadena nombre, apellido;
		cliente cli;
		cout << "Introduzca el nombre del cliente a borrar: "; cin >> nombre;
		cout << "Introduzca los apellidos del cliente a borrar: "; cin >> apellido;
        pelu.EliminarCliente(nombre, apellido);
		break;
	}

	case 8: {
		system("cls");
		//pelu.VolcarPeluqueria("inicial.dat");
		break;
	}
	}


    } while (opcionmenuprincipal!=9);

    system ("pause");
    return 0;
}
