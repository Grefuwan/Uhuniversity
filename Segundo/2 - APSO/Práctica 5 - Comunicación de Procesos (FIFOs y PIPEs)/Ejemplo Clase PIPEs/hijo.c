#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
	
	int valor_respuesta;
	
	printf("HIJO: Buenas tardes\n");
	
	sleep(3);
	
	
	//Leer el valor que ha pasado PADRE por la tuberia
	read(2, &valor_respuesta, sizeof(valor_respuesta) );
	//read(mituberia[0], &valor_respuesta, sizeof(valor_respuesta) );
	//Como en PADRE he cambiado la posicion 2 de la TabCanales por mituberia[0],
		//basta con poner ese 2 ahi y usará mituberia[0]
		
	printf("HIJO: Valor leido por la tuberia: %d\n", valor_respuesta);
	printf("HIJO: Fin del proceso\n");
	
	exit(0);
}
