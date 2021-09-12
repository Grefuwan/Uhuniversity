#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "comun.h"
#include "comunbarcos.h"

int main()
{

 
	int colagrafica;
	struct Parametros param;

	srand( getpid() );
	signal(10, R10); // me preparo para la senyal 10
	signal(12, R12); // me preparo para la senyal 12

// Creamos y abrimos la cola de mensajes
	colagrafica = crea_cola( ftok ("./fichcola.txt", 18) );
	
//Leer parametros de la tuberia
	read ( 2, &param, sizeof(param) );
	
//Recuperar la salida de errores
	int nuevaLectura = dup(2);	//Duplico el lapipe[0] en nuevaLectura
	close(2);			//Cierro la pos 2
	open("/dev/tty", O_RDWR);	//Recupero la salida de errores en la pos 2
	
//Aplicar los parametros
 	

	visualiza(	colagrafica,
			VESTEIN,
			PINTAR,
			TIPOESTE); 
	
	sleep( rand()%(param.lagomax - param.lagomin +1 ) + param.lagomin);

	
	visualiza(	colagrafica,
			VESTEIN,
			BORRAR,
			TIPOESTE);
	
	visualiza(	colagrafica,
			VOESTEOUT,
			PINTAR,
			TIPOESTE);
			
	sleep( rand()%(param.lagomax - param.lagomin +1 ) + param.lagomin);
	
	visualiza(	colagrafica,
			VHORNOS,
			PINTAR,
			TIPOESTE); 

}