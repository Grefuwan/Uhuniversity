#include "TestOrdenacion.h"
#include <iostream>
#include "AlgoritmosOrdenacion.h"
using namespace std;

/** Programa principal **/
int main()
{
	int opcion, opcionobtener;
	do {
		system("cls");
		cout << " " << endl;
		cout << "\t *** FAA. Practica 2. Curso 18/19 ***" << endl;
		cout << "\t\t\t\t\t\tAutor: Juan Garcia Villagran" << endl;
		cout << " " << endl;
		cout << "*** ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION  ***" << endl;
		cout << " " << endl;
		cout << "\t\t1.- Probar los metodos de ordenacion" << endl;
		cout << "\t\t2.- Obtener el caso medio de un metodo de ordenacion" << endl;
		cout << "\t\t3.- Comparar dos metodos" << endl;
		cout << "\t\t0.- Salir" << endl;
		cout << "\t\t--------" << endl;
		cout << "\t\tElige opcion:";
		cin >> opcion;

		switch (opcion) {

		case 1: {
			system("cls");
			TestOrdenacion t;
			t.comprobarMetodosOrdenacion();			//TestOrdenacion.cpp
			break; }


		case 2: {
			system("cls");
			TestOrdenacion test;
			cout << "\n\n\t\t*** Metodo a estudiar para el caso medio ***" << endl;
			cout << "\t\t0: Burbuja" << endl;
			cout << "\t\t1: Insercion" << endl;
			cout << "\t\t2: Seleccion" << endl;
			cout << "\t\t3: Shell" << endl;
			cout << "\t\t4: Quicksort" << endl;
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

	} while (opcion != 0);					//Para que se mantenga en el menu principal hasta que no pulse 0
	return 0;
};