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
	nombreAlgoritmo.push_back("Shell");
	nombreAlgoritmo.push_back("Quicksort");

} 
TestOrdenacion::~TestOrdenacion(){}

/*
 * Ordena un array de enteros según el método indicado
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenación (en milisegundos)
 */
double TestOrdenacion::ordenarArrayDeInt(int v[],int size,int metodo) 
{
	AlgoritmosOrdenacion estrategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	// Invoca al método de ordenación elegido
	switch (metodo){
		case BURBUJA: estrategia.ordenaBurbuja(v, size);
			break;
		case INSERCION: estrategia.ordenaInsercion(v, size);
			break;
		case SELECCION: estrategia.ordenaSeleccion(v, size);
			break;
		case SHELL: estrategia.ordenaShell(v, size);
			break;
		case QUICKSORT: estrategia.ordenaQuicksort(v, 0, size - 1);
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
	int talla;
	cout <<endl<<endl<<"Introduce la talla: ";
	cin>>talla; 
	system("cls"); 
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt *v= new ConjuntoInt(talla); 
		v->GeneraVector(talla);
		cout <<endl<<endl<< "Vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		double secs=ordenarArrayDeInt(v->getDatos(),talla,metodo);
		cout<<endl<<endl<<"Array ordenado con metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		cout<<endl;
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
	ofstream f(nombreAlgoritmo[metodo] + ".dat");
	system("cls");
	cout << "\nCaso Medio de " << nombreAlgoritmo[metodo] << endl;
	cout << "Tiempos de ejecicion\n" << endl;
	cout << "\tTalla\tTiempo (ms)\n" << endl;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla) {
		ConjuntoInt *v = new ConjuntoInt(talla);
		double tiempo = 0;
		for (int j = 1; j <= NUMREPETICIONES; j++) {

			v->GeneraVector(talla);
			tiempo += ordenarArrayDeInt(v->getDatos(), talla, metodo);
			v->vaciar();
		}
		tiempo /= NUMREPETICIONES;
		cout << "\t" << talla << "\t" << tiempo << endl;
		f << talla << "\t" << tiempo << endl;

	}
	f.close();
	system("pause");
	char opc;
	cout << "¿Desea generar la grafica? S/N: " << endl;
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		Graficas graf;

		if (metodo == BURBUJA) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], CUADRADO);
			system("start CmdBurbuja.gpl");
		}

		if (metodo == SELECCION) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], CUADRADO);
			system("start CmdSeleccion.gpl");
		}

		if (metodo == INSERCION) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], CUADRADO);
			system("start CmdInsercion.gpl");
		}

		if (metodo == SHELL) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], CUADRADO);
			system("start CmdShell.gpl");
		}

		if (metodo == QUICKSORT) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], CUADRADO);
			system("start CmdQuicksort.gpl");
		}

		system("pause");
	}
	}
}
/*
 * Compara dos metodos de ordenacion. 
 * Genera el fichero de datos y permite las opcion de crear la gráfica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
void TestOrdenacion::comparar(int metodo1, int metodo2) {
	ofstream f(nombreAlgoritmo[metodo1] + nombreAlgoritmo[metodo2] + "Comparacion.dat");
	system("cls");
	cout << "\nAlgoritmos de busqueda " << " Comparacion" << endl;
	cout << "\tTiempos de ejecucion\n\n" << endl;
	cout << "\tTalla \t\t Tiempo(ms)\t Tiempo (ms)\n" << endl;
	cout << "\tNombre\t\t " << nombreAlgoritmo[metodo1] << "\t " << nombreAlgoritmo[metodo2] << "\n" << endl;
	double tiempo1 = 0, tiempo2 = 0;
	int talla;
	for (talla = tallaIni; talla <= tallaFin; talla += incTalla) {
		ConjuntoInt *v = new ConjuntoInt(talla);
		for (int i = 0; i < NUMREPETICIONES; i++) {
			v->GeneraVector(talla);
			tiempo1 += ordenarArrayDeInt(v->getDatos(), talla, metodo1);
			v->GeneraVector(talla);
			tiempo2 += ordenarArrayDeInt(v->getDatos(), talla, metodo2);
			v->vaciar();
		}
		tiempo1 /= NUMREPETICIONES;
		tiempo2 /= NUMREPETICIONES;

		delete v;

		cout.precision(4);
		cout << "\t\t" << talla << "\t\t    " << setw(10) << fixed << setprecision(4) << tiempo1 << "\t     " << setw(10) << fixed << setprecision(4) << tiempo2 << "\n";
		f << talla << "\t" << tiempo1 << "\t" << tiempo2 << "\n";
	}
	f.close();

	//Generar grafica
	char opt;
	cout << "\nGenerar grafica (S/N): ";
	cin >> opt;
	if (opt == 's' || opt == 'S') {
		Graficas graf;
		if ((metodo1 == BURBUJA && metodo2 == SELECCION) || (metodo1 == SELECCION && metodo2 == BURBUJA)) {
		graf.generarGraficaCMP("Burbuja", "Seleccion");
		system("start CmdCompararBurbujaSeleccion.gpl");
		}

		if ((metodo1 == BURBUJA && metodo2 == INSERCION) || (metodo1 == INSERCION && metodo2 == BURBUJA)) {
			graf.generarGraficaCMP("Burbuja", "Insercion");
			system("start CmdCompararBurbujaInsercion.gpl");

		}

		if ((metodo1 == INSERCION && metodo2 == SELECCION) || (metodo1 == SELECCION && metodo2 == INSERCION)) {
			graf.generarGraficaCMP("Insercion", "Seleccion");
			system("start CmdCompararInsercionSeleccion.gpl");

		}
		cout << "La grafica fue generada\n\n";
	}
	else cout << "No se generara la grafica.\n\n";

	system("pause");

	}