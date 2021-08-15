#include <stdio.h>
#include <unistd.h>


int main() {
	printf("Soy el Proceso 2 con PID: %d\n", getpid() );
	
	return 0;
}