#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int fesclusae,fcolaeste;
void R10() 
{
  close(fesclusae);
  close(fcolaeste);
  exit(0);
}

int main()
{
 int testigo, pidbarco;

 signal(10,R10);
 fesclusae=open("esclusae",O_RDWR);
 fcolaeste=open("colaeste",O_RDWR);

 while(1)
 {
	read(fesclusae,&testigo,sizeof(testigo));
	read(fcolaeste,&pidbarco,sizeof(pidbarco));
	kill(pidbarco,16);
 }
}
