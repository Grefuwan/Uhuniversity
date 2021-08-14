#include <iostream>
#include <cmath>

using namespace std;

class Complejo{

    float a, b, c, d;

    public:

    void Solicitar();
    float SumaC();
    float RestaC();
    float MultiplicC();
    float DivisionC();
};

void Complejo::Solicitar(){
    cout << "Indique los valores a+bi y c+di:";
    cin >> a >> b >> c >> d;
}

float Complejo::SumaC(){
    float SCe, SCi;

    SCe = a + c;
    SCi = b + d;

    return SCe, SCi;

}

float Complejo::RestaC(){
    float RCe, RCi;

    RCe = a - c;
    RCi = b - d;

    return RCe, RCi;
}

float Complejo::MultiplicC(){
    float MCe, MCi;

    MCe = (a*c - b*d);
    MCi = (a*d - b-c);

    return MCe, MCi;
}

float Complejo::DivisionC(){
    float DCe, DCi;

    DCe = (a*c + b*d)/(pow(c,2) + pow(d,2));
    DCi = (b*c - a*d)/(pow(c,2) + pow(d,2));

    return DCe, DCi;
}


int main(){

    float SC, RC, MC, DC;

    Complejo N;
    N.Solicitar();

    SC = N.SumaC();
    RC = N.RestaC();
    MC = N.MultiplicC();
    DC = N.DivisionC();

    cout << "La suma de los numeros complejos resulta: " << SC << " + " << SC << "i" << endl;


    return 0;
}
