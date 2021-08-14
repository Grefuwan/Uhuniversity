#include <iostream>
#include <stdlib.h>

#include "Productos.h"
#include "Ventas.h"
using namespace std;
typedef char cadena[101];
const cadena TIPO_PRODUCTO[3] = {"Electronica","Papeleria","Otros"};

productos::productos(cadena Fichero,cadena FicheroVentas){
    strcpy(fichero, Fichero);
    maxcatalogo = 0;
    numproductos = 0;
    bool correcto = true;

    resumen.open(fichero, ios::in); //Intento abrirlo
    if(resumen.fail()){
        resumen.clear();
        resumen.close();
        resumen.open(fichero, ios::out);
        if(resumen.fail()){
            resumen.clear();
            resumen.close();
            correcto = false;
        }else
            resumen.close();
    }else{
        producto p;
        while(resumen.read((char *) &p, sizeof(producto)) && !resumen.eof()){
            if(p.tipo != -1)
                numproductos++;
        }
        if(resumen.fail()) resumen.clear();
        resumen.seekg(0, ios::end);
        maxcatalogo = resumen.tellg()/sizeof(producto);
        resumen.close();
    }

    if(!(correcto && vent.asignar(FicheroVentas, Fichero))){

    }
}


productos::~productos(){

}

int productos::getmaxcatalogo(){
return maxcatalogo;
}


void productos::setmaxcatalogo(int num){
maxcatalogo = num;
}


int productos::getnumproductos(){
return numproductos;
}


void productos::setnumproductos(int num){
numproductos = num;
}


void productos::mostrarproductos(){
producto p;
venta v;
    resumen.open(fichero, ios::binary | ios::in);
    //ifstream prods (ficheroresumen, ios::out | ios::binary); //New

    //resumen.seekg(sizeof(producto)*(v.producto-1), ios::beg); //New
    //resumen.read((char *) &p, sizeof(producto));


    if(resumen){
        cout << "-------------->LISTA DE PRODUCTOS<--------------\n\n";
        while(resumen.read((char *) &p, sizeof(producto)) && !resumen.eof()){    //Recorrer el archivo
            if(p.tipo != -1){
                cout << "Producto: " << p.nombre <<"\n"
                 << "Ultima Venta: " << p.ultimaventa.dia <<"/"<< p.ultimaventa.mes <<"/"<< p.ultimaventa.anno <<"\n"
                 << "Importe: " << p.importe <<"\n"
                 << "Unidades: " << p.unidades <<"\n"
                 << "Tipo producto: " << TIPO_PRODUCTO[p.tipo-1] <<"\n"
                 << "______________________________________________\n\n";
            }
        }
    }else{
        cout << "ERROR al abrir el archivo.\n";
    }

resumen.close();
}


void productos::mostrarventas(){
vent.mostrarventas();
}


bool productos::anadirventa(){
int id;
    cout << "Introduzca el codigo del producto: ";
    cin >> id;

    //Buscar que el producto exista y no este dado de baja

    producto p;
    if(id <= maxcatalogo){
        resumen.open(fichero, ios::binary | ios::in);

        resumen.seekg(sizeof(producto)*(id-1));
        resumen.read((char *) &p, sizeof(producto));

        resumen.close();

        if(p.tipo == -1)
            cout << "El producto que intenta vender esta dado de baja.\n";
        else  //Es perfectamente vendible
            vent.anadirventa(id);
    }else{
        //La ID no existe, se crea el producto.
        id = ++maxcatalogo;
        numproductos++;

        p.producto = id;    //Inicializar el producto
        p.importe = 0;
        p.unidades = 0;
        p.ultimaventa.anno = 0;
        p.ultimaventa.mes = 0;
        p.ultimaventa.dia = 0;
        cout << "No existe ningun producto con ese codigo, se procede a crearlo.\n"
             << "Introduzca el nombre del producto: ";
        cin.ignore();
        gets(p.nombre);
        do{
            cout << "Introduzca el tipo del producto (1. Electronica | 2. Papeleria | 3. Otros): ";
            cin >> p.tipo;
        }while(p.tipo < 1 || p.tipo > 3);
        cout << "Producto creado correctamente. Empieza la venta.\n";

        resumen.open(fichero, ios::binary | ios::in | ios::out);
        resumen.seekp(0, ios::end);
        resumen.write((char *) &p, sizeof(producto));
        resumen.close();

        vent.anadirventa(id);
}
}


void productos::actualizarresumen(){
 vent.resumirfichero();
}


void productos::obtenerestadisticas(int tipo,int annoini,int annofin){
vent.estadisticas(tipo, annoini, annofin);
}
