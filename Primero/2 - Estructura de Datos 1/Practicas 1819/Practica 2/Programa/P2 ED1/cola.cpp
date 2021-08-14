#include "cola.h"

#include <stdlib.h>


cola::cola(){
  elementos=new cliente[INCREMENTO];
  if (elementos!=NULL)   {
    ne=fin=inicio=0;
    Tama=INCREMENTO;
  }
  else   {
    ne=fin=inicio=-1;
    Tama=-1;
  } }

cola::~cola() {
	if (elementos != NULL)
		delete [] elementos;
	elementos = NULL;
	ne = fin = inicio = -1;
	Tama = 0;
}

void cola::encolar(cliente e) {
	if (ne == Tama) {
		cliente *NuevaZona = new cliente[Tama + INCREMENTO];
		if (NuevaZona != NULL) {
			for (int i = 0; i < ne; i++) {
				NuevaZona[i] = elementos[inicio];
				inicio++;
				if (inicio == Tama) // inicio=(inicio+1)%Tama
					inicio = 0;
			}
			inicio = 0;
			fin = ne;
			Tama += INCREMENTO;
			delete elementos;
			elementos = NuevaZona;
		}
	};
	if (ne < Tama) {
		elementos[fin] = e;
		fin = (fin + 1) % Tama;
		ne++;
	}
}

void cola::desencolar() {
    if(ne == 0) return;
    inicio = (inicio+1)%Tama;
    ne--;

    if(Tama-ne == INCREMENTO && Tama > INCREMENTO){
        cliente *elementosTMP = new cliente[Tama-INCREMENTO];
        if(elementosTMP != NULL){
            for(int i = 0; i < ne; i++){
                elementosTMP[i] = elementos[inicio];
                inicio = (inicio+1)%Tama;
            }
            Tama -= INCREMENTO;
            inicio = 0;
            fin = ne;
            if(elementos != NULL)
                delete [] elementos;
            elementos = elementosTMP;
}
}
}

bool cola::esvacia() {
	return (ne == 0);
}

cliente cola::primero() {
	return elementos[inicio];
}

int cola::longitud() {
	return ne;
}


void cola::copiarcola(cola &c){
    //Vaciar
    if(elementos != NULL)
        delete [] elementos;
    elementos = new cliente[INCREMENTO];
    ne = fin = inicio = 0;
    Tama = INCREMENTO;

    //Pasar de un peluquero a otro
    cola cTMP;
    while(!c.esvacia()){
        encolar(c.primero());
        cTMP.encolar(c.primero());
        c.desencolar();
    }
    while(!cTMP.esvacia()){
        c.encolar(cTMP.primero());
        cTMP.desencolar();
    }
}

