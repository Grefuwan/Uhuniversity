#include <iostream>

using namespace std;

int main()
{
    float euro, dolar, libra;

    cout <<"\nIndique la cantidad de euros a convertir: ";
    cin >> euro;

    dolar = euro * 1.15;
    libra = euro * 0.88;

    cout << "\n\n" << euro << " euros son " << dolar << " dolares y " << libra << " libras";

    return 0;
}
