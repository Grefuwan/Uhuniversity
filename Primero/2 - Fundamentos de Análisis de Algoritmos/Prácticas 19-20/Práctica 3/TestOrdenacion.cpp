/*
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los métodos de ordenacion de la clase Ordenacion funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de ordenación,
 *    guardando los datos y permitiendo imprimir la gráfica correspondiente
 * 3. Comparar el coste temporal de dos de los métodos de ordenación
 *    burbuja, inserción, y selección, guardando los datos y permitiendo imprimir la gráfica correspondiente.
 */
#include "AlgoritmosOrdenacion.h"
#include "TestOrdenacion.h"
#include "ConjuntoInt.h"
#include "Graficas.h"
#include "Mtime.h"
#include "Constantes.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


TestOrdenacion::TestOrdenacion()
{
	nombreAlgoritmo.push_back("Burbuja");
	nombreAlgoritmo.push_back("Insercion");
	nombreAlgoritmo.push_back("Seleccion");
}
TestOrdenacion::~TestOrdenacion() {}

/*
 * Ordena un array de enteros según el método indicado
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenación (en milisegundos)
 */
double TestOrdenacion::ordenarArrayDeInt(int v[], int size, int metodo)
{
	AlgoritmosOrdenacion estrategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	// Invoca al método de ordenación elegido
	switch (metodo) {
	case BURBUJA: estrategia.ordenaBurbuja(v, size);
		break;
	case INSERCION: estrategia.ordenaInsercion(v, size);
		break;
	case SELECCION: estrategia.ordenaSeleccion(v, size);
		break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000;
}

/*
 * Comprueba los metodos de ordenacion
 */
void TestOrdenacion::comprobarMetodosOrdenacion()
{
	system("cls");
	int talla;
	cout << "Introduce la talla: ";
	cin >> talla;
	system("cls");
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		v->GeneraVector(talla);
		cout << endl << endl << "vector inicial para el metodo " << nombreAlgoritmo[metodo] << ":" << endl << endl;
		v->escribe();
		double secs = ordenarArrayDeInt(v->getDatos(), talla, metodo);
		cout << endl << endl << "Array ordenado con metodo " << nombreAlgoritmo[metodo] << ":" << endl << endl;
		v->escribe();
		cout << endl;
		v->vaciar();
		system("pause");
		system("cls");
	} /* fin del for */
	system("cls");
}

/*
 * Calcula el caso medio de un metodo de ordenacion,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: metodo de ordenacion a estudiar.
 */
void TestOrdenacion::casoMedio(int metodo)
{
	Graficas gra;
	double secs, tiempo;
	ofstream f((nombreAlgoritmo[metodo] + ".dat").c_str());
	system("cls");
	cout << endl << "\t*** Ordenacion por " << nombreAlgoritmo[metodo] << "***" << endl;
	cout << "\tTiempos de ejecucion promedio " << endl << endl;
	cout << "\tTalla\t\tTiempo (mseg)" << endl;
	for (int talla = tallaIniO; talla <= tallaFinO; talla += incTallaO) {
		ConjuntoInt* v = new ConjuntoInt(talla);
		tiempo = 0;
		for (int prueba = 1; prueba <= NUMREPETICIONES; prueba++) {
			v->GeneraVector(talla);
			secs = ordenarArrayDeInt(v->getDatos(), talla, metodo);
			tiempo = tiempo + secs;
		}
		tiempo = tiempo / NUMREPETICIONES;
		f << talla << "\t" << tiempo << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << fixed << tiempo << endl;
		delete v;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero " << nombreAlgoritmo[metodo] << ".dat " << endl;

	gra.generarGraficaMEDIO(nombreAlgoritmo[metodo], CUADRADO);

	system("pause");
	system("cls");
}

/*
 * Compara dos metodos de ordenacion.
 * Genera el fichero de datos y permite las opcion de crear la gráfica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
void TestOrdenacion::comparar(int metodo1, int metodo2) {
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
	Graficas gra;
	double secs1, tiempo1, secs2, tiempo2;
	ofstream f1((nombreAlgoritmo[metodo1] + ".dat").c_str());
	ofstream f2((nombreAlgoritmo[metodo2] + ".dat").c_str());
	system("cls");
	cout << endl << "\t*** Ordenacion por " << nombreAlgoritmo[metodo1] << " y " << nombreAlgoritmo[metodo2] << " ***" << endl;
	cout << "\tTiempos de ejecucion promedio " << endl << endl;
	cout << "\t\t\t" << nombreAlgoritmo[metodo1] << "\t\t\t" << nombreAlgoritmo[metodo2] << endl << endl;
	cout << "\tTalla(n)\tTiempo(mseg)\t\tTiempo(mseg)\n" << endl;
	for (int talla = tallaIniO; talla <= tallaFinO; talla += incTallaO) {
		ConjuntoInt* v = new ConjuntoInt(talla);
		ConjuntoInt* vclon = new ConjuntoInt(talla);
		tiempo1 = 0; tiempo2 = 0;
		for (int prueba = 1; prueba <= NUMREPETICIONES; prueba++) {
			v->GeneraVector(talla);
			vclon->Clonar(v->getDatos(), talla);
			secs1 = ordenarArrayDeInt(v->getDatos(), talla, metodo1);
			secs2 = ordenarArrayDeInt(vclon->getDatos(), talla, metodo2);
			tiempo1 = tiempo1 + secs1;
			tiempo2 = tiempo2 + secs2;
		}
		tiempo1 = tiempo1 / NUMREPETICIONES;
		tiempo2 = tiempo2 / NUMREPETICIONES;
		f1 << talla << "\t" << tiempo1 << endl;
		f2 << talla << "\t" << tiempo2 << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << fixed << setprecision(2) << tiempo1 << "\t\t" << setw(10) << fixed << setprecision(2) << tiempo2 << endl;
		delete v; delete vclon;
	}
	f1.close();
	f2.close();
	cout << endl << "Datos guardados en los ficheros " << nombreAlgoritmo[metodo1] << ".dat y " << nombreAlgoritmo[metodo2] << ".dat" << endl;

	gra.generarGraficaCMP(nombreAlgoritmo[metodo1], nombreAlgoritmo[metodo2]);

	system("pause");
	system("cls");
}
