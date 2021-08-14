/*
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los m�todos de b�squeda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un m�todo de b�squeda,
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente con ajuste al Orden de complejidad.
 * 3. Comparar el coste temporal de dos m�todos de b�squeda
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente.
 */
#ifndef _TEST_BUSQUEDA
#define _TEST_BUSQUEDA

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

class TestBusqueda
{
	vector<string> nombreAlgoritmo;
public:

	TestBusqueda();
	~TestBusqueda();

	/*
	 * Busca un elemento en un array de enteros seg�n el m�todo indicado
	 * param key: clave o elemento a buscar
   * param v: el array de enteros donde buscar
	 * param size: tama�o del array de enteros
   * param metodo: Metodo de b�squeda a utilizar
   * return Tiempo empleado en la b�squeda (en milisegundos)
   */
	static double buscaEnArrayDeInt(int key, int v[], int size, int metodo, int& posicion);

	/*
	 * Comprueba que los metodos de b�squeda funcionan correctamente
   */
	void comprobarMetodosBusqueda();

	/*
	   * Calcula el caso medio de un metodo de b�squeda,
	   * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
	 * param metodo: metodo de b�squeda a estudiar.
	 */
	void casoMedio(int metodo);

	/*
	   * Compara dos metodos de busqueda.
	   * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
	 * param metodo1: Primer metodo de b�squeda a comparar
	 * param metodo2: Segundo metodo de b�squeda a comparar
	 */
	void comparar(int metodo1, int metodo2);

	/*
	 * Compara todos los metodos de busqueda.
	 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
	 */
	void compararTodos();

};

#endif
