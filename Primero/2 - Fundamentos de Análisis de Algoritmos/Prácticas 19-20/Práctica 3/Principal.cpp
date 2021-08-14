#include "TestOrdenacion.h"
#include "TestBusqueda.h"
#include <iostream>
using namespace std;

/* Programa principal */
int main()
{

	int opc1, opcionPrincipal, opc2;
	TestOrdenacion testord;
	TestBusqueda testbusc;

	//menu principal
	do
	{
		system("cls");
		cout << "\t***FAA. Practica 3. Curso 19/20 ***\t\tAlumno Juan Garcia Villagran" << endl;
		cout << "\t\t***MENU PRINCIPAL ***" << endl;
		cout << "1.- Algoritmos de Ordenacion" << endl;
		cout << "2.- Algoritmos de Busqueda" << endl;
		cout << "0.- Salir" << endl;
		cout << "------------------" << endl;
		cout << "Elige una opcion: ";
		cin >> opcionPrincipal;
		switch (opcionPrincipal) {
		case 1: // Ordenacion
			do {
				system("cls");
				cout << "***ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION ***" << endl;
				cout << "1.-Probar los metodos de ordenacion" << endl;
				cout << "2.-Obtener el caso medio de un metodo de ordenacion" << endl;
				cout << "3.-Comparar dos metodos" << endl;
				cout << "0.-Salir" << endl;
				cout << "-------------------------" << endl;
				cout << "Elige una opcion: ";
				cin >> opc1;
				system("cls");
				switch (opc1)
				{
				case 1:
				{
					system("cls");
					cout << "***COMPROBANDO EL FUNCIONAMIENTO DE LOS METDOS DE ORDENACION***" << endl;
					testord.comprobarMetodosOrdenacion(); break;
				}
				case 2:
				{
					int opc2;
					system("cls");
					cout << "	*** Metodo a estudiar para el caso medio? ***" << endl;
					cout << "	0.- Burbuja" << endl;
					cout << "	1.- Inserccion" << endl;
					cout << "	2.- Seleccion" << endl;
					cout << "-------------------------" << endl;
					cout << "Elige opcion: ";
					cin >> opc2;
					switch (opc2)
					{
					case 0:
						system("cls");
						cout << "*** ORDENACION POR BURBUJA ***" << endl;
						cout << "	  Tiempo de ejecución promedio para cada tamano de vector" << endl;
						cout << "Talla		Tiempo" << endl;
						testord.casoMedio(opc2);
						break;
					case 1:
						system("cls");
						cout << "*** ORDENACION POR INSERCCION ***" << endl
							<< "	  Tiempo de ejecucion promedio para cada tamano de vector" << endl
							<< "Talla		Tiempo" << endl;
						testord.casoMedio(opc2);
						break;
					case 2:
						system("cls");
						cout << "*** ORDENACIÓN POR SELECCION ***" << endl
							<< "	  Tiempo de ejecucion promedio para cada tamano de vector" << endl
							<< "Talla		Tiempo" << endl;
						testord.casoMedio(opc2);
						break;
					default: break;
					}break;
				}
				case 3:
				{
					int met1, met2;
					system("cls");
					cout << "*** COMPARACION DE DOS METODOS DE ORDENACION ***" << endl
						<< " 	Selecciona los dos metodos a comparar" << endl
						<< "		0.- Burbuja" << endl
						<< "		1.- Inserccion " << endl
						<< "		2.- Seleccion" << endl
						<< "----------------------------" << endl
						<< "Elige metodo 1: ";
					cin >> met1;
					cout << "Elige metodo 2: ";
					cin >> met2;
					system("cls");
					switch (met1 + met2)
					{
					case 1: //burbuja e inserccion
						system("cls");
						cout << "***COMPARACION ENTRE BURBUJA E INSERCCION" << endl
							<< "		Tiempo de ejecucion promedio para cada tamano de vector" << endl
							<< "Talla		Tiempo(Burbuja)	    Tiempo(Inserccion)" << endl;
						testord.comparar(0, 1);
						break;
					case 2: //burbuja y seleccion
						system("cls");
						cout << "***COMPARACION ENTRE BURBUJA y SELECCION" << endl
							<< "		Tiempo de ejecucion promedio para cada tamano de vector" << endl
							<< "Talla		Tiempo(Burbuja)	    Tiempo(Seleccion)" << endl;
						testord.comparar(0, 2);
						break;
					case 3: //inserccion y seleccion
						system("cls");
						cout << "***COMPARACION ENTRE INSERCCION Y SELECCION" << endl
							<< "		Tiempo de ejecucion promedio para cada tamano de vector" << endl
							<< "Talla		Tiempo(Inserccion)	   Tiempo(Seleccion)" << endl;
						testord.comparar(1, 2);
						break;

					default:break;
					}break;
				}
				case 0: break;
				default:break;
				}
			} while (opc1 != 0);
			break;

		case 2: {
			do {
				system("cls");
				cout << "***ANALISIS EXPERIMENTAL DE ALGORITMOS DE BUSQUEDA***" << endl;
				cout << "1.- Probar los metodos de busqueda" << endl;
				cout << "2.- Obtener el caso medio de un metodo de busqueda" << endl;
				cout << "3.- Comparar dos metodos" << endl;
				cout << "4.- Comparar todos los metodos" << endl;
				cout << "0.- Volver al menu principal" << endl;
				cout << "----------------------" << endl;
				cout << "Elige una opcion: "; cin >> opc2;
				switch (opc2) {
				case 1: {
					testbusc.comprobarMetodosBusqueda();
				}
					  break;

				case 2: {
					int opcion;
					system("cls");
					cout << "\n\n\n\t\t*** Metodo a estudiar para el caso medio ***\n\n";
					cout << "\t0. Busqueda Secuencial Iterativa\n\n";
					cout << "\t1. Busqueda Binaria Iterativa\n\n";
					cout << "\t2. Busqueda Interpolacion Iterativa\n\n";
					cout << "\t--------\n\n";
					cout << "\tElige Opcion: ";
					cin >> opcion;
					switch (opcion) {
					case 0: {
						system("cls");
						testbusc.casoMedio(0);
						break;
					}

					case 1: {
						system("cls");
						testbusc.casoMedio(1);
						break;
					}
					case 2: {
						system("cls");
						testbusc.casoMedio(2);
						break;
					}
					}

				}
					  break;

				case 3: {
					int opcion1, opcion2;
					system("cls");
					cout << "\n\n\n\t\t*** COMPARACION DE DOS METODOS DE BUSQUEDA ***\n\n";
					cout << "\tSelecciona los dos metodos a comparar\n\n";
					cout << "\t0: Busqueda Secuencial Iterativa\n\n";
					cout << "\t1: Busqueda Binaria Iterativa\n\n";
					cout << "\t2: Busqueda Interpolacion Iterativa\n\n";
					cout << "\t--------\n\n";
					cout << "\tElige metodo 1: ";
					cin >> opcion1;
					cout << "\n\tElige metodo 2: ";
					cin >> opcion2;
					testbusc.comparar(opcion1, opcion2);
					system("pause");
				}
					  break;

				case 4: {
					system("cls");
					cout << "\n\n\n\t\t*** COMPARACION DE TODOS METODOS DE BUSQUEDA ***\n\n";
					testbusc.compararTodos();
					system("pause");
				}
					  break;

				}
			} while (opc2 != 0);
			}
			break;
		}
	}while (opcionPrincipal != 0);
	return 0;
};