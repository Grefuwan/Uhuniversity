#include <iostream>
using namespace std;

class empleado {
    int horasnormales, horasextras;

    public:
        void cargar();//El void en si no devuelve ningun valor, sino que se le introduce
        float nomina();//El float devolverá el salario
        };

    void empleado::cargar(){
        cout << "Indique las horas normales y extras" << endl;
        cin >> horasnormales >> horasextras;
    }

    float empleado::nomina(){
        float n;
        n = (horasnormales*5 + horasextras*8)*0.85;
    }




int main()
{
    empleado Fulano; //Estoy declarando que un empleado se denomina Fulano
    float Nfinal;

    Fulano.cargar();//Ejerzo Cargar sobre el empleado Fulano
    Nfinal = Fulano.nomina();

    cout << "La nomina total es de: " << Nfinal;

return 0;
}
