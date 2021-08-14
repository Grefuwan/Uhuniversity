#include <iostream>

using namespace std;

class Factorial{

    int N;
public:
    void informacion();
    long factorial();
};

void Factorial::informacion(){

    do{
        cout << "Indica un numero ... ";
        cin >> N;

        if (N < 0 || N >=20)
            cout << "Numero no valido. Vuelva a repetir el proceso." << endl;
    }
    while(N < 0 || N >= 20);//Tiene que repetir el bucle hasta que ponga un numero entre 0 y 20
}
/*Paso 1: Inicializar F1
Paso 2: Si N es 0 o 1-> Devuelvo F
        Si N>1 [No >=] se pone en bucle

        F = F*i
*/

long Factorial::factorial(){
    long F=1;
    int i;

    for (i=2; i<= N; i++)
        F = F*i;

        return F;
}


int main()
{
    long F;
    Factorial Fac;

    Fac.informacion();

    F = Fac.factorial();
    cout << "El numero factorial es: " << F << endl;
    return 0;
}
