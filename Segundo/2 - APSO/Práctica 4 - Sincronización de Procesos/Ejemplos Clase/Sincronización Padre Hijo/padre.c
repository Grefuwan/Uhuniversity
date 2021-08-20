#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	
	printf("Soy el proceso PADRE y voy a crear a mi hijo\n");
	
	
	int pidDevuelto;
	int retorno;
	int vpid = fork();	//Duplicamos para el hijo

	
	if (vpid == 0){
		execl("hijo", "hijo", NULL);
		perror("Error execl");	//Si se ejecuta esta linea es porque ha habido un error al crear el execl
		exit(-1);
	
	}
	
	else if (vpid == -1){
		printf("Error al crear el fork()\n");
		//perror ("Error");	//Además de mostrar "Error", muestra detalladamente el error ocurrido
	}
	printf("Esperando a mi hijo\n");
	pidDevuelto = wait(&retorno); 
	
	if ( WIFSIGNALED(retorno) ){	//Si el hijo muere por una señal, hará lo que indica a continuación
		printf("El proceso ha muerto por la SEÑAL: %d\n", WTERMSIG(retorno) );
	}
	
	if ( WIFEXITED(retorno) ) {
		printf("El proceso ha muerto por el EXIT: %d\n", WEXITSTATUS(retorno) );
	}
	
	printf("El proceso hijo tenia el PID %d\n", pidDevuelto);
	printf("Fin del proceso PADRE\n");
	
	
	return 0;
}