#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *f1(void);	//Creo la funcion de contar hasta 2500000000

unsigned long long ContH1 = 0;

int main(){
	
	pthread_t Hilo1;
	
	
	pthread_create (&Hilo1 , NULL , (void *) &f1 , NULL);
	
	sleep(2);	//Espero 2 segundos
	pthread_join(Hilo1, NULL)
	
	pthread_detach(Hilo1);
	
	
	return 0;
}



void *f1 (void){
	for (int i = 0; i < 2500000000; i++){
		ContH1++;
	}
}