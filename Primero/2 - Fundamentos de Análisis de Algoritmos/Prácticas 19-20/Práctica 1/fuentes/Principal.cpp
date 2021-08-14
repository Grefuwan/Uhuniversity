#include "TestAlgoritmo.h"
#include "ConjuntoInt.h"
#include "Constantes.h"
#include <iostream>
using namespace std;


/* Programa principal */
int main()
{
	TestAlgoritmo test;
	int opcionmain;
	do {
		system("cls");
		cout << "\t\t*** FAA. Practica 1. Curso 19/20 ***\t\tJuan Garcia Villagran" << endl;
		cout << "\n\n\t\t*** ESTUDIO DE LA COMPLEJIDAD DEL ALGORITMO BUSQUEDA SECUENCIAL ***\n" << endl;
		cout << "\t\t\t1.- Estudio Teorico" << endl;
		cout << "\t\t\t2.- Estudio Empirico" << endl;
		cout << "\t\t\t0.- Salir\n\t\t\t---------\n" << endl;
		cout << "\t\t\tElige opcion: "; cin >> opcionmain;
		switch (opcionmain) {
		case 1: int opcionTeorica; 
			do{			
			system("cls");
			cout << "\t\t*** ESTUDIO TEORICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL ***" << endl;
			cout << "\t\t\t1.- Probar el algoritmo de busqueda secuencial" << endl;
			cout << "\t\t\t2.- Obtener los casos del metodo de busqueda secuencial" << endl;
			cout << "\t\t\t3.- Comparar los casos" << endl;
			cout << "\t\t\t0.- Volver al menu principal" << endl;
			cout << "\t\t\t-------------" << endl;
			cout << "\t\t\tElige opcion: "; cin >> opcionTeorica;
			switch (opcionTeorica) {
			case 1:
				test.comprobarAlgoritmo();
				break;
			case 2:
					int opcioncaso;
					system("cls");
					cout << "\n\t\t*** Caso a estudiar para la busqueda secuencial ***" << endl;
					cout << "\t\t0: Caso peor" << endl;
					cout << "\t\t1: Caso medio" << endl;
					cout << "\t\t2: Caso mejor" << endl;
					cout << "\t\t-------------" << endl;
					cout << "\t\tElige opcion: "; cin >> opcioncaso;
					switch (opcioncaso) {
					case 0:
						test.costeCasoTeorico(0);
						break;
					case 1:
						test.costeCasoTeorico(1);
						break;
					case 2:
						test.costeCasoTeorico(2);
						break;
					}
				break;
			case 3:
				test.compararTeorico(0, 1, 2);
				break;

			}
			} while (opcionTeorica != 0);
			  break;
		case 2:
			int opcionempirico;
			do {
				system("cls");
				cout << "\t\t*** ESTUDIO EMPIRICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL ***" << endl;
				cout << "\t\t\t1.- Probar el algoritmo de busqueda secuencial" << endl;
				cout << "\t\t\t2.- Obtener los casos del metodo de busqueda secuencial" << endl;
				cout << "\t\t\t3.- Comparar los casos" << endl;
				cout << "\t\t\t0.- Volver al menu principal" << endl;
				cout << "\t\t\t-------------" << endl;
				cout << "\t\t\tElige opcion: "; cin >> opcionempirico;
				switch (opcionempirico) {
				case 1:
					test.comprobarAlgoritmo();
					break;
				case 2:
					int opcioncaso;
					system("cls");
					cout << "\n\t\t*** Caso a estudiar para la busqueda secuencial ***" << endl;
					cout << "\t\t0: Caso peor" << endl;
					cout << "\t\t1: Caso medio" << endl;
					cout << "\t\t2: Caso mejor" << endl;
					cout << "\t\t-------------" << endl;
					cout << "\t\tElige opcion: "; cin >> opcioncaso;
					switch (opcioncaso) {
					case 0:
						test.costeCasoEmpirico(0);
						break;
					case 1:
						test.costeCasoEmpirico(1);
						break;
					case 2:
						test.costeCasoEmpirico(2);
						break;
					}
					break;
				case 3:
					test.compararEmpirico(0, 1, 2);
					break;
				}
			} while (opcionempirico != 0);
			break;
		}
	} while (opcionmain != 0);
return 0;
}

