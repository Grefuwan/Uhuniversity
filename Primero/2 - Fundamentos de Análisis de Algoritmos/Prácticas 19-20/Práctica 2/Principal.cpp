#include "TestOrdenacion.h"
#include <iostream>
using namespace std;

/* Programa principal */
int main()
{

	int opc1;
	TestOrdenacion t;

	//menu principal
	do
	{
		system("cls");
		cout << "\t***FAA. Practica 2. Curso 19/20 ***\t\tAlumno Juan Garcia Villagran" << endl;
		cout << "\t\t***MENU PRINCIPAL ***" << endl;
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
			t.comprobarMetodosOrdenacion(); break;
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
				t.casoMedio(opc2);
				break;
			case 1:
				system("cls");
				cout << "*** ORDENACION POR INSERCCION ***" << endl
					<< "	  Tiempo de ejecucion promedio para cada tamano de vector" << endl
					<< "Talla		Tiempo" << endl;
				t.casoMedio(opc2);
				break;
			case 2:
				system("cls");
				cout << "*** ORDENACIÓN POR SELECCION ***" << endl
					<< "	  Tiempo de ejecucion promedio para cada tamano de vector" << endl
					<< "Talla		Tiempo" << endl;
				t.casoMedio(opc2);
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
				t.comparar(0, 1);
				break;
			case 2: //burbuja y seleccion
				system("cls");
				cout << "***COMPARACION ENTRE BURBUJA y SELECCION" << endl
					<< "		Tiempo de ejecucion promedio para cada tamano de vector" << endl
					<< "Talla		Tiempo(Burbuja)	    Tiempo(Seleccion)" << endl;
				t.comparar(0, 2);
				break;
			case 3: //inserccion y seleccion
				system("cls");
				cout << "***COMPARACION ENTRE INSERCCION Y SELECCION" << endl
					<< "		Tiempo de ejecucion promedio para cada tamano de vector" << endl
					<< "Talla		Tiempo(Inserccion)	   Tiempo(Seleccion)" << endl;
				t.comparar(1, 2);
				break;

			default:break;
			}break;
		}
		case 0: break;
		default:break;
		}
	} while (opc1 != 0);
	return 0;
};