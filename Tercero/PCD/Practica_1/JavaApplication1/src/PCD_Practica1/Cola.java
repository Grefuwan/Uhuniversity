package PCD_Practica1;

import java.util.Arrays;

public class Cola implements ICola {

    int head;
    int tail;
    int contadorTail = 0;   //Contador para el módulo y num de vueltas de la cola
    int contadorHead = 0;
    int capacidad;  //Capacidad del vector
    int numElementos;   //Numero de Elementos que hay
    Object[] datos;

    public Cola(int capacidad) {    //Constructor
        //Inicializa la cola y los atributos de la clase
        this.head = 0;
        this.tail = 0;
        this.capacidad = capacidad;
        this.datos = datos = new Object[capacidad];
        for (int i = 0; i < capacidad; i++) {
            this.datos[i] = 0;
        }
    }

    
    public int GetNum() {

        int numElems = 0;

        for (int i = 0; i < capacidad; i++) {
            if ((int) datos[i] != -1) {
                numElems++;
            }
        }

        return numElems;
    }

    
    public void Acola(Object elemento) throws Exception {
        //Comprueba si la Cola no está llena, mientras no esté llena
        //Si no lo está, añade elemento
        try {
            if (!colallena() ){
                System.out.println("Voy a llenar la cola con el elemento " + elemento.toString());
                datos[tail] = elemento;
                contadorTail++;
                tail = contadorTail % capacidad;
                        
            }
        } catch (Exception e) {
        }


//        try {
//            if (numElementos != getNum()) {
//                datos[tail] = elemento;
//                contadorTail++;
//                tail = contadorTail % capacidad;
//            }
//        } catch (Exception e) {
//            throw e = new java.lang.Exception("Error: Cola Llena");
//        }

    }

    
    public Object Desacola() throws Exception {
        Object obj = 0;
//Comprueba que existan elementos, busca el primero y lo extrae
        try {
            if (numElementos != 0) {
                obj = datos[head];
                datos[head] = -1;
                contadorHead++;
                head = contadorHead % capacidad;
            }

        } catch (Exception e) {
            throw e = new java.lang.Exception("Error: Cola Vacia");
        }

        return obj;
    }

    @Override
    public Object Primero() throws Exception {
        Object obj = null;
        //Comprueba que existan elementos, busca el primero y lo extrae
        try {
            if (numElementos != 0) {
                obj = datos[head];
                contadorHead++;
                head = contadorHead % capacidad;
            }
        } catch (Exception e) {
            throw e = new java.lang.Exception("Error: Cola Vacia");
        }

        return obj;
    }

    public boolean colavacia() {
        boolean isVacia = false;

        if (GetNum() == 0) {
            isVacia = true;
        }

        return isVacia;
    }

    public boolean colallena() {
        boolean isLlena = false;

        if (GetNum() == capacidad) {
            isLlena = true;
        }

        return isLlena;
    }

    @Override
    public String toString() {
        String str = "";
        int i = 0;
        int tamano = datos.length;
        while (i < tamano) {
            if (!datos[i].equals(0)) {
                str += datos[i].toString() + " - ";
            } else {
                str += " - 0 - ";
            }
            i++;
        }
        return str;

    }

}
