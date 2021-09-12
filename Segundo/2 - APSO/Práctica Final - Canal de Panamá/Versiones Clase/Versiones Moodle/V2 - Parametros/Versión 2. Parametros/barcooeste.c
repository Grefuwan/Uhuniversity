#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

#include "comun.h"
#include "comunbarcos.h"

int main()
{

 
 int colagrafica, lapipe;
 struct Parametros param;
 
 srand(getpid());
 signal(10,R10); // me preparo para la senyal 10
 signal(12,R12); // me preparo para la senyal 12

 // Creamos y abrimos la cola de mensajes
 colagrafica=crea_cola(ftok ("./fichcola.txt", 18));
 // Leemos de la pipe los parametros
 read(2,&param,sizeof(param));
  //recuperamos la salida de errores 
 lapipe=dup(2);
 close(2);
 open("/dev/tty",O_RDWR);

 visualiza(colagrafica, VOESTEIN, PINTAR, TIPOOESTE); 
 sleep((rand()%(param.lagomax-param.lagomin+1)+param.lagomin));
 visualiza(colagrafica, VOESTEIN, BORRAR, TIPOOESTE); 
 visualiza(colagrafica, VESTEOUT, PINTAR, TIPOOESTE); 
 sleep((rand()%(param.lagomax-param.lagomin+1)+param.lagomin));
 visualiza(colagrafica, VHORNOS, PINTAR, TIPOOESTE); 

}



