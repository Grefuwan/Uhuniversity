#include <iostream>
                        //Metes numeros, introduces uno y te dice si está o no
using namespace std;
#define M 10

class matrices
{
    int tabla [M];
public:
    void cargar();     //Pondra cada elemento de la tabla el valor de su indice
    bool encontrar();  //Pedira un numero entero por teclado y devolvera true si esta en la tabla; false si no

};

void matrices::cargar()
{
    cout << "Introduzca " << M << " valores: " << endl;
    for (int i=0; i<M; i++)
    {
        cin >> tabla[M];
    }

}

bool matrices::encontrar()
{
    cout << "Introduzca el valor que quiera buscar entre los anteriores: " << endl;
    int val, i;
    bool busqueda = false;
    cin >> val;

    while ((i<M) && (busqueda==false))
    {
        if (tabla [M] == val)
            busqueda = true;
        else i++;
    }
    return busqueda;
}
int main()
{
    bool busqueda;
    matrices matr;
    matr.cargar();
    matr.encontrar();
    if (busqueda==true)
        cout << "Numero encontrado." << endl;
    else
        cout << "Numero no encontrado" << endl;

    return 0;
}
