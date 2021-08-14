#ifndef _Ventas_h
#define _Ventas_h
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
typedef char cadena[101];

    struct Sfecha {
        int dia;
        int mes;
        int anno;
    };

    struct venta{
        Sfecha fecha;       //Fecha de venta
        int unidades;       //Unidades vendidas
        int producto;       //Codigo del producto
        float importe;      //Importe de las ventas
    };

    class ventas{
        fstream detalle;
        cadena fichero;
        cadena ficheroresumen;
        public:
            ventas();
            ~ventas();
            void anadirventa(int num);
            void mostrarventas();
            void resumirfichero();
            void estadisticas(int tipo,int annoini,int annofin);
            bool asignar(cadena Fichero,cadena FicheroResumen);
    };

#endif // _Ventas_h
