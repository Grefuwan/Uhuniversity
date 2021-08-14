#include <iostream>
#include <math.h>

using namespace std;

class Fracciones{

    int a, b, c, d;

    public:
        void Solicitar();
        float SumarF(), RestaF(), MultiplicF(), DivisionF();
};

void Fracciones::Solicitar(){
    cout << "Indique los valores a, b, c, d: ";
    cin >> a >> b >> c >> d;
}

float Fracciones::SumarF(){
        float SF;

        SF = (a/b) + (c/d);

        return SF;
}

float Fracciones::RestaF(){
        float RF;

        RF = (a*d - b*c)/(b*d*1.0);

        return RF;
}

float Fracciones::MultiplicF(){
        float MF;

        MF = (a*c)/(b*d*1.0);

        return MF;
}

float Fracciones::DivisionF(){
        float DF;

        DF = (a*d)/(b*c*1.0);

        return DF;
}

int main(){

    float SF, RF, MF, DF;
    Fracciones F;

    F.Solicitar();

    SF = F.SumarF();
    RF = F.RestaF();
    MF = F.MultiplicF();
    DF = F.DivisionF();

    cout << "La suma de las fracciones resulta: " << SF;
    cout << "\nLa resta de las fracciones resulta: " << RF;
    cout << "\nEl producto de las fracciones resulta: " << MF;
    cout << "\nLa division de las fracciones resulta: " << DF;

    return 0;
}
