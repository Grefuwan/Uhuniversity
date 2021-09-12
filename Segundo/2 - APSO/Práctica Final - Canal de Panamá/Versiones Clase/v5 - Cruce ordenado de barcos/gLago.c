#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void R10();

int fLago, fColaLago;

int main(){
	

	int testigo = 1;
	int pidBarco;
	
//Preparar para la señal 10
	signal(10, R10);
	
//Abrir las FIFOS con las que se trabajará
	fLago = open ("lago", O_RDONLY);
	fColaLago = open ("colaLago", O_RDONLY);
	
//Hacemos el bucle infinito para leer testigos	
	while(1){
	//Leer el testigo de fLago
		read (fLago, &testigo, sizeof(testigo));
	//Leer el PID del proximo barco en la FIFO ColaLago
		read (fColaLago, &pidBarco, sizeof(pidBarco) );
	//Avisar con la señal 16 al barco con el PID leido anteriormente
		kill (pidBarco, 16);
	}
//El bucle solo para cuando se reciba la señal 10
	

	return 0;

}




void R10(){	//Cierra las FIFOs y sale del programa
	
	close(fLago);
	close(fColaLago);
	
	exit(0);
}