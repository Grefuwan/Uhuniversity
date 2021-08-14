#include <iostream>
using namespace std;
#include <ctime>  //para time
#include <cstdlib> // for srand, rand
#include "ConjuntoInt.h"

ConjuntoInt::ConjuntoInt (int max)
{
 tamano= max;
 datos= new int[max];
}
ConjuntoInt::~ConjuntoInt ()
{
 delete[] datos;
}
void ConjuntoInt::vaciar ()
{
 tamano= 0;
}
int* ConjuntoInt::getDatos()
{
	int* v=datos;
	for (int i= 0; i <tamano;i++){
		v[i]=datos[i];}
	return v;
}

void ConjuntoInt::GeneraVector (int tam)
{
	tamano=tam;
	srand( (unsigned)time( NULL ) ); //srand(time(0));
	for (int i= 0; i<tamano; i++){
		datos[i] = rand()%1000; //genera un n�mero aleatorio entre 1 y 999
 }
}
int ConjuntoInt::generaKey()
{
	return datos[rand()%tamano]; // devuelve el valor del  array en una posici�n aleatoria entre 1 y el tama�o del array
}
void ConjuntoInt::escribe()
{
	for (int i= 0; i<tamano; i++)
		cout << datos[i] << (i<tamano-1? ", ": "\n");
}
int ConjuntoInt::getPrimero() 
{
	return datos[0];
}
int ConjuntoInt::busquedaSecuencial (int valor)
{
	int i=0;
	while (datos[i]!= valor && i<tamano)
	{
		i=i+1;
	}
	if (datos[i]==valor)
		return i;	 // devuelve la posici�n i donde se encuentra el valor en el array
	else
		return -1;  // devuelve -1, no se encuentra el valor en el array
}