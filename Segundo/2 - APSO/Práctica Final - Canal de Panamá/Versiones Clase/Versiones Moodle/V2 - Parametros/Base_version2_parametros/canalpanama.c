#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct Parametros{
 int tesclusa;  // Tiempo de estancia en la esclusa
 int lagomin;   //Intervalo de tiempo en cruzar el lago MIN
 int lagomax;   //Intervalo de tiempo en cruzar el lago MAX
 int mevoymin;  //Intervalo de tiempo en esperar para irse MIN
 int mevoymax;  //Intervalo de tiempo en esperar para irse MAX
};

int creaproceso(const char *, const char *);

void leeparametros(struct Parametros *param,int *maxbarcos,int *creamin,int *creamax, int *caplago);
void R10();
void R12();
int llega10=0;

/************************* MAIN **************************************************/
int main()
{
 
 int pservidorgraf, i;

 struct Parametros param;
 int maxbarcos,creamin,creamax,caplago;

 
 signal(10,R10);
 signal(12,R12);
 srand(getpid());

 
 leeparametros(&param,&maxbarcos,&creamin,&creamax,&caplago);
 
 pservidorgraf=creaproceso("servidor_ncurses",NULL); //parametro 1 es proceso y parametro 2 fichero de redireccion
 if(!llega10) pause(); //Espero a que el servidor grafico de el OK
 for(i=1;i<=maxbarcos;i++) 
 {
 	if(rand()%2==0) 
 	{
 	   creaproceso("barcoeste",NULL);
  	}
	else 
	{  
	   creaproceso("barcooeste",NULL);
	}  
 	sleep((rand()%(creamax-creamin+1))+creamin);
 }
 for(i=1;i<=maxbarcos;i++) wait(NULL);
 sleep(1);
 kill(pservidorgraf,10);
 system("reset");
 
}


/***************** CREAPROCESO ********************************/
int creaproceso(const char nombre[],const char redire[])
{
 int vpid;

 vpid=fork();
 if(vpid==0)
 {
    if(redire!=NULL)
    {
      close(1);
      open(redire,O_WRONLY|O_CREAT,0600);
    }
    execl(nombre,nombre,NULL);
    perror("error de execl");
    exit(-1);
 }
 else if (vpid==-1)
 {
   perror("error de fork");
   exit(-1);
 }
 return vpid;
}
 
/***************** LEEPARAMETROS ********************************/
void leeparametros(struct Parametros *param,int *maxbarcos,int *creamin,int *creamax, int *caplago)
{
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
 
 while(ok == 9)
 {
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
void R10()
{
 llega10=1;
}

/***************** R12 ********************************/
void R12()
{
 printf("No es posible arrancar el servidor gráfico\n");
 exit(-1);
}
