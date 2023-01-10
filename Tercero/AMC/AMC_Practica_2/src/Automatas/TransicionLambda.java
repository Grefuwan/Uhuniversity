package Automatas;

import java.util.Set;

/**
 *
 * @author Juan Garcia Villagran
 */
public class TransicionLambda {

    private String origen;
    private Set<String> estadosResultantes;

    public TransicionLambda(String origen, Set<String> estadosResultantes) {
        super();
        this.origen = origen;
        this.estadosResultantes = estadosResultantes;
    }

    public String toString() {
        return "[" + origen + ", " + estadosResultantes.toString() + "]";
    }

    public String getOrigen() {
        return origen;
    }

    public Set<String> getEstadosResultantes() {
        return estadosResultantes;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }

    public void setEstadosResultantes(Set<String> estadosResultantes) {
        this.estadosResultantes = estadosResultantes;
    }

}

