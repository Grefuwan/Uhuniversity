#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	printf("L4: Sesion 5. Trabajando con FIFOs. Soy el Hijo\n");
	

	//Abrimos la FIFO----------------------------------------
	//Lectura
	printf("HIJO: Voy a intentar abrir para Escritura\n");
	int vfifo = open("fifo1", O_WRONLY);
	printf("HIJO: Abierto para lectura\n");
	
	
	//Lecturas o Escrituras----------------------------------
	//Escritura
	int valor = 15;
	write(vfifo , &valor, sizeof(int) ); //Tambien se puede poner sizeof(valor)
	
	
	//Cerramos las conexiones--------------------------------
	close (vfifo);
		
	
	sleep(5);
	
	exit(0);
}
