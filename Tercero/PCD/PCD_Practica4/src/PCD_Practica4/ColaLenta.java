package PCD_Practica4;

public class ColaLenta implements ICola {

    private int head;
    private int tail;
    private int capacidad;  //Capacidad del vector
    private int numElementos;   //Numero de Elementos que hay
    private Object[] datos;
    private CanvasCola cv;

    public ColaLenta(int capacidad, CanvasCola elcanvas) {    //Constructor
        this.head = 0;
        this.tail = 0;
        this.capacidad = capacidad;
        this.numElementos = 0;
        this.datos = new Object[capacidad];
        this.cv = elcanvas;

        for (int i = 0; i < capacidad; i++) {
            this.datos[i] = 0;
        }
    }

    /**
     * Devuelve el numero de elementos que hay en la cola
     *
     * @return this.numelementos
     */
    @Override
    public int getNum() {
        return this.numElementos;
    }

    /**
     * Comprueba si la ColaLenta no está llena.Si no lo está, añade elemento Si
     * no puede acolar, hace 3 intentos esperando a que haya hueco. Si no lo
     * consigue al tercero, lanza excepcion de Cola Llena y finaliza el hilo.
     *
     * @param elemento que encola
     *
     * @throws java.lang.Exception Si la cola está llena
     */
    @Override
    public synchronized void Acola(Object elemento) throws Exception {

        int intentos = 0;

        while (colallena() && intentos < 3) {
            try {
                cv.avisa("Acola: Cola Llena");
                wait();
                intentos++;
            } catch (Exception e) {
                throw new Exception("Acola: Cola Llena");
            }

        }

        if (!colallena()) {
            datos[tail] = elemento;
            numElementos++;
            tail = ++tail % capacidad;
            cv.representa(datos, head, tail, numElementos);

            notifyAll();
        }
        else {
            throw new Exception("Acola: Cola Llena");
        }

    }

    /**
     * Comprueba que existan elementos, busca el primero y lo extrae
     *
     * @return Elemento que desacola
     *
     * @throws java.lang.Exception Si la cola está vacía
     */
    @Override
    public synchronized Object Desacola() throws Exception {

        int intentos = 0;
        Object obj = datos[head];
        
        while (colavacia() && intentos < 3) {
            try {
                cv.avisa("Desacola: Cola Vacia");
                wait();
                intentos++;
            } catch (InterruptedException ex) {
                throw new Exception();
            }
        }

        if (!colavacia()) {
            datos[head] = 0;
            numElementos--;
            head = ++head % capacidad;
            cv.representa(datos, head, tail, numElementos);

            notifyAll();
        }

        else {
            throw new Exception("Desacola: Cola Vacia");
        }

        return obj;
    }

    /**
     * Comprueba que existan elementos, busca el primero y lo devuelve
     *
     * @return Primer elemento de la cola
     *
     * @throws java.lang.Exception Si la cola está vacía
     */
    @Override
    public Object Primero() throws Exception {
        if (colavacia()) {
            throw new Exception("Primero: Cola Vacia");
        }
        return datos[head];

    }

    public boolean colavacia() {
        return this.numElementos == 0;
    }

    public boolean colallena() {
        return this.numElementos == this.capacidad;
    }

    @Override
    public String toString() {
        String str = "";
        int i = 0;
        int tamano = datos.length;
        while (i < tamano) {
            if (!datos[i].equals(0)) {
                str += " - " + datos[i].toString() + " - ";
            }
            else {
                str += " - ~ - ";
            }
            i++;
        }
        return str;

    }

}

