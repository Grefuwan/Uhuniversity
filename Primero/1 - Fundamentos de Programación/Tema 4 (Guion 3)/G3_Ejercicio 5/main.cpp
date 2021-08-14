#include <iostream>
#define M 2
#define N 2
using namespace std;

typedef char cadena[30];

struct persona {
    int dni;        //DNI de la persona sin letra
    cadena nombre;  //Nombre de la persona
};


class matrices {
    persona tabla[M][N];
    public:
        void cargar();      //Pondrá en cada elemento de la tabla un dni (sin letra) y un nombre leídos desde teclado.
        void encontrar();   //Pedirá un dni por teclado y mostrará por pantalla si ese dni está o no en la tabla y además en el caso de que esté mostrará el nombre de esa persona.
};
void matrices::cargar(){
    for(int i=0; i<M;i++){
        for(int j=0; j<N;j++){
            cout<<"Indique el DNI de la persona ";
            cin>>tabla[i][j].dni;
            cout<<"Indique el nombre de la persona ";
            cin>>tabla[i][j].nombre;
        }
    }
}

void matrices::encontrar(){
    int j=0, i=0,Dni;
    bool busqueda=false;
    cout<<"Indique un dni a buscar ";
    cin>>Dni;
    while((j<M)&&(busqueda==false)){
        while((i<N)&&(busqueda==false)){
            if(tabla[i][j].dni==Dni)
                busqueda=true;
            else j++;
        }
            i++;
    }
    if(busqueda){
        cout<<"El DNI esta y pertenece a "<<tabla[i-1][j].nombre<<" el cual es un español de bien";
    }
    else cout<<"Usted no es español, fuera moro mierda";

}
int main()
{
    matrices porro;
    porro.cargar();
    porro.encontrar();
    return 0;
}
