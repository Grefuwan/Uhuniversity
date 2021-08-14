#include <iostream>

using namespace std;

class TablasMultiplicar
{
    int TablaIni, TablaFin;
public:
    void PedirNoTablas();
    void MostrarTablas();
};

void TablasMultiplicar::PedirNoTablas()
{
    cout << "Indique las tablas iniciales y finales a mostrar: " << endl;
    cin >> TablaIni >> TablaFin;

    if (TablaIni<1 && TablaFin<1 && TablaFin>10 && TablaIni>10)
        cout << "Valores no validos. Introduzca tablas entre 1 y 10";
}

void TablasMultiplicar::MostrarTablas()
{

}

int main()
{
TablasMultiplicar t;
t.PedirNoTablas();
t.MostrarTablas();
    return 0;
}
