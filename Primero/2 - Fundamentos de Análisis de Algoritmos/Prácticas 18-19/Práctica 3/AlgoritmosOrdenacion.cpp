﻿/*
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