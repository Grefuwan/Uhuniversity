#include <iostream>
#include <math.h>

using namespace std;

class Movimiento{

    float V0, S0, a;
    int t;

    public:
        void Solicitar();
        float VFinal();
        float SFinal();
};


void Movimiento::Solicitar(){

    cout << "Indique V0, S0, a y t: ";
    cin >> V0 >> S0 >> a >> t;
}

float Movimiento::VFinal(){

    float VF;
    VF = V0 + a*t;
    return VF;
}

float Movimiento::SFinal(){

    float SF;
    SF = S0 + V0*t + (1/2.0)*a*pow(t,2);
    return SF;
}

int main()
{
    float VF, SF; //Son los valores que van a ser devueltos en el programa principal, luego tienes que declararlos

    Movimiento M;
    M.Solicitar();

    VF = M.VFinal();
    SF = M.SFinal();

    cout << "El espacio final es: " << SF << "m y la velocidad final es: " << VF << "m/s.";



    return 0;
}
