#include <iostream>
using namespace std;

int main (){

    float teoria, practica, NotaFinal;

    cout << "\nIndique la nota de teoria y de practicas: ";
    cin >> teoria >> practica;

    NotaFinal = teoria*0.7 + practica*0.3;

    cout <<"\nLa nota en la asignatura es: " << NotaFinal;

    return 0;
}
