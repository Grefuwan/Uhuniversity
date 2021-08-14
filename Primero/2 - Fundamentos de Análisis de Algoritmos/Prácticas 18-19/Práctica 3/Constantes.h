/* 
 *Definiciones de las Constantes utilizadas en la práctica 3. 
 */
#ifndef _CONSTANTES
#define _CONSTANTES

/* Constantes simbólicas para indicar el metodo de ordenacion*/
enum algoritmosOrdenacion { BURBUJA, INSERCION, SELECCION};

/* Constantes simbólicas para indicar el metodo de Busqueda*/
enum algoritmosBusquedaClave{SECUENCIALIt, BINARIARc, TERNARIARc};

/* Constantes para indicar el Orden de complejidad*/
enum ordenes {LOGN,N,NLOGN,CUADRADO};

/* Constantes para indicar el Numero de repeticiones para el caso medio de cada método de ordenación-búsqueda */
static const int NUMREPETICIONES=100;

/* Constantes para indicar la variacion de las tallas del vector */
enum valoresTallas { tallaIni = 1000,tallaFin = 10000,incTalla = 1000};

#endif