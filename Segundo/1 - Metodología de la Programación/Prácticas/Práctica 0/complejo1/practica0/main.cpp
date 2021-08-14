#include <iostream>
#include "complejo.h"

using namespace std;

int main()
{
    const complejo a(2,-3);
    complejo b(-4,5),c(8,8);
    a.ver();
    b.ver();
    b.set();
    b.ver();
    b.set(7,9);
    a.ver();
    b.ver();
    cout << "parte real de a: " << a.getr() << endl;
    cout << "parte imaginaria de a: " << a.geti() << endl;

    int x,y;
    x+y;

    c=b+a;
    cout << "c=b+a" << endl;
    c.ver();

    c=a+b;
    cout << "c=a+b" << endl;
    c.ver();

    c=a+8;
    cout << "c=a+8" << endl;
    c.ver();

    c=8+a;
    cout << "c=8+a" << endl;
    c.ver();

    c=-a;
    cout << "c=-a" << endl;
    c.ver();

    return 0;
}
