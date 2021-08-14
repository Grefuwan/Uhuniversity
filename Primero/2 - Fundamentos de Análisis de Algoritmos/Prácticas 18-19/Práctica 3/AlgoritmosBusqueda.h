/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de Búsqueda para buscar un elemento en un vector de enteros.
 * Define las implementaciones de los siguientes métodos de búsqueda
 * de búsqueda en vectores:
 *	- Secuencial
 *	- Binaria o dicotómica
 *  - Ternaria
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
   int busquedaSecuencialIt(int v[], int size,int key);

	/*
	 * Función busquedaBinariaRc, implementa el método de búsqueda binaria Recursivo
	 * param v: el array de enteros donde buscar
	 * param size: tamaño del array
	 * param key: clave o elemento a buscar
	 * return posición de la clave en el array
	 */
   int busquedaBinariaRc(int v[], int size,int key);
	 int BinariaRc(int A[], int left, int right, int key);

	/*
	 * Función busquedaTernariaRc, implementa el método de búsqueda ternaria recursiva
	 * param v: el array de enteros donde buscar
	 * param size: tamaño del array
	 * param key: clave o elemento a buscar
	 * return posición de la clave en el array
	 */
	 int busquedaTernariaRc(int v[], int size,int key);
	 int TernariaRc(int A[], int left, int right, int key);
};
#endif