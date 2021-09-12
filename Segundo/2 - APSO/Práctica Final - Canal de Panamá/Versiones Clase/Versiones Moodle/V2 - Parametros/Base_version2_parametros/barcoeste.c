#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>

#include "comun.h"
#include "comunbarcos.h"

int main()
{

 
 int colagrafica;
 struct Parametros param;

 srand(getpid());
 signal(10,R10); // me preparo para la senyal 10
 signal(12,R12); // me preparo para la senyal 12

 // Creamos y abrimos la cola de mensajes
 colagrafica=crea_cola(ftok ("./fichcola.txt", 18));
 

 visualiza(colagrafica, VESTEIN, PINTAR, TIPOESTE); 
 sleep(rand()%3+1);
 visualiza(colagrafica, VESTEIN, BORRAR, TIPOESTE); 
 visualiza(colagrafica, VOESTEOUT, PINTAR, TIPOESTE); 
 sleep(rand()%3+1);
 visualiza(colagrafica, VHORNOS, PINTAR, TIPOESTE); 

}


