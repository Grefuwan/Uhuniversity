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
	
	printf("PR2: Soy el Proceso 2\n");
	
	
//Crear la llave para la Cola----------------------
	key = ftok("./Makefile", 25);
	
	if (key == (key_t)-1){ //Casteo el -1 para que sea key_t
		printf("P2-ERROR: No se puede obtener la llave de la cola\n");
		exit(-1);
	}
	
		
//Abrir la cola------------------------------------
	idCola = msgget(key, 0600 | IPC_CREAT);
	
	if (idCola == -1){
		printf("P2-ERROR: No se puede abrir la cola\n");
		exit(-1);
	}
	
	
//Inicializar el struct----------------------------
	primerDNI.tipo = 1;
	primerDNI.valor = 98765432;
	primerDNI.letra = 'Q';
	
	
//Enviar o recibir---------------------------------
	sentOK = msgsnd( idCola,
			 (struct msgbuf *)&primerDNI,
			 sizeof(primerDNI) - sizeof (long),
			 IPC_NOWAIT );
	
	if (sentOK == -1){
		printf("P2-ERROR: No se ha podido enviar el mensaje\n");
		exit(-1);
	}
	printf("PR2: Mensaje enviado correctamente\n");
	
	

	return 0;
}
