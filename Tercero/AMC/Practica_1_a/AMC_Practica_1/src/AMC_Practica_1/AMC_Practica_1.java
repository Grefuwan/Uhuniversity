package AMC_Practica_1;

import java.util.ArrayList;

public class AMC_Practica_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Punto pA = new Punto(16.47, 36.10);
        Punto pB = new Punto(16.47, 54.44);
        Punto pC = new Punto(20.09, 92.54);
        Punto pD = new Punto(22.39, 93.37);
        Punto pE = new Punto(25.23, 97.24);
        Punto pF = new Punto(22.00, 36.05);
        Punto pG = new Punto(19.41, 37.12);
        Punto pH = new Punto(20.47, 97.02);
        Punto pI = new Punto(17.20, 96.29);
        Punto pM = new Punto(04.15, 16.32);
        Punto pJ = new Punto(16.30, 97.22);
        Punto pK = new Punto(14.05, 98.12);
        //Varios puntos inventados

        ArrayList<Punto> puntos = new ArrayList<Punto>();

        puntos.add(pA);
        puntos.add(pB);
        puntos.add(pC);
        puntos.add(pD);
        puntos.add(pE);
        puntos.add(pF);
        puntos.add(pG);
        puntos.add(pH);
        puntos.add(pI);
        puntos.add(pJ);
        puntos.add(pK);
        puntos.add(pM);
        //Añado esos puntos

        //Muestro puntos iniciales
        for (int p = 0; p < puntos.size(); p++) {
            System.out.println("Punto: " + puntos.get(p).toString() + "\n");
        }

        ArrayList<Punto> solucion = new ArrayList<Punto>();
        solucion = Algoritmos.minDistanTresPuntos(puntos);

        //Muestro solucion
        System.out.println("\n");

        for (int p = 0; p < solucion.size(); p++) {
            System.out.println("Solucion:" + solucion.get(p).toString());
        }
    }

}
