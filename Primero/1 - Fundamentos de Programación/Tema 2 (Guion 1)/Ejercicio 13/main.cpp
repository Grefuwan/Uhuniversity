#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    float raiz, solmas, solmenos;

    cout << "Indique los valores a, b y c: ";
    cin >> a, b, c;

    raiz = sqrt (pow(b,2) -4*a*c);

    solmas = (-b + raiz)/(2.0 * a);
    solmenos = (-b - raiz)/ (2.0 * a);

    cout << "\n\mLas soluciones de la ecuacion de segundo grado dada son: " << solmas <<" y " << solmenos << "\n\n";



    return 0;
}
