#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

struct dni{
	long tipo;
	int valor;
	char letra;
};

//Vamos a hacer que Proceso 1 lea la cola y Proceso 2 escriba en ella

int main() {
	
	key_t key;
	int idCola, sentOK, rcvOK, borraOK;
	struct dni primerDNI, copiaDNI;
	
	printf("PR1: Soy el Proceso 1\n");
	
	
//Crear la llave para la Cola----------------------
	key = ftok("./Makefile", 25);
	
	if (key == (key_t)-1){ //Casteo el -1 para que sea key_t
		printf("P1-ERROR: No se puede obtener la llave de la cola\n");
		exit(-1);
	}
	
		
//Abrir la cola------------------------------------
	idCola = msgget(key, 0600 | IPC_CREAT);
	
	if (idCola == -1){
		printf("P1-ERROR: No se puede abrir la cola\n");
		exit(-1);
	}
	
/*	
//Inicializar el struct----------------------------
	primerDNI.tipo = 1;
	primerDNI.valor = 48123456;
	primerDNI.letra = 'F';
	
	
//Enviar o recibir---------------------------------
	sentOK = msgsnd( idCola,
			 (struct msgbuf *)&primerDNI,
			 sizeof(primerDNI) - sizeof (long),
			 IPC_NOWAIT );
	
	if (sentOK == -1){
		printf("P1-ERROR: No se ha podido enviar el mensaje\n");
		exit(-1);
	}
	printf("Mensaje enviado correctamente\n");
	
	sleep(5);
*/	
//Autorecibir el mensaje enviado-------------------
	printf("PR1: Esperando DNI...\n");
	rcvOK = msgrcv(	idCola,
			(struct msgbuf *)&copiaDNI,
			sizeof(primerDNI) - sizeof (long),
			1,
			0 );
	if (rcvOK == -1){
		printf("P1-ERROR: No se ha podido recibir el mensaje\n");
		exit(-1);
	}
	printf("PR1: Mensaje recibido correctamente\n");
	
	
//Mostrar por pantalla el mensaje------------------
	printf("PR1: DNI leido correctamente: %d-%c\n", copiaDNI.valor, copiaDNI.letra);
	
	
//Eliminar la cola---------------------------------
	printf("PR1: Eliminando la cola...\n");
	borraOK = msgctl (idCola,
		  IPC_RMID,
		  NULL);
	if (borraOK == -1){
		printf("P1-ERROR: No borrado correctamente\n");
		exit(-1);
	}
	
	
	
	printf("\nPR1: Todo finaliza correctamente\n\n");
	return 0;
}
