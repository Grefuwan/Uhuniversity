package Automatas;

import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author Juan Garcia Villagran
 */
public class Transicion {

    private String origen;
    private String transicion;
    private Set<String> destino = new HashSet<>();

    public Transicion(String origen, String transicion, String destino) {
        super();
        this.origen = origen;
        this.transicion = transicion;
        this.destino.add(destino);

    }

    public String getPrimeroResultante() {
        String result = null;
        for (String estResult : destino) {
            result = estResult;
            break;
        }
        return result;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }

    public void setTransicion(String transicion) {
        this.transicion = transicion;
    }

    public void setDestino(Set<String> destino) {
        this.destino = destino;
    }

    public String getOrigen() {
        return origen;
    }

    public String getTransicion() {
        return transicion;
    }

    public Set<String> getDestino() {
        return destino;
    }

    public String toString() {
        return "\n[" + origen + " --(" + transicion + ")-> " + destino.toString() + "]";
    }

}

