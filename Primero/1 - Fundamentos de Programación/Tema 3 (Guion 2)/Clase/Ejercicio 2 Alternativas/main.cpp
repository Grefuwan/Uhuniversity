#include <iostream>

using namespace std;

int main()
{

    float a,b;


    cout << "Introduzca dos valores: " << endl;
    cin >> a >> b;

    if (a==b)
        cout << a << " es igual que " << b;
    else
        if (a<b)
            cout << b << " es mayor que " << a;

        else
            cout << a << " es mayor que " << b;




    return 0;
}
