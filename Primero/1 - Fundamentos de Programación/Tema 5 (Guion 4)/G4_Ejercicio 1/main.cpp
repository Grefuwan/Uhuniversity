#include <iostream>
#include <cstring>

using namespace std;

typedef char cad[20];

class tprod {
    cad nombre;
    float precio;
    int stock;
public:
    tprod ();
    void cambiarnombre (cad nom);
    void cambiarprecio (float prec);
    void cambiarstock (int stoc);
    void leenombre (cad nom);
    float leeprecio();
    void leestock (int &st);
    void vender (int cantidad);
};

tprod::tprod()
{
    precio = 0;
    stock = 0;
    strcpy (nombre, "No hay producto"); //Libreria cstring (c++) o string.h (c)
}

void tprod::cambiarnombre(cad nom)
{
    strcpy(nombre, nom);
}

void tprod::cambiarprecio(float prec)
{
    precio = prec;
}

void tprod::cambiarstock(int stoc)
{
    stock = stoc;
}

void tprod::leenombre(cad nom)
{
    strcpy(nom, nombre);
}

float tprod::leeprecio()
{
    return precio;
}

void tprod::leestock(int &st)
{
    st = stock;
}

void tprod::vender(int cantidad)
{
    stock = stock - cantidad;
    if (cantidad > stock)
        cout << "No hay suficiente stock. Venta no realizada." << endl;
    else
    cout << "El precio total de la venta es: " << precio * cantidad << "\n\n";
}



#define MAX 5
class almacen {
    tprod productos [MAX];
    int nprod;
public:
    almacen ();
    void vaciar ();
    int existe (cad nom);
    void verprod (int pos, tprod &prod);
    int insertar (tprod P);
    void vertabla ();
    void vender (int pos, int cant);
    char menu ();
};

almacen::almacen()
{
    nprod = 0;
}

void almacen::vaciar()
{
    nprod = 0;
}

int almacen::existe(cad nom)
{
    int i, pos;
    cad original;
    i = 0;
    pos = -1;

    while (i < nprod && pos == -1){
        productos[i].leenombre(original);
        if (strcmp(original, nom) == 0)
        pos = i;
        i++;
    }
    return pos;
}

void almacen::verprod(int pos, tprod &prod)
{
    prod=productos[pos];
}

int almacen::insertar(tprod P)      //Si lleno = 2      Si ya existe = 1        Si entra = 0
{
    int resultado;
        if (nprod >= MAX)
        resultado = 2;
        else
    {       cad nombre;
            P.leenombre(nombre);
            if (existe(nombre)!= -1)
                resultado = 1;
            else
            {   resultado = 0;
                productos[nprod] = P;
                nprod++;

            }
    }
    return resultado;
}


void almacen::vertabla()
{
    if(nprod == 0)
        {
            cout << "El almacen esta vacio.\n";
        }
    else
    {
		cad nombre;
		int stock;
		for(int i = 0; i < nprod; i++)
            {
                productos[i].leenombre(nombre);
                productos[i].leestock(stock);
                cout << "Nombre: " << nombre << "\n";
                cout << "Precio: " << productos[i].leeprecio() << "\n";
                cout << "Stock:  " << stock << "\n\n";
            }
    }
}

void almacen::vender(int pos, int cant)
{
    productos[pos].vender(cant);
    /*int stock = productos[pos].leestock(stock);
    float dineros = productos[pos].leeprecio();


    for (int i =0; i < nprod; i++)
    {
        if (cant > stock)
        cout << "No hay suficiente stock. Venta no realizada." << endl;
        else
        {stock = stock - cant;
        cout << "El precio total de la venta es: " << dineros * cant << "\n\n";}
    }*/
}

char almacen::menu()
{
    cout << "\n \n" << endl;
    cout << "************* MENU ******************" << endl;
    cout << "*******A.- Visualizar la tabla.\t *****" << endl;
    cout << "*******B.- Insertar un producto.\t *****" << endl;
    cout << "*******C.- Vender un producto.\t *****" << endl;
    cout << "*******D.- Vaciar el almacen.\t *****" << endl;
    cout << "*******E.- Salir..\t *****" << endl;
    cout << "*************************************" << endl;
    cout << "Pon la opcion que deseas: ";
    char opcionnova;
    cin >> opcionnova;
    return opcionnova;
}


int main()
{

    almacen almac;
    char opcion;

    tprod nuevoproducto;
    cad newproducto;        //Nombre del nuevo producto
    float PrecioNewProd;    //Precio del nuevo producto
    int StockNewProd;       //Stock del nuevo producto

    int returnexistencias;  //Return del almacen.insertar

    cad ProductoVender;     //Producto a vender (c)
    int CantidadAVender;
    do
    {
        opcion = almac.menu();
        switch (opcion)
        {

            case 'A': //A
             //a
                        almac.vertabla();
                        break;

            case 66: //B
            case 98: //b
                        cout << "Inserte un nuevo producto: " << endl;
                        cout << "Nombre: "; cin >> newproducto;
                        cout << "Precio: "; cin >> PrecioNewProd;
                        cout << "Stock: "; cin >> StockNewProd;
                        nuevoproducto.cambiarnombre(newproducto);
                        nuevoproducto.cambiarprecio(PrecioNewProd);
                        nuevoproducto.cambiarstock(StockNewProd);
                        returnexistencias = almac.insertar(nuevoproducto);
                        switch (returnexistencias)
                        {
                            case 2: cout << "El almacen esta lleno crack.";
                            break;

                            case 1: cout << "El producto ya existe.";
                            break;

                            case 0: cout << "Producto anadido al almacen";
                            break;
                        }

                        break;

            case 67: //C
            case 99: //c
                        cout << "Indique el producto que desee vender: ";
                        cin >> ProductoVender;
                        returnexistencias = almac.existe(ProductoVender);
                        if (returnexistencias == -1)
                            cout << "Ese producto no existe";
                        else
                        {
                            cout << "Introduzca la cantidad a vender:";
                            cin >> CantidadAVender;
                            almac.vender(returnexistencias, CantidadAVender);
                        }
                break;

            case 68:  //D
            case 100: //d
                        almac.vaciar();
                        cout << "Almacen Vaciado";
                break;

            case 69:
            case 101:
                        cout << "Taluego";
                break;
        }

    }while (opcion !=69 && opcion != 101);

    return 0;
}



/*  Old main

    tprod noje;
    cad nom;
    float prec;
    int st, khan;

    //---------------------------------     Inicio
    noje.leenombre(nom);
    cout << "Nombre: " << nom << endl;

    prec = noje.leeprecio();                    //Mirarme bien que coño es esto
    cout << "Precio: " << prec << endl;

    noje.leestock(st);
    cout << "Stock: " << st << endl;
    cout << "\n\n";

    //---------------------------------     Cambio de producto
    cout << "Nuevo nombre: "; cin >> nom;
    noje.cambiarnombre(nom);

    cout << "Nuevo precio: "; cin >> prec;
    noje.cambiarprecio(prec);

    cout << "Nuevo stock: "; cin >> st;
    noje.cambiarstock(st);
    cout << "\n\n";

    //---------------------------------     Nuevo producto
    noje.leenombre(nom);
    cout << "Nombre: " << nom << endl;

    prec = noje.leeprecio();
    cout << "Precio: " << prec << endl;

    noje.leestock(st);
    cout << "Stock: " << st << endl;
    cout << "\n\n";

    //---------------------------------
    cout << "Indique la cantidad a comprar: "; cin >> khan;
    noje.vender(khan);      */


