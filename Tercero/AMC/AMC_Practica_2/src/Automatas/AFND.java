package Automatas;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Define un Automata Finito No Determinista
 *
 * @author Juan Garcia Villagran
 */
public class AFND implements Cloneable {

    private Set<String> estados;
    private Set<String> estadosIniciales;
    private Set<String> estadosFinales;
    private List<Transicion> listaTransiciones;
    private List<TransicionLambda> transicionesLambda; //indica la lista de listaTransiciones λ del AFND

    /**
     * Construye un AFND dados sus estados, los estados iniciales, los estados
     * finales, las transiciones y las transiciones lambda
     *
     * @param estados
     * @param estadosIniciales
     * @param estadosFinales
     * @param transiciones
     * @param transicionesLambda
     */
    public AFND(Set<String> estados, Set<String> estadosIniciales, Set<String> estadosFinales, List<Transicion> transiciones, List<TransicionLambda> transicionesLambda) {
        super();
        this.estados = estados;
        this.estadosIniciales = estadosIniciales;
        this.estadosFinales = estadosFinales;
        this.listaTransiciones = transiciones;
        this.transicionesLambda = transicionesLambda;
    }

    /**
     * Comprueba si un estado es Final
     *
     * @param estado Estado a comprobar
     *
     * @return True o False si el estado es Final o no
     */
    public boolean esFinal(String estado) {
        boolean esfinal = false;
        if (estadosFinales.contains(estado)) {
            esfinal = true;
        }
        return esfinal;
    }

    /**
     * Comprueba si un macroestado es Final
     *
     * @param macroestado
     *
     * @return True o False si el estado es Final o no
     */
    public boolean esFinal(Set<String> macroestado) {
        boolean esfinal = false;
        for (String estado : macroestado) {
            if (estadosFinales.contains(estado)) {
                esfinal = true;
                break;
            }
        }
        return esfinal;
    }

    /**
     * Determina los estados destino tras las listaTransiciones de un estado
     *
     * @param estado  Estado que transiciona
     * @param simbolo Transicion
     *
     * @return Estados destino tras una condicion
     */
    public Set<String> transicion(String estado, String simbolo) {
        Set<String> nuevos = new HashSet<>();
        for (Transicion tran : listaTransiciones) {
            if (tran.getOrigen().equalsIgnoreCase(estado) && tran.getTransicion().equalsIgnoreCase(simbolo)) {
                nuevos.addAll(tran.getDestino());
            }
        }
        return nuevos;
    }

    /**
     * Devuelve los estados destino tras la transicion de todo el macroestado
     *
     * @param macroestado Macroestado de estados
     * @param simbolo     Transicion
     *
     * @return Estados destino
     */
    public Set<String> transicion(Set<String> macroestado, String simbolo) {
        Set<String> nuevos = new HashSet<>();
        for (String estado : macroestado) {
            nuevos.addAll(transicion(estado, simbolo));
        }
        return nuevos;
    }

    public Set<String> transicionLambda(String estado) {
        Set<String> nuevos = new HashSet<>();
        for (TransicionLambda tran : transicionesLambda) {
            if (tran.getOrigen().equalsIgnoreCase(estado)) {
                nuevos.addAll(tran.getEstadosResultantes());
            }
        }
        return nuevos;
    }

    public void lambdaClausura(Set<String> macroestado) {
        int antiguoN = -1;
        Set<String> nuevos = new HashSet<>();
        do {
            antiguoN = macroestado.size();
            nuevos = new HashSet<>(macroestado);

            for (String estado : macroestado) {
                nuevos.addAll(transicionLambda(estado));
            }
            macroestado.addAll(nuevos);
        } while (antiguoN != macroestado.size());
        macroestado.addAll(nuevos);
    }

    public boolean reconocer(String[] cadena) {

        boolean valido = false;

        if (cadena.length > 0) {

            Set<String> siguienteSet = new HashSet<String>(getEstadosIniciales());

            for (String entrada : cadena) {
                if (entrada.equals("")) {
                    valido = false;
                    break;
                }

                boolean simbolo = false;

                for (Transicion tran : listaTransiciones) {
                    if (tran.getTransicion().equals(entrada)) {
                        simbolo = true;
                        break;
                    }
                }

                if (simbolo == true) {
                    lambdaClausura(siguienteSet);
                    siguienteSet = transicion(siguienteSet, entrada);
                }
                else {
                    valido = true;
                    break;
                }
            }
            valido = esFinal(siguienteSet);
        }
        return valido;

    }

    @Override
    public String toString() {
        String str = "AFND\n";
        str += "estados:" + Arrays.toString(estados.toArray(String[]::new)) + "\n";
        str += "estados iniciales:" + Arrays.toString(estadosIniciales.toArray(String[]::new)) + "\n";
        str += "estados finales:" + Arrays.toString(estadosFinales.toArray(String[]::new)) + "\n";
        str += "transiciones:" + listaTransiciones.toString() + "\n";
        str += "transiciones lambda:" + transicionesLambda.toString() + "\n";
        return str;
    }

    /**
     * Define como se clona un objeto AFND
     */
    @Override
    public Object clone() throws CloneNotSupportedException {
        AFND obj = null;
        try {
            obj = (AFND) super.clone();
            obj.estados = new HashSet<>(estados);
            obj.estadosIniciales = new HashSet<>(estadosIniciales);
            obj.estadosFinales = new HashSet<>(estadosFinales);
            obj.listaTransiciones = new ArrayList<>(listaTransiciones);
            obj.transicionesLambda = new ArrayList<>(transicionesLambda);
        } catch (CloneNotSupportedException ex) {
            System.out.println("No se puede duplicar el autómata.");
        }
        return obj;
    }

    /**
     * @return Devuelve los estados totales
     */
    public Set<String> getEstados() {
        return new HashSet<>(estados);
    }

    /**
     * @param estados Establece los estados totales
     */
    public void setEstados(Set<String> estados) {
        this.estados = estados;
    }

    /**
     * @return Devuelve los estados iniciales
     */
    public Set<String> getEstadosIniciales() {
        return new HashSet<>(estadosIniciales);
    }

    /**
     * @param estadosIniciales Establece los estados iniciales
     */
    public void setEstadosIniciales(Set<String> estadosIniciales) {
        this.estadosIniciales = estadosIniciales;
    }

    /**
     * @return Devuelve los estados finales
     */
    public Set<String> getEstadosFinales() {
        return new HashSet<>(estadosFinales);
    }

    /**
     * @param estadosFinales Establece los estados finales
     */
    public void setEstadosFinales(Set<String> estadosFinales) {
        this.estadosFinales = estadosFinales;
    }

    /**
     * @return Devuelve las listaTransiciones comunes
     */
    public List<Transicion> getListaTransiciones() {
        return listaTransiciones;
    }

    /**
     * @param listaTransiciones Establece las listaTransiciones comunes
     */
    public void setListaTransiciones(List<Transicion> listaTransiciones) {
        this.listaTransiciones = listaTransiciones;
    }

    /**
     * @return Devuelve las listaTransiciones Lambda
     */
    public List<TransicionLambda> getTransicionesLambda() {
        return transicionesLambda;
    }

    /**
     * @param transicionesLambda Establece las listaTransiciones Lambda
     */
    public void setTransicionesLambda(List<TransicionLambda> transicionesLambda) {
        this.transicionesLambda = transicionesLambda;
    }

}

