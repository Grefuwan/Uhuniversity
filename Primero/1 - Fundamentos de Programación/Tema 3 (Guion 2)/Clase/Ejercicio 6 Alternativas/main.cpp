#include <iostream>

using namespace std;

class operaciones{

    int n1, n2;

public:
    void informacion();
    void operacion();
};

void operaciones::informacion(){

    cout << "Indique dos numeros: ";
    cin >> n1 >> n2;
}

void operaciones::operacion(){

    char op;
    cout << "Indique una operacion (+, s, S, -, r, R): ";
    cin >> op;

    if (op=='+' || op=='s' || op=='S')//Sumas, que puede introducir uno de esos valores
        cout <<"\nLa suma es: " << n1+n2;

    else
        if (op == '-' || op == 'r' || op == 'R')//Restas, que puede introducir uno de esos valores
            cout <<"\nLa resta es: " << n1-n2;
        else
            cout << "\nOperacion no valida.";
}

int main()
{
    operaciones datos;

    datos.informacion();
    datos.operacion();

    return 0;
}
