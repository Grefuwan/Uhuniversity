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


void R14();
void R16();

int colagrafica;
int fEsclusae, fEsclusao, fLago;
int fcolaOeste, fcolaEste, fcolaLago;
int miPID, llega16 = 0, llega14 = 0;


int main()
{

 
	//int colagrafica;			//La ponemos como Var Global para R14
	struct Parametros param;
	//int fEsclusae, fEsclusao, fLago; 	//La ponemos como Var Global para R14
	int testigo=1;

	srand( getpid() );
	signal(10, R10); // me preparo para la senyal 10 (Pintar OK)
	signal(12, R12); // me preparo para la senyal 12 (Pintar KO)
	signal(14, R14); // me preparo para la senyal 14 (Cabo de Hornos)
	signal(16, R16); // Paso a los recursos

// Creamos y abrimos la cola de mensajes
	colagrafica = crea_cola( ftok ("./fichcola.txt", 18) );
	
//Abrir las FIFOS en W/R
	fEsclusae = open("esclusae", O_RDWR);
	fEsclusao = open("esclusao", O_RDWR);
	fLago = open("lago", O_RDWR);

	fcolaOeste = open("colaOeste", O_WRONLY);
	fcolaEste = open("colaEeste", O_WRONLY);
	fcolaLago = open("colaLago", O_WRONLY);
	
//Leer parametros de la tuberia
	read ( 2, &param, sizeof(param) );
	
//Recuperar la salida de errores
	int nuevaLectura = dup(2);	//Duplico el lapipe[0] en nuevaLectura
	close(2);			//Cierro la pos 2
	open("/dev/tty", O_RDWR);	//Recupero la salida de errores en la pos 2



//Aplicar los parametros

//Pintar en el Oceano Oeste (Entrada)
	visualiza(	colagrafica,
			VOESTEIN,
			PINTAR,
			TIPOOESTE); 
//Establecer la Alarma
	alarm( rand()%( param.mevoymax - param.mevoymin + 1 ) + param.mevoymin ); //Activar la Alarma

//Escribir mi PID en colaLago para poder cruzarlo
	miPID = getpid();
	write (fcolaLago, &miPID, sizeof(miPID));

//Esperar la señal 16
	if (!llega16)
		pause();

//Aqui se puede llegar por la señal 14 o por 16
	
	if (llega14){ //Señal 14 - Cabo de Hornos
		
		//Borrar del Oceano Oeste (Entrada)
		//Pintar en Cabo de Hornos
		visualiza(	colagrafica,
				VOESTEIN,
				BORRAR,
				TIPOOESTE);
				
		visualiza(	colagrafica,
				VHORNOS,
				PINTAR,
				TIPOOESTE);
		//Devolver el testigo cuando se obtenga
		if(!llega16)
			pause();
		write (fLago, &testigo, sizeof(testigo));
	
	}
	
	else{ //Señal 16 - Canal de Panamá
		//Desactivar la Alarma
			llega16 = 0;
			alarm(0); //Desactivar la Alarma

		//Obtener Testigo Esclusa Oeste (Principio)
			//read (fEsclusao, &testigo, sizeof(testigo)); //Testigo Esclusa Oeste
			write (fcolaOeste, &miPID, sizeof(miPID));
		//Esperar la señal 16
			if (!llega16)
				pause();
			
			llega16 = 0;
		//Borrar de Oceano Oeste (Entrada); pintar en Esclusa Oeste y simular espera
		//No soltar ni obtener ningun testigo
			visualiza(	colagrafica,
					VOESTEIN,
					BORRAR,
					TIPOOESTE); 
					
			visualiza(	colagrafica,
					VESCLUSAOESTE,
					PINTAR,
					TIPOOESTE);
					
			sleep(param.tesclusa); //Valor fijo

		//Borrar de Esclusa Oeste; pintar en Lago (Carril Oeste) y simular espera
		//Soltar Testigo Esclusa Oeste (Antes de la espera)
		//Pedir Testigo Esclusa Este (Despues de la espera)
			visualiza(	colagrafica,
					VESCLUSAOESTE,
					BORRAR,
					TIPOOESTE);
					
			visualiza(	colagrafica,
					VLAGOO,
					PINTAR,
					TIPOOESTE);
					
			write (fEsclusao, &testigo, sizeof(testigo));

			sleep( rand()%(param.lagomax - param.lagomin +1 ) + param.lagomin);
			
			//read (fEsclusae, &testigo, sizeof(testigo));
			write (fcolaEste, &miPID, sizeof(miPID));
		//Esperar la señal 16
			if (!llega16)
				pause();

		//Borrar de Lago (Carril Oeste); pintar en Esclusa Este y simular espera
		//Soltar Testigo Lago (Antes de la espera)

			visualiza(	colagrafica,
					VLAGOO,
					BORRAR,
					TIPOOESTE);
					
			visualiza(	colagrafica,
					VESCLUSAESTE,
					PINTAR,
					TIPOOESTE);
					
			write (fLago, &testigo, sizeof(testigo));
			
			sleep(param.tesclusa); //Valor fijo

		//Borrar de Eslusa Este; pintar en Oceano Este (Salida)
		//Soltar Testigo Esclusa Este
			visualiza(	colagrafica,
					VESCLUSAESTE,
					BORRAR,
					TIPOOESTE);

			visualiza(	colagrafica,
					VESTEOUT,
					PINTAR,
					TIPOOESTE); 
			
			write (fEsclusae, &testigo, sizeof(testigo));
			}

//Cerrar conexiones FIFOS
	close(fEsclusae);
	close(fEsclusao);
	close(fLago);
//Cerrar conexiones FIFOS
	close(fEsclusae);
	close(fEsclusao);
	close(fLago);
}




void R14(){
	llega14 = 1;
};

void R16(){

	llega16 = 1;

};