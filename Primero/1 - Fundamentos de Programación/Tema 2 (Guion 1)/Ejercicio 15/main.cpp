#include <iostream>

using namespace std;

int main()
{
    float a, b, c, d, e, f, x, y;

    cout << "Dadas las siguientes ecuaciones: ";
    cout << "\n\n   ce - bf           af - cd" << "\nx=---------       y=---------" << "\n   ae - bd           ae - bd";
    cout << "\n\nIndique los valores de a, b, c, d, e y f: ";

    cout << "\na: "; cin >> a;
    cout << "\nb: "; cin >> b;
    cout << "\nc: "; cin >> c;
    cout << "\nd: "; cin >> d;
    cout << "\ne: "; cin >> e;
    cout << "\nf: "; cin >> f;

    x = (c*e - b*f)/(a*e - b*d);
    y = (a*f - c*d)/(a*e - b*d);

    cout << "\n\nLos valores obtenidos son X=" << x << " e Y=" << y;






    return 0;
}
