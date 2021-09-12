#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int flago,fcolalago;
void R10() 
{
 close(flago);
 close(fcolalago);
 exit(0);
}

int main()
{
 int testigo, pidbarco;

 signal(10,R10);
 flago=open("lago",O_RDWR);
 fcolalago=open("colalago",O_RDWR);

 while(1)
 {
	read(flago,&testigo,sizeof(testigo));
	read(fcolalago,&pidbarco,sizeof(pidbarco));
	kill(pidbarco,16);
 }
}
