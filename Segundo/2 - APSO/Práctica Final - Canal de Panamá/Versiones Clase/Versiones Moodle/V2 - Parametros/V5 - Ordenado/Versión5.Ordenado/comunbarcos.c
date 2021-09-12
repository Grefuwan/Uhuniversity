#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/msg.h>

#include "comun.h"
#include "comunbarcos.h"

int llega10=0;
int llega14=0;
int llega16=0;

/*********** FUNCION: visualiza ********************************************************/ 
/*********** Pinta o borra en el servidor gráfico **************************************/

void visualiza(int cola, int donde, int que, int como)
{
 struct tipo_elemento peticion;

 peticion.tipo=1; //da igual cual poner, no usamos tipos
 peticion.pid=getpid();
 peticion.donde=donde;
 peticion.que=que;
 peticion.cualidad=como;
 
 msgsnd(cola, (struct tipo_elemento *) &peticion,sizeof(struct tipo_elemento)-sizeof(long),0);
      
 if(que==PINTAR) 
 {
	if(!llega10) pause(); //espero conformidad de que me han pintado, sino me mataran
	llega10=0;
 }

}

/*********** FUNCION: crea_cola ********************************************************/ 
/*********** Obtiene acceso a la cola de mensajes con el id que se pasa ****************/
int crea_cola(key_t clave)
{
 int identificador;
 if(clave == (key_t) -1) 
 {
   printf("Error al obtener clave para cola mensajes\n");
   exit(-1);
 }

 identificador = msgget(clave, 0600 | IPC_CREAT);
 if (identificador == -1)
 {
   printf("Error al obtener identificador para cola mensajes\n");
   perror("msgget");
   exit (-1);
 }
 
 return identificador;
}

/******************/

void R10()
{
 llega10=1;
}

/********************/

void R12() // indica que no se puede pintar y muere
{
 printf("CLIENTE %d: No puedo pintarme, porque no hay sitio en la ventana\n",getpid());
 exit(-1);
}

/******************/

void R14()
{
 llega14=1;
}

void R16()
{
 llega16=1;
}
