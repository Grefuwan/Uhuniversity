//Diseñe un programa que lea una temperatura medida en la escala Celsius (grados centígrados) y la convierta a grados Fahrenheit, según la siguiente fórmula://
#include <iostream>

using namespace std;

int main()
{
   float tempcelsius, tempfahren;

   cout << "\nIndique la temperatura en grados Celsius: ";
   cin >> tempcelsius;

   tempfahren = ((9.0*tempcelsius)/5.0) +32;

   cout << "\nLa conversion a grados Fahrenheit es de: " << tempfahren << "\n\n\n";

   return 0;
}
