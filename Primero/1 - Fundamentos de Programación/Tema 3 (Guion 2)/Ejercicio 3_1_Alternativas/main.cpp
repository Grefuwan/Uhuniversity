#include <iostream>

using namespace std;

int main()
{
    float nota;
    cout << "Inserte la nota obtenida: " << endl;
    cin >> nota;

    if (nota<0 || nota > 10)
        cout << "Nota no valida, introduzca otro valor: ";
    if (nota >=0 && nota <5)
        cout << "Suspenso";
    if (nota >=5 && nota <7)
        cout << "Aprobado";
    if (nota >=7 && nota <9)
        cout << "Notable";
    if (nota >=9 && nota <=10)
        cout << "Sobresaliente";

    return 0;
}

