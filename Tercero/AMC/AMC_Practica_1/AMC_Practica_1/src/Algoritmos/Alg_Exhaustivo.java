package Algoritmos;

import AMC_Practica_1.Punto;
import AMC_Practica_1.Triangulo;
import static Algoritmos.Distancias.distancia3;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class Alg_Exhaustivo {

    private static ArrayList<Punto> arrResult = new ArrayList();

    public static Triangulo minDistanTresPuntosExhaustivo(ArrayList<Punto> arrPuntos) {
        Triangulo result = new Triangulo(arrPuntos.get(0), arrPuntos.get(1), arrPuntos.get(2));

        Triangulo aux;

        //Va a mirar la distancia de cada punto al resto para tener la mínima
        for (int i = 0; i < arrPuntos.size(); i++) {
            for (int j = i + 1; j < arrPuntos.size(); j++) {
                for (int k = j + 1; k < arrPuntos.size(); k++) {
                    aux = new Triangulo(arrPuntos.get(i), arrPuntos.get(j), arrPuntos.get(k));
                    if (aux.sumaLadoMenores() <= result.sumaLadoMenores()) {
                        result.setA(aux.getA());
                        result.setB(aux.getB());
                        result.setC(aux.getC());
                    }

                }
            }
        }
        return result;
    }

}

