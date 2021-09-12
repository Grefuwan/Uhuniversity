#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_BARCOS 10

int llega10=0;

void R12() { //Llega si el servidor grafico no consigue arrancar
	printf("Imposible arrancar el servidor\n"); 
	exit(-1);
}

void R10() { //Llega cada vez que el servidor grafico confirma una escritura o arranca 
	llega10 = 1;
}


int main() {

	int pidsg, pidBarco, valAleat;
	
//Prepararse para recibir señales 10 y 12
	signal(10 , R10);
	signal(12 , R12);


//Inicializar semilla numero aleatorio
	srand( getpid() );


//Lanzar servidor grafico y esperar confirmacion de arranque
	pidsg = fork();
	if(pidsg == 0) {
		execl("servidor_ncurses" , "servidor_ncurses" , NULL);
		perror("EXECL Servidor Ncurses");
		exit(-1);
	}
	else if ( pidsg == -1){
		perror("FORK Servidor Grafico");
		exit(-1);
	}
	if( !llega10 )
		pause();


//Crear x barcos
	for (int i=1; i<=MAX_BARCOS; i++){
		
		valAleat = rand()%2; //valAleat valdrá 0 o 1, por el mod2
		pidBarco = fork();
		
		if(pidBarco == 0) {
			
			if (valAleat == 0)
				execl("barcoeste" , "barcoeste" , NULL);
			else //valAleat == 1
				execl("barcooeste" , "barcooeste" , NULL); 
			
			perror("EXECL Barcos");
			exit(-1);
		}
		
		else if ( pidBarco == -1){
			perror("FORK Barcos");
			exit(-1);
		}
		
		sleep(rand()%3+2); //Esperar entre 2 y 4 segundos entre creacion y creacion
				   //0+2  --  1+2  --  2+2

	}
	
//Esperar la finalizacion de mis hijos (Barcos)
	for (int i=1; i<=MAX_BARCOS*2; i++){
		wait(NULL);
	}


//Esperamos un poco 
	sleep(10);


//Enviamos la señal de terminacion para el servidor grafico
	kill(pidsg , 10);
	
	wait(NULL); //Recoge el servidor gráfico
	
	system("reset");


	return 0;
}