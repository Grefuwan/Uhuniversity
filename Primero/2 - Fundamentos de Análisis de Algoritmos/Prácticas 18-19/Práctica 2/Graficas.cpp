/* 
 * Clase Graficas, contiene m�todos crear los ficheros de comandos para dibujar 
 * la gr�fica que corresponda. 
 */
#include "Graficas.h"
#include "Constantes.h"
#include <fstream>
#include <iostream>
using namespace std;

/*
 * M�todo generarGraficaMEDIO, genera el fichero de comandos para GNUPlot 
 * y dibuja la gr�fica del caso medio de un m�todo de
 * ordenaci�n y su ajuste a la funci�n correspondiente.  
 * param nombre_metodo: metodo de ordenacion.
 * param orden: Orden del metodo de ordenacion.
 */
void Graficas::generarGraficaMEDIO(string nombre_metodo,int orden)
{
	ofstream file("grafica.gpl");

	file << "set title \"Tiempo de ordenacion por " << nombre_metodo << "\"\n"
		<< "set key top left vertical inside\n"
		<< "set grid\n"
		<< "set xlabel \"Talla (n)\""
		<< "set ylabel \"Tiempo (ms)\" "
		<< "\n"
		<< "N(x) = ";
	
	switch (orden) {
	
	case CUADRADO: file << "a*x*x + b*x + c\n";
		break;
	
	case NlogN: file << "a*log(a)\n";
		break;
	}

	file << "fit N(x) \"t" << nombre_metodo << ".dat\" using 1:2 via ";
	switch (orden) {
	
	case CUADRADO: file << "a,b,c\n";
		break;
	
	case NlogN: file << "a\n";
		break;
	}

	file << "plot N(x) title \"Aproximaci�n\", \"t" << nombre_metodo << ".dat\" using 1:2 title \"Resultado emp�rico\"\n"
		<< "\n"
		<< "set terminal pdf\n"
		<< "set output \"busqueda" << nombre_metodo << ".pdf\"\n"
		<< "replot\n"
		<< "#pause -1 \"Pulsa Enter para continuar...\"\n"
		<< "unset output";

	file.close();
}	

/*
 * M�todo generarGraficaCMP, genera el fichero de comandos para GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer m�todo de ordenaci�n 
 * param nombre2: es el nombre del fichero de datos del segundo m�todo de ordenaci�n 
 */
void  Graficas::generarGraficaCMP(string nombre1,string nombre2)
{
	ofstream file("CmdComparar.gpl");

	file << "set title \"Comparacion tiempos " << nombre1 << " y " << nombre2 << "\"\n"
		<< "set key top left vertical inside\n"
		<< "set grid\n"
		<< "set xlabel \"Talla (n)\"\n"
		<< "set ylabel \"Tiempo (ms)\"\n\n"
		<< "plot \"" << nombre1 << ".dat\" using 1:2 with lines title \"" << nombre1 << "\", \"" << nombre2 << ".dat\" using 1:2 with lines title \"" << nombre2 << "\"\n"
		<< "set terminal pdf\n"
		<< "replot\n"
		<< "set output \"" << nombre1 << nombre2 << ".pdf\" \n"
		<< "#pause -1 \"Pulsa Enter para continuar...\"\n"
		<< "unset output";
	file.close();

}