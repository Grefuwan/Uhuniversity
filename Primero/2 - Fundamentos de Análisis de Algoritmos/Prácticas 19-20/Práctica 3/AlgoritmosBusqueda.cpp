/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de Búsqueda para buscar un elemento en un vector de enteros.
 * Define las implementaciones de los siguientes métodos de búsqueda
 * de búsqueda en vectores:
 *	- Secuencial
 *	- Binaria o dicotómica
 *  - Ternaria
 */
#include "AlgoritmosBusqueda.h"


 /*
  * Implementación de los métodos de la clase AlgoritmosBusqueda
  */
AlgoritmosBusqueda::AlgoritmosBusqueda() { }
AlgoritmosBusqueda:: ~AlgoritmosBusqueda() { }


/*
* Función busquedaSecuencialIt, implementa el método de búsqueda secuencial Iterativo
* param v: el array de enteros donde buscar
* param size: tamaño del array
* param key: clave o elemento a buscar
* return posición de la clave en el array
*/
int AlgoritmosBusqueda::busquedaSecuencialIt(int v[], int size, int key)
{
	int i = size;
	while (v[i] != key && i>=0)
	{
		i--;
	}
	if (v[i] == key)
		return i;
	else
		return -1;
}


/*
* Función búsquedaBinariaIt, implementa el método de búsqueda binaria Iterativo
* param v: el array de enteros donde buscar
* param size: tamaño del array
* param key: clave o elemento a buscar
* return posición de la clave en el array
*/
int AlgoritmosBusqueda::busquedaBinariaIt(int v[], int size, int key) {
	bool encontrado;
	int mitad, primero, ultimo;
	primero = 0;
	ultimo = size;
	encontrado = false;
	while (primero <= ultimo && encontrado == false) {
		mitad = ((primero + ultimo) / 2);
		if (key == v[mitad]) {
			encontrado = true;
		}
		else {
			if (key < v[mitad]) {
				ultimo = mitad - 1;
			}
			else {
				if (key > v[mitad]) {
					primero = mitad + 1;
				}
			}
		}
	}
	if (encontrado == true) {
		return mitad; // posición donde se encuentra el elemento en el array
	}
	else {
		return -1; // no se encuentra el elemento en el array
	}
}

/*
* Función busquedaInterpolaciónIt, implementa búsqueda por Interpolación iterativa
* param v: el array de enteros donde buscar
* param size: tamaño del array
* param key: clave o elemento a buscar
* return posición de la clave en el array
*/
int AlgoritmosBusqueda::busquedaInterpolacionIt(int v[], int size, int key) {
	int p, primero, ultimo;
	primero = 0;
	ultimo = size-1;
	while ((v[ultimo] >= key) && (v[primero] < key)) {
		p = primero + ((ultimo - primero) * (key - v[primero]) / (v[ultimo] - v[primero]));
		if (key > v[p]) {
			primero = p + 1;
		}
		else {
			if (key < v[p]) {
				ultimo = p - 1;
			}
			else {
				primero = p;
			}
		}
	}
	if (v[primero] == key) {
		return primero; // posición donde se encuentra el elemento en el array
	}
	else {
		return -1; // no se encuentra el elemento en el array
	}
}
