#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float R, longitud, superficie, volumen, PI;
    PI = 3.141592;

    cout << "\nInserte el radio de la circunferencia: " << endl;
    cin >> R;

    longitud = 2 * PI * R;
    superficie = PI * pow (R,2);
    volumen = 4 * PI * ((pow (R,3)/3.0));

    cout << "\nLa longitud es: " << longitud << "\nLa superficie es: " << superficie << "\nEl volumen es: " << volumen;


    return 0;
}
