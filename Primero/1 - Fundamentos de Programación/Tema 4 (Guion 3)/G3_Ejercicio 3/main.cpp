#include <iostream>

using namespace std;
#define M 3
#define N 3

class tres
{   int tabla[M][N];
    public:
        void cargar();//Pondr� en cada elemento de la tabla el valor del producto de sus �ndices.
        int encontrar();//Pedir� un n�mero entero por teclado y devolver� 1 si ese n�mero est� en la tabla, en caso contrario devolver� 0.
};

void tres::cargar()
{
    for (int i=0; i<M; i++)
       for (int j=0; j<N; j++)
            tabla[M][N]= i*j;
}

int tres::encontrar()
{   int numero;
    cout << "Introduzca un valor para comprobar si esta, en cuyo caso mostrara un 1; en caso negativo, mostrara un 0: ";
    cin >> numero;

    int busqueda;
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {   if (numero == tabla [i][j])
                return busqueda = 1;
        }
    }
    return 0;
}

int main()
{
    tres busca;
    busca.cargar();
    int busqueda = busca.encontrar();
    cout << busqueda;
    if (busqueda == 0)
        cout << "El numero no esta.";
    if (busqueda == 1)
        cout << "El numero esta.";


    return 0;
}
