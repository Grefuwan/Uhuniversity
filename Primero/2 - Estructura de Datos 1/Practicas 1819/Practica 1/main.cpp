#include <iostream>
#include <cstdlib>
#include "Productos.h"
#include "Ventas.h"

using namespace std;

int main()
{        int opcionmain;
         productos prods("resumen.dat", "Ventas.dat");

    do{
        system ("cls");
        cout << "Practica 1" << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "\t1.- Ver fichero detalle ventas" << endl;
        cout << "\t2.- Ver fichero productos" << endl;
        cout << "\t3.- Anadir venta" << endl;
        cout << "\t4.- Crear resumen ventas" << endl;
        cout << "\t5.- Obtener estadisticas (tipo producto y periodo)" << endl;
        cout << "\t0.- Salir" << endl;
        cout << "\n\n" << endl;
        cout << "\tOpcion: "; cin >> opcionmain;

        switch (opcionmain){

        case 1:
        prods.mostrarventas();
        break;



        case 2:
        prods.mostrarproductos();
        break;



        case 3:
        prods.anadirventa();
        break;



        case 4:
        prods.actualizarresumen();
        cout << "Resumen actualizado \n";
        break;



        case 5:
        int tipo, annoinicio, annofin;
        cout << "Introduzca el tipo de producto,siendo: " << endl;
        cout << "1.- Electronica" << endl;
        cout << "2.- Papeleria" << endl;
        cout << "3.- Otros" << endl;
        cin >> tipo;
        cout << "\n\nIntroduzca el anno de inicio: "; cin >> annoinicio;
        cout << "\nIntroduzca el anno de fin: "; cin >> annofin;
        prods.obtenerestadisticas(tipo, annoinicio, annofin);
        break;



        default:
        cout << "Opcion incorrecta. Introduzca una opcion valida." << endl;

        }
        system ("pause");

    } while (opcionmain!=0);
    return 0;
}
