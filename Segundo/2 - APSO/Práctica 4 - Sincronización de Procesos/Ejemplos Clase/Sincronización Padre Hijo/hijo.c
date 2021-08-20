#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	printf("Soy el proceso HIJO con PID: %d\n", getpid() );
	
	sleep(5);
	
	printf("Fin del proceso HIJO\n");
	
	return 0;
}