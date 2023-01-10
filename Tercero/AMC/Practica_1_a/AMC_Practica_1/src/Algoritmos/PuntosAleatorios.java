package Algoritmos;

import AMC_Practica_1.Punto;
import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class PuntosAleatorios {

    private int numAleatorios = 0;
    private static Random r = new Random();
    private static ArrayList<Punto> arrPuntosAleatorios;

    public PuntosAleatorios(int numAleatorios) {
        this.numAleatorios = numAleatorios;
    }

    public static ArrayList<Punto> creaArrayAleatorios(int numAleatorios) {
        arrPuntosAleatorios = new ArrayList();

        for (int i = 0; i < numAleatorios; i++) {
            int coordX = r.nextInt(numAleatorios + 1);
            int coordY = r.nextInt(numAleatorios + 1);
            arrPuntosAleatorios.add(i, new Punto((int) coordX, (int) coordY));
        }
        System.out.println(arrPuntosAleatorios.toString());
        return arrPuntosAleatorios;

    }

}

