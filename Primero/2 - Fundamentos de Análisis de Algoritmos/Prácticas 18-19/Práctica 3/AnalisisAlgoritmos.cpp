#include "TestOrdenacion.h"
#include "TestBusqueda.h"
#include <iostream>
#include "AlgoritmosOrdenacion.h"
using namespace std;

/** Programa principal **/
int main()
{
	int opcionordenacion, opcionbusqueda, opcionmenu, opcionobtener, opcionobtener2;
	do {
		system("cls");
		cout << " " << endl;
		cout << "\t *** FAA. Practica 3. Curso 18/19 ***" << endl;
		cout << "\t\t\t\t\t\tAutor: Juan Garcia Villagran" << endl;
		cout << " " << endl;
		cout << "\t\t1.- MENU ORDENACION" << endl;
		cout << "\t\t2.- MENU BUSQUEDA" << endl;
		cout << "\t\t0.- Salir" << endl;
		cout << "\t\t--------" << endl;
		cout << "\t\tElige opcion:";
		cin >> opcionmenu;

		switch (opcionmenu) {

		case 1: {
			do {
				system("cls");
				cout << "*** ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION  ***" << endl;
				cout << " " << endl;
				cout << "\t\t1.- Probar los metodos de ordenacion" << endl;
				cout << "\t\t2.- Obtener el caso medio de un metodo de ordenacion" << endl;
				cout << "\t\t3.- Comparar dos metodos" << endl;
				cout << "\t\t0.- Salir" << endl;
				cout << "\t\t--------" << endl;
				cout << "\t\tElige opcion:";
				cin >> opcionordenacion;
				switch (opcionordenacion) {
				case 1: {
					TestOrdenacion t;
					t.comprobarMetodosOrdenacion();			//TestOrdenacion.cpp
					break;
				}

				case 2: {
					system("cls");
					TestOrdenacion test;
					cout << "\n\n\t\t*** Metodo a estudiar para el caso medio ***" << endl;
					cout << "\t\t0: Burbuja" << endl;
					cout << "\t\t1: Insercion" << endl;
					cout << "\t\t2: Seleccion" << endl;
					cout << "\t\t------------" << endl;
					cout << "\t\tElige opcion:"; cin >> opcionobtener;
					test.casoMedio(opcionobtener);						//Hacerlo, no tiene nada || TestOrdenacion.cpp
					break;
				}

				case 3: {
					system("cls");
					TestOrdenacion test;
					int opcioncomp1, opcioncomp2;
					cout << "\n\n\t\t*** COMPARACION DE DOS METODOS DE ORDENACION ***" << endl;
					cout << "\t\tSelecciona los dos metodos a comparar:" << endl;
					cout << "\t\t0.- Burbuja" << endl;
					cout << "\t\t1.- Insercion" << endl;
					cout << "\t\t2.- Seleccion" << endl;
					cout << "\t\tElige Metodo 1: "; cin >> opcioncomp1;
					cout << "\t\tElige Metodo 2: "; cin >> opcioncomp2;
					test.comparar(opcioncomp1, opcioncomp2);

					break;
				}

				}

			} while (opcionordenacion != 0);

		}

		case 2: {
			do {
				system("cls");
				cout << "*** ANALISIS EXPERIMENTAL DE ALGORITMOS DE BUSQUEDA  ***" << endl;
				cout << " " << endl;
				cout << "\t\t1.- Probar los metodos de busqueda" << endl;
				cout << "\t\t2.- Obtener el caso medio de un metodo de busqueda" << endl;
				cout << "\t\t3.- Comparar dos metodos" << endl;
				cout << "\t\t0.- Volver al menu principal" << endl;
				cout << "\t\t--------" << endl;
				cout << "\t\tElige opcion:";
				cin >> opcionbusqueda;
				switch (opcionbusqueda) {

				case 1: {
					system("cls");
					TestBusqueda t;
					t.comprobarMetodosBusqueda();
					break;
				}

				case 2: {
					system("cls");
					TestBusqueda test;
					cout << "\n\n\t\t*** Metodo a estudiar para el caso medio ***" << endl;
					cout << "\t\t0: Busqueda Secuencial Iterativa" << endl;
					cout << "\t\t1: Busqueda Binaria Recursiva" << endl;
					cout << "\t\t2: Busqueda Ternaria Recursiva" << endl;
					cout << "\t\t------------" << endl;
					cout << "\t\tElige opcion:"; cin >> opcionobtener2;
					test.casoMedio(opcionobtener2);						//Hacerlo, no tiene nada || TestOrdenacion.cpp
					break;
				}

				case 3: {
					system("cls");
					TestBusqueda test;
					int opcioncomp1, opcioncomp2;
					cout << "\n\n\t\t*** COMPARACION DE DOS METODOS DE ORDENACION ***" << endl;
					cout << "\t\tSelecciona los dos metodos a comparar:" << endl;
					cout << "\t\t0.- Busqueda Secuencial Iterativa" << endl;
					cout << "\t\t1.- Busqueda Binaria Recursiva" << endl;
					cout << "\t\t2.- Busqueda Ternaria Recursiva" << endl;
					cout << "\t\tElige Metodo 1: "; cin >> opcioncomp1;
					cout << "\t\tElige Metodo 2: "; cin >> opcioncomp2;
					test.comparar(opcioncomp1, opcioncomp2);
				}

				}

			} while (opcionbusqueda != 0);




		}




		}
	} while (opcionmenu != 0);					//Para que se mantenga en el menu principal hasta que no pulse 0
	return 0;
}