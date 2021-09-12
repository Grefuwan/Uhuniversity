#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


struct Parametros{
	int tesclusa;  // Tiempo de estancia en la esclusa
	int lagomin;   // Intervalo de tiempo en cruzar el lago MIN
	int lagomax;   // Intervalo de tiempo en cruzar el lago MAX
	int mevoymin;  // Intervalo de tiempo en esperar para irse MIN
	int mevoymax;  // Intervalo de tiempo en esperar para irse MAX
};

int creaproceso( const char *, const char *);
int creaprocesotub(const char nombre[], int tub[], int canal);
int fEsclusae, fEsclusao, fLago;
int testigo = 1;

void leeparametros(	struct Parametros *param,
			int *maxbarcos,
			int *creamin,
			int *creamax, 
			int *caplago);
void R10();
void R12();
int llega10 = 0;

/************************* MAIN **************************************************/
int main() {
 
	int pservidorgraf, i;

	struct Parametros param;
	int maxbarcos, creamin, creamax, caplago;
	int lapipe[2];


	signal(10, R10);
	signal(12, R12);
	srand( getpid() );

	//Crear la tubería
	int res_tub = pipe (lapipe);
	if (res_tub == -1){
		printf("Error al crear la PIPE\n");
		exit(-1);
	}

 
	leeparametros(	&param,		//Datos para los barcos
			&maxbarcos,	//Maximo de Barcos
			&creamin,	//Minimo del tiempo aleatorio
			&creamax,	//Maximo del tiempo aleatorio
			&caplago);	//Capacidad del Lago
 
	pservidorgraf = creaproceso("servidor_ncurses",NULL); //parametro 1 es proceso y parametro 2 fichero de redireccion
	if( !llega10 )
		pause(); //Espero a que el servidor grafico de el OK
		
//Crear las FIFOS
	mkfifo("esclusae", 0600);
	mkfifo("esclusao", 0600);
	mkfifo("lago"	 , 0600);


//Abrir las FIFOS en W/R
	fEsclusae = open("esclusae", O_RDWR);
	fEsclusao = open("esclusao", O_RDWR);
	fLago = open("lago", O_RDWR);
	
//Escribir los testigos para cada FIFO
	//Para las esclusas
	write (fEsclusae, &testigo, sizeof(testigo) );
	write (fEsclusao, &testigo, sizeof(testigo) );
	
	//Para el lago: Ajustarlo a caplago
	for (int i=1; i<=caplago; i++)
		write (fLago, &testigo, sizeof(testigo) );
	
	
	
//Crear Barcos con PIPES
	for(i = 1; i <= maxbarcos; i++) {
		if( rand()%2 == 0 ) {
			//creaproceso("barcoeste",NULL);
			creaprocesotub("barcoeste", lapipe, 2);
			write( lapipe[1], &param, sizeof(param) );
		}
		else {  
			//creaproceso("barcooeste",NULL);
			creaprocesotub("barcooeste", lapipe, 2);
			write( lapipe[1], &param, sizeof(param) );
		}
		
		sleep( ( rand()%( creamax-creamin+1 ) ) + creamin);
		
	}
	
	for(i = 1; i <= maxbarcos; i++)
		wait(NULL);
	
	sleep(10);
	kill(pservidorgraf, 10);
	wait(NULL);
	
	
//Cerrar conexiones FIFOS
	close(fEsclusae);
	close(fEsclusao);
	close(fLago);
	
	
//Eliminar FIFOS
	unlink("esclusae");
	unlink("esclusao");	
	unlink("lago");	
	
	
//Acabar el programa
	system("reset");
 
}








/******************************** CREAPROCESO ********************************/
int creaproceso(const char nombre[],const char redire[]) {
	int vpid;

	vpid = fork();
	if(vpid == 0) {
		if(redire != NULL) {
			close(1);
			open(redire, O_WRONLY|O_CREAT,0600);
		}
		execl(nombre,nombre, NULL);
		perror("ERROR EXECL");
		exit(-1);
	}
	else if (vpid == -1) {
		perror("ERROR FORK");
		exit(-1);
	}
	return vpid;
}

/******************************** CREAPROCESOTUBERIA ********************************/
int creaprocesotub(const char nombre[],int tub[], int canal) {
	int vpid;

	vpid = fork();
	if(vpid == 0) {
	//Cerrar la posicion de la tab Canales en la que queremos salvar
		close(canal);
	//Duplicar la posicion de la tab Canales de lectura de tub en la posicion cerrada
		dup(tub[0]);
		execl(nombre,nombre, NULL);
		perror("ERROR EXECL");
		exit(-1);
	}
	else if (vpid == -1) {
		perror("ERROR FORK");
		exit(-1);
	}
	return vpid;
}




/***************** LEEPARAMETROS ********************************/
void leeparametros(struct Parametros *param,int *maxbarcos,int *creamin,int *creamax, int *caplago) {
	int ok=9;

	*maxbarcos=10; //Numero de barcos que se crearan
	*creamin=1;   //Intervalo de tiempo para crear nuevos barcos MIN
	*creamax=5;   //Intervalo de tiempo para crear nuevos barcos MAX
	*caplago=6;   //Capacidad del lago
	param->tesclusa=7;  // Tiempo de estancia en la esclusa
	param->lagomin=5;   //Intervalo de tiempo en cruzar el lago MIN
	param->lagomax=10;   //Intervalo de tiempo en cruzar el lago MAX
	param->mevoymin=10;  //Intervalo de tiempo en esperar para irse MIN
	param->mevoymax=15;  //Intervalo de tiempo en esperar para irse MAX
 
	while(ok == 9) {
		system("clear");
		printf("Valores de los parámetros...\n\n");
		printf("Numero de barcos que se crearan: %d\n",*maxbarcos);
		printf("Intervalo de tiempo para crear nuevos barcos: [%d-%d] \n",*creamin,*creamax);
		printf("Tiempo de estancia en la esclusa: %d\n",param->tesclusa);
		printf("Capacidad del lago: %d\n",*caplago);
		printf("Intervalo de tiempo en cruzar el lago: [%d-%d]\n",param->lagomin,param->lagomax);
		printf("Intervalo de tiempo en esperar para irse: [%d-%d]\n",param->mevoymin,param->mevoymax); 
		printf("Pulse 9 si desea introducir nuevos valores, cualquier otro valor si desea continuar.\n");
		scanf("%d",&ok);

		if(ok == 9){
			do{
				printf("Numero de barcos que se crearan [maximo 50]:\n");
				scanf("%d",maxbarcos);
			}while(*maxbarcos <= 0 || *maxbarcos > 50);

			do{
				printf("Intervalo de tiempo para crear nuevos barcos MIN [entre 1 y 10]: \n");
				scanf("%d",creamin);
			}while(*creamin< 1 ||*creamin > 10 );

			do{
				printf("Intervalo de tiempo para crear nuevos barcos MAX [entre 5 y 20]: \n");
				scanf("%d",creamax);
			}while(*creamax < 5 || *creamax > 20 || *creamax<=*creamin);
	 
			do{
				printf("Tiempo de estancia en la esclusa [maximo 20]: \n");
				scanf("%d",&param->tesclusa);
			}while(param->tesclusa <= 0 || param->tesclusa > 20);
		
			do{
				printf("Capacidad del lago [maximo 8]: \n");
				scanf("%d",caplago);
			}while(*caplago <= 1 || *caplago > 8);
		
			do{
				printf("Intervalo de tiempo en cruzar el lago MIN [entre 1 y 10]: \n");
				scanf("%d",&param->lagomin);
			}while(param->lagomin< 1 ||param->lagomin > 10 );
		
			do{
				printf("Intervalo de tiempo en cruzar el lago MAX [entre 5 y 20]: \n");
				scanf("%d",&param->lagomax);
			}while(param->lagomax < 5 || param->lagomax > 20 || param->lagomax <= param->lagomin );
		
			do{
				printf("Intervalo de tiempo en esperar para irse MIN [entre 1 y 10]:\n");
				scanf("%d",&param->mevoymin);
			}while(param->mevoymin< 1 ||param->mevoymin > 10 );
		
			do{
				printf("Intervalo de tiempo en esperar para irse MAX [entre 5 y 20]:\n");
				scanf("%d",&param->mevoymax);
			}while(param->mevoymax < 5 || param->mevoymax > 20 || param->mevoymax <= param->mevoymin);
		}
	}
}


/***************** R10 ********************************/	
void R10() {
	llega10=1;
}

/***************** R12 ********************************/
void R12() {
	printf("No es posible arrancar el servidor gráfico\n");
	exit(-1);
}
