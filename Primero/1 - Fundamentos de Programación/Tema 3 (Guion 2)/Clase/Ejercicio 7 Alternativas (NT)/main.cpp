#include <iostream>
using namespace std;

class Billete{
    int distancia;
    int dias;
    int edad;
public:
    void informacion();//Pide la distancia, los dias del viaje y la edad del turista
    float operacion();//Precio de billete ida/vuelta, si dias>7 y distancia>800km o persona>55años, precio-0.25%. 0.5€/km

};

void Billete::informacion(){

    cout << "Especifique la distancia a recorrer, los dias del viaje y su edad." << endl;
    cout << "Dias: ";
    cin >> dias >> endl;
    cout << "Distancia: ";
    cin >> distancia >> endl;
    cout << "Edad: ";
    cin >> edad >> endl;


}

int main()
{






    return 0;
}
