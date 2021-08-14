#ifndef _Productos_h
#define _Productos_h
#include <fstream>
#include "Ventas.h"
using namespace std;


    typedef char cadena[101];

    struct producto{
        Sfecha ultimaventa;
        int unidades;
        int producto;
        float importe;
        int tipo;
        char nombre[20];
    };

    class productos{
        int numproductos;       //Numero de productos activos
        int maxcatalogo;        //Codigo mayor existente en el catalogo
        fstream resumen;        //Nombre logico para manejar el fichero de productos
        cadena fichero;         //Nombre fisico del fichero de productos
        ventas vent;            //Objeto de clase ventas que contiene las ventas de la empresa
        public:
            productos(cadena Fichero,cadena FicheroVentas);
            ~productos();
            int getmaxcatalogo();
            void setmaxcatalogo(int num);
            int getnumproductos();
            void setnumproductos(int num);
            void mostrarproductos();
            void mostrarventas();
            bool anadirventa();
            void actualizarresumen();
            void obtenerestadisticas(int tipo,int annoini,int annofin);
    };
#endif // _Productos_h
