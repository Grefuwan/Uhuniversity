package Algoritmos;

import AMC_Practica_1.Punto;
import AMC_Practica_1.Triangulo;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class Alg_DyV {

    private static Triangulo tMinimo;
    public static ArrayList<Punto> solucion;

    public static Triangulo minDistanTresPuntosDyV(ArrayList<Punto> arrPuntos) {
        arrPuntos = Distancias.quicksort(arrPuntos);
        Triangulo result = minDistanTresPuntosDyVRecurs(arrPuntos, 0, arrPuntos.size());
        return result;
    }

    public static Triangulo minDistanTresPuntosDyVRecurs(ArrayList<Punto> arrPuntos, int izq, int dcha) {
        if (dcha - izq + 1 <= 6) {
            ArrayList<Punto> cambio = new ArrayList();
            cambio=arrPuntos;
            return Alg_Exhaustivo.minDistanTresPuntosExhaustivo(cambio);
        }

    }

    public static ArrayList<Punto> convierteTrianguloArray() {
        solucion.add(0, tMinimo.getA());
        solucion.add(1, tMinimo.getB());
        solucion.add(2, tMinimo.getC());

        return solucion;
    }

}

