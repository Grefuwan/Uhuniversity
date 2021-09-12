#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {

	int status;

	printf("L4: Sesion 5. Trabajando con FIFOs. Soy el Padre\n");
	
	//Creamos la FIFO----------------------------------------
	int vmake = mkfifo("fifo1", 0666); // (Nombre, Permisos)
	
	if(vmake == 0){
		printf("FIFO creada correctamente\n");
	}
	else{
		printf("No se ha podido crear la FIFO\n");
		exit(-1);
	}
	
	
	//Creamos el proceso HIJO--------------------------------
	int vpid = fork();
	if (vpid == 0){
		execl ("hijo", "hijo", NULL);
	}
	else if (vpid == -1){
		printf("Error en el fork()\n");
		exit(-1);
	}
	
	//Abrimos la FIFO----------------------------------------
	//Lectura
	printf("PADRE: Voy a intentar abrir para lectura\n");
	int vfifo = open("fifo1", O_RDONLY);
	printf("PADRE: Abierto para lectura\n");
	
	
	//Lecturas o Escrituras----------------------------------
	//Lectura
	int v;
	read (vfifo, &v, sizeof(int) );
	
	printf("PADRE: el valor leido de fifo1 es: %d\n", v);
	
	//Cerramos las conexiones--------------------------------
	close(vfifo); //Se pone el int de abrir la fifo (vfifo), no el de crear (vmake)
	
	
	wait (&status); //Espero al hijo
	
	
	//Eliminamos la FIFO-------------------------------------
	unlink("fifo1");
	
	printf("FIFO eliminada satisfactoriamente\n");
	
	
	return 0;
}
