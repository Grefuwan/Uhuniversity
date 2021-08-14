#include <iostream>
#include "Complejo.h"


using namespace std;

int main()
{
    Complejo a (2,7), b (0,-4), d (0,0);
    cout << a.getr() << endl;
    a.ver();

    a.set (1,5);                    //Cuando le introduzco 2 parametros, ejecuta el primer set
    a.ver();
    a.set();                        //Cuando no le introduzco parametros, ejecuta el segundo set
    a.ver();

    d.ver();
    d=a+b;
    d.ver();
    b.ver();


    const Complejo c(5,4);
    cout << c.getr() << endl;
    cout << c.geti() << endl;


    return 0;
}
