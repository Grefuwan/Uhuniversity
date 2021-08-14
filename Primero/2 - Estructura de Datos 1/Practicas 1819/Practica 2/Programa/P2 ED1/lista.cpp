#include "lista.h"
#include <iostream>

lista::lista() {
	/*peluquero *elementosTMP = new peluquero[INCREMENTO];
	if (elementos != NULL)
	{
		Tama = INCREMENTO;
		n = 0;
	}
	else
	{
		Tama = n = -1;
	}*/
	elementos = NULL;
    if(elementos != NULL)
        delete [] elementos;
    elementos = new peluquero[INCREMENTO];
    if(elementos == NULL){
        Tama = n = -1;
    }
    else{
        Tama = INCREMENTO;
        n = 0;
    }
}

lista::~lista() {
	if (elementos != NULL)
		delete[] elementos;
	elementos = NULL;
	Tama = n = 0;
}

lista::lista(peluquero &e) {
    if(elementos != NULL)
        delete [] elementos;
    elementos = new peluquero[INCREMENTO];

    if(elementos == NULL){
        Tama = n = -1;
    }
    else{
        Tama = INCREMENTO;
        n = 1;
        elementos[0]=e;
    }
    insertar(1, e);
}

bool lista::esvacia() {
	return (n == 0);
}

int lista::longitud() {
	return n;
}

void lista::anadirIzq(peluquero e) {
	insertar(1, e);
}
void lista::anadirDch(peluquero e) {
	insertar(n + 1, e);
}
void lista::eliminarIzq() {
	eliminar(1);
}
void lista::eliminarDch() {
	eliminar(n);
}
peluquero lista::observarIzq() {
	return(observar(1));
}
peluquero lista::observarDch() {
	return (observar(n));
}
void lista::concatenar(lista l) {
	int lon = l.longitud();
	for (int i = 1; i <= lon; i++) {
		insertar(n + 1, l.observar(i));
	}
}


bool lista::pertenece(peluquero &e) {
	return (posicion(e) != -1);
}

void lista::insertar(int i, peluquero &e)
{
  if (n==Tama)
  {
    peluquero *elementosTMP=new peluquero[Tama+INCREMENTO];
    if (elementosTMP!=NULL)
    {
        for (int j=0;j<n; j++)
            copiarpeluquero(elementosTMP[j], elementos[j]);

        Tama+=INCREMENTO;
        delete [] elementos;
        elementos=elementosTMP;
    }
  }
  if (n<Tama)
  {
    for (int pos = n-1; pos > i-1; pos--)
    {

        copiarpeluquero(elementos[pos+1], elementos[pos]);
    }
    copiarpeluquero(elementos[i-1], e);
    n++;
  }
}
void lista::eliminar(int i) {
	while (i < n)
	{
		elementos[i - 1] = elementos[i]; // Desplazamiento
		i++;
	}
	n--;
	if (Tama - n >= INCREMENTO && Tama > INCREMENTO)
	{
		peluquero *elementosTMP = new peluquero [Tama - INCREMENTO];
		if (elementosTMP != NULL)
		{
			Tama -= INCREMENTO;
			for (int i = 0; i < Tama; i++)
				elementosTMP[i] = elementos[i];
			delete[] elementos;
			elementos = elementosTMP;
		}
	}
}

void lista::modificar(int i, peluquero &e) {
	elementos[i - 1] = e;
}

peluquero& lista::observar(int i) {
	return (elementos[i - 1]);
}

int lista::posicion(peluquero &e) {
	int i = 0;
	while (elementos[i].Codigo != e.Codigo && i < n)
		i++;
	return (i == n ? -1 : i + 1);
}


void copiarpeluquero(peluquero &destino,peluquero &origen){
    destino.Codigo = origen.Codigo;
    destino.TipoServicio = origen.TipoServicio;
    strcpy(destino.Nombre, origen.Nombre);
    strcpy(destino.Apellidos, origen.Apellidos);
    destino.Col.copiarcola(origen.Col);
}

