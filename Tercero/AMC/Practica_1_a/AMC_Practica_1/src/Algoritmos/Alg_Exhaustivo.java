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

    private ArrayList<Punto> result;
    
    public static ArrayList<Punto> minDistanTresPuntosExhaustivo(ArrayList<Punto> arrPuntos) {
        ArrayList<Punto> result = new ArrayList<>();
        result.add(arrPuntos.get(0));
        result.add(arrPuntos.get(1));
        result.add(arrPuntos.get(2));

        double minima = distancia3(arrPuntos.get(0), arrPuntos.get(1), arrPuntos.get(2));

        double distancia = 0;

        //Va a mirar la distancia de cada punto al resto para tener la mínima
        for (int i = 0; i < arrPuntos.size(); i++) {
            for (int j = 0; j < arrPuntos.size(); j++) {
                if (i == j) {
                    continue;
                }
                for (int k = 0; k < arrPuntos.size(); k++) {
                    if (k == j || i == k) {
                        continue;
                    }
                    distancia = distancia3(arrPuntos.get(i), arrPuntos.get(j), arrPuntos.get(k));

                    if (distancia < minima) {
                        minima = distancia;
                        result.set(0, arrPuntos.get(i));
                        result.set(1, arrPuntos.get(j));
                        result.set(2, arrPuntos.get(k));
                    }

                }
            }
        }

        return result;
    }

    public void toPunto(){
        return new Triangulo(result.get(0), result.get(1), result.get(2));
    }
    
}

