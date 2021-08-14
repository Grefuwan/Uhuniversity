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
#include "TestOrdenacion.h"
#include "Mtime.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

TestBusqueda::TestBusqueda()
{
	nombreAlgoritmo.push_back("SecuencialI");
	nombreAlgoritmo.push_back("BinariaR");
	nombreAlgoritmo.push_back("TernariaR");
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
double TestBusqueda::buscaEnArrayDeInt(int key,int v[],int size,int metodo,int &posicion) 
{
    AlgoritmosBusqueda strategia;
		Mtime t;
		LARGE_INTEGER t_inicial, t_final;
		QueryPerformanceCounter(&t_inicial);
// Invoca al método de búsqueda elegido
    switch (metodo)
		{
				case SECUENCIALIt: posicion=strategia.busquedaSecuencialIt(v, size, key);
            break;
				case BINARIARc: posicion=strategia.busquedaBinariaRc(v, size, key); 
            break;
				case TERNARIARc: posicion=strategia.busquedaTernariaRc(v, size, key); 
            break;
		}
		QueryPerformanceCounter(&t_final);
    return t.performancecounter_diff(&t_final, &t_inicial) * 1000000;   
}

/*
 * Comprueba los metodos de búsqueda
 */
void TestBusqueda::comprobarMetodosBusqueda(){
	int talla;
	cout<<endl<<endl<<"Introduce la talla: ";
	cin>>talla; 
	system("cls");
	ConjuntoInt *v= new ConjuntoInt(talla); 
	AlgoritmosOrdenacion AlOrdena;
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++){
		v->GeneraVector(talla);
		/* Ordenar array*/
		AlOrdena.ordenaInsercion(v->getDatos(),talla);
		cout <<endl<<endl<< "vector para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		int key;
		cout<<endl<<endl<<"Introduce la clave a buscar: ";
		cin>>key; 
		int posicion;
		buscaEnArrayDeInt(key,v->getDatos(),talla,metodo,posicion);
		cout<<endl<<endl<<"posicion de "<<key<<" buscado con el metodo "<<nombreAlgoritmo[metodo]<< " : "<<posicion<<endl<<endl;
		v->vaciar(); 
		system("pause");
		system("cls");
	}
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
	TestOrdenacion testo;
	int key;
	ofstream f(nombreAlgoritmo[metodo1] + nombreAlgoritmo[metodo2] + "Comparacion.dat");
	system("cls");
	cout << "\nAlgoritmos de busqueda " << " Comparacion" << endl;
	cout << "\tTiempos de ejecucion\n\n" << endl;
	cout << "\tTalla \t\t Tiempo(ms)\t Tiempo (ms)\n" << endl;
	cout << "\tNombre\t\t " << nombreAlgoritmo[metodo1] << "\t " << nombreAlgoritmo[metodo2] << "\n" << endl;
	double tiempo1 = 0, tiempo2 = 0;
	int talla;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla) {
		ConjuntoInt *v = new ConjuntoInt(talla);
		int posicion = 0;
		int tmp;
		for (int j = 1; j <= NUMREPETICIONES; j++) {
			v->GeneraVector(talla);
			tiempo1 += buscaEnArrayDeInt(v->generarKey(), v->getDatos(), talla, metodo1, tmp);
			v->GeneraVector(talla);
			tiempo2 += buscaEnArrayDeInt(v->generarKey(), v->getDatos(), talla, metodo2, tmp);
			v->vaciar();
		}
		tiempo1 /= NUMREPETICIONES;
		tiempo2 /= NUMREPETICIONES;

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
		if ((metodo1 == SECUENCIALIt && metodo2 == BINARIARc) || (metodo1 == BINARIARc && metodo2 == SECUENCIALIt)) {
			graf.generarGraficaCMP("SecuencialIt", "BinariaRc");
			system("start CmdCompararSecuencialItBinariaRc.gpl");
		}

		if ((metodo1 == SECUENCIALIt && metodo2 == TERNARIARc) || (metodo1 == TERNARIARc && metodo2 == SECUENCIALIt)) {
			graf.generarGraficaCMP("SecuencialIt", "TernariaRc");
			system("start CmdCompararSecuencialItTernariaRc.gpl");

		}

		if ((metodo1 == BINARIARc && metodo2 == TERNARIARc) || (metodo1 == TERNARIARc && metodo2 == BINARIARc)) {
			graf.generarGraficaCMP("BinariaRc", "TernariaRc");
			system("start CmdCompararBinariaRcTernariaRc.gpl");

		}
		cout << "La grafica fue generada\n\n";
	}
	else cout << "No se generara la grafica.\n\n";

	system("pause");


}
/*
 * Calcula el caso medio de un metodo de búsqueda,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: metodo de búsqueda a estudiar.
 */
void TestBusqueda::casoMedio(int metodo)
{
	int key;
	TestOrdenacion testo;
	ofstream f(nombreAlgoritmo[metodo] + ".dat");
	system("cls");
	cout << "\nCaso Medio de " << nombreAlgoritmo[metodo] << endl;
	cout << "Tiempos de ejecucion\n" << endl;
	cout << "\tTalla \tTiempo (ms)\n" << endl;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla) {
		ConjuntoInt *v = new ConjuntoInt(talla);
		int posicion = 0;
		double tiempo = 0;
		for (int j = 1; j <= NUMREPETICIONES; j++) {
			v->GeneraVector(talla);
			key = v->generarKey();
			testo.ordenarArrayDeInt(v->getDatos(), talla, INSERCION);
			tiempo += buscaEnArrayDeInt(key, v->getDatos(), talla, metodo, posicion);
			v->vaciar();
		}

		tiempo /= NUMREPETICIONES;
		cout << "\t" << talla << "\t" << tiempo << "\t" << /*key << "\t" << posicion <<*/ endl;
		f << talla << "\t" << tiempo << endl;
	}
	f.close();
	system("pause");
	char opc;
	cout << "¿Desea generar la grafica? S/N" << endl;
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		Graficas graf;
		if (metodo == SECUENCIALIt) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], N);
			system("start CmdSecuencialIt.gpl");
		}
		if (metodo == BINARIARc) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], LOGN);
			system("start CmdBinariaRc.gpl");
		}
		if (metodo == TERNARIARc) {
			graf.generarGraficaMEDIO(nombreAlgoritmo[metodo], LOGN);
			system("start CmdTernariaRc.gpl");
		}
	}
	}
}	
