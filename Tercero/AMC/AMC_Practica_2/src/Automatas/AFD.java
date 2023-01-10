package Automatas;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

/**
 * Define un Automata Finito Determinista
 *
 * @author Juan Garcia Villagran
 */
public class AFD implements Cloneable {

    private Set<String> estados;
    private String estadoInicial;
    private Set<String> estadosFinales;
    private List<Transicion> listaTransiciones;

    /**
     * Construye un AFD dados los estados, el estado inicial, los estados
     * finales y las transiciones
     *
     * @param estados           Estados que conforman el AFD
     * @param estadoInicial     Estado desde el que se parte
     * @param estadosFinales    Estados finales
     * @param listaTransiciones Transiciones con origen, simbolo de transicion y
     *                          destino
     */
    public AFD(Set<String> estados, String estadoInicial, Set<String> estadosFinales, List<Transicion> listaTransiciones) {
        this.estados = estados;
        this.estadoInicial = estadoInicial;
        this.estadosFinales = estadosFinales;
        this.listaTransiciones = listaTransiciones;
    }

    /**
     * Agrega una transicion al listado de transiciones
     *
     * @param origen     Origen de la transicion
     * @param transicion Simbolo de la transicion
     * @param destino    Destino de la transicion
     */
    public void agregarTransicion(String origen, String transicion, String destino) {
        listaTransiciones.add(new Transicion(origen, transicion, destino));
    }

    /**
     * Devuelve el destino de una transicion almacenada dado un origen y su
     * simbolo de transicion
     *
     * @param estado  Estado origen
     * @param simbolo Simbolo de la transicion
     *
     * @return Destino de la transicion, si existe
     */
    public String transicion(String estado, String simbolo) {
        String est2 = null;
        for (Transicion tran : listaTransiciones) {
            if (tran.getOrigen().equalsIgnoreCase(estado) && tran.getTransicion().equalsIgnoreCase(simbolo)) {
                est2 = tran.getPrimeroResultante();
            }
        }
        return est2;
    }

    /**
     * Comprueba si un estado es Final
     *
     * @param estado Estado a comprobar
     *
     * @return True o False si el estado es Final o no
     */
    public boolean esFinal(String estado) {
        boolean contains = false;
        for (String item : estadosFinales) {
            if (item.equalsIgnoreCase(estado)) {
                contains = true;
                break;
            }
        }
        return contains;
    }

    /**
     * Comprueba si una cadena de caracteres es válida en el autómata,
     * comenzando en el estado inicial y acabando en un estado final
     *
     * @param cadena Cadena de caracteres a comprobar
     *
     * @return True o False si la cadena es valida o no
     */
    public boolean reconocer(String[] cadena) {
        boolean valido = false;

        if (cadena.length > 0) {
            String estadoActual = this.estadoInicial;

            for (String entrada : cadena) {
                if (entrada.contentEquals("")) {    //Si un elemento de la cadena está vacío, pafuera
                    valido = false;
                    break;
                }

                boolean simbolo = false;

                for (Transicion tran : listaTransiciones) { //Buscamos que en las transiciones salgan los caracteres de la cadena
                    if (tran.getTransicion().equals(entrada)) {
                        simbolo = true;
                        break;
                    }
                }

                if (simbolo == true) {  //Si los simbolos son validos, comprobamos que lleguen a un Estado Final
                    String estadoSiguiente = null;

                    for (Transicion tran : listaTransiciones) {
                        if (tran.getOrigen().equals(estadoActual) && tran.getTransicion().equals(entrada)) {
                            estadoSiguiente = tran.getPrimeroResultante();
                            break;
                        }
                    }
                    if (estadoSiguiente == null) {
                        valido = false;
                        break;
                    }
                    else {
                        estadoActual = estadoSiguiente;
                    }
                }
                else {
                    valido = false;
                    break;
                }
            }

            valido = esFinal(estadoActual);
        }
        else {
            valido = false;
        }

        return valido;
    }

    public String toString() {
        String str = "AFD\n";
        str += "Estados:" + estados + "\n";
        str += "Estado Inicial:" + estadoInicial + "\n";
        str += "Estados Finales:" + estadosFinales + "\n";
        str += "Lista de Transiciones:" + listaTransiciones.toString() + "\n";
        return str;
    }

    /**
     * Define como se clona un objeto AFD
     *
     * @return
     *
     * @throws CloneNotSupportedException
     */
    @Override
    public Object clone() throws CloneNotSupportedException {
        AFD obj = null;
        try {
            obj = (AFD) super.clone();
            obj.listaTransiciones = new ArrayList<>(listaTransiciones);
        } catch (CloneNotSupportedException ex) {
            System.out.println("No se puede duplicar el autómata.");
        }
        return obj;
    }

    public void setEstados(Set<String> estados) {
        this.estados = estados;
    }

    public void setEstadoInicial(String estadoInicial) {
        this.estadoInicial = estadoInicial;
    }

    public void setEstadosFinales(Set<String> estadosFinales) {
        this.estadosFinales = estadosFinales;
    }

    public void setListaTransiciones(List<Transicion> listaTransiciones) {
        this.listaTransiciones = listaTransiciones;
    }

    public Set<String> getEstados() {
        return estados;
    }

    public String getEstadoInicial() {
        return estadoInicial;
    }

    public Set<String> getEstadosFinales() {
        return estadosFinales;
    }

    public List<Transicion> getListaTransiciones() {
        return listaTransiciones;
    }

}

