#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "comun.h"
#include "comunbarcos.h"

int colagrafica;
int fesclusao, fesclusae, flago;

void R14(){
 visualiza(colagrafica, VOESTEIN, BORRAR, TIPOOESTE); 
 visualiza(colagrafica, VHORNOS, PINTAR, TIPOOESTE); 
 close(fesclusae);
 close(fesclusao);
 close(flago);
 exit(0);
}

int main()
{

 
 int lapipe;
 struct Parametros param;
 int testigo=1;

 srand(getpid());
 signal(10,R10); // me preparo para la senyal 10
 signal(12,R12); // me preparo para la senyal 12
 signal(14,R14);


 // Creamos y abrimos la cola de mensajes
 colagrafica=crea_cola(ftok ("./fichcola.txt", 18));
 // Abrimos las fifos
 fesclusae=open("esclusae",O_RDWR);
 fesclusao=open("esclusao",O_RDWR);
 flago=open("lago",O_RDWR);
 // Leemos de la pipe los parámetros
 read(2,&param,sizeof(param));
 //recuperamos la salida de errores 
 lapipe=dup(2);
 close(2);
 open("/dev/tty",O_RDWR);
 
 visualiza(colagrafica, VOESTEIN, PINTAR, TIPOOESTE); 
 //programo la alarma
 alarm(rand()%(param.mevoymax-param.mevoymin+1)+param.mevoymin);
 // reservo sitio en el lago
 read(flago,&testigo,sizeof(testigo));
 //desactivo la alarma
 alarm(0);
 // reservo la esclusa este
 read(fesclusao,&testigo,sizeof(testigo));
 //entro en la esclusa
 visualiza(colagrafica, VOESTEIN, BORRAR, TIPOOESTE); 
 visualiza(colagrafica, VESCLUSAOESTE, PINTAR, TIPOOESTE); 
 sleep(param.tesclusa);
//salgo y voy al lago
 visualiza(colagrafica, VESCLUSAOESTE, BORRAR, TIPOOESTE); 
 visualiza(colagrafica, VLAGOO, PINTAR, TIPOOESTE); 
 write(fesclusao,&testigo,sizeof(testigo));
 sleep((rand()%(param.lagomax-param.lagomin+1))+param.lagomin);
 // reservo la esclusa oeste
 read(fesclusae,&testigo,sizeof(testigo));
 // salgo del lago y voy a la esclusa
 visualiza(colagrafica, VLAGOO, BORRAR, TIPOOESTE); 
 visualiza(colagrafica, VESCLUSAESTE, PINTAR, TIPOOESTE);
 write(flago,&testigo,sizeof(testigo));
 sleep(param.tesclusa);
 //salgo de la esclusa y me marcho
 visualiza(colagrafica, VESCLUSAESTE, BORRAR, TIPOOESTE);
 visualiza(colagrafica, VESTEOUT, PINTAR, TIPOOESTE); 
 write(fesclusae,&testigo,sizeof(testigo));

 close(fesclusae);
 close(fesclusao);
 close(flago);
}


