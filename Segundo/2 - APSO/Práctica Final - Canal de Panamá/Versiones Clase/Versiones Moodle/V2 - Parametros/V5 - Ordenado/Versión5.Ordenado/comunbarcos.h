#include <sys/types.h>
#include <sys/ipc.h>


int crea_cola(key_t clave);
void visualiza(int cola, int donde, int que, int como);
void R10();
void R12();
void R14();
void R16();


struct Parametros{
 int tesclusa;  // Tiempo de estancia en la esclusa
 int lagomin;   //Intervalo de tiempo en cruzar el lago MIN   
 int lagomax;   //Intervalo de tiempo en cruzar el lago MAX   
 int mevoymin;  //Intervalo de tiempo en esperar para irse MIN
 int mevoymax;  //Intervalo de tiempo en esperar para irse MAX
};
     
