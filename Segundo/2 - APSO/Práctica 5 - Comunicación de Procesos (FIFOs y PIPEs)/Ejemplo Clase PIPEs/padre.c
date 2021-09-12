#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
	
	int val = 20;
	
	int pid, status;
	
	int mituberia[2], rest;	//PIPE
	
	printf("PADRE: Sesion 5 PIPES\n");
	
	printf("PADRE: Voy a crear la tuberia\n");
	rest = pipe(mituberia);
	
	if (rest == -1){
		printf("PADRE: Error al crear la tuberia\n");
		perror("ERROR PIPE");
		exit(-3);
	}
	
	printf("PADRE: Tuberia creada correctamente. Leo por %d y escribo por %d\n", mituberia[0], mituberia[1] );
	
	//PADRE: Quiero escribir en la tuberia
	printf("PADRE: Escribo en la tuberia\n");
	write(mituberia[1] , &val , sizeof(val) );

	
	pid = fork();
	
	if (pid == 0) {
		//Soy el proceso COPIA/ HIJO
		
		//Cerrar una posicion de la 0 a la 2 de la TabCanales
		//Duplicar el canal de la tuberia que queramos salvar
		close(2);
		dup (mituberia[0]);
		
		execl ("hijo", "hijo", NULL);
		
		printf("PADRE: Error en el execl\n");//Si se ejecutan estan lineas es que ha fallado la ejecucion
		perror("ERROR EXECL");
		exit(-1); 
	}
	
	else if (pid == -1){
		printf("PADRE: Error en el fork\n");
		perror("ERROR FORK");
		exit(-2);
	
	}
	
	//Soy el PADRE
	
	//sleep(2);
	
	printf("PADRE: Esperando al HIJO\n");
	wait(&status);
	
	printf("PADRE: Fin del proceso\n");
	
	return 0;
}
