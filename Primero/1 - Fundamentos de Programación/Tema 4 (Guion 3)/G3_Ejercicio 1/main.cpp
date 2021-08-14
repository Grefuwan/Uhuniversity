#include <iostream>

using namespace std;
#define M 10

class uno
{
    int tabla [M];
public:
    void cargar();
    int maximo();
    int minimo();
};

void uno::cargar()
{
    for (int i = 0; i< M; i++)
        cin >> tabla [i];
}

int uno::maximo()
{
    int maxim;

    maxim = tabla [0];
    for (int i = 1; i<M; i++)
        if ( maxim < tabla [i])
             maxim = tabla [i];
    return maxim;
}

int uno::minimo()
{
    int minim;

    minim = tabla [0];
    for (int i = 1; i < M; i++)
        if (minim > tabla [i])
            minim = tabla [i];
    return minim;
}

int main()
{
    uno eksde;
    eksde.cargar();


    cout << "El mayor valor es " <<  eksde.maximo() << endl;
    cout << "El minimo valor es " << eksde.minimo() << endl;






    return 0;
}
