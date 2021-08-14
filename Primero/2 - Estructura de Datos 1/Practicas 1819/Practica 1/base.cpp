/*

typedef char cadena[101];
struct Sfecha
{
    int dia;
    int mes;
    int anno;
};
struct venta
{
 Sfecha fecha;
 int unidades;
 int producto;
 float importe;
};


class ventas
{

  fstream detalle;
  cadena fichero;
  cadena ficheroresumen;


    public:

       void anadirventa(int num);
       void mostrarventas();
       void resumirfichero();
       void estadisticas(int tipo,int annoini,int annofin);
       bool asignar(cadena Fichero,cadena FicheroResumen);

};

struct producto
{
 Sfecha ultimaventa;
 int unidades;
 int producto;
 float importe;
 int tipo;
 char nombre[20];
};

class productos
{
    int numproductos;
    int maxcatalogo;
    fstream resumen;
    cadena fichero;
    ventas ven;
    public:
        productos(cadena Fichero,cadena FicheroVentas);
        ~productos();
        int getmaxcatalogo();
       void setmaxcatalogo(int num);
       int getnumproductos(){return numproductos;};
       void setnumproductos(int num){numproductos=num;};
       void mostrarproductos();
       void mostrarventas();
       bool anadirventa();
       void actualizarresumen();
       void obtenerestadisticas(int tipo,int annoini,int annofin);
};

// METODO DE ORDENACION BURBUJA de una clase vector con los elementos en el atributo celda. Deberá adaptarlo a su problema/práctica
void vector::Burbuja(int inicio, int fin)
        {
        int pos,ele;
        for (pos=inicio; pos<fin; pos++)
            for (ele=fin; ele>pos; ele--)
                if(celda[ele-1]>celda[ele])
                    intercambiar(celda[ele-1],celda[ele]);//Funciín genérica que tendrá que ser implementada
        }
*/
