/*
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los métodos de búsqueda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente con ajuste al Orden de complejidad.
 * 3. Comparar el coste temporal de dos métodos de búsqueda
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente.
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
	 * Busca un elemento en un array de enteros según el método indicado
	 * param key: clave o elemento a buscar
   * param v: el array de enteros donde buscar
	 * param size: tamaño del array de enteros
   * param metodo: Metodo de búsqueda a utilizar
   * return Tiempo empleado en la búsqueda (en milisegundos)
   */
	static double buscaEnArrayDeInt(int key, int v[], int size, int metodo, int& posicion);

	/*
	 * Comprueba que los metodos de búsqueda funcionan correctamente
   */
	void comprobarMetodosBusqueda();

	/*
	   * Calcula el caso medio de un metodo de búsqueda,
	   * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
	 * param metodo: metodo de búsqueda a estudiar.
	 */
	void casoMedio(int metodo);

	/*
	   * Compara dos metodos de busqueda.
	   * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
	 * param metodo1: Primer metodo de búsqueda a comparar
	 * param metodo2: Segundo metodo de búsqueda a comparar
	 */
	void comparar(int metodo1, int metodo2);

	/*
	 * Compara todos los metodos de busqueda.
	 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
	 */
	void compararTodos();

};

#endif
