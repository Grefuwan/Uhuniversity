#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int fesclusao, fcolaoeste;
void R10() 
{
 close(fesclusao);
 close(fcolaoeste);
 exit(0);
}

int main()
{
 int testigo, pidbarco;

 signal(10,R10);
 fesclusao=open("esclusao",O_RDWR);
 fcolaoeste=open("colaoeste",O_RDWR);

 while(1)
 {
	read(fesclusao,&testigo,sizeof(testigo));
	read(fcolaoeste,&pidbarco,sizeof(pidbarco));
	kill(pidbarco,16);
 }
}
