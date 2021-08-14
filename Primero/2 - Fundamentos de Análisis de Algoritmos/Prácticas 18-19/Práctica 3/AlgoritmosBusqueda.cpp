
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
int AlgoritmosBusqueda::busquedaSecuencialIt(int v[], int size,int key)
{
	int i = 1;
	while (v[i] != key && i <= size) {
		i = i + 1;
	}
	if (v[i] == key)
		return i;
	else
		return -1;
}

/*
	 * Función busquedaBinariaRc, implementa el método de búsqueda binaria Recursivo
	 * param v: el array de enteros donde buscar
	 * param size: tamaño del array
	 * param key: clave o elemento a buscar
	 * return posición de la clave en el array
	 */
   
int AlgoritmosBusqueda::busquedaBinariaRc(int v[], int size, int key)
{
	return BinariaRc(v, 0, size - 1, key);
}

int AlgoritmosBusqueda::BinariaRc(int v[], int left, int right, int key) //left primero, right ultimo
{
	if (left >= right) {
		if (v[right] = key)
		return right;
		else
			return -1;
	}
	int mitad = ((right + left) / 2);
	if (key == v[mitad]) {
		return mitad;
	}
	else {
		if (key < v[mitad]) {
			return BinariaRc(v, left, mitad - 1, key);
		}
		else {
			if (key > v[mitad]) {
				return BinariaRc(v, mitad + 1, right , key);
			}
		}
	}
}
	
/*
	 * Función busquedaTernariaRc, implementa el método de búsqueda ternaria recursiva
	 * param v: el array de enteros donde buscar
	 * param size: tamaño del array
	 * param key: clave o elemento a buscar
	 * return posición de la clave en el array
	 */
	 
int AlgoritmosBusqueda::busquedaTernariaRc(int v[], int size,int key)
{
	return TernariaRc(v, 0, size - 1, key);

}

int AlgoritmosBusqueda::TernariaRc(int v[], int left, int right, int key) //left primero, right ultimo
{
	//if (left >= right) {
	//	if (v[right] == key)
	//		return right;
	//	else
	//		return -1;
	//}
	if (left > right)
		return -1;

	if (left == right && v[right] == key)
		return right;

	else {
		int tercio = (right - left + 1) / 3;

		if (key == v[left + tercio]) {
			return left + tercio; //cierto
		}
		else {
			if (key == v[right - tercio]) {
				return right - tercio;
			}
			else {
				if (key < v[left + tercio]) {
					return TernariaRc(v, left, left + tercio - 1, key);
				}
				else {
					if (key < v[right - tercio]) {
						return TernariaRc(v, left + tercio + 1, right - tercio , key);
					}
					else {
						return TernariaRc(v, right - tercio + 1, right, key);
					}
				}
			}
		}
	}
}
