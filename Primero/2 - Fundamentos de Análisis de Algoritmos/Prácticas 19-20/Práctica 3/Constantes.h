/*
 *Definiciones de las Constantes utilizadas en la pr�ctica 3.
 */
#ifndef _CONSTANTES
#define _CONSTANTES

 /* Constantes simb�licas para indicar el metodo de ordenacion*/
enum algoritmosOrdenacion { BURBUJA, INSERCION, SELECCION };

/* Constantes simb�licas para indicar el metodo de Busqueda*/
enum algoritmosBusquedaClave { SECUENCIALIt, BINARIAIt, INTERPOLACIONIt };

/* Constantes para indicar el Orden de complejidad*/
enum ordenes { LOGN, N, NLOGN, CUADRADO };

/* Constantes para indicar el Numero de repeticiones para el caso medio de cada m�todo de ordenaci�n-b�squeda */
static const int NUMREPETICIONES = 100;

/* Constantes para indicar la variacion de las tallas del vector */
enum valoresTallasO { tallaIniO = 100, tallaFinO = 1000, incTallaO = 100 };
/* Constantes para indicar la variacion de las tallas del vector */
enum valoresTallasB { tallaIniB = 100, tallaFinB = 1000, incTallaB = 100 };

#endif
