/*
 * Clase AlgoritmosOrdenacion que implementa los Algoritmos de Ordenación para ordenar un vector de enteros en orden descendente.
 * Define las implementaciones de los siguientes métodos de Ordenación en vectores: 
 *	- Burbuja
 *	- Inserción
 *	- Selección.
 */

#include "AlgoritmosOrdenacion.h"

AlgoritmosOrdenacion :: AlgoritmosOrdenacion() {}
AlgoritmosOrdenacion :: ~AlgoritmosOrdenacion(){}

/*
 * Función ordenaBurbuja, implementa el método de ordenación Burbuja
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 */

void AlgoritmosOrdenacion::ordenaBurbuja(int v[], int size)
{
	int auxiliar;
	for (int i=size-2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (v[j] > v[j + 1]){
				auxiliar = v[j];
				v[j] = v[j+1];
				v[j + 1] = auxiliar;
			}
		}
}

}


/*
 * Función ordenaInsercion, implementa el método de ordenación por Inserción
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 */

void AlgoritmosOrdenacion :: ordenaInsercion(int v[], int size)
{
	int x, j;
	for (int i = 1; i < size; i++) {
		x = v[i];
		j = i - 1;
		while (j >= 0 && x < v[j]) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = x;
	}
}

/*
 * Función ordenaSeleccion, implementa el método de ordenación por Selección
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 */
void AlgoritmosOrdenacion :: ordenaSeleccion(int v[], int size)
{
	int posminimo, auxiliar;
	for (int i = 0; i <= size-2; i++) {
		posminimo = i;
		for (int j = i + 1; j < size; j++) {
			if (v[j] < v[posminimo]) {
				posminimo = j;
			}
		}

		auxiliar = v[posminimo];
		v[posminimo] = v[i];
		v[i] = auxiliar;
	}
}

void AlgoritmosOrdenacion::ordenaShell(int v[], int size) {
	int i, j, inc, temp;

	for (inc = 1; inc < size; inc = inc * 3 + 1);

	while (inc > 0)
	{
		for (i = inc; i < size; i++)
		{
			j = i;
			temp = v[i];
			while ((j >= inc) && (v[j - inc] > temp))
			{
				v[j] = v[j - inc];
				j = j - inc;
			}

			v[j] = temp;
		}

		inc /= 2;
	}
}


void AlgoritmosOrdenacion::ordenaQuicksort(int v[], int izq, int der) {
	int piv = v[izq];
	int i = izq;
	int j = der;
	int aux;

	while (i < j) {
		while (v[i] <= piv && i < j) i++;
		while (v[j] > piv) j--;
		if (i < j) {
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}

	v[izq] = v[j];
	v[j] = piv;
	if (izq < j - 1)
		ordenaQuicksort(v, izq, j - 1);
	if (j + 1 < der)
		ordenaQuicksort(v, j + 1, der);

}
