/*
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los métodos de búsqueda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente con ajuste al Orden de complejidad.
 * 3. Comparar el coste temporal de dos métodos de búsqueda
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente.
 */
#include "TestBusqueda.h"
#include "Constantes.h"
#include "AlgoritmosBusqueda.h"
#include "AlgoritmosOrdenacion.h"
#include "ConjuntoInt.h"
#include "Graficas.h"
#include "Mtime.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "TestOrdenacion.h"
using namespace std;

TestBusqueda::TestBusqueda()
{
	nombreAlgoritmo.push_back("SecuencialI");
	nombreAlgoritmo.push_back("BinariaR");
	nombreAlgoritmo.push_back("INTERPOLACIONIt");
}
TestBusqueda::~TestBusqueda()
{
}

/*
 * Busca en un array de enteros según el método indicado
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 * param metodo: Metodo de búsqueda a utilizar
 * return Tiempo empleado en la busqueda (en milisegundos)
 */
string BuscarNombreOrdenacion(int met);
double TestBusqueda::buscaEnArrayDeInt(int key, int v[], int size, int metodo, int& posicion)
{
	AlgoritmosBusqueda strategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	// Invoca al método de búsqueda elegido
	switch (metodo) {
	case SECUENCIALIt: posicion = strategia.busquedaSecuencialIt(v, size, key);
		break;
	case BINARIAIt: posicion = strategia.busquedaBinariaIt(v, size, key);
		break;
	case INTERPOLACIONIt: posicion = strategia.busquedaInterpolacionIt(v, size, key);
		break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000000;
}

/*
 * Comprueba los metodos de búsqueda
 */
void TestBusqueda::comprobarMetodosBusqueda() {
	int talla;
	cout << "\nIntroduce la talla: ";
	cin >> talla;
	system("cls");
	ConjuntoInt* v = new ConjuntoInt(talla);
	AlgoritmosOrdenacion AlOrdena;
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++) {
		v->GeneraVector(talla);

		AlOrdena.ordenaInsercion(v->getDatos(), talla);  //Ordenar array
		cout << "\n\nVector para el metodo " << nombreAlgoritmo[metodo] << ":" << endl << endl;
		v->escribe();
		int key;
		cout << "\n\nIntroduce la clave a buscar: ";
		cin >> key;
		int posicion;
		buscaEnArrayDeInt(key, v->getDatos(), talla, metodo, posicion);
		cout << "\n\nPosicion de " << key << " buscado con el metodo " << nombreAlgoritmo[metodo] << " : " << posicion << endl << endl;
		v->vaciar();
		system("pause");
		system("cls");
	}
	system("cls");
}


/*
 * Calcula el caso medio de un metodo de búsqueda,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: metodo de búsqueda a estudiar.
 */
void TestBusqueda::casoMedio(int metodo)
{
	system("cls");
	char opc;
	Graficas gra;
	string nombre = BuscarNombreOrdenacion(metodo);
	cout << "Busqueda " << nombre << ". Tiempos de ejecucion promedio " << endl << endl;
	cout << "\tTalla \t\t\tTiempo <mseg>" << endl << endl;
	ofstream f((nombre + ".dat").c_str(), ios::binary);
	for (int talla = tallaIniB; talla <= tallaFinB; talla += incTallaB)
	{
		int posicion = 0;
		double tiempo = 0;
		ConjuntoInt* v = new ConjuntoInt(talla);
		v->GeneraVector(talla);
		TestOrdenacion t;
		t.ordenarArrayDeInt(v->getDatos(), talla, 1); //Ordena por inserccion(metodo de ordenacion mas rapido de los 3)
		for (int i = 1; i <= NUMREPETICIONES; i++)
		{
			int key = 1 + rand() % (talla - 1); //Genera una key aleatoria , va dentro de este bucle para poder calcular un caso medio lo mas real posible
			tiempo += buscaEnArrayDeInt(key, v->getDatos(), talla, metodo, posicion);
		}
		v->vaciar();
		tiempo /= NUMREPETICIONES;
		cout << "\t" << talla << "\t\t\t" << tiempo << endl;
		f << talla << "\t" << tiempo << endl;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero " << nombre << ".dat " << endl;

	if (metodo == 0)
		gra.generarGraficaMEDIO(nombre, N);
	else
		gra.generarGraficaMEDIO(nombre, LOGN);
	system("pause");
	system("cls");
}


/*
 * Compara dos metodos de búsqueda.
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo1: Primer metodo de búsqueda a comparar
 * param metodo2: Segundo metodo de búsqueda a comparar
 */

void TestBusqueda::comparar(int metodo1, int metodo2)
{
	system("cls");
	char opc;
	Graficas gra;
	string nombre1, nombre2;
	nombre1 = BuscarNombreOrdenacion(metodo1);
	nombre2 = BuscarNombreOrdenacion(metodo2);
	cout << "Busqueda " << nombre1 << " y " << nombre2 << ". Tiempos de ejecucion promedio " << endl;
	cout << "\t\t\t" << nombre1 << "\t\t" << nombre2 << endl << endl;
	cout << "\tTalla \t\tTiempo (mseg)\t\tTiempo (mseg)" << endl << endl;
	ofstream f1(metodo1 + ".dat", ios::binary), f2(metodo2 + ".dat", ios::binary);
	for (int talla = tallaIniB; talla <= tallaFinB; talla += incTallaB)
	{
		int posicion = 0;
		double tiempo1 = 0, tiempo2 = 0;
		ConjuntoInt* v = new ConjuntoInt(talla);
		ConjuntoInt* vclon = new ConjuntoInt(talla);
		for (int i = 1; i <= NUMREPETICIONES; i++)
		{
			v->GeneraVector(talla);
			vclon->Clonar(v->getDatos(), talla);
			//Usamos la misma key y vector para ambos metodos de busqueda para que la comparacion sea lo mas exacta posible//
			int key = 1 + rand() % (talla - 1);
			tiempo1 += buscaEnArrayDeInt(key, v->getDatos(), talla, metodo1, posicion);
			tiempo2 += buscaEnArrayDeInt(key, vclon->getDatos(), talla, metodo2, posicion);
		}
		v->vaciar();
		tiempo1 /= NUMREPETICIONES;
		tiempo2 /= NUMREPETICIONES;

		cout << "\t" << talla << "\t\t" << tiempo1 << setw(6) << "\t\t" << tiempo2 << setw(6) << endl;

		f1 << talla << "\t" << tiempo1 << endl;
		f2 << talla << "\t" << tiempo2 << endl;
	}
	f1.close();
	f2.close();
	cout << endl << "Datos guardados en los ficheros " << nombre1 << ".dat y " << nombre2 << ".dat" << endl;

	gra.generarGraficaCMP(nombre1, nombre2);

	system("pause");
	system("cls");

}


string BuscarNombreOrdenacion(int met)
{
	string nom;
	if (met == 0)
		nom = "SecuencialIt";
	else
		if (met == 1)
			nom = "BinariaIt";
		else
			nom = "InterpolacionIt";
	return nom;
}

/*
 * Compara todos los metodos de búsqueda.
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 */

void TestBusqueda::compararTodos(){
	Graficas gra;
	double secs1, tiempo1, secs2, tiempo2, secs3, tiempo3;
	ofstream f1((nombreAlgoritmo[SECUENCIALIt] + ".dat").c_str());
	ofstream f2((nombreAlgoritmo[BINARIAIt] + ".dat").c_str());
	ofstream f3((nombreAlgoritmo[INTERPOLACIONIt] + ".dat").c_str());

	system("cls");
	cout << endl << "\t*** Ordenacion de todos los algoritmos de Busqueda ***" << endl;
	cout << "\tTiempos de ejecucion promedio " << endl << endl;
	cout << "\t\t\t" << nombreAlgoritmo[SECUENCIALIt] << "\t\t\t" << nombreAlgoritmo[BINARIAIt] << "\t\t\t" << nombreAlgoritmo[INTERPOLACIONIt] << endl << endl;
	cout << "\tTalla(n)\tTiempo(mseg)\t\tTiempo(mseg)\n" << endl;
	for (int talla = tallaIniO; talla <= tallaFinO; talla += incTallaO) {
		int posicion = 0;
		ConjuntoInt* v = new ConjuntoInt(talla);
		ConjuntoInt* vclon = new ConjuntoInt(talla);
		ConjuntoInt* vclon2 = new ConjuntoInt(talla);
		tiempo1 = 0; tiempo2 = 0, tiempo3 = 0;
		for (int prueba = 1; prueba <= NUMREPETICIONES; prueba++) {
			v->GeneraVector(talla);
			vclon->Clonar(v->getDatos(), talla);
			vclon2->Clonar(vclon->getDatos(), talla);
			int key = 1 + rand() % (talla - 1);
			secs1 = buscaEnArrayDeInt(key, v->getDatos(), talla, SECUENCIALIt, posicion);
			secs2 = buscaEnArrayDeInt(key, vclon->getDatos(), talla, BINARIAIt, posicion);
			secs3 = buscaEnArrayDeInt(key, vclon2->getDatos(), talla, INTERPOLACIONIt, posicion);
			tiempo1 = tiempo1 + secs1;
			tiempo2 = tiempo2 + secs2;
			tiempo3 = tiempo3 + secs3;
		}
		tiempo1 = tiempo1 / NUMREPETICIONES;
		tiempo2 = tiempo2 / NUMREPETICIONES;
		tiempo3 = tiempo3 / NUMREPETICIONES;
		f1 << talla << "\t" << tiempo1 << endl;
		f2 << talla << "\t" << tiempo2 << endl;
		f3 << talla << "\t" << tiempo3 << endl;

		cout << "\t" << talla << "\t\t" << setw(10) << fixed << setprecision(2) << tiempo1 << "\t\t" << setw(10) << fixed << setprecision(2) << tiempo2 << "\t\t" << setw(10) << fixed << setprecision(2) << tiempo3 << endl;
		delete v; delete vclon; delete vclon2;
	}
	f1.close();
	f2.close();
	f3.close();
	cout << endl << "Datos guardados en los ficheros " << nombreAlgoritmo[SECUENCIALIt] << ".dat, " << nombreAlgoritmo[BINARIAIt] << ".dat y " << nombreAlgoritmo[INTERPOLACIONIt] << ".dat" << endl;

	gra.generarGraficaCMP_TODOS(nombreAlgoritmo);

	system("pause");
	system("cls");
}