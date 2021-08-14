#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Ventas.h"
#include "Productos.h"

typedef char cadena[101];
bool compararFecha(Sfecha f1, Sfecha f2);

using namespace std;

//bool compararFecha(Sfecha f1, Sfecha f2);


ventas::ventas()
{
}


ventas::~ventas()
{
}


void ventas::anadirventa(int num){
venta vent, temporal;
producto prod;
bool posision = true;
int insertIndex = 0;

detalle.open(fichero, ios::binary | ios:: in | ios::out);
if (!detalle.fail()){       //Si no hay error al abrirlo, se introducen los datos
    vent.producto = num;
    cout << "Introduzca el dia, mes y anno de la venta: ";
    cin >> vent.fecha.dia >> vent.fecha.mes >> vent.fecha.anno;
    cout << "Introduzca el numero de unidades vendidas: ";
    cin >> vent.unidades;
    cout << "Introduzca el importe: ";
    cin >> vent.importe;

    bool encaja = false;
    detalle.seekg(0, ios::end);
    do{
        if(detalle.tellg() <= 0){
            encaja = true;  //Encaja porque no hay ventas anteriores
        }else{
            detalle.seekg((int) -sizeof(venta), ios::cur);  //Retrodece una posicion
            detalle.read((char *) &temporal, sizeof(venta));     //Lee la venta
            if(compararFecha(temporal.fecha, vent.fecha)){    //Comparacion de fechas
                detalle.write((char *) &temporal, sizeof(venta));    //Escrebe la venta una posicion más abajo
                detalle.seekg((int) -sizeof(venta)*2, ios::cur);    //Sube las dos posiciones que se ha movido
            }else{
                encaja = true;  //Encaja porque la venta leida es anterior
            }
        }
        if(encaja)
            detalle.write((char *) &vent, sizeof(venta));
    }while(!encaja);
    }else{
        cout << "Error al abrir el fichero de ventas\n";
}


detalle.close();
}


void ventas::mostrarventas(){
venta ven;
producto product;

detalle.open (fichero, ios::in |ios::binary);               //Abro el archivo de Ventas, en modo lectura
ifstream prods (ficheroresumen, ios::out | ios::binary);    //Creo un nuevo fichero fisico, en modo escritura



cout << "----- VENTAS -----" << endl;

while (detalle.read((char *)&ven, sizeof(venta))&& !detalle.eof())
    {
    prods.seekg(sizeof(producto)*(ven.producto-1), ios::beg);
    prods.read((char *) &product, sizeof(producto));

    if (prods && product.tipo != -1)
        {
            cout << "Fecha de venta: " << ven.fecha.dia << "/" << ven.fecha.mes << "/" << ven.fecha.anno << endl;
            cout << "Producto: " << product.nombre << endl;
            cout << "Unidades: " << ven.unidades << endl;
            cout << "Importe: " << ven.importe << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
    else
        {
            cout << "El producto vendido " << ven.producto << " no fue encontrado.\n" << endl;
        }
        prods.clear();
    }
prods.close();
detalle.close();


}

void ventas::resumirfichero(){
/*
detalle.open(fichero, ios::in | ios::binary);       //Abrimos el fichero de Ventas
fstream ActualizarVentas;                         //Como no se puede acceder al fichero de Productos, creamos uno
ActualizarVentas.open(ficheroresumen, ios::in | ios:: binary);    //Y lo abrimos



detalle.close();*/



producto p;
    venta v;

    fstream prods(ficheroresumen, ios::binary | ios::in | ios::out);
    detalle.open(fichero, ios::binary | ios::in);

    if(detalle && prods){
        while(prods.read((char *) &p, sizeof(producto)) && !prods.eof()){  //Leer y comprobar que no se haya acabado el archivo de productos
            detalle.seekg(0, ios::beg);
            while(detalle.read((char *) &v, sizeof(venta)) && !detalle.eof()){  //Buscar en ventas
                if(v.producto == p.producto && compararFecha(v.fecha, p.ultimaventa)){   //La venta del producto actual
                    p.ultimaventa = v.fecha;
                    p.unidades += v.unidades;   //Actualizar datos
                    p.importe += v.importe;
                }

            }
            if(detalle.fail()) detalle.clear(); //Parece que esto no es necesario, pero hace mucho


            prods.seekp((int) -sizeof(producto), ios::cur); //Volver a la posicion de inicio del producto actual
            prods.write((char *) &p, sizeof(producto));     //Reescribir el productos actual
        }
    }

    prods.close();
detalle.close();
}

void ventas::estadisticas(int tipo,int annoini,int annofin){


}

bool ventas::asignar(cadena Fichero,cadena FicheroResumen){	//Fichero = Ventas; FR = Productos

    strcpy(fichero, Fichero);
    strcpy (ficheroresumen, FicheroResumen);
	bool encontrado = true;

	detalle.open(fichero, ios::in);		                            //Intenta abrirlo
	if (detalle.fail()){
		detalle.close();
		detalle.clear();
		detalle.open(fichero, ios::out|ios::binary);				//Si al abrirlo no puede, lo crea en modo de lectura
		if (detalle.fail()){				                            //Si no puede crearlo, rip
			detalle.close();
			encontrado = false;
		}
		else detalle.close();
	}
	else detalle.close();

	return encontrado;
}

bool compararFecha(Sfecha f1, Sfecha f2){
    return f1.anno >  f2.anno ||        //Devuelve True si f1 > f2
          (f1.anno == f2.anno && f1.mes >  f2.mes) ||
          (f1.anno == f2.anno && f1.mes == f2.mes && f1.dia > f2.dia);
}
