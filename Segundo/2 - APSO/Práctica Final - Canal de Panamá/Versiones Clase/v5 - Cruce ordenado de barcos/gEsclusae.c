#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void R10();

int fEsclusae, fColaEste;

int main(){
	

	int testigo = 1;
	int pidBarco;
	
//Preparar para la señal 10
	signal(10, R10);
	
//Abrir las FIFOS con las que se trabajará
	fEsclusae = open ("esclusae", O_RDONLY);
	fColaEste = open ("colaEste", O_RDONLY);
	
//Hacemos el bucle infinito para leer testigos	
	while(1){
	//Leer el testigo de fEsclusae
		read (fEsclusae, &testigo, sizeof(testigo));
	//Leer el PID del proximo barco en la FIFO colaEste
		read (fColaEste, &pidBarco, sizeof(pidBarco) );
	//Avisar con la señal 16 al barco con el PID leido anteriormente
		kill (pidBarco, 16);
	}
//El bucle solo para cuando se reciba la señal 10
	

	return 0;

}




void R10(){	//Cierra las FIFOs y sale del programa
	
	close(fEsclusae);
	close(fColaEste);
	
	exit(0);
}