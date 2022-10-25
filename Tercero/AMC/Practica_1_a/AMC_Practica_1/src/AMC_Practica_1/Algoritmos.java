package AMC_Practica_1;

import java.util.ArrayList;

public class Algoritmos {

    //Distancia entre 2 puntos
    public static double distancia2(Punto p1, Punto p2) {
        return Math.sqrt(Math.pow(p2.getPuntoX() - p1.getPuntoX(), 2) + Math.pow(p2.getPuntoY() - p1.getPuntoY(), 2));
    }

    //Distancia entre 3 puntos
    public static double distancia3(Punto p1, Punto p2, Punto p3) {
        return distancia2(p1, p2) + distancia2(p2, p3);
    }

    //Minima distancia entre 3 puntos por FUERZA BRUTA
    public static ArrayList<Punto> minDistanTresPuntos(ArrayList<Punto> puntos) {
        ArrayList<Punto> result = new ArrayList<Punto>();
        result.add(puntos.get(0));
        result.add(puntos.get(1));
        result.add(puntos.get(2));

        double minima = 0;
        minima = distancia3(puntos.get(0), puntos.get(1), puntos.get(2));

        double distancia = 0;

        //Va a mirar la distancia de cada punto al resto para tener la mínima
        for (int i = 0; i < puntos.size(); i++) {
            for (int j = 0; j < puntos.size(); j++) {
                if (i == j) {
                    continue;
                }
                for (int k = 0; k < puntos.size(); k++) {
                    if (k == j || i == k) {
                        continue;
                    }
                    distancia = distancia3(puntos.get(i), puntos.get(j), puntos.get(k));

                    if (distancia < minima) {
                        minima = distancia;
                        result.set(0, puntos.get(i));
                        result.set(1, puntos.get(j));
                        result.set(2, puntos.get(k));
                    }

                }
            }
        }

        return result;

    }

    public static ArrayList<Punto> minDistanTresPuntosDyV(ArrayList<Punto> puntos) {
        ArrayList<Punto> result = new ArrayList<Punto>();
        result.add(puntos.get(0));
        result.add(puntos.get(1));
        result.add(puntos.get(2));

        double minima = 0;
        minima = distancia3(puntos.get(0), puntos.get(1), puntos.get(2));

        double distancia = 0;

        if (puntos.size() < 3) {

        } else {
            Integer mitad = puntos.size() / 2;
            minDistanTresPuntosDyV(puntos);
        }

        return result;

    }

}
