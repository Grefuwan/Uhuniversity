#include <iostream>

using namespace std;

class TablaMultiplicar
{
    int Tabla;
public:
    void PedirNoTabla();
    void MostrarTabla();
};

void TablaMultiplicar::PedirNoTabla()
{
    cout << "Indique que tabla desea ver: " << endl;
    cin >> Tabla;
    cout << "\n\n";

    if (Tabla <0 && Tabla >10)
        cout << "Tabla no valida, inserte un valor comprendido entre 0 y 10: " << endl;

}

void TablaMultiplicar::MostrarTabla()
{
    switch (Tabla)
    {
        case 0: cout << "0x0 = 0\n0x1 = 0\n0x2 = 0\n0x3 = 0\n0x4 = 0\n0x5 = 0\n0x6 = 0\n0x7 = 0\n0x8 = 0\n"; break;
        case 1: cout << "1x1 =1"; break;
        case 2: cout << "Tabla del 2"; break;
        case 3: cout << "Tabla del 3"; break;
        case 4: cout << "Tabla del 4"; break;
        case 5: cout << "Tabla del 5"; break;
        case 6: cout << "Tabla del 6"; break;
        case 7: cout << "Tabla del 7"; break;
        case 8: cout << "Tabla del 8"; break;
        case 9: cout << "Tabla del 9"; break;
        case 10: cout << "Tabla del 10"; break;
    }
}

int main()
{ TablaMultiplicar T;
    T.PedirNoTabla();
    T.MostrarTabla();
    return 0;
}
