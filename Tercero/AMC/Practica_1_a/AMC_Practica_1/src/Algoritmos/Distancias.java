package Algoritmos;

import AMC_Practica_1.Punto;
import java.awt.geom.Point2D;
import java.util.*;

public class Distancias {

    //Distancia entre 2 arrPuntos
    public static double distancia2(Punto p1, Punto p2) {
        return Point2D.distance(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }

    //Distancia entre 3 arrPuntos
    public static double distancia3(Punto p1, Punto p2, Punto p3) {
        return distancia2(p1, p2) + distancia2(p2, p3);
    }

    
    
    
    public static ArrayList<Punto> quicksort(ArrayList<Punto> puntos) {
        quicksort(puntos, 0, puntos.size() - 1);
        return puntos;
    }

    public static void quicksort(ArrayList<Punto> P, int izq, int dcha) {
        if (izq < dcha) {
            int q = partition(P, izq, dcha);
            quicksort(P, izq, q);
            quicksort(P, q + 1, dcha);
        }
    }

    @SuppressWarnings("empty-statement")
    public static int partition(ArrayList<Punto> P, int e, int d) {
        double x = P.get(e).getX();
        int i = e - 1;
        int j = d + 1;
        for (;;) {
            while (x < P.get(--j).getX());
            while (P.get(++i).getX() < x);
            if (i >= j) {
                return j;
            }
            swap(P, i, j);
        }
    }

    public static void swap(ArrayList<Punto> P, int i, int j) {
        Punto aux = P.get(i);
        P.set(i, P.get(j));
        P.set(j, aux);
    }

}

