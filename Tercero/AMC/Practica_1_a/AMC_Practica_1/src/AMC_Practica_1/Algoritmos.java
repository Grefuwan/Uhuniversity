package AMC_Practica_1;

import java.util.ArrayList;

public class Algoritmos {

    //Distancia entre 2 arrPuntos
    public static double distancia2(Punto p1, Punto p2) {
        return Math.sqrt(Math.pow(p2.getX() - p1.getX(), 2) + Math.pow(p2.getY() - p1.getY(), 2));
    }

    //Distancia entre 3 arrPuntos
    public static double distancia3(Punto p1, Punto p2, Punto p3) {
        return distancia2(p1, p2) + distancia2(p2, p3);
    }

    //Minima distancia entre 3 arrPuntos por FUERZA BRUTA
    public static ArrayList<Punto> minDistanTresarrPuntos(ArrayList<Punto> arrPuntos) {
        ArrayList<Punto> result = new ArrayList<Punto>();
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

    public static ArrayList<Punto> minDistanTresarrPuntosDyV(ArrayList<Punto> arrPuntos) {
        ArrayList<Punto> result = new ArrayList<Punto>();
        result.add(arrPuntos.get(0));
        result.add(arrPuntos.get(1));
        result.add(arrPuntos.get(2));

        double minima = 0;
        minima = distancia3(arrPuntos.get(0), arrPuntos.get(1), arrPuntos.get(2));

        double distancia = 0;

        if (arrPuntos.size() < 3) {

        }
        else {
            Integer mitad = arrPuntos.size() / 2;
            minDistanTresarrPuntosDyV(arrPuntos);
        }

        return result;

    }

}

