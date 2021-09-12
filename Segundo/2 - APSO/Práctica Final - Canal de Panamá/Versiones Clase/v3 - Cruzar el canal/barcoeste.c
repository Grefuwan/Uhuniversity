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
	int fEsclusae, fEsclusao, fLago;
	int testigo=1;

	srand( getpid() );
	signal(10, R10); // me preparo para la senyal 10
	signal(12, R12); // me preparo para la senyal 12

// Creamos y abrimos la cola de mensajes
	colagrafica = crea_cola( ftok ("./fichcola.txt", 18) );
	
//Abrir las FIFOS en W/R
	fEsclusae = open("esclusae", O_RDWR);
	fEsclusao = open("esclusao", O_RDWR);
	fLago = open("lago", O_RDWR);
	
//Leer parametros de la tuberia
	read ( 2, &param, sizeof(param) );
	
//Recuperar la salida de errores
	int nuevaLectura = dup(2);	//Duplico el lapipe[0] en nuevaLectura
	close(2);			//Cierro la pos 2
	open("/dev/tty", O_RDWR);	//Recupero la salida de errores en la pos 2




//Aplicar los parametros
//Pintar en el Oceano Este (Entrada)
//Obtener Testigo Lago
//Obtener Testigo Esclusa Este (Principio)
	visualiza(	colagrafica,
			VESTEIN,
			PINTAR,
			TIPOESTE); 
	
	read (fLago, &testigo, sizeof(testigo)); //Testigo del Lago
	read (fEsclusae, &testigo, sizeof(testigo)); //Testigo Esclusa Oeste
	

//Borrar de Oceano Este (Entrada); pintar en Esclusa Eeste y simular espera
//No soltar ni obtener ningun testigo
	visualiza(	colagrafica,
			VESTEIN,
			BORRAR,
			TIPOESTE); 
			
	visualiza(	colagrafica,
			VESCLUSAESTE,
			PINTAR,
			TIPOESTE);
			
	sleep(param.tesclusa); //Valor fijo

//Borrar de Esclusa Este; pintar en Lago (Carril Este) y simular espera
//Soltar Testigo Esclusa Este (Antes de la espera)
//Pedir Testigo Esclusa Oeste (Despues de la espera)
	visualiza(	colagrafica,
			VESCLUSAESTE,
			BORRAR,
			TIPOESTE);
			
	visualiza(	colagrafica,
			VLAGOE,
			PINTAR,
			TIPOESTE);
			
	write (fEsclusae, &testigo, sizeof(testigo));

	sleep( rand()%(param.lagomax - param.lagomin +1 ) + param.lagomin);
	
	read (fEsclusao, &testigo, sizeof(testigo));

//Borrar de Lago (Carril Este); pintar en Esclusa Oeste y simular espera
//Soltar Testigo Lago (Antes de la espera)

	visualiza(	colagrafica,
			VLAGOE,
			BORRAR,
			TIPOESTE);
			
	visualiza(	colagrafica,
			VESCLUSAOESTE,
			PINTAR,
			TIPOESTE);
			
	write (fLago, &testigo, sizeof(testigo));
	
	sleep(param.tesclusa); //Valor fijo

//Borrar de Eslusa Oste; pintar en Oceano Oste (Salida)
//Soltar Testigo Esclusa Oste
	visualiza(	colagrafica,
			VESCLUSAOESTE,
			BORRAR,
			TIPOESTE);

	visualiza(	colagrafica,
			VOESTEOUT,
			PINTAR,
			TIPOESTE); 
	
	write (fEsclusao, &testigo, sizeof(testigo));

			
//Cerrar conexiones FIFOS
	close(fEsclusae);
	close(fEsclusao);
	close(fLago);

}