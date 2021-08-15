#include <stdio.h>
#include <unistd.h>


int main() {
	int numProceso;
	
	printf("Bienvenidos a la sesion 3\n");
	
	numProceso = fork();
	
	if (numProceso == 0)
		execl ("P2", "P2", NULL);		
	
	
	else if (numProceso > 0){
		printf("Soy el proceso padre P1 con PID: %d\n", getpid() );
		
		//printf("Soy el proceso copia con PID: %d y el PID de mi padre es: %d\n", getpid(), getppid() );
		
		sleep (2);	//Se tiene que poner porque, si no, el getppid() del hijo devuelve 1 en vez del PID del
				//padre. "Hay que esperar un poco" (Ponce)		
	}
	
	else
		printf("Error al realizar el fork\n");

	return 0;
}