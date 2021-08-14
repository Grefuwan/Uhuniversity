/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de Búsqueda para buscar un elemento en un vector de enteros.
 * Define las implementaciones de los siguientes métodos de búsqueda
 * de búsqueda en vectores:
 *	- Secuencial
 *	- Binaria o dicotómica
 *  - Interpolacion
 */
#ifndef _BUSQUEDA
#define _BUSQUEDA

class AlgoritmosBusqueda
{
public:
	AlgoritmosBusqueda();
	~AlgoritmosBusqueda();

	/*
	   * Función busquedaSecuencialIt, implementa el método de búsqueda secuencial Iterativo
	   * param v: el array de enteros donde buscar
	   * param size: tamaño del array
	   * param key: clave o elemento a buscar
	   * return posición de la clave en el array
	   */
	int busquedaSecuencialIt(int v[], int size, int key);

	/*
	   * Función búsquedaBinariaIt, implementa el método de búsqueda binaria Iterativo
	   * param v: el array de enteros donde buscar
	   * param size: tamaño del array
	   * param key: clave o elemento a buscar
	   * return posición de la clave en el array
	   */
	int busquedaBinariaIt(int v[], int size, int key);

	/*
	   * Función busquedaInterpolaciónIt, implementa búsqueda por Interpolación iterativa
	   * param v: el array de enteros donde buscar
	   * param size: tamaño del array
	   * param key: clave o elemento a buscar
	   * return posición de la clave en el array
	   */
	int busquedaInterpolacionIt(int v[], int size, int key);
};
#endif
