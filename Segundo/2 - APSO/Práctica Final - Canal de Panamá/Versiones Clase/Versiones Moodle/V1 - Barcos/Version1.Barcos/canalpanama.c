#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MAXBARCOS 30

int creaproceso(const char *, const char *);
void R10();
void R12();
int llega10=0;

int main()
{
 
 int pservidorgraf, i;

 signal(10,R10);
 signal(12,R12);
 srand(getpid());
 pservidorgraf=creaproceso("servidor_ncurses",NULL); //parametro 1 es proceso y parametro 2 fichero de redireccion
 if(!llega10) pause(); //Espero a que el servidor gráfico de el OK
 for(i=1;i<=MAXBARCOS;i++) 
 {
 	if(rand()%2==0) creaproceso("barcoeste",NULL);
	else creaproceso("barcooeste",NULL);
 	sleep(rand()%3+1);
 }
 for(i=1;i<=MAXBARCOS;i++) wait(NULL);
 kill(pservidorgraf,10);
 system("reset");
 
}

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
 
void R10()
{
 llega10=1;
}

void R12()
{
 printf("No es posible arrancar el servidor gráfico\n");
 exit(-1);
}
