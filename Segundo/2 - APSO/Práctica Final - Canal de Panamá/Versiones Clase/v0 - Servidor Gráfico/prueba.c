#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#include "comun.h"

int llega10=0;

void R12(){ //Llega si el servidor grafico no consigue arrancar
 printf("Imposible arrancar el servidor ....\n"); 
 exit(-1);
}

//Llega cada vez que el servidor grafico confirma una escritura o arranca 
void R10(){ llega10=1;}

/*********** FUNCION MAIN ********************/
int main()
{

 int pidsg, colagraf;
 struct tipo_elemento info;
 key_t clave;

 signal(10,R10);
 signal(12,R12);

 //Lanzamos el servidor grafico y esperamos confirmacion de arranque
 pidsg=fork();
 if(pidsg==0) {
	execl("servidor_ncurses","servidor_ncurses",NULL);
	perror("execl");
	exit(-1);
 }
 if(!llega10) pause();

 //accedemo a la cola de mensajes del servidor grafico
 clave=ftok("./fichcola.txt",18);
 if(clave == (key_t) -1) 
 {
   printf("Error al obtener clave para cola mensajes\n");
   exit(-1);
 }

 colagraf = msgget(clave, 0600 | IPC_CREAT);
 if (colagraf == -1)
 {
   printf("Error al obtener identificador para cola mensajes\n");
   perror("msgget");
   exit (-1);
 }
  
 //Visualizamos el barco
 info.tipo=1; //da igual cual poner, no usamos tipos
 info.pid=getpid();
 info.donde=VOESTEIN;
 info.que=PINTAR;
 info.cualidad=TIPOOESTE;

 llega10=0;
 msgsnd(colagraf,(struct msgbuf *) &info,sizeof(info)-sizeof(long),0);

 //Esperamos confirmación del servidor gráfico
 if(!llega10) pause();

 //Esperamos un poco 
 sleep(10);
 
 //Enviamos la señal de terminacion para el servidor grafico
 kill(pidsg,10);
 system("reset");

 return 0;
}







