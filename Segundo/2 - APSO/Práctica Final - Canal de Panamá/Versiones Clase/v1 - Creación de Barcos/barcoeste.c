#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#include "comun.h"


//Variables
int llega10 = 0;

//Prototipos de funciones
void R10();	//Controla la llegada de la señal 10
void R12();	//Controla la llegada de la señal 12 y termina ejecución

int main(){

	key_t clave;
	int colagraf;
	struct tipo_elemento info;
	
//Prepararse para recibir señales 10 y 12
	signal(10, R10);
	signal(12, R12);
	
	
//Crear y abrir cola de mensajes para servidor ncurses (grafico)
	clave = ftok("./fichcola.txt" , 18);
	if(clave == (key_t) - 1) {
		printf("Error al obtener clave para cola mensajes\n");
		exit(-1);
	}

	colagraf = msgget(clave, 0600 | IPC_CREAT);
	if (colagraf == -1) {
		printf("Error al obtener identificador para cola mensajes\n");
		perror("msgget");
		exit (-1);
	}
	
	
//Pintar en el inicio (Oceano Este)
	info.tipo	= 1; //Da igual, no usamos tipos
	info.pid	= getpid();
	info.donde	= VESTEIN;
	info.que	= PINTAR;
	info.cualidad	= TIPOESTE;

	llega10 = 0;
	msgsnd(	colagraf,
		(struct msgbuf *) &info,sizeof(info)-sizeof(long),
		0);

	//Esperamos confirmación del servidor gráfico
	if(!llega10)
		pause();
	
	
//Esperar
	sleep(7);
	
	
//Borrar del inicio (Oceano Este)
	info.tipo	= 1; //Da igual, no usamos tipos
	info.pid	= getpid();
	info.donde	= VESTEIN;
	info.que	= BORRAR;
	info.cualidad	= TIPOESTE;

	msgsnd(	colagraf,
		(struct msgbuf *) &info,sizeof(info)-sizeof(long),
		0);

	//No tenemos que esperar respuesta en el borrado
	//if(!llega10)
		//pause();


	
//Pintar en el final (Oceano Oeste)
	info.tipo	= 1; //Da igual, no usamos tipos
	info.pid	= getpid();
	info.donde	= VOESTEOUT;
	info.que	= PINTAR;
	info.cualidad	= TIPOESTE;

	llega10 = 0;
	msgsnd(	colagraf,
		(struct msgbuf *) &info,sizeof(info)-sizeof(long),
		0);

	//Esperamos confirmación del servidor gráfico
	if(!llega10)
		pause();
	

//Fin del barco
	exit(0);
}


//Controla la llegada de la señal 10
void R10() {
	llega10 = 1;
}

//Controla la llegada de la señal 12 y termina ejecución
void R12() {
	perror("BARCO ESTE NO PINTADO");
	exit(-1);
}