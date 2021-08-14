/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de B�squeda para buscar un elemento en un vector de enteros.
 * Define las implementaciones de los siguientes m�todos de b�squeda
 * de b�squeda en vectores:
 *	- Secuencial
 *	- Binaria o dicot�mica
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
	   * Funci�n busquedaSecuencialIt, implementa el m�todo de b�squeda secuencial Iterativo
	   * param v: el array de enteros donde buscar
	   * param size: tama�o del array
	   * param key: clave o elemento a buscar
	   * return posici�n de la clave en el array
	   */
	int busquedaSecuencialIt(int v[], int size, int key);

	/*
	   * Funci�n b�squedaBinariaIt, implementa el m�todo de b�squeda binaria Iterativo
	   * param v: el array de enteros donde buscar
	   * param size: tama�o del array
	   * param key: clave o elemento a buscar
	   * return posici�n de la clave en el array
	   */
	int busquedaBinariaIt(int v[], int size, int key);

	/*
	   * Funci�n busquedaInterpolaci�nIt, implementa b�squeda por Interpolaci�n iterativa
	   * param v: el array de enteros donde buscar
	   * param size: tama�o del array
	   * param key: clave o elemento a buscar
	   * return posici�n de la clave en el array
	   */
	int busquedaInterpolacionIt(int v[], int size, int key);
};
#endif
