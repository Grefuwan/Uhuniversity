/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de B�squeda para buscar un elemento en un vector de enteros.
 * Define las implementaciones de los siguientes m�todos de b�squeda
 * de b�squeda en vectores:
 *	- Secuencial
 *	- Binaria o dicot�mica
 *  - Ternaria
 */
#include "AlgoritmosBusqueda.h"


 /*
  * Implementaci�n de los m�todos de la clase AlgoritmosBusqueda
  */
AlgoritmosBusqueda::AlgoritmosBusqueda() { }
AlgoritmosBusqueda:: ~AlgoritmosBusqueda() { }


/*
* Funci�n busquedaSecuencialIt, implementa el m�todo de b�squeda secuencial Iterativo
* param v: el array de enteros donde buscar
* param size: tama�o del array
* param key: clave o elemento a buscar
* return posici�n de la clave en el array
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
* Funci�n b�squedaBinariaIt, implementa el m�todo de b�squeda binaria Iterativo
* param v: el array de enteros donde buscar
* param size: tama�o del array
* param key: clave o elemento a buscar
* return posici�n de la clave en el array
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
		return mitad; // posici�n donde se encuentra el elemento en el array
	}
	else {
		return -1; // no se encuentra el elemento en el array
	}
}

/*
* Funci�n busquedaInterpolaci�nIt, implementa b�squeda por Interpolaci�n iterativa
* param v: el array de enteros donde buscar
* param size: tama�o del array
* param key: clave o elemento a buscar
* return posici�n de la clave en el array
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
		return primero; // posici�n donde se encuentra el elemento en el array
	}
	else {
		return -1; // no se encuentra el elemento en el array
	}
}
