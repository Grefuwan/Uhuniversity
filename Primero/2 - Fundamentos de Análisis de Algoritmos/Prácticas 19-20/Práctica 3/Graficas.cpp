/*
 * Clase Graficas, contiene métodos crear los ficheros de comandos para dibujar
 * la gráfica que corresponda.
 */
#include "Graficas.h"
#include "Constantes.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

/*
 * Método generarGraficaMEDIO, genera el fichero de comandos para GNUPlot
 * y dibuja la gráfica del caso medio de un método de
 * ordenación y su ajuste a la función correspondiente.
 * param nombre_metodo: metodo de ordenacion.
 * param orden: Orden del metodo de ordenacion.
 */
void Graficas::generarGraficaMEDIO(string nombre_metodo, int orden)
{
	/* Generar grafica */
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S':
	{
		ofstream f("CmdMedio.gpl");

		f << "\t\t#ESTE ES UN SCRIPT DE GNUPLOT PARA ESTUDIO DE 1 METODO" << endl;
		f << "set title \"" << nombre_metodo << "\"" << endl;
		f << "set key top left vertical inside" << endl;
		f << "set grid" << endl;
		f << "set xlabel \"Talla (n)\"" << endl;
		f << "set ylabel \"Tiempo (ms)\"" << endl;
		switch (orden) {
		case CUADRADO:
		{
			f << "Cuadrado(x) = a*x*x + b*x + c\n" << "fit Cuadrado(x) \"";
		}
		break;
		case NLOGN:
		{
			f << "nLogn(x) = a*x*log(x) + b \n" << "fit nLogn(x) \"";
		}
		break;
		case LOGN:
		{
			f << "Logn(x) = a*log(x) + b \n" << "fit Logn(x) \"";
		}
		break;
		case N:
		{
			f << "N(x) = a*x + b\n" << "fit N(x) \"";
		}
		break;
		}
		f << nombre_metodo << ".dat\" using 1:2 via ";
		switch (orden)
		{
		case CUADRADO:
		{
			f << "a,b,c\n";
		}break;
		case NLOGN:
		case LOGN:
		case N:
		{
			f << "a,b\n";
		}break;

		}
		f << "plot \"" << nombre_metodo << ".dat\" using 1:2 title \"" << nombre_metodo << "\", ";
		if (orden == CUADRADO)
			f << "Cuadrado(x)" << endl;
		else if (orden == NLOGN)
			f << "nLogn(x)" << endl;
		else if (orden == LOGN)
			f << "Logn(x)" << endl;
		else
			f << "N(x)" << endl;
		f << "set terminal pdf" << endl;
		f << "set output \"" << nombre_metodo << ".pdf\"" << endl;
		f << "replot" << endl;
		f << "unset output" << endl;
		f << "pause -1 \"Pulsa Enter para continuar...\"" << endl;
		f.close(); f.clear();
		system("start CmdMedio.gpl");
		system("cls");
		cout << endl << "Grafica guardada en el fichero " << nombre_metodo << ".pdf" << endl;
		cout << endl << "Fichero de comandos guardado en CmdMedio.gpl" << endl;
	}
	break;
	default:
	{
		cout << "Grafica no guardada en fichero " << endl;
	}
	break;
	}
	cout << endl;
}

/*
 * Método generarGraficaCMP, genera el fichero de comandos para GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer método de ordenación
 * param nombre2: es el nombre del fichero de datos del segundo método de ordenación
 */
void  Graficas::generarGraficaCMP(string nombre1, string nombre2)
{
	/* Generar grafica */
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S':
	{
		ofstream f("CmdComparar.gpl");
		f << "\t\t#ESTE ES UN SCRIPT DE GNUPLOT PARA COMPARACION DE 2 METODOS" << endl;
		f << "set title \"Comparacion de tiempos" << nombre1 << " y " << nombre2 << "\"" << endl;
		f << "set key top left vertical inside" << endl;
		f << "set grid" << endl;
		f << "set xlabel \"Talla (n)\"" << endl;
		f << "set ylabel \"Tiempo (ms)\"" << endl;
		f << "plot \"" << nombre1 << ".dat\" using 1:2 with lines title \"" << nombre1 << "\", \"" << nombre2 << ".dat\" using 1:2 with lines title \"" << nombre2 << "\"" << endl;
		f << "set terminal pdf" << endl;
		f << "set output \"" << nombre1 << nombre2 << ".pdf\"" << endl;
		f << "replot" << endl;
		f << "unset output" << endl;
		f << "pause -1 \"Pulsa Enter para continuar...\"" << endl;
		f.close(); f.clear();
		system("start CmdComparar.gpl");
		system("cls");
		cout << endl << "Grafica guardada en el fichero " << nombre1 << nombre2 << ".pdf" << endl;
		cout << endl << "Fichero de comandos guardado en CmdComparar.gpl" << endl;
	}
	break;
	default:
	{
		cout << "Grafica no guardada en fichero " << endl;
	}
	break;
	}
	cout << endl;
}

/*
 * Método generarGraficaCMP, genera el fichero de comandos para GNUPlot.
 */
void  Graficas::generarGraficaCMP_TODOS(vector<string> nombres)
{
	system("pause");
	ofstream file("CmdGraficaTodos.gpl");

	file << "set title \"Comparativa de todos los algoritmos\"\n"
		<< "set key top left vertical inside\n"
		<< "set grid\n"
		<< "set xlabel \"Talla (n)\"\n"
		<< "set ylabel \"Tiempo(ms)\"\n"
		<< "\n";

	file << "plot ";
	for (int algoritmo = 0; algoritmo < nombres.size(); algoritmo++)
		file << "\"tTodos.dat\" using 1:" << (algoritmo + 2) << " with lines title \"" << nombres[algoritmo] << "\"" << (algoritmo == nombres.size() - 1 ? "\n" : ", ");
	file << "\n"
		<< "set terminal pdf\n"
		<< "set output \"ComparativaTodos.pdf\"\n"
		<< "replot\n"
		<< "#pause -1 \"Pulsa Enter para continuar...\"\n"
		<< "unset output";
	system("start CmdGraficaTodos.gpl");
	system("cls");

	file.close();
}